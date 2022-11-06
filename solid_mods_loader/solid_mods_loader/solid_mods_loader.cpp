#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <windows.h>
#include "json/json.h"

const char game_executable[] = "mgs2_sse.exe";

HANDLE process_handle = INVALID_HANDLE_VALUE;
HANDLE thread_handle = INVALID_HANDLE_VALUE;

std::string mods_folder;

std::vector<std::string*> config_names;

std::string patch_types[] = { "offset", "call", "jmp", "bytes", "float", "bool" };

std::unordered_map<std::string, DWORD> loaded_modules;

void start_process(char* executable)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(NULL, executable, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		exit(0);
	}

	process_handle = pi.hProcess;
	thread_handle = pi.hThread;
}

DWORD load_dll(HANDLE handle, const char* path)
{
	DWORD dll_base = NULL;

	int length = strlen(path) + 1;

	LPVOID buffer = VirtualAllocEx(handle, NULL, length, MEM_COMMIT, PAGE_READWRITE);

	WriteProcessMemory(handle, buffer, (LPVOID)path, length, NULL);

	HANDLE h = CreateRemoteThread(handle, NULL, 0,
		(LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"),
			"LoadLibraryA"), buffer, 0, NULL);

	WaitForSingleObject(h, INFINITE);

	GetExitCodeThread(h, &dll_base);

	VirtualFreeEx(handle, buffer, length, MEM_RELEASE);

	return dll_base;
}

DWORD load_dll_if_not_loaded(HANDLE handle, const char* path, bool debug)
{
	DWORD dll_base = NULL;

	if (loaded_modules.find(path) == loaded_modules.end())
	{
		dll_base = load_dll(handle, path);

		if (debug)
		{
			printf("\t\tLoaded \"%s\": 0x%X\n", path, dll_base);
		}

		loaded_modules[path] = dll_base;
	}
	else
	{
		dll_base = loaded_modules[path];
	}

	return dll_base;
}

DWORD install_hook(HANDLE handle, HMODULE library, DWORD address, const char* name, bool jump = false)
{
	BYTE buf[10];
	memset(buf, 0, sizeof(buf));

	DWORD target = (DWORD)GetProcAddress(library, name);

	if (jump)
	{
		buf[0] = 0xE9;
	}
	else
	{
		buf[0] = 0xE8;
	}

	*(DWORD *)(buf + 1) = (DWORD)(target - (address + 5));

	WriteProcessMemory(handle, (LPVOID)address, buf, 5, NULL);

	return target;
}

void get_mods_folder()
{
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);

	mods_folder = buffer;

	mods_folder = mods_folder.substr(0, mods_folder.find_last_of("\\/"));
	mods_folder.append("\\mods\\");
}

void find_configs()
{
	WIN32_FIND_DATA ffd;
	HANDLE h = INVALID_HANDLE_VALUE;

	h = FindFirstFile(std::string(mods_folder).append("*").c_str(), &ffd);

	if (INVALID_HANDLE_VALUE == h)
	{
		return;
	}

	do
	{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			std::string filename = std::string(ffd.cFileName);

			if (filename.size() >= 5 && filename.compare(filename.length() - 5, 5, ".json") == 0)
			{
				config_names.push_back(new std::string(mods_folder + filename));
			}
		}
	} while (FindNextFile(h, &ffd) != 0);

	FindClose(h);
}

void load_mods(HANDLE handle)
{
	for (unsigned int u = 0; u < config_names.size(); u++)
	{
		printf("\n");

		Json::Value root;
		std::ifstream ifs;
		ifs.open(config_names[u]->c_str());

		Json::CharReaderBuilder builder;
		builder["collectComments"] = true;
		JSONCPP_STRING errs;
		if (!parseFromStream(builder, ifs, &root, &errs)) 
		{			
			printf("Error! Failed to parse config %s!\n", config_names[u]->c_str());
			std::cout << errs << std::endl;
			continue;
		}

		const Json::Value name_value = root["name"];
		const Json::Value description_value = root["description"];
		const Json::Value enabled_value = root["enabled"];

		bool debug = false;
		const Json::Value debug_value = root["debug"];
		if (debug_value.isBool())
		{
			debug = debug_value.asBool();
		}

		if (name_value.isNull() || description_value.isNull() || enabled_value.isNull())
		{
			printf("Error! Missing name/description/enabled value(s)!\n");
			continue;
		}

		const char *s = "Disabled";
		if (enabled_value.asBool())
		{
			s = "Enabled";
		}

		printf("Mod \"%s\" - %s\n", name_value.asCString(), s);

		if (!enabled_value.asBool())
		{
			printf("\t-> Skipping...\n");
			continue;
		}

		printf("\t-> Description:\n");
		printf("\t\t%s\n\n", description_value.asCString());

		const Json::Value patches = root["patches"];

		if (patches.isNull())
		{
			printf("\t-> Error! There are no patches!\n");
			continue;
		}

		bool flag = false;
		for (unsigned int v = 0; v < patches.size(); v++)
		{
			const Json::Value patch = patches[v];

			const Json::Value type_value = patch["type"];
			const Json::Value address_value = patch["address"];

			if (type_value.isNull())
			{
				printf("\t-> Error! Bad patch without type!\n");
				flag = true;
				break;
			}

			const std::string type = type_value.asString();

			DWORD address = NULL;
			if (address_value.isNull())
			{
				if (strcmp(type.c_str(), "bytes") == 0
					|| strcmp(type.c_str(), "float") == 0
					|| strcmp(type.c_str(), "bool") == 0
					)
				{
					const Json::Value library_value = patch["library"];
					const Json::Value export_value = patch["export"];

					if (library_value.isNull() || export_value.isNull())
					{
						printf("\t-> Error! \"%s\" patch type without library/export!\n", type.c_str());
						flag = true;
						break;
					}

					const std::string library_name = library_value.asString();
					std::string dll_path = std::string(mods_folder + library_name);
					load_dll_if_not_loaded(handle, dll_path.c_str(), debug);
					HMODULE library = LoadLibrary(dll_path.c_str());

					address = (DWORD)GetProcAddress(library, export_value.asCString());
				}
				else
				{
					printf("\t-> Error! Bad patch without address!\n");
					flag = true;
					break;
				}
			}

			if (!address_value.isNull())
			{
				const std::string address_string = address_value.asString();
				address = std::stoul(address_string, NULL, 0x10);
			}

			if (std::find(std::begin(patch_types), std::end(patch_types), type) == std::end(patch_types))
			{
				printf("\t-> Error! Unknown patch type \"%s\"!\n", type.c_str());
				flag = true;
				break;
			}

			if (strcmp(type.c_str(), "offset") == 0)
			{
				const Json::Value library_value = patch["library"];
				const Json::Value export_value = patch["export"];

				if (library_value.isNull() || export_value.isNull())
				{
					printf("\t-> Error! \"offset\" patch type without library/export!\n");
					flag = true;
					break;
				}

				const std::string library_name = library_value.asString();
				std::string dll_path = std::string(mods_folder + library_name);
				load_dll_if_not_loaded(handle, dll_path.c_str(), debug);
				HMODULE library = LoadLibrary(dll_path.c_str());

				BYTE offset[4];
				*(DWORD*)offset = (DWORD)GetProcAddress(library, export_value.asCString());

				WriteProcessMemory(handle, (LPVOID)address, &offset, sizeof(offset), NULL);

				if (debug)
				{
					printf("\t\tPatch (offset): Address 0x%X, Offset 0x%X\n", address, *(DWORD*)offset);
				}
			}
			else if (strcmp(type.c_str(), "call") == 0)
			{
				const Json::Value library_value = patch["library"];
				const Json::Value export_value = patch["export"];

				if (library_value.isNull() || export_value.isNull())
				{
					printf("\t-> Error! \"call\" patch type without library/export!\n");
					flag = true;
					break;
				}

				const std::string library_name = library_value.asString();
				std::string dll_path = std::string(mods_folder + library_name);
				load_dll_if_not_loaded(handle, dll_path.c_str(), debug);
				HMODULE library = LoadLibrary(dll_path.c_str());

				DWORD target = install_hook(handle, library, address, export_value.asCString());

				if (debug)
				{
					printf("\t\tPatch (call):   Address 0x%X, Target 0x%X\n", address, target);
				}
			}
			else if (strcmp(type.c_str(), "jmp") == 0)
			{
				const Json::Value library_value = patch["library"];
				const Json::Value export_value = patch["export"];

				if (library_value.isNull() || export_value.isNull())
				{
					printf("\t-> Error! \"jmp\" patch type without library/export!\n");
					flag = true;
					break;
				}

				const std::string library_name = library_value.asString();
				std::string dll_path = std::string(mods_folder + library_name);
				load_dll_if_not_loaded(handle, dll_path.c_str(), debug);
				HMODULE library = LoadLibrary(dll_path.c_str());

				DWORD target = install_hook(handle, library, address, export_value.asCString(), true);

				if (debug)
				{
					printf("\t\tPatch (jmp):    Address 0x%X, Target 0x%X\n", address, target);
				}
			}
			else if (strcmp(type.c_str(), "bytes") == 0)
			{
				const Json::Value data_value = patch["value"];

				if (data_value.isNull())
				{
					printf("\t-> Error! \"bytes\" patch type without value!\n");
					flag = true;
					break;
				}

				const std::string bytes = data_value.asString();
				size_t size = bytes.size() / 2;
				const char* pos = bytes.c_str();

				char* buf = new char[size]();

				for (size_t count = 0; count < size; count++)
				{
					sscanf_s(pos, "%2hhx", &buf[count]);
					pos += 2;
				}

				WriteProcessMemory(handle, (LPVOID)address, buf, size, NULL);

				if (debug)
				{
					printf("\t\tPatch (bytes):  Address 0x%X, Size 0x%X\n", address, size);
				}

				delete buf;
			}
			else if (strcmp(type.c_str(), "float") == 0)
			{
				const Json::Value float_value = patch["value"];

				if (float_value.isNull())
				{
					printf("\t-> Error! \"float\" patch type without value!\n");
					flag = true;
					break;
				}

				float f = float_value.asFloat();

				DWORD data = *(DWORD*)&f;

				WriteProcessMemory(handle, (LPVOID)address, &data, sizeof(data), NULL);

				if (debug)
				{
					printf("\t\tPatch (float):  Address 0x%X, Dword 0x%X\n", address, data);
				}
			}
			else if (strcmp(type.c_str(), "bool") == 0)
			{
				const Json::Value bool_value = patch["value"];

				if (bool_value.isNull())
				{
					printf("\t-> Error! \"bool\" patch type without value!\n");
					flag = true;
					break;
				}

				BYTE data = (BYTE)bool_value.asBool();

				WriteProcessMemory(handle, (LPVOID)address, &data, sizeof(data), NULL);

				if (debug)
				{
					printf("\t\tPatch (bool):  Address 0x%X, Byte 0x%X\n", address, data);
				}
			}
		}
			
		if (flag)
		{
			printf("\t-> Error! Failed to parse patches!\n");
			continue;
		}
	}
}

int main()
{
	printf("--= Solid Mods Loader by oct0xor =--\n\n");
	printf("Version: 1.1\n");

	get_mods_folder();

	find_configs();

	if (config_names.size() == 0)
	{
		printf("Error! Cant find files in \"mods\" folder\n");
		exit(0);
	}

	printf("Launching the game...\n");

	start_process((char*)game_executable);

	printf("Loading mods...\n");

	load_mods(process_handle);

	WaitForSingleObject(process_handle, INFINITE);
	CloseHandle(process_handle);
	CloseHandle(thread_handle);

	for (unsigned int u = 0; u < config_names.size(); u++)
	{
		delete config_names[u];
	}

	config_names.clear();
}

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

typedef void(__cdecl* func1)(int arg0);
typedef void(__cdecl* func2)(void* arg0, int arg1);
typedef UINT64(__cdecl* func3)(UINT64 arg0);
typedef void(__cdecl* func4)(void* arg0);
typedef void(__cdecl* func5)(void* arg0, void* arg1, void* arg2, int arg3);
typedef void(__cdecl* func6)(void* arg0, void* arg1);
typedef void(__stdcall* func7)(void* arg0, void* arg1, void* arg2);
typedef void(__cdecl* func8)(DWORD arg0, DWORD arg1);
typedef void(__cdecl* func9)(void* arg0, void* arg1, void* arg2, void* arg3);
typedef int(__cdecl* func10)(int arg0, float *arg1, float *arg2, __int16 arg3, int arg4, int arg5);
typedef float*(__cdecl* func11)(float *arg0);
typedef void(__cdecl* func12)(float *arg0, float *arg1, int arg2, float arg3);
typedef void(__cdecl* func13)(WORD *arg0, WORD *arg1, int arg2);
typedef void(__cdecl* func14)(WORD *arg0, WORD *arg1, int arg2, int arg3);
typedef int(__cdecl* func15)(BYTE *arg0);
typedef void*(__cdecl* func16)(void* arg0, void* arg1);
typedef void(__cdecl* func17)(void* arg0, void* arg1, int arg2);
typedef void(__cdecl* func18)(void* arg0, void* arg1, void* arg2);
typedef void(__cdecl* func19)(void* arg0, void* arg1, void* arg2, float arg3, float arg4, float arg5);
typedef int(__cdecl* func20)(void* arg0, void* arg1, int arg2, int arg3);
typedef int(__cdecl* func21)(int arg0);
typedef int(__cdecl* func22)(int arg0, int arg1);
typedef void(__cdecl* func23)(int arg0, int arg1, int arg2, int arg3);
typedef void(__cdecl* func24)(int arg0, int arg1, int arg2, int arg3, int arg4);
typedef void(__cdecl* func25)(int arg0, void* arg1);
typedef int(__cdecl* func26)();
typedef int(__cdecl* func27)(int arg0, void** arg1);
typedef void(__cdecl* func28)(void *a1, int a2, int a3);
typedef void(__cdecl* func29)(void *a1, int a2, int a3, int a4);
typedef int(__cdecl* func30)(float *arg0, float *arg1);
typedef void(__cdecl* func31)(float *arg0, float *arg1, float arg2, int arg3);
typedef int(__cdecl* func32)(float *arg0, float *arg1, float *arg2, float *arg3, float *arg4);
typedef void*(__cdecl* func33)(int arg0, int arg1, int arg2, int arg3);
typedef int(__cdecl* func34)(void* arg0, void* arg1);

func2  set_next_player_camera_original = (func2)0x883FB0;
func5  convert_stick_to_button_original = (func5)0x8D00A0;
func9  calc_and_set_pos = (func9)0x88B4A0;
func9  calc_and_set_trg = (func9)0x88B450;
func9  calc_and_set_rot = (func9)0x88B330;
func10 check_collision = (func10)0x8DB100;
func11 get_collision_point = (func11)0x8DB190;
func15 sub_4CD370 = (func15)0x4CD370;
func6  sub_8A7F40 = (func6)0x8A7F40;
func17 sub_8A84F0 = (func17)0x8A84F0;
func18 set_vec_bounds = (func18)0x88B220;
func5  sub_8A9FA0 = (func5)0x8A9FA0;
func17 near_exp = (func17)0x8D1C30;
func1  sub_8CEAA0 = (func1)0x8CEAA0;
func19 sub_8D2580 = (func19)0x8D2580;
func20 sub_8D4A10 = (func20)0x8D4A10;
func4  sub_8D4A50 = (func4)0x8D4A50;
func21 paddemo_cmd = (func21)0x4C9770;
func15 check_if_snake_needs_to_jump_original = (func15)0x4BEE90;
func4  camera_transitions_handler_original = (func4)0x87DA20;
func22 gcl_get_option_value = (func22)0x8DF0B0;
func2  sub_4C9840 = (func2)0x4C9840;
func1  sub_8D04B0 = (func1)0x8D04B0;
func22 sub_878060 = (func22)0x878060;
func4  destroy_object = (func4)0x8CEA10;
func4  paddemo_exec = (func4)0x4C98B0;
func23 screen_text_locate = (func23)0x889440;
func24 screen_text_color = (func24)0x889390;
func25 screen_text_put = (func25)0x889780;
func26 chara_func_0xDFADB_original = (func26)0x49C180;
func29 play_animation = (func29)0x4F27D0;
func33 create_camera = (func33)0x8848B0;
func4  channel_del_camera = (func4)0x88A0D0;
func4  sub_884750 = (func4)0x884750;
func4  set_direction_for_PL_SubjectMove = (func4)0x4D0190;
func26 get_rand = (func26)0x924F98;
func26 check_if_special_blade_attack_original = (func26)0x4BAE30;
func34 raiden_event_msg_motion_original = (func34)0x4E8EA0;
func2  sub_4F3360 = (func2)0x4F3360;

BYTE*  Rightstick_X = (BYTE*)0xEDAC9C;
BYTE*  Rightstick_Y = (BYTE*)0xEDAC9D;
BYTE*  Leftstick_X = (BYTE*)0xEDAC9E;
BYTE*  Leftstick_Y = (BYTE*)0xEDAC9F;
DWORD* PL_SubjectMove = (DWORD*)0xA18B00;
BYTE*  PL_Object = (BYTE*)0xF60950;
BYTE*  GCL_Variables = (BYTE*)0xA01F34;
BYTE*  SAVED_GCL_Variables = (BYTE*)0xA01F38;
BYTE*  Cameras_Daemon = (BYTE*)0xA53D24;
DWORD* Cameras_Num = (DWORD*)0xA53D20;

#pragma pack (push, 1)

struct FVECTOR {
	float vec[4];
};

struct SVECTOR {
	WORD vec[4];
};

struct CAMERA_MGS2_PC {
	FVECTOR position;
	FVECTOR target;
	float angle;
	DWORD unk0;
	DWORD priority;
	DWORD enabled;
	DWORD next;
	void* interpolate_func_in;
	void* interpolate_func_out;
	WORD interpolate_time_in;
	WORD interpolate_time_out;
	FVECTOR bound1;
	FVECTOR bound2;
	FVECTOR limit1;
	FVECTOR limit2;
	SVECTOR rotate;
	DWORD track;
	DWORD camera_id;
	DWORD flag;
	DWORD channel_id;
	DWORD interpolate_id;
	BYTE unk6[52];
};

struct CAMERA_OBJECT {
	BYTE object_header[0x30];
	CAMERA_MGS2_PC camera;
};

struct CAMERA_CHANNEL_MGS2_PC {
	CAMERA_MGS2_PC cameras[9];
	CAMERA_MGS2_PC current;
	CAMERA_MGS2_PC master;
	CAMERA_MGS2_PC* next;
	void* interpolate_func;
	DWORD interpolate_time;
	DWORD flag;
	BYTE unk3[16];
};

struct DAEMON_OBJECT {
	BYTE object_header[0x30];
	CAMERA_CHANNEL_MGS2_PC channels[2];
};

struct NEW_TPS_CAMERA {
	DWORD flag1;
	float xyz_mul_preset;
	float angle_preset1;
	float z_limit1;
	float z_limit2;
	float vec_mul_preset;
	float trg_cor_preset;
	float pos_cor_preset1;
	float pos_cor_preset2;
	float angle_preset2;
	float rx;
	float ry;
	DWORD rflags1;
	DWORD rflags2;
	DWORD flag2;
	DWORD flags;
	float distance;
	WORD  direction;
	float direction_delta;
	float z_value;
	DWORD z_index;
	float unk_0x328;
	float unk_0x32C;
	float trg_mul_value1;
	float pos_mul_value1;
	float trg_mul_value2;
	float pos_mul_value2;

	FVECTOR vec_pos_new_temp;
	FVECTOR vec_trg_new_temp;

	FVECTOR vec_obj_pos;

	// Pos and Trg for next camera
	FVECTOR vec_pos_new;
	FVECTOR vec_trg_new;
};

#pragma pack (pop)

enum BUTTONS_MGS2_PC {
	RIGHT = 0x2000, // Also LR
	LEFT = 0x8000,  // Also LL
	UP   = 0x1000,  // Also LU
	DOWN = 0x4000,  // Also LD
	Y = 0x10,
	B = 0x20,
	A = 0x40,
	X = 0x80,
	L1 = 4, // Should be L2
	R1 = 8, // Should be R2
	L2 = 1, // Should be L1
	R2 = 2, // Should be R1
	L3 = 0x200,
	R3 = 0x400,
	START = 0x800,
	BACK = 0x100,
	RU = 0x100000,
	RD = 0x400000,
	RR = 0x200000,
	RL = 0x800000,
};

float fl_table[12] = {
	1000.0, -1400.0, 900.0,
	2000.0, -1000.0, 900.0,
	3700.0, 950.0, 500.0,
	2250.0, 5500.0, 0.0
};

float pos_corrections_table[4] = {
	0.0,
	1.0,
	0.0,
	0.0
};

enum MGS2_WEAPONS {
	WEAPON_M9 = 1,
	WEAPON_USP,
	WEAPON_SOCOM,
	WEAPON_PSG1,
	WEAPON_RGB6,
	WEAPON_NIKITA,
	WEAPON_STINGER,
	WEAPON_CLAYMORE,
	WEAPON_C4,
	WEAPON_CHAFF_G,
	WEAPON_STUN_G,
	WEAPON_D_MIC,
	WEAPON_HF_BLADE,
	WEAPON_COOLANT,
	WEAPON_AKS_74U,
	WEAPON_MAGAZINE,
	WEAPON_GRENADE,
	WEAPON_M4,
	WEAPON_PSG1_T,
	WEAPON_D_MIC_2,
	WEAPON_BOOK,
};

enum MGS2_ITEMS {
	ITEM_RATION = 1,
	ITEM_SCOPE,
	ITEM_MEDICINE,
	ITEM_BANDAGE,
	ITEM_PENTAZEMIN,
	ITEM_B_D_U,
	ITEM_B_ARMOR,
	ITEM_STEALTH,
	ITEM_MINE_D,
	ITEM_SENSOR_A,
	ITEM_SENSOR_B,
	ITEM_N_V_G,
	ITEM_THERM_G,
	ITEM_SCOPE_2,
	ITEM_DG_CAMERA,
	ITEM_BOX_1,
	ITEM_CIGS,
	ITEM_CARD,
	ITEM_SHAVER,
	ITEM_PHONE,
	ITEM_CAMERA,
	ITEM_BOX_2,
	ITEM_BOX_3,
	ITEM_WET_BOX,
	ITEM_AP_SENSR,
	ITEM_BOX_4,
	ITEM_BOX_5,
	ITEM_RAZOR,
	ITEM_SCM_SUPR,
	ITEM_AK_SUPR,
	ITEM_CAMERA_2,
	ITEM_BANDANA,
	ITEM_DOG_TAGS,
	ITEM_MO_DISC,
	ITEM_USP_SUPR,
	ITEM_SP_WIG,
	ITEM_WIG_A,
	ITEM_WIG_B,
	ITEM_WIG_C,
	ITEM_WIG_D,
};

#define TPS_CAMERA_ID 0x1337CA

bool IsEnabled = true;

DWORD PrevButtons = 0;

NEW_TPS_CAMERA NewTpsCamera;

bool IsInited = false;

char StageName1[0x10];
char StageName2[0x10];

bool IsPaddemo = false;

WORD DebugAnimationId = 0;

bool FromFpsMode = false;

bool PlayerModelIsHidden = false;

int CameraResetButtonCountdown = 0;

bool BladeAttack = false;
bool BladeSpecialAttack = false;
WORD BladeDirection = 0;

extern "C" __declspec(dllexport) float Sensitivity = (float)0.6; // 1.3333334
extern "C" __declspec(dllexport) BYTE Invert_X = FALSE;
extern "C" __declspec(dllexport) BYTE Invert_Y = FALSE;

void osd_message(const char* format, ...)
{
	va_list arglist;
	char buf[256];

	va_start(arglist, format);
	vsprintf(buf, format, arglist);
	va_end(arglist);

	screen_text_color(0, 180, 180, 180, 128);
	screen_text_locate(0, 10, 10, 0);
	screen_text_put(0, buf);
}

void get_player_pos(float* vec, bool flag)
{	
	memcpy(vec, (void*)(*(DWORD*)PL_Object + 0x13E0), 0x10);

	if (flag)
	{
		vec[1] -= 250.0;
	}

	// Makes camera less wobbly
	vec[0] = (float)(int)(vec[0] * 100 + 0.5) / 100;
	vec[1] = (float)(int)(vec[1] * 100 + 0.5) / 100;
	vec[2] = (float)(int)(vec[2] * 100 + 0.5) / 100;
	vec[3] = (float)(int)(vec[3] * 100 + 0.5) / 100;
}

void math_stuff_inner(float *output, float value)
{
	float a;
	float b;
	float c;

	if (value >= -1.5707963 /*-1.5708*/)
	{
		if (value > 1.5707963 /*1.5708*/)
		{
			a = 3.1415927 /*3.1416*/ - value;
			b = a * a;
			c = (float)-(float)((float)(a * a)
				* (float)((float)((float)(a * a)
					* (float)((float)((float)(a * a)
						* (float)((float)((float)(a * a) * 0.000024802) + -0.0013889))
						+ 0.0416667 /*0.041667*/)) + -0.5)) - 1.0;
		}
		else
		{
			b = value * value;
			a = value;
			c = (float)((float)(value * value)
				* (float)((float)((float)(value * value)
					* (float)((float)((float)(value * value)
						* (float)((float)((float)(value * value) * 0.000024802) + -0.0013889))
						+ 0.0416667 /*0.041667*/)) + -0.5)) + 1.0;
		}
	}
	else
	{
		a = -3.1415927 /*-3.1416*/ - value;
		b = a * a;
		c = (float)-(float)((float)(a * a)
			* (float)((float)((float)(a * a)
				* (float)((float)((float)(a * a)
					* (float)((float)((float)(a * a) * 0.000024802) + -0.0013889))
					+ 0.0416667 /*0.041667*/)) + -0.5)) - 1.0;
	}
	output[1] = c;
	*output = a
		* (float)((float)(b
			* (float)((float)(b
				* (float)((float)(b * (float)((float)(b * 0.0000027557) + -0.00019841))
					+ 0.0083333)) + -0.1666667 /*-0.16667*/)) + 1.0);
}

void math_stuff(float *output, float value)
{
	float a;
	bool b;
	float c;

	a = value + 3.1415927 /*3.1416*/;
	b = (float)((float)(value + 3.1415927 /*3.1416*/) * 0.1591549 /*0.15915*/) < 0.0;
	c = (float)(int)(float)((float)(value + 3.1415927 /*3.1416*/) * 0.1591549 /*0.15915*/);
	if (b)
		c = (float)((int)(float)(a * 0.1591549 /*0.15915*/) - 1);
	math_stuff_inner(output, (float)(a - (float)(c * 6.2831854 /*6.2832*/)) - 3.1415927 /*3.1416*/);
}

void rot_y_to_vec(FVECTOR *vec, short rot, float len)
{
	float temp[2];
	math_stuff(temp, ((float)rot * 3.1415927) * 0.000030517578);
	vec->vec[1] = 0.0;
	vec->vec[0] = len * temp[0];
	vec->vec[2] = len * temp[1];
}

void get_camera_new_pos_and_trg(NEW_TPS_CAMERA* ws)
{
	FVECTOR temp;
	memset(&temp, 0, sizeof(temp));

	int fl_index = ws->z_index;

	float vec_pos_new_1_copy = ws->vec_pos_new_temp.vec[1];
	float vec_trg_new_1_copy = ws->vec_trg_new_temp.vec[1];

	float value0;
	float value1;
	float value2;
	if (ws->flag1)
	{
		int fl_index_next = fl_index + 1;
		if (fl_index + 1 >= 3)
			fl_index_next = 3;

		float m = (float)(ws->z_value * 3.0) - (float)fl_index;

		value0 = fl_table[3 * fl_index + 0] + (float)((float)(fl_table[3 * fl_index_next + 0] - fl_table[3 * fl_index + 0]) * m);
		value1 = fl_table[3 * fl_index + 1] + (float)((float)(fl_table[3 * fl_index_next + 1] - fl_table[3 * fl_index + 1]) * m);
		value2 = fl_table[3 * fl_index + 2] + (float)((float)(fl_table[3 * fl_index_next + 2] - fl_table[3 * fl_index + 2]) * m);
	}
	else
	{
		value0 = fl_table[3 * fl_index + 0];
		value1 = fl_table[3 * fl_index + 1];
		value2 = fl_table[3 * fl_index + 2];
	}

	ws->unk_0x32C = 0.0;

	float x = 0.0;

	float trg_mul_value = (float)(value2 + ws->trg_cor_preset) + ws->unk_0x328 + x;

	float player_pos[4];
	get_player_pos(player_pos, true);

	ws->vec_trg_new_temp.vec[0] = player_pos[0] + (float)(pos_corrections_table[0] * trg_mul_value);
	ws->vec_trg_new_temp.vec[1] = player_pos[1] + (float)(pos_corrections_table[1] * trg_mul_value);
	ws->vec_trg_new_temp.vec[2] = player_pos[2] + (float)(pos_corrections_table[2] * trg_mul_value);
	ws->vec_trg_new_temp.vec[3] = player_pos[3] + (float)(pos_corrections_table[3] * trg_mul_value);

	rot_y_to_vec(&temp, ws->direction, -value0);

	temp.vec[1] = temp.vec[1] + value1 + ws->pos_cor_preset1;
	ws->vec_pos_new_temp.vec[0] = ws->vec_trg_new_temp.vec[0] + temp.vec[0];
	ws->vec_pos_new_temp.vec[1] = ws->vec_trg_new_temp.vec[1] + temp.vec[1];
	ws->vec_pos_new_temp.vec[2] = ws->vec_trg_new_temp.vec[2] + temp.vec[2];
	ws->vec_pos_new_temp.vec[3] = ws->vec_trg_new_temp.vec[3] + temp.vec[3];

	if (ws->pos_cor_preset2 != 0.0)
	{
		temp.vec[0] = ws->vec_pos_new_temp.vec[0] - ws->vec_trg_new_temp.vec[0];
		temp.vec[1] = ws->vec_pos_new_temp.vec[1] - ws->vec_trg_new_temp.vec[1];
		temp.vec[2] = ws->vec_pos_new_temp.vec[2] - ws->vec_trg_new_temp.vec[2];
		temp.vec[3] = ws->vec_pos_new_temp.vec[3] - ws->vec_trg_new_temp.vec[3];
	
		float pos_mul_value = (float)(ws->pos_cor_preset2
			/ sqrtf((float)((float)(temp.vec[1] * temp.vec[1]) + (float)(temp.vec[0] * temp.vec[0]))
				+ (float)(temp.vec[2] * temp.vec[2])
				)
			) + 1.0;
	
		ws->vec_pos_new_temp.vec[0] = ws->vec_trg_new_temp.vec[0] + (float)(temp.vec[0] * pos_mul_value);
		ws->vec_pos_new_temp.vec[1] = ws->vec_trg_new_temp.vec[1] + (float)(temp.vec[1] * pos_mul_value);
		ws->vec_pos_new_temp.vec[2] = ws->vec_trg_new_temp.vec[2] + (float)(temp.vec[2] * pos_mul_value);
		ws->vec_pos_new_temp.vec[3] = ws->vec_trg_new_temp.vec[3] + (float)(temp.vec[3] * pos_mul_value);
	}
	
	rot_y_to_vec(&temp, ws->direction - 0x4000, 1.0);
	
	ws->vec_trg_new_temp.vec[0] = ws->vec_trg_new_temp.vec[0] + (float)(temp.vec[0] * ws->trg_mul_value1);
	ws->vec_trg_new_temp.vec[1] = ws->vec_trg_new_temp.vec[1] + (float)(temp.vec[1] * ws->trg_mul_value1);
	ws->vec_trg_new_temp.vec[2] = ws->vec_trg_new_temp.vec[2] + (float)(temp.vec[2] * ws->trg_mul_value1);
	ws->vec_trg_new_temp.vec[3] = ws->vec_trg_new_temp.vec[3] + (float)(temp.vec[3] * ws->trg_mul_value1);
	
	ws->vec_pos_new_temp.vec[0] = ws->vec_pos_new_temp.vec[0] + (float)(temp.vec[0] * ws->pos_mul_value1);
	ws->vec_pos_new_temp.vec[1] = ws->vec_pos_new_temp.vec[1] + (float)(temp.vec[1] * ws->pos_mul_value1);
	ws->vec_pos_new_temp.vec[2] = ws->vec_pos_new_temp.vec[2] + (float)(temp.vec[2] * ws->pos_mul_value1);
	ws->vec_pos_new_temp.vec[3] = ws->vec_pos_new_temp.vec[3] + (float)(temp.vec[3] * ws->pos_mul_value1);
	
	ws->vec_trg_new_temp.vec[0] = ws->vec_trg_new_temp.vec[0] + (float)(pos_corrections_table[0] * (float)-ws->trg_mul_value2);
	ws->vec_trg_new_temp.vec[1] = ws->vec_trg_new_temp.vec[1] + (float)(pos_corrections_table[1] * (float)-ws->trg_mul_value2);
	ws->vec_trg_new_temp.vec[2] = ws->vec_trg_new_temp.vec[2] + (float)(pos_corrections_table[2] * (float)-ws->trg_mul_value2);
	ws->vec_trg_new_temp.vec[3] = ws->vec_trg_new_temp.vec[3] + (float)(pos_corrections_table[3] * (float)-ws->trg_mul_value2);
	
	ws->vec_pos_new_temp.vec[0] = ws->vec_pos_new_temp.vec[0] + (float)(pos_corrections_table[0] * (float)-ws->pos_mul_value2);
	ws->vec_pos_new_temp.vec[1] = ws->vec_pos_new_temp.vec[1] + (float)(pos_corrections_table[1] * (float)-ws->pos_mul_value2);
	ws->vec_pos_new_temp.vec[2] = ws->vec_pos_new_temp.vec[2] + (float)(pos_corrections_table[2] * (float)-ws->pos_mul_value2);
	ws->vec_pos_new_temp.vec[3] = ws->vec_pos_new_temp.vec[3] + (float)(pos_corrections_table[3] * (float)-ws->pos_mul_value2);
	
	if (!ws->flag1 && !ws->flag2)
	{
		ws->vec_pos_new_temp.vec[1] = vec_pos_new_1_copy + (float)((float)(ws->vec_pos_new_temp.vec[1] - vec_pos_new_1_copy) * 0.25);
		ws->vec_trg_new_temp.vec[1] = vec_trg_new_1_copy + (float)((float)(ws->vec_trg_new_temp.vec[1] - vec_trg_new_1_copy) * 0.25);
	}

	ws->vec_pos_new.vec[0] = ws->vec_pos_new_temp.vec[0];
	ws->vec_pos_new.vec[1] = ws->vec_pos_new_temp.vec[1];
	ws->vec_pos_new.vec[2] = ws->vec_pos_new_temp.vec[2];
	ws->vec_pos_new.vec[3] = ws->vec_pos_new_temp.vec[3];

	ws->vec_trg_new.vec[0] = ws->vec_trg_new_temp.vec[0];
	ws->vec_trg_new.vec[1] = ws->vec_trg_new_temp.vec[1];
	ws->vec_trg_new.vec[2] = ws->vec_trg_new_temp.vec[2];
	ws->vec_trg_new.vec[3] = ws->vec_trg_new_temp.vec[3];
}

void set_new_tps_camera_pos_and_trg(NEW_TPS_CAMERA* ws, CAMERA_MGS2_PC* camera_current, CAMERA_MGS2_PC* camera_next)
{
	get_camera_new_pos_and_trg(&NewTpsCamera);

	float vec_mul_value = ws->vec_mul_preset;
	float angle_mul_value = 0.1666667 /*0.16667*/;

	int flags = ws->flags;
	if ((flags & 1) != 0)
	{
		ws->flags = flags & 0xFFFFFFFE;
		ws->distance = 1.0;
		ws->unk_0x328 = ws->unk_0x32C;
		angle_mul_value = 1.0;
	}

	float player_pos[4];
	get_player_pos(player_pos, false);

	ws->vec_obj_pos.vec[0] = player_pos[0] + (float)(pos_corrections_table[0] * 500.0);
	ws->vec_obj_pos.vec[1] = player_pos[1] + (float)(pos_corrections_table[1] * 500.0);
	ws->vec_obj_pos.vec[2] = player_pos[2] + (float)(pos_corrections_table[2] * 500.0);
	ws->vec_obj_pos.vec[3] = player_pos[3] + (float)(pos_corrections_table[3] * 500.0);

	camera_next->position.vec[0] = camera_current->position.vec[0] + (float)(vec_mul_value * (float)(ws->vec_pos_new.vec[0] - camera_current->position.vec[0]));
	camera_next->position.vec[1] = camera_current->position.vec[1] + (float)(vec_mul_value * (float)(ws->vec_pos_new.vec[1] - camera_current->position.vec[1]));
	camera_next->position.vec[2] = camera_current->position.vec[2] + (float)(vec_mul_value * (float)(ws->vec_pos_new.vec[2] - camera_current->position.vec[2]));
	camera_next->position.vec[3] = camera_current->position.vec[3] + (float)(vec_mul_value * (float)(ws->vec_pos_new.vec[3] - camera_current->position.vec[3]));
	
	camera_next->target.vec[0] = camera_current->target.vec[0] + (float)(vec_mul_value * (float)(ws->vec_trg_new.vec[0] - camera_current->target.vec[0]));
	camera_next->target.vec[1] = camera_current->target.vec[1] + (float)(vec_mul_value * (float)(ws->vec_trg_new.vec[1] - camera_current->target.vec[1]));
	camera_next->target.vec[2] = camera_current->target.vec[2] + (float)(vec_mul_value * (float)(ws->vec_trg_new.vec[2] - camera_current->target.vec[2]));
	camera_next->target.vec[3] = camera_current->target.vec[3] + (float)(vec_mul_value * (float)(ws->vec_trg_new.vec[3] - camera_current->target.vec[3]));

	float mul_delta = 0.02; // 0.020833

	float new_distance = ws->distance;

	FVECTOR temp;
	memcpy(temp.vec, camera_next->position.vec, sizeof(FVECTOR));
	for (int i = 0; i < 4; i++)
	{
		int result = check_collision(0x40000000, temp.vec, ws->vec_obj_pos.vec, 15, 4, 4);

		if (result)
		{
			get_collision_point(temp.vec);
	
			float a = temp.vec[2] * temp.vec[2] + temp.vec[1] * temp.vec[1] + temp.vec[0] * temp.vec[0];
			float b;
			if (a == 0.0)
				b = 0.0;
			else
				b = sqrt(fabs(a));
	
			if (b == 0.0)
				break;
	
			float c1 = camera_next->position.vec[1] - ws->vec_obj_pos.vec[1];
			float c2 = camera_next->position.vec[0] - ws->vec_obj_pos.vec[0];
			float c3 = camera_next->position.vec[2] - ws->vec_obj_pos.vec[2];
			float d = sqrt(fabs(c1 * c1 + c2 * c2 + c3 * c3));

			float m = (1.0 / d) * (d - b);

			if (new_distance > m)
				new_distance = m;

			new_distance = (float)(int)(new_distance * 100 + 0.5) / 100; // Rounding Floating Point Number To two Decimal Places
	
			if (new_distance > mul_delta)
				new_distance -= mul_delta;

			temp.vec[0] = ws->vec_obj_pos.vec[0] + (float)(new_distance * (float)(camera_next->position.vec[0] - ws->vec_obj_pos.vec[0]));
			temp.vec[1] = ws->vec_obj_pos.vec[1] + (float)(new_distance * (float)(camera_next->position.vec[1] - ws->vec_obj_pos.vec[1]));
			temp.vec[2] = ws->vec_obj_pos.vec[2] + (float)(new_distance * (float)(camera_next->position.vec[2] - ws->vec_obj_pos.vec[2]));
			temp.vec[3] = ws->vec_obj_pos.vec[3] + (float)(new_distance * (float)(camera_next->position.vec[3] - ws->vec_obj_pos.vec[3]));
		}
		else 
		{
			break;
		}
	}

	// Collision enable/disable
	ws->distance = new_distance;

	float mul_min = 0.15;
	if (ws->distance < mul_min)
	{
		// Hack to prevent camera inside head
		ws->distance = mul_min;
	}

	camera_next->position.vec[0] = ws->vec_obj_pos.vec[0] + (float)(ws->distance * (float)(camera_next->position.vec[0] - ws->vec_obj_pos.vec[0]));
	camera_next->position.vec[1] = ws->vec_obj_pos.vec[1] + (float)(ws->distance * (float)(camera_next->position.vec[1] - ws->vec_obj_pos.vec[1]));
	camera_next->position.vec[2] = ws->vec_obj_pos.vec[2] + (float)(ws->distance * (float)(camera_next->position.vec[2] - ws->vec_obj_pos.vec[2]));
	camera_next->position.vec[3] = ws->vec_obj_pos.vec[3] + (float)(ws->distance * (float)(camera_next->position.vec[3] - ws->vec_obj_pos.vec[3]));
	
	camera_next->target.vec[0] = ws->vec_obj_pos.vec[0] + (float)(ws->distance * (float)(camera_next->target.vec[0] - ws->vec_obj_pos.vec[0]));
	camera_next->target.vec[1] = ws->vec_obj_pos.vec[1] + (float)(ws->distance * (float)(camera_next->target.vec[1] - ws->vec_obj_pos.vec[1]));
	camera_next->target.vec[2] = ws->vec_obj_pos.vec[2] + (float)(ws->distance * (float)(camera_next->target.vec[2] - ws->vec_obj_pos.vec[2]));
	camera_next->target.vec[3] = ws->vec_obj_pos.vec[3] + (float)(ws->distance * (float)(camera_next->target.vec[3] - ws->vec_obj_pos.vec[3]));
	
	if (ws->distance != 1.0)
	{
		ws->distance += mul_delta;

		if (ws->distance > 1.0) // Slowly increase after collision
			ws->distance = 1.0;
	}

	calc_and_set_rot(camera_next->position.vec, camera_next->target.vec, camera_next->rotate.vec, &camera_next->track);

	float z = (float)(ws->z_value - 0.6666667) / 0.3333333 /*0.33333*/;
	if (z < 0.0)
	{
		z = 0.0;
	}

	camera_next->angle = (float)((float)((float)(ws->angle_preset2 * (float)((float)((float)(ws->angle_preset1 - 1.0) * z) + 1.0)) - camera_next->angle) * angle_mul_value) + camera_next->angle;
}

void set_camera_xy(NEW_TPS_CAMERA* ws)
{
	float rx = ws->rx;

	WORD direction_prev = ws->direction;
	float direction_delta = (float)((float)((float)(rx * 0.0078125) * 341.33331 /*341.33*/) * ws->xyz_mul_preset)
		+ (float)(ws->direction_delta * 0.625);
	ws->direction_delta = direction_delta;
	ws->direction = direction_prev + (int)direction_delta;
}

void set_camera_z(NEW_TPS_CAMERA* ws)
{
	float limit1;
	float limit2;
	float value;
	int index1;
	int index2;

	limit1 = ws->z_limit1;
	limit2 = ws->z_limit2;

	if (ws->flag1)
	{
		value = ws->z_value + (float)((float)((float)(ws->ry * -0.0078125) * 0.0277778 /*0.027778*/) * ws->xyz_mul_preset);
		if (limit2 < value)
			value = ws->z_limit2;
		if (limit1 > value)
			value = ws->z_limit1;
	}
	else
	{
		index1 = ws->z_index;
		if ((ws->rflags1 & 1) != 0)
			++index1;
		index2 = index1;
		if ((ws->rflags1 & 2) != 0)
			index2 = index1 - 1;
		if (index2 > 3)
		{
			index2 = 3;
		}
		else if (index2 < 0)
		{
			index2 = 0;
		}
		value = (float)index2 * 0.3333333 /*0.33333*/;
		if (limit2 < value)
			value = ws->z_limit2;
		if (limit1 > value)
			value = ws->z_limit1;
	}

	ws->z_value = value;
	ws->z_index = (int)(float)(value * 3.0);
}

void set_camera_mul_values(NEW_TPS_CAMERA* ws)
{
	ws->trg_mul_value1 = ws->trg_mul_value1 + (float)((float)(0.0 - ws->trg_mul_value1) * 0.33333);
	ws->pos_mul_value1 = ws->pos_mul_value1 + (float)((float)(0.0 - ws->pos_mul_value1) * 0.33333);
	ws->trg_mul_value2 = ws->trg_mul_value2 + (float)((float)(0.0 - ws->trg_mul_value2) * 0.33333);
	ws->pos_mul_value2 = ws->pos_mul_value2 + (float)((float)(1.0 - ws->pos_mul_value2) * 0.33333);
}

void convert_rightstick_data(NEW_TPS_CAMERA* ws)
{
	BYTE rx = *Rightstick_X;
	BYTE ry = *Rightstick_Y;

	rx = ~rx;
	ry = ~ry;

	if (Invert_X)
	{
		rx = ~rx;
	}

	if (Invert_Y)
	{
		ry = ~ry;
	}

	int rx_ = rx - 0x80;
	int ry_ = ry - 0x80;

	int flags = 0;
	if (rx_ >= 0x60)
		flags = 4;
	if (rx_ <= -0x60)
		flags |= 8;
	if (ry_ <= -0x60)
		flags |= 1;
	if (ry_ >= 0x60)
		flags |= 2;

	ws->rflags2 = flags;
	ws->rflags1 = flags & (flags ^ ws->rflags2);

	float rx_fixed;
	if (rx_ >= 0)
	{
		rx_fixed = (float)(rx_ - 0x20);
		if (rx_fixed < 0.0)
			rx_fixed = 0.0;
	}
	else
	{
		rx_fixed = (float)(rx_ + 0x20);
		if (rx_fixed > 0.0)
			rx_fixed = 0.0;
	}

	ws->rx = rx_fixed * Sensitivity;

	float ry_fixed;
	if (ry_ < 0)
	{
		ry_fixed = (float)(ry_ + 0x20);
		if (ry_fixed > 0.0)
			ry_fixed = 0.0;
	}
	else
	{
		ry_fixed = (float)(ry_ - 0x20);
		if (ry_fixed < 0.0)
			ry_fixed = 0.0;
	}

	ws->ry = ry_fixed * Sensitivity;
}

void init_new_tps_camera(CAMERA_MGS2_PC* camera)
{
	memset(&NewTpsCamera, 0, sizeof(NewTpsCamera));

	NewTpsCamera.flag1 = 1;
	NewTpsCamera.xyz_mul_preset = 1.0;
	NewTpsCamera.angle_preset1 = 0.85;
	NewTpsCamera.z_limit2 = 1.0;
	NewTpsCamera.vec_mul_preset = 0.3333333;
	NewTpsCamera.pos_cor_preset2 = 179.986816;
	NewTpsCamera.angle_preset2 = 1.8999999 /*1.9*/;
	NewTpsCamera.flags = 3;

	WORD direction = *(WORD*)(*(DWORD*)PL_Object + 0x6A) << 4;

	NewTpsCamera.direction = direction;
	NewTpsCamera.z_value = 0.6666667;
	NewTpsCamera.z_index = 2;

	set_new_tps_camera_pos_and_trg(&NewTpsCamera, camera, camera);
}

CAMERA_MGS2_PC* find_next_camera_inner(CAMERA_CHANNEL_MGS2_PC *channel)
{
	CAMERA_MGS2_PC* camera;
	for (int i = 0; i < 9; ++i)
	{
		camera = &channel->cameras[i];

		while (1)
		{
			camera = (CAMERA_MGS2_PC*)camera->next;

			if (!camera)
				break;

			if (camera->enabled)
				return camera;
		}
	}

	return NULL;
}

bool is_patchable_camera(CAMERA_MGS2_PC* camera)
{
	if (camera->interpolate_id == 6 || camera->interpolate_id == 8 /* CAM ID: 0x3D568C */)
		return true;

	if (camera->camera_id == 0x2FC5CD) /* Fight with Ray's (w46a) - Cam ID 0x002FC5CD - Flag: 0x231, Unk0: 0x2, Priority: 0x80, Enabled: 0x1, Next: 0x0, Ifi: 0x88A1B0, Ifo: 0x88A1B0, Iti: 0x20, Ito: 0x20, Channel ID: 0x0, Interp ID: 0x7 */
		return true;

	if (camera->camera_id == 0x65ACA3) /* Fight with Solidus (w61a) - Cam ID 0x0065ACA3 - Flag: 0x1000230, Unk0: 0x2, Priority: 0xA0, Enabled: 0x1, Next: 0x0, Ifi: 0x88A1B0, Ifo: 0x0, Iti: 0x20, Ito: 0x0, Channel ID: 0x0, Interp ID: 0x5 */
		return true;

	return false;
}

void set_next_player_camera_special(CAMERA_OBJECT *cw, int flag)
{
	switch (cw->camera.unk0)
	{
	case 4:
		if ((flag & 0x100) != 0)
		{
			memcpy(cw->camera.rotate.vec, (void*)(0xF6DE70 + cw->camera.channel_id * 8), 8);
		}
		calc_and_set_trg(
			cw->camera.position.vec,
			cw->camera.target.vec,
			cw->camera.rotate.vec,
			&cw->camera.track);
		break;
	case 1:
		calc_and_set_rot(
			cw->camera.position.vec,
			cw->camera.target.vec,
			cw->camera.rotate.vec,
			&cw->camera.track);
		break;
	case 2:
		calc_and_set_pos(
			cw->camera.position.vec,
			cw->camera.target.vec,
			cw->camera.rotate.vec,
			&cw->camera.track);
		break;
	}
}

void get_stage_name()
{
	const char* name1 = (const char*)(*(DWORD*)GCL_Variables + 0x1C); // resident (stage)
	const char* name2 = (const char*)(*(DWORD*)GCL_Variables + 0x2C); // stage

	//osd_message("%s - %s", name1, name2);

	if (strcmp(StageName1, name1) != 0 || strcmp(StageName2, name2) != 0)
	{
		strcpy(StageName1, name1);
		strcpy(StageName2, name2);

		char buf[0x100];
		sprintf_s(buf, "Level: %s - %s\n", name1, name2);
		OutputDebugStringA(buf);
	}
}

CAMERA_MGS2_PC* find_camera_by_id(int camera_id, int channel_id)
{
	int count = *Cameras_Num;
	for (int i = 0; i < count; i++)
	{
		CAMERA_MGS2_PC* camera = (CAMERA_MGS2_PC*)*(DWORD*)(0xA53C60 + i * 4);

		if (camera->camera_id == camera_id && camera->channel_id == channel_id)
			return camera;
	}

	return NULL;
}

void dump_camera_data(CAMERA_MGS2_PC *camera)
{
	char buf[0x200];
	sprintf_s(buf, "Cam ID 0x%08X - Flag: 0x%X, Unk0: 0x%X, Priority: 0x%X, Enabled: 0x%X, Next: 0x%X, Ifi: 0x%X, Ifo: 0x%X, Iti: 0x%X, Ito: 0x%X, Channel ID: 0x%X, Interp ID: 0x%X\n",
		camera->camera_id, camera->flag, camera->unk0, camera->priority, camera->enabled, camera->next, (DWORD)camera->interpolate_func_in, (DWORD)camera->interpolate_func_out, camera->interpolate_time_in, camera->interpolate_time_out, camera->channel_id, camera->interpolate_id);
	OutputDebugStringA(buf);
	
	for (int i = 0; i < sizeof(camera->unk6); i++)
	{
		sprintf(buf + i * 5, "0x%02X ", camera->unk6[i]);
	}
	
	int size = strlen(buf);
	
	buf[size - 1] = '\n';
	buf[size] = 0;
	
	OutputDebugStringA(buf);
}

void create_tps_camera()
{
	CAMERA_MGS2_PC* camera = (CAMERA_MGS2_PC*)create_camera(TPS_CAMERA_ID, 0, 0x6, 0); // int camera_id, int channel_id, int interpolate_id, int priority

	if (camera)
	{
		camera->flag = 1;
		camera->unk0 = 2;
		camera->priority = 0;
		camera->interpolate_func_in = (void*)0x88A2F0;
		camera->interpolate_func_out = (void*)0x88A2F0;
		camera->interpolate_time_in = 0x30;
		camera->interpolate_time_out = 0x30;
	
		IsInited = false;
	}
}

void request_camera_switch()
{
	DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
	if (dw)
	{
		dw->channels[0].flag |= 1;
	}
}

void set_next_player_camera(CAMERA_OBJECT *cw, int flag)
{
	//get_stage_name();

	create_tps_camera();

	if (IsEnabled)
	{
		//char buf[0x100];
		//sprintf_s(buf, "Bits: 0x%llX\n", *(UINT64*)0xF60958);
		//OutputDebugStringA(buf);

		//char buf[0x100];
		//sprintf_s(buf, "Bits2: 0x%llX\n", *(UINT64*)0xF609C0);
		//OutputDebugStringA(buf);

		//dump_camera_data(&cw->camera);

		if (cw->camera.camera_id == TPS_CAMERA_ID)
		{
			if (IsPaddemo && (*(UINT64*)0xF60958 & 0x1000000000000 /* Cutscene bit */) == 0)
			{
				//OutputDebugStringA("Force paddemo end!\n");
				IsPaddemo = false;
			}

			if (IsPaddemo)
			{
				return;
			}

			if (!IsInited && *(DWORD*)PL_Object != NULL)
			{
				// Special case for when we use button combo to toggle IsEnabled flag
				init_new_tps_camera(&cw->camera);
				IsInited = true;
			}

			cw->camera.flag &= 1; // Patchable camera should not have this flag set to prevent problems during interp 4 -> 6 (could be observed after Olga battle in r_tnk0 - w00c)

			DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;

			bool skip = false;
			bool fps_mode = false;
			for (int chan_id = 0; chan_id < 2; chan_id++)
			{
				CAMERA_CHANNEL_MGS2_PC* camera_channel = &dw->channels[chan_id];

				if ((camera_channel->flag & 0x10) == 0)
				{
					if (*(DWORD*)(0xDB7044 + chan_id * 0x4A0))
					{
						CAMERA_MGS2_PC* camera;
						for (int i = 0; i < 9; ++i)
						{
							camera = &camera_channel->cameras[i];

							while (1)
							{
								camera = (CAMERA_MGS2_PC*)camera->next;

								if (!camera)
									break;

								if (camera->enabled && camera != &cw->camera && !is_patchable_camera(camera))
								{
									if (camera->camera_id == 0x0072EF36 /* FPS mode */ ||
										camera->camera_id == 0x001BF6B8 /* FPS mode with weapon */ ||
										camera->camera_id == 0x0051BBC9 /* ITEM_SCOPE_2 */
										)
									{
										fps_mode = true;
									}

									skip = true;
									break;
								}
							}
						}
					}
				}
			}

			if (skip)
			{
				FromFpsMode = fps_mode;
				return;
			}

			if (FromFpsMode && *(DWORD*)PL_Object != NULL)
			{
				// Reset direction if we switch from FPS camera

				WORD direction = *(WORD*)(*(DWORD*)PL_Object + 0x6A) << 4;
				NewTpsCamera.direction = direction;

				FromFpsMode = false;
			}

			if (*(DWORD*)PL_Object != NULL)
			{
				convert_rightstick_data(&NewTpsCamera);

				set_camera_xy(&NewTpsCamera);

				set_camera_z(&NewTpsCamera);

				set_camera_mul_values(&NewTpsCamera);

				set_new_tps_camera_pos_and_trg(&NewTpsCamera, &cw->camera, &cw->camera);
			}
		}
		else
		{
			if ((flag & 1) == 0)
			{
				set_next_player_camera_special(cw, flag);
			}
			else
			{
				set_next_player_camera_original(cw, flag);
			}
		}
	}
	else
	{
		if ((flag & 1) == 0)
		{
			set_next_player_camera_special(cw, flag);
		}
		else
		{
			set_next_player_camera_original(cw, flag);
		}
	}
}

extern "C" __declspec(dllexport) void __cdecl camera_handler(CAMERA_OBJECT *cw)
{
	if (*(DWORD*)Cameras_Daemon)
	{
		int flag = cw->camera.flag;
		if ((flag & 0x1000) != 0)
		{
			channel_del_camera(cw->camera.position.vec);
			destroy_object(cw);
		}
		else if ((flag & 0x40000000) != 0)
		{
			destroy_object(cw);
		}
		else
		{
			if ((flag & 0x4000) != 0)
				cw->camera.flag = flag & 0xFFFFBFFF;

			if (cw->camera.enabled || cw->camera.camera_id == TPS_CAMERA_ID)
			{
				int channel_id = cw->camera.channel_id;
				float* pos_in = (float*)*(DWORD*)(0xA54570 + channel_id * 4);

				if (pos_in)
				{
					float* pos_out = (float*)(0xA54550 + channel_id * 0x10);

					pos_out[0] = pos_in[0];
					pos_out[1] = pos_in[1];
					pos_out[2] = pos_in[2];
					pos_out[3] = pos_in[3];
				}

				if ((flag & 0x2000000) != 0)
				{
					sub_884750(&cw->camera);
				}
				else
				{
					set_next_player_camera(cw, flag);
				}
			}
		}
	}
}

DWORD convert_buttons(DWORD buttons)
{
	int id = *(DWORD*)0xEDACD0 * 10;

	if ((*(DWORD*)(0xEDAD5C + id * 4) & 0x1000) != 0)
	{
		// Dont need to convert...
	}
	else
	{
		if ((*(DWORD*)0xEDAD28 & buttons) != 0)
		{
			DWORD buttons_new = buttons & 0xF00;

			int index = 0;
			do
			{
				if ((buttons & *(DWORD*)(0xA00B70 + index * 4)) != 0)
				{
					int mapped = *(BYTE*)(0xEDAD18 + index);
					buttons_new = *(DWORD*)(0xA00B70 + mapped * 4) | buttons_new;
				}
				++index;
			} while (index < 12);

			buttons = buttons_new;
		}
	}

	return buttons;
}

DWORD convert_buttons_back(DWORD buttons)
{
	int id = *(DWORD*)0xEDACD0 * 10;

	if ((*(DWORD*)(0xEDAD5C + id * 4) & 0x1000) != 0)
	{
		// Dont need to convert...
	}
	else
	{
		if ((*(DWORD*)0xEDAD28 & buttons) != 0)
		{
			DWORD buttons_new = buttons & 0xF00;

			int index = 0;
			do
			{
				int mapped = *(BYTE*)(0xEDAD18 + index);

				if ((buttons & *(DWORD*)(0xA00B70 + mapped * 4)) != 0)
				{
					buttons_new = *(DWORD*)(0xA00B70 + index * 4) | buttons_new;
				}
				++index;
			} while (index < 12);

			buttons = buttons_new;
		}
	}

	return buttons;
}

extern "C" __declspec(dllexport) void __cdecl convert_stick_to_button(void* arg0, void* arg1, void* arg2, int arg3)
{
	DWORD buttons = ~*(DWORD*)((BYTE*)arg2 + 4);

	buttons = convert_buttons(buttons);

	//char buf[0x100];
	//sprintf_s(buf, "Buttons: 0x%X\n", buttons);
	//OutputDebugStringA(buf);

	BYTE active_weapon_id = 0;
	BYTE active_item_id = 0;
	if (*(DWORD*)PL_Object != 0)
	{
		active_weapon_id = (BYTE)*(DWORD*)(*(DWORD*)PL_Object + 0x9A0);
		active_item_id = (BYTE)*(DWORD*)(*(DWORD*)PL_Object + 0x9B8);
	}

	bool is_fps_mode = (*(DWORD*)0x9A86A4 & R1) && (buttons & R1);
	//bool is_fps_mode = (*(UINT64*)0xF60958 & 0x6000000) == 0x6000000; // TODO: Fix me

	if (is_fps_mode
		|| (active_weapon_id == WEAPON_COOLANT)
		|| (active_weapon_id == WEAPON_D_MIC)
		|| (active_weapon_id == WEAPON_D_MIC_2)
		|| (active_weapon_id == WEAPON_PSG1)
		|| (active_weapon_id == WEAPON_PSG1_T)
		|| (active_weapon_id == WEAPON_STINGER)
		|| (active_item_id == ITEM_SCOPE_2)
		|| (*(UINT64*)0xF609C0 & 0x200) // pl_subject_demo
		)
	{
		// In FPS mode it should be possible to use both sticks
		// It should also work with weapons/items that force FPS mode without pressing R1 e.g. COOLANT
		// It should also work during pl_subject_demo (demo with possibility to control players camera)

		BYTE rx = *Rightstick_X;
		BYTE ry = *Rightstick_Y;

		if (rx < 0x50u || rx > 0xB0u || ry < 0x50u || ry > 0xB0u)
		{
			*Leftstick_X = *Rightstick_X;
			*Leftstick_Y = *Rightstick_Y;
		}
	}

	if (PrevButtons != buttons && (buttons & L1) && (buttons & Y))
	{
		if (IsEnabled)
		{
			IsEnabled = false;
			IsInited = false;
			request_camera_switch();
		}
		else
		{
			IsEnabled = true;
			IsInited = false;
		}
	}

	//if (PrevButtons != buttons && (buttons & L1) && (buttons & Y))
	//{
	//	//DebugAnimationId++;
	//	//
	//	//char buf[0x100];
	//	//sprintf_s(buf, "DebugAnimationId: %d\n", DebugAnimationId);
	//	//OutputDebugStringA(buf);
	//
	//	if (DebugAnimationId != 79)
	//	{
	//		DebugAnimationId = 79;
	//	}
	//	else
	//	{
	//		DebugAnimationId = 1;
	//	}
	//
	//}

	// In MGS3 L1 - resets camera, R1 - is FPS view, L2 - items, R2 - weapons
		// In MGS2 all the same but L1 is unused - we need to use it
		// L1 and double tap L1 have different effects, double tap also resets Z
		// But there is a catch: it interferences with blade protection stance
	if (PrevButtons != buttons && buttons == L1) 
	{
		if (IsEnabled && !IsPaddemo && *(DWORD*)PL_Object != NULL && active_weapon_id != WEAPON_HF_BLADE)
		{
			WORD direction = *(WORD*)(*(DWORD*)PL_Object + 0x6A) << 4;
			NewTpsCamera.direction = direction;

			if (CameraResetButtonCountdown > 0)
			{
				NewTpsCamera.z_value = 0.6666667;
				CameraResetButtonCountdown = 0;
			}
			else 
			{
				CameraResetButtonCountdown = 60;
			}
		}
	}

	if (CameraResetButtonCountdown > 0)
	{
		CameraResetButtonCountdown--;
	}

	BladeAttack = false;
	BladeSpecialAttack = false;
	BladeDirection = 0;
	if (IsEnabled && active_weapon_id == WEAPON_HF_BLADE)
	{
		bool flag = false;
		if (buttons & B)
		{
			buttons &= ~B;
			BladeAttack = true;
			flag = true;
		}

		if (buttons & L3)
		{
			buttons &= ~L3;
			BladeAttack = true;
			BladeSpecialAttack = true;
			flag = true;
		}

		if (flag)
		{
			*(DWORD*)((BYTE*)arg2 + 4) = ~convert_buttons_back(buttons);
		}
	}

	PrevButtons = buttons;

	if (IsEnabled)
	{
		*(DWORD*)0xEDAE78 = 0; // camera_direction_fix
	}

	convert_stick_to_button_original(arg0, arg1, arg2, arg3);
}

WORD get_camera_direction(DAEMON_OBJECT* dw)
{
	return dw->channels[0].next->rotate.vec[1] - 0x800;
}

extern "C" __declspec(dllexport) int __cdecl check_if_snake_is_next_to_wall_controls(BYTE *buttons)
{
	if (IsEnabled && !IsPaddemo)
	{
		DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
		if (dw)
		{
			if ((*(DWORD*)(buttons + 4) & 0xF000) != 0)
			{
				WORD cam_direction = get_camera_direction(dw);
				*(DWORD*)(*(DWORD*)PL_Object + 0x400) += cam_direction;
			}
		}
	}

	return sub_4CD370(buttons);
}

CAMERA_MGS2_PC* find_next_camera(CAMERA_CHANNEL_MGS2_PC *channel, int *some_counter)
{
	CAMERA_MGS2_PC *next_camera;

	if (*some_counter > 0)
		--*some_counter;

	if (*(DWORD*)0xF6DE60 && !*some_counter)
	{
		sub_8CEAA0(*(DWORD*)0xF6DE60);
		*(DWORD*)0xF6DE60 = 0;
		channel->flag |= 1;
	}

	if ((channel->flag & 1) != 0)
	{
		next_camera = find_next_camera_inner(channel);
		if (!next_camera)
		{
			return NULL;
		}

		channel->flag &= 0xFFFFFFFE;

		if (next_camera == channel->next && next_camera->interpolate_id == 2)
			return next_camera;

		if (is_patchable_camera(next_camera))
		{
			CAMERA_MGS2_PC* tps_camera = find_camera_by_id(TPS_CAMERA_ID, 0);

			if (tps_camera)
			{
				next_camera = tps_camera;
			}
		}

		channel->flag |= 0x100;

		if ((channel->flag & 0x1000) != 0)
		{
			memcpy(&channel->current, next_camera, sizeof(channel->current));
			channel->flag = channel->flag & 0xFFFFEFFF;
			channel->interpolate_func = (void*)0x88A180;
			return next_camera;
		}

		if (next_camera->interpolate_id == 2)
		{
			if ((channel->next->flag & 0x10) != 0)
			{
				channel->current.bound1 = channel->next->bound1;
				channel->current.bound2 = channel->next->bound2;
				channel->current.flag |= 0x10;
			}
			else
			{
				channel->current.flag &= 0xFFFFFFEF;
			}

			if ((channel->next->flag & 0x20) != 0)
			{
				channel->current.limit1 = channel->next->limit1;
				channel->current.limit2 = channel->next->limit2;
				channel->current.flag |= 0x20;
			}
			else
			{
				channel->current.flag &= 0xFFFFFFDF;
			}
		}

		if (channel->current.interpolate_id == next_camera->interpolate_id)
		{
			if (channel->current.priority <= next_camera->priority && channel->current.interpolate_func_out != 0)
			{
				channel->interpolate_func = channel->current.interpolate_func_out;
				channel->interpolate_time = channel->current.interpolate_time_out;
			}
			else
			{
				channel->interpolate_func = next_camera->interpolate_func_in;
				channel->interpolate_time = next_camera->interpolate_time_in;
			}
		}
		else if (channel->current.interpolate_id <= next_camera->interpolate_id && channel->current.interpolate_func_out != 0)
		{
			channel->interpolate_func = channel->current.interpolate_func_out;
			channel->interpolate_time = channel->current.interpolate_time_out;
		}
		else
		{
			channel->interpolate_func = next_camera->interpolate_func_in;
			channel->interpolate_time = next_camera->interpolate_time_in;
		}

		channel->current.interpolate_id = next_camera->interpolate_id;
		channel->current.priority = next_camera->priority;
		channel->current.interpolate_func_in = next_camera->interpolate_func_in;
		channel->current.interpolate_time_in = next_camera->interpolate_time_in;
		channel->current.interpolate_func_out = next_camera->interpolate_func_out;
		channel->current.interpolate_time_out = next_camera->interpolate_time_out;
	}
	else
	{
		next_camera = channel->next;

		if (is_patchable_camera(next_camera))
		{
			CAMERA_MGS2_PC* tps_camera = find_camera_by_id(TPS_CAMERA_ID, 0);

			if (tps_camera)
			{
				next_camera = tps_camera;
			}
		}
	}

	if (!next_camera)
		return NULL;

	return next_camera;
}

bool interpolate_and_rotate_stuff(CAMERA_CHANNEL_MGS2_PC *camera_channel)
{
	CAMERA_MGS2_PC *cam1 = &camera_channel->current;
	CAMERA_MGS2_PC *cam2 = camera_channel->next;

	if ((camera_channel->flag & 0x100) != 0)
	{

		if ((DWORD)camera_channel->interpolate_func == 0x0088AA90)
		{
			// Function 0x0088AA90 may fail if FPS camera is looking up or down
			// Because of this, function 0x0088AA90 will be called again and again and it will glitch camera
			// This hack fixes this bug
			
			memcpy(cam1, cam2, sizeof(CAMERA_MGS2_PC));
			cam1->flag &= 0xFFFFFEFF;
			cam1->flag &= 0xDFFFFFFF;
		}
		else
		{
			((void(__cdecl *)(CAMERA_CHANNEL_MGS2_PC *, CAMERA_MGS2_PC *, CAMERA_MGS2_PC *))camera_channel->interpolate_func)(
				camera_channel,
				cam1,
				cam2);
		}
	}
	else if (cam2)
	{
		if ((camera_channel->flag & 0x2000) != 0)
		{
			cam1->position.vec[0] = cam2->position.vec[0];
			cam1->position.vec[1] = cam2->position.vec[1];
			cam1->position.vec[2] = cam2->position.vec[2];
			cam1->position.vec[3] = cam2->position.vec[3];
			cam1->target = cam2->target;
			cam1->angle = cam2->angle;
			camera_channel->flag &= 0xFFFFDFFF;
		}
		else
		{
			near_exp(&cam1->position, &cam2->position, 3);
			near_exp(&cam1->target, &cam2->target, 3);

			// In MGS3 there is also a call to calc_and_set_rot(channel->current.position.vec, channel->current.target.vec, (int)channel->current.rotate.vec, &channel->current.track);

			cam1->angle = (cam2->angle - cam1->angle) * 0.25 + cam1->angle;
		}

		cam1->rotate = cam2->rotate;
		cam1->track = cam2->track;
		cam1->interpolate_id = cam2->interpolate_id;
	}

	if ((cam2->flag & 0x1000000) != 0)
	{
		if ((cam2->flag & 0x10) != 0)
			set_vec_bounds(cam1->position.vec, cam2->bound1.vec, cam2->bound2.vec);
		if ((cam2->flag & 0x20) != 0)
			set_vec_bounds(cam1->target.vec, cam2->limit1.vec, cam2->limit2.vec);
	}

	int vec2 = cam1->rotate.vec[2] & 0xFFF;
	if ((cam1->rotate.vec[2] & 0xFFF) > 0x800)
		vec2 = (cam1->rotate.vec[2] & 0xFFF) - 0x1000;
	cam1->position.vec[3] = (double)vec2 * 0.0015339813;

	if ((cam1->flag & 0x20000000) == 0)
		calc_and_set_rot(cam1->position.vec, cam1->target.vec, cam1->rotate.vec, &cam1->track);

	cam1->flag = cam1->flag & 0xDFFFFFFF;

	// Added this to ease debugging
	cam1->camera_id = cam2->camera_id;

	return false;
}

extern "C" __declspec(dllexport) void __cdecl camera_transitions_handler(DAEMON_OBJECT *dw)
{
	if (IsEnabled && !IsPaddemo)
	{
		for (int chan_id = 0; chan_id < 2; chan_id++)
		{
			CAMERA_CHANNEL_MGS2_PC* camera_channel = &dw->channels[chan_id];

			if ((camera_channel->flag & 0x10) == 0)
			{
				// Current camera is set by memcpy from interpolate func's

				if (*(DWORD*)(0xDB7044 + chan_id * 0x4A0))
				{
					CAMERA_MGS2_PC* cam_next = find_next_camera(camera_channel, (int*)(0xF6DE58 + chan_id * 4));
					if (cam_next)
					{
						if (!chan_id)
						{
							if (cam_next->interpolate_id)
								*(DWORD*)0xA5397C = *(DWORD*)0xA5397C & 0xFFFFFFBF;
							else
								*(DWORD*)0xA5397C = *(DWORD*)0xA5397C | 0x40;
						}

						camera_channel->next = cam_next;

						if (!*(DWORD*)0x118ADB0)
						{
							void(__cdecl *func)(void *, void *, void *, float);
							func = *(void(__cdecl **)(void *, void *, void *, float))camera_channel->unk3;

							// Sets camera_channel->current
							bool result = interpolate_and_rotate_stuff(camera_channel);

							FVECTOR position;
							position.vec[0] = camera_channel->current.position.vec[0];
							position.vec[1] = camera_channel->current.position.vec[1];
							position.vec[2] = camera_channel->current.position.vec[2];
							position.vec[3] = camera_channel->current.position.vec[3];

							FVECTOR target;
							target.vec[0] = camera_channel->current.target.vec[0];
							target.vec[1] = camera_channel->current.target.vec[1];
							target.vec[2] = camera_channel->current.target.vec[2];
							target.vec[3] = camera_channel->current.target.vec[3];

							int cur_channel_id = camera_channel->current.channel_id;

							DWORD x = *(DWORD*)(0xA53D28 + cur_channel_id * 4) & 0x7FFFFFFF;
							float f = *(float*)&x;

							if (!(camera_channel->current.interpolate_id <= 2)
								&& f > 0.1
								&& (*(DWORD *)(Cameras_Daemon + 0x92C + 0x910 * cur_channel_id) & 0x4000) == 0)
							{
								DWORD x = *(DWORD*)(0xA53D38 + cur_channel_id * 4) & 0x7FFFFFFF;
								float value0 = *(float*)&x;

								float z;
								if (value0 <= 0.001)
								{
									z = *(float *)(0xA53D28 + cur_channel_id * 4);
								}
								else
								{
									if ((*(DWORD*)0x118ADB0 & 6) == 0)
									{
										*(float*)(0xA53D78 + cur_channel_id * 4) = *(float*)(0xA53D78 + cur_channel_id * 4) + *(float *)(0xA53D38 + cur_channel_id * 4);
										*(float*)(0xA53D80 + cur_channel_id * 4) = 0.035101604 + *(float*)(0xA53D80 + cur_channel_id * 4);
									}

									float f = *(float *)(0xA53D28 + cur_channel_id * 4);

									float m;
									if (f <= 64.0)
										m = f;
									else
										m = 64.0;

									z = sin(*(float *)(0xA53D78 + cur_channel_id * 4)) * f + sin(*(float *)(0xA53D80 + cur_channel_id * 4)) * m;
								}

								position.vec[1] += z;
								target.vec[1] += z;

								if (*(float*)(0xA53D78 + cur_channel_id * 4) > 3141593.8)
									*(float*)(0xA53D78 + cur_channel_id * 4) = 0.0;

								if (*(float*)(0xA53D80 + cur_channel_id * 4) > 3141593.8)
									*(float*)(0xA53D80 + cur_channel_id * 4) = 0.0;
							}

							if (*(DWORD*)(0xF6E4D0 + chan_id * 4) && (camera_channel->current.flag & 0x4000000) == 0)
							{
								*(DWORD*)(0xF6E4D0 + chan_id * 4) = 0;

								sub_8A7F40((FVECTOR*)0x9FE190, (SVECTOR*)&camera_channel->current.rotate);

								FVECTOR temp;
								sub_8A84F0((FVECTOR*)(0xA53CE0 + chan_id * 4), &temp, 1);

								position.vec[0] += temp.vec[0];
								position.vec[1] += temp.vec[1];
								position.vec[2] += temp.vec[2];
								position.vec[3] += temp.vec[3];

								target.vec[0] += temp.vec[0];
								target.vec[1] += temp.vec[1];
								target.vec[2] += temp.vec[2];
								target.vec[3] += temp.vec[3];

								if ((cam_next->flag & 0x10) != 0)
									set_vec_bounds(&position, cam_next->bound1.vec, cam_next->bound2.vec);

								if ((cam_next->flag & 0x20) != 0)
									set_vec_bounds(&target, cam_next->limit1.vec, cam_next->limit2.vec);
							}

							func((void*)(0xDB6DC0 + chan_id * 0x4A0), &position, &target, camera_channel->current.angle); // executes func 0x8A9FA0

							memcpy(&camera_channel->master, &camera_channel->current, sizeof(camera_channel->master));

							camera_channel->master.position.vec[0] = position.vec[0];
							camera_channel->master.position.vec[1] = position.vec[1];
							camera_channel->master.position.vec[2] = position.vec[2];
							camera_channel->master.position.vec[3] = position.vec[3];

							camera_channel->master.target.vec[0] = target.vec[0];
							camera_channel->master.target.vec[1] = target.vec[1];
							camera_channel->master.target.vec[2] = target.vec[2];
							camera_channel->master.target.vec[3] = target.vec[3];

							calc_and_set_rot(
								camera_channel->master.position.vec,
								camera_channel->master.target.vec,
								camera_channel->master.rotate.vec,
								&camera_channel->master.track);

							if (!chan_id)
							{
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4A4) = (__int64)position.vec[0];
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4A8) = (__int64)position.vec[1];
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4AC) = (__int64)position.vec[2];

								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4B0) = (__int64)target.vec[0];
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4B4) = (__int64)target.vec[1];
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4B8) = (__int64)target.vec[2];

								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4BC) = camera_channel->master.rotate.vec[0];
								*(DWORD *)(*(DWORD *)GCL_Variables + 0x4C0) = camera_channel->master.rotate.vec[1];
							}

							camera_channel->flag &= 0xFFFF7FFF;
						}
					}
					else
					{
						FVECTOR vec1;
						memset(&vec1, 0, sizeof(vec1));
						FVECTOR vec2;
						memset(&vec2, 0, sizeof(vec2));
						vec2.vec[2] = 1.0;
						sub_8A9FA0((void*)(0xDB6DC0 + chan_id * 0x4A0), &vec1, &vec2, 0);
					}
				}
			}
		}
	}
	else
	{
		camera_transitions_handler_original(dw);
	}
}

extern "C" __declspec(dllexport) int __cdecl check_if_snake_needs_to_jump(BYTE *a1)
{
	if (IsEnabled && !IsPaddemo)
	{
		SVECTOR v12;
		float v13[2];
		float v14[4];
		float v15[4];
		float v16[4];

		DWORD v1 = *((DWORD *)a1 + 0x28C);
		if (v1 == 0x42D644
			|| v1 == 0xA5D059
			|| v1 == 0x8CD046
			|| (a1[0xDA] & 1) == 0)
		{
			return 0;
		}

		float v11 = *((float *)a1 + 0x34);
		v14[0] = *((float *)a1 + 0x10);
		v14[1] = v11 + 750.0;
		v14[3] = *((float *)a1 + 0x13);
		v14[2] = *((float *)a1 + 0x12);

		v12.vec[0] = 0;
		v12.vec[2] = 0;

		v12.vec[1] = *(WORD *)(*((DWORD *)a1 + 0x2AF) + 0x10);

		// This patch fixes bug with wrong direction when snake stands on object
		DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
		if (dw)
		{
			v12.vec[1] += get_camera_direction(dw);
		}

		if (*PL_SubjectMove)
		{
			DWORD x1 = *((DWORD *)a1 + 0x14) & 0x7FFFFFFF;
			DWORD x2 = *((DWORD *)a1 + 0x16) & 0x7FFFFFFF;

			if (*(float*)&x1 > 0.0099999998 || (*(float*)&x2 > 0.0099999998))
			{
				sub_8A7F40((void*)0x9FE190, (void*)(a1 + 0x60));
				sub_8A84F0((void*)(a1 + 0x50), v15, 1);
				v12.vec[1] = (WORD)(atan2(v15[0], v15[2]) * 651.89844 + 0.5) & 0xFFF;
			}

			long double v6 = (double)((v12.vec[1] & 0xFFF) - ((v12.vec[1] & 0xFFFu) <= 0x800 ? 0 : 0x1000)) * 0.0015339808;
			*(float *)0xA185A4 = sin(v6) * 40.0;
			*(float *)0xA185A8 = cos(v6) * 40.0;
		}
		else
		{
			DWORD v7 = *((DWORD *)a1 + 0x75);
			v15[0] = 0.0;
			v15[2] = 0.0;
			v15[1] = 0.0;
			v15[3] = 1.0;
			v15[0] = **(float **)(0x70 * *(DWORD *)(v7 + 0x70) + *(DWORD *)(v7 + 4) + 0x4C);
			v15[2] = *(float *)(*(DWORD *)(0x70 * *(DWORD *)(v7 + 0x70) + *(DWORD *)(v7 + 4) + 0x4C) + 8);

			DWORD y1 = *(DWORD*)((BYTE*)v15) & 0x7FFFFFFF;
			DWORD y2 = *(DWORD*)((BYTE*)v15 + 8) & 0x7FFFFFFF;

			if (*(float*)&y1 > 0.1 || *(float*)&y2 > 0.1)
			{
				sub_8A7F40((void*)0x9FE190, (void*)(a1 + 0x60));
				sub_8A84F0(v15, v15, 1);
				v12.vec[1] = (WORD)(atan2(v15[0], v15[2]) * 651.89844 + 0.5) & 0xFFF;
			}
		}

		sub_8D2580(v16, v14, &v12, 0.0, 0.0, 250.0);

		if (*(DWORD*)0xA18594 & 1)
		{
			if (check_collision(*((DWORD *)a1 + 0x39), v14, v16, 0xF, 0x10, 0x10))
				return 0;
		}

		if ((sub_8D4A10((void*)*(DWORD*)0xEDE76C, v16, 1, 0x4010) & 1) == 0)
			return 0;

		sub_8D4A50(v13);

		if (v11 - 750.0 < v13[0])
			return 0;

		if (*PL_SubjectMove)
			return 1;

		DWORD v9 = *((DWORD *)a1 + 0x28C);
		if (v9 == 0x697227 || v9 == 0x9047E1)
		{
			*((WORD *)a1 + 0x31) = *(WORD*)0xF60938;
			*((WORD *)a1 + 0x35) = *(WORD*)0xF60938;
			return 1;
		}
		else
		{
			*((WORD *)a1 + 0x31) = v12.vec[1];
			*((WORD *)a1 + 0x35) = v12.vec[1];
			return 1;
		}
	}
	else
	{
		return check_if_snake_needs_to_jump_original(a1);
	}
}

extern "C" __declspec(dllexport) int __cdecl start_paddemo(int char_id)
{
	DWORD name_hash = gcl_get_option_value(0x66, 0);

	BYTE* object = (BYTE*)paddemo_cmd(char_id);

	return (int)object;
}

extern "C" __declspec(dllexport) void __cdecl paddemo_handler(BYTE *a1)
{
	int state = *((DWORD *)a1 + 23);
	sub_4C9840(a1, state);

	if (state)
	{
		if (state - 1)
		{
			if (state - 1 == 1)
			{
				sub_8D04B0(*((DWORD *)a1 + 20));

				*(DWORD*)0xA5397C &= 0xBFFFFFFF;

				int proc_id = *((DWORD *)a1 + 21);
				if (proc_id)
				{
					sub_878060(proc_id, 0);
					*((DWORD *)a1 + 21) = 0;
				}

				IsPaddemo = false;

				destroy_object(a1);
			}
		}
		else
		{
			if (!IsPaddemo)
			{
				DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;

				CAMERA_MGS2_PC* camera = find_next_camera_inner(&dw->channels[0]);
				if (camera)
				{
					memcpy(&dw->channels[0].current, camera, sizeof(CAMERA_MGS2_PC));
					memcpy(&dw->channels[0].master, camera, sizeof(CAMERA_MGS2_PC));
					dw->channels[0].next = camera;
				}

				CAMERA_CHANNEL_MGS2_PC* camera_channel = &dw->channels[0];
				if ((camera_channel->flag & 0x10) == 0 && *(DWORD*)(0xDB7044 + 0 * 0x4A0))
				{
					CAMERA_MGS2_PC* cam = camera_channel->next;
				}

				IsPaddemo = true;
			}

			paddemo_exec(a1);
		}
	}
}

// Direction might be wrong while swimming in water (with this 2 funcs I patch snake_swimming_controls - 004B04A0)
extern "C" __declspec(dllexport) int __cdecl diff_direction_for_swimming(int a1, int a2)
{
	// Swimming fix 
	DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
	if (IsEnabled && dw && !IsPaddemo)
	{
		a2 += get_camera_direction(dw);
	}

	unsigned __int16 delta = (a1 - a2) & 0xFFF;
	if (delta > 0x800u)
		delta -= 0x1000;
	return a2 + (__int16)delta;
}

extern "C" __declspec(dllexport) int __cdecl pick_direction_for_swimming(int a1, int a2, int a3)
{
	// Swimming fix 
	DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
	if (IsEnabled && dw && !IsPaddemo)
	{
		a2 += get_camera_direction(dw);
	}

	int result;
	if (a1 >= a2)
	{
		result = a1 - a3;
		if (a1 - a3 <= a2)
			return a2;
		return result;
	}
	result = a3 + a1;
	if (a3 + a1 < a2)
		return result;
	return a2;
}

extern "C" __declspec(dllexport) int __cdecl chara_func_0xDFADB()
{
	int result = chara_func_0xDFADB_original();

	if (IsEnabled)
	{
		result |= 0x10;
		result |= 0x800;
	}

	return result;
}

//extern "C" __declspec(dllexport) void __cdecl standstill_play_animation(void* a1, int a2, int a3, int a4)
//{
//	play_animation(a1, DebugAnimationId, a3, a4);
//}

extern "C" __declspec(dllexport) int __cdecl get_camera_direction_fix_for_hanging()
{
	if (IsEnabled && !IsPaddemo)
	{
		return 0;
	}
	else
	{
		return *(DWORD*)0xEDAE78;
	}
}

extern "C" __declspec(dllexport) int __cdecl diff_direction_for_hanging1(int a1, int a2)
{
	// Hanging fix 
	if (IsEnabled && !IsPaddemo)
	{
		a1 = 0x400;
	}

	unsigned int result = (a2 - a1) & 0xFFF;
	if (result > 0x800)
		result = 0x1000 - result;
	return result;
}

extern "C" __declspec(dllexport) int __cdecl diff_direction_for_hanging2(int a1, int a2)
{
	// Hanging fix 
	if (IsEnabled && !IsPaddemo)
	{
		a1 = 0xC00;
	}

	unsigned int result = (a2 - a1) & 0xFFF;
	if (result > 0x800)
		result = 0x1000 - result;
	return result;
}

extern "C" __declspec(dllexport) void __cdecl set_direction_for_PL_SubjectMove_wrap_with_set_stick_direction(void* a1)
{
	*(DWORD*)(*(DWORD*)PL_Object + 0x400) = *(__int16 *)(*(DWORD *)((BYTE*)a1 + 0xABC) + 0x10);

	if (IsEnabled && !IsPaddemo)
	{
		DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
		if (dw)
		{
			WORD cam_direction = get_camera_direction(dw);
			*(DWORD*)(*(DWORD*)PL_Object + 0x400) += cam_direction;
		}
	}

	set_direction_for_PL_SubjectMove(a1);
}

extern "C" __declspec(dllexport) int __cdecl is_rightstick_used(void* a1)
{
	if (IsEnabled)
	{
		if (BladeSpecialAttack)
		{
			*(DWORD *)((BYTE*)a1 + 0xA60) = 1;
			*(WORD *)((BYTE*)a1 + 0xA84) = 9;
		}

		return BladeAttack;
	}
	else
	{
		return *(BYTE *)(*(DWORD *)((BYTE *)a1 + 0xABC) + 0x12) & 2;
	}
}

extern "C" __declspec(dllexport) WORD __cdecl get_blade_direction(void* a1)
{
	if (IsEnabled)
	{
		if (is_rightstick_used(a1))
		{
			if (BladeDirection == 0)
			{
				BladeDirection = get_rand() & 0xFFF;
			}

			return BladeDirection;
		}

		return 0xFFFF;
	}
	else
	{
		FVECTOR rstick;
		int flags = 0;

		*(DWORD*)0xA18564 = 0;

		if (is_rightstick_used(a1))
		{
			rstick.vec[0] = (float)*(unsigned __int8 *)(*(DWORD *)((BYTE*)a1 + 0xABC) + 20) - 128.0;
			rstick.vec[2] = (float)*(unsigned __int8 *)(*(DWORD *)((BYTE*)a1 + 0xABC) + 21) - 128.0;

			DWORD rstick0 = *(DWORD*)(&rstick.vec[0]) & 0x7FFFFFFF;
			DWORD rstick2 = *(DWORD*)(&rstick.vec[2]) & 0x7FFFFFFF;

			if (*(float*)&rstick0 < 96.0)
				flags = 1;

			if (*(float*)&rstick2 < 96.0)
				flags |= 2u;

			*(DWORD*)0xA18564 = rstick0;

			if (*(float*)&rstick2 > *(float*)&rstick0)
				*(DWORD*)0xA18564 = rstick2;

			if (flags == 3)
				return 0xFFFF;
			else
				return (__int64)(atan2(rstick.vec[0], rstick.vec[2]) * 651.89844 + 0.5) & 0xFFF;
		}
		
		return 0xFFFF;
	}
}

extern "C" __declspec(dllexport) int __cdecl check_if_special_blade_attack()
{
	if (IsEnabled)
	{
		return BladeSpecialAttack;
	}
	else
	{
		return check_if_special_blade_attack_original();
	}
}

extern "C" __declspec(dllexport) int __cdecl diff_direction_for_blade_protection(int a1, int a2)
{
	// Blade protection stance fix
	DAEMON_OBJECT* dw = (DAEMON_OBJECT*)*(DWORD*)Cameras_Daemon;
	if (IsEnabled && dw && !IsPaddemo)
	{
		WORD cam_direction = get_camera_direction(dw);
		return (*(__int16 *)(*(DWORD *)((BYTE*)*(DWORD*)PL_Object + 0xABC) + 0x10) + cam_direction) & 0xFFF;
	}
	
	unsigned int result = (a2 - a1) & 0xFFF;
	if (result > 0x800)
		result = 0x1000 - result;

	if (!IsEnabled)
	{
		if (result < 256)
		{
			result = a2;
		}
		else
		{
			result = *(WORD*)(*(DWORD*)PL_Object + 0x6A);
		}
	}

	return result;
}

extern "C" __declspec(dllexport) int __cdecl raiden_event_msg_motion(void* a1, void* a2)
{
	DWORD stage_name = *(DWORD*)(*(DWORD*)GCL_Variables + 0x2C);

	bool flag = false;
	if (stage_name == 0x62353277 /* w25b */)
	{
		if (*(DWORD *)(*(DWORD *)((BYTE*)a2 + 8) + 20) == 0x403)
		{
			flag = true;
		}
	}
	else if (stage_name == 0x63353277 /* w25c */)
	{
		if (*(DWORD *)(*(DWORD *)((BYTE*)a2 + 8) + 20) == 0x403
			&& *(DWORD *)(*(DWORD *)((BYTE*)a2 + 8) + 8) == 0xC00) // It breaks hanging without this additional check
		{
			flag = true;
		}
	}

	if (flag)
	{
		// Its impossible to change weapon and etc if I just do "return 1", this seems to fix this
		*(UINT64*)0xF60958 &= ~0x2000;
		sub_4F3360(a1, 0);

		return 1;
	}

	return raiden_event_msg_motion_original(a1, a2);
}

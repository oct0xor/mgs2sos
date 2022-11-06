# Metal Gear Solid 2 - The Substance Of Subsistence (S.O.S.) Mod

To celebrate the 20th anniversary of Metal Gear Solid 2, I did what this game always deserved. Play the game like never before and see it from a whole new angle!

This mod lets you play Metal Gear Solid 2: Substance with the 3rd person camera (and game controls) from Metal Gear Solid 3: Subsistence.

The code to have a normal 3rd person camera was never present in the game, and in order to implement it, I had to reverse engineer and rewrite many things in the game engine.

[Trailer](https://www.youtube.com/watch?v=pPsGTdWGZLc)

This project was difficult to complete, I previously posted a [dev diary](https://www.youtube.com/watch?v=AGGNfOq8u3o) where I talked about some of the issues I encountered (although after this video I had to fix many more issues).

## Repository overview

This repository contains the source code for the `mgs2_oct0xor` mod and the `solid_mods_loader` mod loader.

Most Metal Gear Solid 2 mods work by patching the game's code. The problem is that everyone patches the game in its own way and it's hard to ensure compatibility between different mods. 
To improve this and prevent problems in a future I've decided to create a universal loader that loads libraries and applies patches with the help of special `json` files. 
I hope that more developers will start to use this universal loader for their own mods. 

I provide `json` files for the "The Substance Of Subsistence (S.O.S.)"  mod and the additional "Hide HUD elements" mod that I've used to record the [Trailer](https://www.youtube.com/watch?v=pPsGTdWGZLc). 
These `json` mod configs are stored in the `mods` folder. 

By default the `mgs2_hide_hud.json` mod is disabled, to enable it change the `enabled` value to `true`.
Don't try to change the "patches" if you don't know what you are doing - this is an instruction for the loader so that it knows what needs to be changed in the game's memory.
For `mgs2_oct0xor.json` its allowed to change `Sensitivity` (the default value is `0.6`), `Invert_X` (the default value is `false`, can be change to `true`) and `Invert_Y` (the default value is `false`, can be change to `true`).

## Binaries
https://github.com/oct0xor/mgs2sos/releases

## Installation
Unpack the contents of `release.zip` archive to `\bin` folder (inside `Metal Gear Solid 2 Substance` installation directory) and launch `solid_mods_loader.exe`.

## How to build
Visual Studio (2017 or others)

## Disclaimer

This is not commercial project.
It is not affilated with Konami.
It doesnt endorse piracy in any form.
You need to own a PC version of the game to play this mod.
All copyrighted content belongs to their respective owners and may not be illegally distributed.

I've finished the game a couple of times and I've fixed almost all the problems I found. But I'm sure that more die-hard fans of the game can find more issues that I haven't noticed. If you find something that was working before and now is broken - please create an Issue.

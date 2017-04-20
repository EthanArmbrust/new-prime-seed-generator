# Metroid Prime Seed Generator

This repo comes with a compiled version of the software.

New version of the Metroid Prime Seed Generator

There are huge improvements over the old version.  The Seed Generator is able to look through seeds without even running the Randomizer anymore.  This means that the Randomizer.exe is no longer required to find seeds, you don't need to keep the program in focus, your paks will not become corrupted by cancelling the program, and most importantly, there are HUGE speed improvements.

Average Time to find a Normal Seed with No Exceptions and multithreading on:

Windows:
A10-7700K @ 3.4 GHz - 0.71 seconds  
i7-4970 @ 3.60 GHz - 0.38 seconds

MacOS:  
iMac (Late 2015) i5-5575R @ 2.8 GHz - 0.08 seconds  
Mac Mini (Mid 2011) i5-2520M @ 2.8 GHz - 0.17 seconds  

Linux:  
i3-6100u @ 2.3 GHz - 0.39 seconds  
i7-4970 @ 3.60 GHz - 0.23 seconds

A great improvement over the hours the old generator used to take.

----------------

#Randomizer Script Compatibility

Place the Generator in the same folder as the Randomizer Script.  After the Generator has found a seed, you will be asked if you want to open the script.  The settings will be automatically entered for the script.

----------------


# Compiling Instructions

Building requires a C++ compiler with posix threading.

Run the build.bat to build for Windows on Windows.

Run the buildForWindows.sh to build for Windows on Linux.

Run the buildForLinux.sh to build for Linux on Linux.

--------------

# Change Log  

Version 1.0  
Initial Release of new version.
Switched over from using Claris's Randomizer logs to doing randomizing "in-house"  
Created Linux version  


Version 1.1  
Added multithreading support for an approx. 2x speed increase.  
Small other optimizations for additional speed increases.  
Created macOS version  

"Behind-the-Scenes" changes:  
Restructured LogChecker to be a class instead of a messy conglomeration of methods, allowing for multithreading
Removed lots of unnessecary code duplication in the main.
Swapped out apvector for std::vector


Version 1.2
Fixed bug where generator would write the wrong seed to the settings file (Thanks Bash for finding this!)  
Merged all of the main files into a single file  


---------------

# Credits

Metroid Prime Randomizer created by Claris

Metroid Prime Randomizer Script by rekameohs

Portions of the checker written by Sjorec

Help with higher difficulty checker from Tomlube

Inspiration from A. Ziccardi

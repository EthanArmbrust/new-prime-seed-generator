# Metroid Prime Seed Generator

This repo comes with a compiled version of the software.

New version of the Metroid Prime Seed Generator

There are huge improvements over the old version.  The Seed Generator is able to look through seeds without even running the Randomizer anymore.  This means that the Randomizer.exe is no longer required to find seeds, you don't need to keep the program in focus, your paks will not become corrupted by cancelling the program, and most importantly, there are HUGE speed improvements.

Average Time to find a Normal Seed with No Exceptions:

Windows:  
i3-6100u @ 2.3 GHz - 3.1 seconds  
i5-3350p @ 3.1 GHz - 1.6 seconds  
i7-4970 @ 3.60 GHz - 1.1 seconds

Linux:  
i3-6100u @ 2.3 GHz - 1.02 seconds  
i5-3350p @ 3.1 GHz - 0.87 seconds  
i7-4970 @ 3.60 GHz - 0.45 seconds

A great improvement over the hours the old generator used to take.

----------------

#Randomizer Script Compatibility

Place the Generator in the same folder as the Randomizer Script.  After the Generator has found a seed, you will be asked if you want to open the script.  The settings will be automatically entered for the script.

----------------


#Compiling Instructions

Building Windows version requires mingw with g++.

Building Linux version requires g++.

Run the build.bat to build for Windows for Windows.

Run the buildForWindows.sh to build for Windows on Linux.

Run the buildForLinux.sh to build for Linux on Linux.

---------------

#Credits

Metroid Prime Randomizer created by Claris

Metroid Prime Randomizer Script by rekameohs

Portions of the checker written by Sjorec

Help with higher difficulty checker from Tomlube

Inspiration from A. Ziccardi

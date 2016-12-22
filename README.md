# Metroid Prime Seed Generator

This repo comes with a compiled version of the software.

New version of the Metroid Prime Seed Generator

There are huge improvements over the old version.  The Seed Generator is able to look through seeds without even running the Randomizer anymore.  This means that the Randomizer.exe is no longer required to find seeds, your paks will not become corrupted by cancelling the program, and most importantly, there are HUGE speed improvements.

Average Time to find a Normal Seed with No Exceptions:

i3-6100u @	2.3GHz - 3.1 seconds  
i7-4970 @ 3.60 GHz - 1.1 seconds

A great improvement over the hours the old generator used to take.

----------------

#Randomizer Script Compatibility

Place the Generator in the same folder as the Randomizer Script.  After the Generator has found a seed, you will be asked if you want to open the script.  The settings will be automatically entered for the script.

----------------


#Compiling Instructions

Requires Mingw-w64

Run the build.sh script.

This software requires a version of MinG-w64 with POSIX threads.  It will not compile properly with win32 threads.

---------------

#Credits

Metroid Prime Randomizer created by Claris

Metroid Prime Randomizer Script by rekameohs

Portions of the checker written by Sjorec

Help with higher difficulty checker from Tomlube

Inspiration from A. Ziccardi


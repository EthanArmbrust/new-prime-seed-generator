# Metroid Prime Seed Generator

New version of the Metroid Prime Seed Generator.  This program finds seeds that are completable for Claris' Metroid Prime Randomizer.

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
# Usage  

The Seed Generator opens to a command-line menu. Type the number of the option you want and press enter.  

Options `1-4` generate a seed with the specified difficulty.  You will be asked to provide the exceptions you want.  Enter the exception numbers separated by spaces.  Leave blank for no exceptions.  Once a seed has been found, you will be brought back to the main menu with the seed and exceptions shown at the top. Make sure you copy the settings over to the randomizer correctly if you are not using the script, including the exceptions!  

Option `5` creates a log file.  This will create a log file in the exact same format as the randomizer (with the exception of the first line).  You will be asked to provide the exceptions you want.  Enter the exception numbers separated by spaces.  Leave blank for no exceptions.  You will then be asked to provide a seed. Enter a number between 0 and 2147483647, or leave blank for a random seed.  The log will be created in the `SeedGenLogs` folder.  

Option `6` will check if a seed is completable. Enter the exception numbers separated by spaces.  Leave blank for no exceptions. You will be asked to provide a seed. Enter a number between 0 and 2147483647.  The Seed Generator will check the seed and print the lowest difficulty that the seed is completable on.  
You can use the `-v` modifier with option 6 to show the item order for seed.  
Ex. `6 -v`  

Option `7` allows you to run the program indefinitely while printing completable seeds to a text file.  Selecting this option brings you to another menu.  From here you can select the difficulty you want, after which you can input your desired exclusions.  

Option `8` allows you disable/enable multithreading. Multithreading is enabled by default.  Use option 8 to turn off multithreading if you have an ancient single thread CPU or have scarce resources.  If unsure, leave this alone.  

Type `exit` to quit the program.  

### Modifiers   

`$` - Max difficulty.  Place this before options `1-4` to generate a seed of the given difficulty or lower.  Ex. `$3` will give a seed that is completable under Easy, Normal, or Veteran difficulties. This has been changed from previous versions.   

`-f` - No floaty allowed. Place this after options `3` or `4` to get a seed that does not require floaty jump.  Easy and Normal difficulties will never require floaty jump.  Can be used with `6` to check if a seed is completable without floaty jump.  Can be used on the print to text file menu.  Ex. `4 -f`

`-v` - Verbose manual checker.  Place this after option `6` to have the manual checker to show the order that checker expects you to pick up the items for the given seed.  This will likely not be the most logical order when playing, but it is a possible order.  Can be used in conjunction with the `-f` modifier.  Ex. `6 -v`, `6 -v -f` 


### Randomizer Script Compatibility

Place the Seed Generator in the same folder as the Randomizer Script.  After the Generator has found a seed, you will be asked if you want to open the script.  The randomizer settings will be automatically entered for the script.

----------------


# Compiling Instructions

Building requires a C++ compiler with posix threading.

Run the build.bat to build for Windows on Windows.

Run the buildForWindows.sh to build for Windows on Linux.

Run the buildForLinux.sh to build for Linux on Linux.

--------------

# Change Log  

#### Version 1.0  
Initial Release of new version.
Switched over from using Claris's Randomizer logs to doing randomizing "in-house"  
Created Linux version  


#### Version 1.1  
Added multithreading support for an approx. 2x speed increase.  
Small other optimizations for additional speed increases.  
Created macOS version  

"Behind-the-Scenes" changes:  
Restructured LogChecker to be a class instead of a messy conglomeration of methods, allowing for multithreading
Removed lots of unnessecary code duplication in the main.
Swapped out apvector for std::vector


#### Version 1.2  
Fixed bug where generator would write the wrong seed to the settings file (Thanks Bash for finding this!)  
Merged all of the main files into a single file  

#### Version 1.3  
Fixed checker bug with floaty jump  
Checker no longer expects you to be able to pick up artifacts through walls due to the 3.2 update of the Randomizer  
Added verbose flag for manual checker. Add a -v to option 6 from the main menu to get the checkers item order list  
Added no floaty flag for manual checker. Add a -f to any generating option to generate a seed that will not require floaty jump. Can be used on the manual checker and the print menu.  

#### Version 1.4
Numerous changes to checker logic  
Updated verbose manual checker to print location and full name of location and item  
Removed "Why" mode option from menu because it doesn't look like it's happening any time soon and was taking up space  
Added log printing option
Swapped the `$` operator around.  Old `$` functionality is on by default now, and using `$` now accepts seeds of lower difficulties.
Fixed memory leak



---------------

# Credits

Metroid Prime Randomizer created by Claris

Metroid Prime Randomizer Script by rekameohs

Portions of the checker written by Sjorec

Help with higher difficulty checker from Tomlube

Inspiration from A. Ziccardi

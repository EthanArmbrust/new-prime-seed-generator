#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <thread>
#include <future>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "logChecker.h"
#include "randomizerTime.h"
//platform specific includes
#ifdef __APPLE__
#include <sys/syscall.h>
#elif defined __linux__
#include <sys/syscall.h>
#include <linux/kernel.h>
#elif defined _WIN32 || defined _WIN64
#include "windows.h"
#endif





void mainMenu();
void processOption();
void manualChecker(bool verbose, bool noFloatyAllowed);
void printMenu();
void clearScreen();
bool fileExists(const std::string& fileName);
void getTimeAndSeedCount(double, int);
int getASeed();
void createLogFile();
vector <int> getTheExceptions();
void loadScript(int, vector <int>);
string simplifyString(string);
void multithreadTest(bool, int, bool, bool);
string seedListName(int difficulty, bool only);





using namespace std;




string header1 = "			    Seed Generator v1.3";
string header2 = "			        by Interslice";
string option;
string printOption;
string bottomHelp1 = "Type $# to give a seed of ONLY a difficulty. Type HELP $ for more info.";
string bottomHelp2 = "Type \"HELP #\" for more information on an option.";
//string pretzels = "these pretzels are making me thirsty!";
bool mainThreadDone = false;
bool newThreadDone = false;
int newThreadSeedCount = 0;
int barePrintSeed = -1;
bool enableMultithreading = true;
string multithreadingState = "8 - Disable Multithreading \n \n";
int scriptSeed;
string dirSeparator;





int main(){

  #if defined _WIN32 || defined _WIN64
  dirSeparator = "\\";
  #elif defined __APPLE__ || defined __linux__
  dirSeparator = "/";
  #endif

  mainMenu();
  return 0;
}

void mainMenu(){

	clearScreen();
	cout << header1 << endl;
	cout << header2 << endl << endl;
	cout << "1 - Generate an \"Easy\" difficulty seed \n \n";
	cout << "2 - Generate a \"Normal\" difficulty seed \n \n";
	cout << "3 - Generate a \"Veteran\" difficulty seed\n \n";
	cout << "4 - Generate a \"Hypermode\" difficulty seed\n \n";
	cout << "5 - Generate a \"Why\" difficulty seed (Coming soon) \n \n";
	cout << "6 - Check a seed \n \n";
	cout << "7 - Export seeds to text file \n \n";
  cout << multithreadingState;
  //cout << simplifyString(pretzels) << endl;
	cout << bottomHelp1 << endl;
	cout << bottomHelp2 << "\n"  << endl;
	cout << "> ";
	getline(cin, option);
	processOption();
}

void processOption(){
	clearScreen();
  string temp = simplifyString(option);
  option = temp;

  if(option == "L"){
    system("mkdir SeedGenLogs");
    clearScreen();
    createLogFile();
  }

	if(option == "1" || option == "$1" || option == "$1-F" || option == "1-F"){
		multithreadTest(false, 1, false, false);
	}
	if(option == "2" || option == "2-F"){
	   multithreadTest(false, 2, false, false);
	}
	if(option == "3"){
	   multithreadTest(false, 3, false, false);
	}
  if(option == "3-F"){
     multithreadTest(false, 3, false, true);
  }
	if(option == "4"){
		multithreadTest(false, 4, false, false);
	}
  if(option == "4-F"){
		multithreadTest(false, 4, false, true);
	}
	if(option == "5"){
    cout << "This will be added sometime in the future" << endl;
		cin.get();
	}
	if(option == "6"){
		manualChecker(false, false);
	}
  if(option == "6-V"){
		manualChecker(true, false);
	}
  if(option == "6-V-F" || option == "6-F-V"){
		manualChecker(true, true);
	}
  if(option == "6-F"){
		manualChecker(false, true);
	}
	if(option == "7"){
		printMenu();
	}
  if(option == "8"){
    enableMultithreading = !enableMultithreading;
    if(enableMultithreading){
      multithreadingState = "8 - Disable Multithreading \n \n";
    }
    else multithreadingState = "8 - Enable Multithreading \n \n";
  }

	if(option == "$2" || option == "$2-F"){
		multithreadTest(false, 2, true, false);
	}
	if(option == "$3"){
		multithreadTest(false, 3, true, false);
	}
  if(option == "$3-F"){
		multithreadTest(false, 3, true, true);
	}

	if(option == "$4" || option == "$ 4"){
		multithreadTest(false, 4, true, false);
	}
  if(option == "$4-F"){
		multithreadTest(false, 4, true, true);
	}
	if(option == "HELP1"){
		cout << "This is the easiest difficulty seed.  These seeds can be completed with little to no sequence breaking.  Good for those unfamiliar with Metroid Prime speedrunning or if you are playing on a patched version of the game." << endl;
		cin.get();

	}
	if(option == "HELP2"){
		cout << "This is the original rendition of the seed generator.  This difficulty will NOT require the player to do any Hyper Bomb Jumps or Uber Bomb Jumps, do a Suitless Magmoor run (except from the Tallon elevator to South Magmoor), do the Chozo floaty glitch without Space Jump, or any other stupid tricks.  Good for beginner speedrunners with moderate knowledge of sequence breaking.  A full list of item requirements can be found here: http://bombch.us/BNcL" << endl;
		cin.get();
	}
	if(option == "HELP3"){
		cout << "This is a step up from the previous difficulty.  Players will be expected to be able to do all 22% tricks, as well as some of the easier 21% tricks.  A full list of item requirements can be found here: http://bombch.us/BNcM . Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(option == "HELP4"){
		cout << "This difficulty requires the player to do pretty much everything, minus some very difficult tricks such as Life Grove 21%, Root Cave without Space Jump, and other tricks that you wish were never discovered. Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(option == "HELP5"){
		cout << "If it is possible, you might have to do it.  To be added soon." << endl;
		cin.get();
	}

	if(option == "HELP6"){
		cout << "Allows you to manually check a seed.  Enter the exceptions and the seed when prompted.  Will return the lowest possible difficulty that it is completable on. Use \"-v\" to get the item order list.  Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(option == "HELP$"){
		cout << "Gives you a seed that is completable only by a player of desired skill level. For example, $5 will generate a seed that is completable by a \"Veteran\" player, but not a \"Normal\" player \n \n" << endl;
		cin.get();
	}
	if(option == "HELP7"){
		cout << "Allows you to pick a difficulty and run the generator indefinatly while dumping completable seeds into a text file.  Lists are located in the CompletableSeeds folder." << endl;
		cin.get();
	}
	if(option == "DF"){
		cout << "df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df \n Here's your seed: 69696969 \n Exceptions: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99 \n  df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df" << endl;
		cin.get();
	}

  if(option != "EXIT"){
	mainMenu();
  }
}


string seedListName(int difficulty, bool only){
  if(difficulty == 1){
    return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Easy_Seed_List.txt";
  }
  if(difficulty == 2){
    if(only){
      return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Normal_Only_Seed_List.txt";
    }
    else return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Normal_Seed_List.txt";
  }
  if(difficulty == 3){
    if(only){
      return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Veteran_Only_Seed_List.txt";
    }
    else return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Veteran_Seed_List.txt";
  }
  if(difficulty == 4){
    if(only){
      return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Hypermode_Only_Seed_List.txt";
    }
    else return "." + dirSeparator + "CompletableSeeds" + dirSeparator + "Hypermode_Seed_List.txt";
  }
}


void barebonesSeedGen(vector<int> apNumbers, int difficulty, bool print, bool only, bool noFloatyAllowed, std::ofstream& seedList){
  int seedCounter = 0;
  CurrentTime current_time;
  LogChecker checker2;
  int randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647);
	checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed);
	seedCounter++;

  if(!print){
  if(!only){
	while(!checker2.returnDifficulty(difficulty) && !mainThreadDone){
		randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
  	checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed);
		seedCounter++;
    }
  }
  else{
    bool seedGood = false;
    while(!seedGood && !mainThreadDone){
    randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
    seedCounter++;
    checker2.difficultyCheck(difficulty,randoSeed, apNumbers, false, noFloatyAllowed);
    if(checker2.returnDifficulty(difficulty)){
      checker2.difficultyCheck(difficulty-1,randoSeed, apNumbers, false, noFloatyAllowed);
      if(!checker2.returnDifficulty(difficulty-1)){
        seedGood = true;
      }
     }
    }
  }
    if(!mainThreadDone){
      newThreadDone = true;
      header1 = checker2.returnSeed();
      scriptSeed = randoSeed;
      }
    newThreadSeedCount = seedCounter;
  }
  else{
    if(!only){
      for(;;){
  	while(!checker2.returnDifficulty(difficulty)){
  		randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
    	checker2.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed);
  		seedCounter++;
      }
      seedList << checker2.returnSeed() << " " << checker2.returnExceptions()  << endl;
      randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
      checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed);
     }
    }
    else{
      bool seedGood = false;
      for(;;){
      while(!seedGood){
      randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
      seedCounter++;
      checker2.difficultyCheck(difficulty, randoSeed, apNumbers, false, noFloatyAllowed);
      if(checker2.returnDifficulty(difficulty)){
        checker2.difficultyCheck(difficulty-1, randoSeed, apNumbers, false, noFloatyAllowed);
        if(!checker2.returnDifficulty(difficulty-1)){
          seedGood = true;
        }
       }
      }
      seedList << checker2.returnSeed() << " " << checker2.returnExceptions() << endl;
      seedGood = false;
     }
    }

  }

  }



void multithreadTest(bool print, int difficulty, bool only, bool noFloatyAllowed){
  bool validSelection = false;

  ofstream seedList;
	vector<int> apNumbers(0);
  while(!validSelection){

	cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);
	stringstream numStream(str);
	while (numStream >> x)
		numbers.push_back(x);

	sort(numbers.begin(), numbers.end());
  bool tooLarge = false;
  apNumbers.resize(numbers.size());

	for(int tran = 0; tran < apNumbers.size(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    clearScreen();
    cout << "Invalid Selection.  Please try again" << endl;
  }
 }
 CurrentTime current_time;
 int seedCounter = 0;
 LogChecker checker;
 if(!print){

	clock_t begin = clock();

  clearScreen();

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed);
	seedCounter++;
  if(enableMultithreading){
  std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, noFloatyAllowed, std::ref(seedList));
  if(!only){
	while(!checker.returnDifficulty(difficulty) && !newThreadDone){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed);
		seedCounter++;
  }
 }
 else {
   bool seedGood = false;
   while(!seedGood && !newThreadDone){
   randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
   seedCounter++;
   cout << "Current Seed: " << randoSeed << '\r' << flush;
   checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed);
   if(checker.returnDifficulty(difficulty)){
     checker.difficultyCheck(difficulty-1,randoSeed, apNumbers,false, noFloatyAllowed);
     if(!checker.returnDifficulty(difficulty-1)){
       seedGood = true;
     }
    }
   }
 }
if(!newThreadDone){
  mainThreadDone = true;
}
t1.join();}

else{
if(!only){
while(!checker.returnDifficulty(difficulty) && !newThreadDone){
  cout << "Current Seed: " << randoSeed << '\r' << flush;
  randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  checker.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed);
  seedCounter++;
}
}
else {
 bool seedGood = false;
 while(!seedGood && !newThreadDone){
 randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
 seedCounter++;
 cout << "Current Seed: " << randoSeed << '\r' << flush;
 checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed);
 if(checker.returnDifficulty(difficulty)){
   checker.difficultyCheck(difficulty-1,randoSeed, apNumbers,false, noFloatyAllowed);
   if(!checker.returnDifficulty(difficulty-1)){
     seedGood = true;
   }
  }
 }
}
if(!newThreadDone){
mainThreadDone = true;
 }
}

clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
seedCounter += newThreadSeedCount;
#if defined _WIN32 || defined _WIN64
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
#else
if(enableMultithreading){
  getTimeAndSeedCount(elapsed_secs/200.0, seedCounter);
}
else getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);

#endif
if(mainThreadDone){
  header1 = checker.returnSeed();
  scriptSeed = randoSeed;
}
header2 = checker.returnExceptions();
mainThreadDone = false;
newThreadDone = false;
newThreadSeedCount = 0;

if(fileExists("." + dirSeparator + "Metroid Prime Randomizer.bat")){
  clearScreen();
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    clearScreen();
    loadScript(scriptSeed, apNumbers);
    clearScreen();
    system("\"Metroid Prime Randomizer.bat\"");
  }
 }
}

else{
  int prevSeed = -1;
  system("mkdir CompletableSeeds");
  clearScreen();
  seedList.open(seedListName(difficulty, only), ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  if(enableMultithreading){
    std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, noFloatyAllowed, std::ref(seedList));
    t1.detach();}
  for(;;){ //infinite loop
    if(!only){
    while(!checker.returnDifficulty(difficulty) && !newThreadDone){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
      checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed);
      seedCounter++;
    }
    }
    else{
     bool seedGood = false;
     while(!seedGood && !newThreadDone){
     randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
     seedCounter++;
     cout << "Current Seed: " << randoSeed << '\r' << flush;
     checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed);
     if(checker.returnDifficulty(difficulty)){
       checker.difficultyCheck(difficulty-1,randoSeed, apNumbers, false, noFloatyAllowed);
       if(!checker.returnDifficulty(difficulty-1)){
         seedGood = true;
       }
      }
     }
    }
  if(prevSeed != randoSeed){
  seedList << checker.returnSeed() << " " << checker.returnExceptions() << endl;
  prevSeed = randoSeed;
  checker.resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    checker.CheckFinishNormalNew(randoSeed, apNumbers, false);
    seedCounter++;
      }
    }
  }
}



int getASeed(){
  int inputSeed = -1;
  cout << "Please enter the seed:" << endl;
  cout << "> ";
	cin >> inputSeed;
  return inputSeed;
}

vector <int> getTheExceptions(){

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);
	stringstream numStream(str);
	while (numStream >> x)
		numbers.push_back(x);

	sort(numbers.begin(), numbers.end());

	vector<int> apNumbers(numbers.size());

	for(int tran = 0; tran < apNumbers.size(); tran++){
		apNumbers[tran] = numbers[tran];
	}
  return apNumbers;
}



void manualChecker(bool verbose, bool noFloatyAllowed){
	bool tempVersion;
	string firstLine;

  cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";




  vector <int> apNumbers = getTheExceptions();

  int inputSeed = getASeed();
  LogChecker checker;
  if(noFloatyAllowed){
    cout << "No Floaty Allowed: " << endl;
  }

	checker.CheckFinishEasyNew(inputSeed, apNumbers, verbose);
		if(checker.returnCompletableEasy()){
			cout << "Seed is completable (Easy Difficulty)" << endl;
      cout << "Press Enter to continue...";
			cin.ignore().get();
		}
		else{checker.CheckFinishNormalNew(inputSeed, apNumbers,verbose);
			if(checker.returnCompletableNormal()){
				cout << "Seed is completable (Normal Difficulty)" << endl;
        cout << "Press Enter to continue...";
				cin.ignore().get();
			}
			else{checker.CheckFinishVeteranNew(inputSeed, apNumbers, verbose, noFloatyAllowed);
				if(checker.returnCompletableVeteran()){
					cout << "Seed is completable (Veteran Difficulty)" << endl;
          cout << "Press Enter to continue...";
					cin.ignore().get();
				}
				else{checker.CheckFinishHypermodeNew(inputSeed, apNumbers, verbose, noFloatyAllowed);
					if(checker.returnCompletableHypermode()){
						cout << "Seed is completable (Hypermode Difficulty)" << endl;
            cout << "Press Enter to continue...";
						cin.ignore().get();
					}
					else{
						cout << "This seed is NOT completable (Easy through Hypermode)" << endl;
            cout << "Press Enter to continue...";
						cin.ignore().get();
					}
				}
			}
		}

	}


void printMenu(){
	cout << "Seeds and exceptions will be printed to a log file.  The seeds will be generated and recorded until the user stops the program. \n \n";
	cout << "Please select the difficulty.  Note that you may use the $ operator to get an exclusive difficulty. \n \n";
	cout << "1 - Easy \n \n";
	cout << "2 - Normal \n \n";
	cout << "3 - Veteran \n \n";
	cout << "4 - Hypermode \n \n";
	cout << "EXIT - Return to Main Menu \n \n \n \n";
	cout << "> ";

	getline(cin, printOption);

  printOption = simplifyString(printOption);

	if(printOption == "1" || printOption == "1-F" || printOption == "$1-F"){
		multithreadTest(true, 1, false, false);
	}
	if(printOption == "2" || printOption == "2-F"){
		multithreadTest(true, 2, false, false);
	}
	if(printOption == "3"){
		multithreadTest(true, 3, false, false);
	}
  if(printOption == "3-F"){
		multithreadTest(true, 3, false, true);
	}
	if(printOption == "4"){
    multithreadTest(true, 4, false, false);
	}
  if(printOption == "4-F"){
    multithreadTest(true, 4, false, true);
	}


	if(printOption == "$1"){
		multithreadTest(true, 1, false,false);
	}
	if(printOption == "$2" || printOption == "$2-F"){
		multithreadTest(true, 2, true,false);
	}
	if(printOption == "$3"){
		multithreadTest(true, 3, true,false);
	}
  if(printOption == "$3-F"){
		multithreadTest(true, 3, true,true);
	}
	if(printOption == "$4"){
		multithreadTest(true, 4, true,false);
	}
  if(printOption == "$4-F"){
		multithreadTest(true, 4, true,true);
	}
	if(printOption == "EXIT" || printOption == "exit"){
		mainMenu();
	}
	printMenu();
}



bool fileExists(const std::string& fileName)
{
     std::fstream file;
     file.open(fileName.c_str(), std::ios::in);
     if (file.is_open() == true)
     {
         file.close();
         return true;
     }
     file.close();
     return false;
}

void getTimeAndSeedCount(double elapsedTime, int seedCount){
	double intTime = elapsedTime;
	stringstream stream;
	stream << setprecision(3) << intTime;
	bottomHelp1 = "Total time to create seed: ";
	bottomHelp2 = "Number of seeds processed: ";
 	bottomHelp1 += stream.str();
	bottomHelp1 += " seconds";
  bottomHelp2 +=  to_string(seedCount);

}

void loadScript(int settingSeed, vector <int> settingException){

  vector <string> settingsLines(18, "");


  ifstream myfile;
  myfile.open("." + dirSeparator + "tools" + dirSeparator + "settings.txt");

if(myfile.is_open()){
  int x = 0;
  while(getline(myfile,settingsLines[x])){
    x++;
	}
  myfile.close();

}
else {cout << "Couldn't find settings file.";}


string line ="seed ";
line += to_string(settingSeed);
line += " -e ";

cout << "Remove hud popups? (Y/N)" << endl;
cout << "> ";

string popupSetting;
getline(cin, popupSetting);
bool popup = false;

popup = (simplifyString(popupSetting) == "Y" || simplifyString(popupSetting) == "YES");

for(int bob = 0; bob < settingException.size(); bob++){
  if(bob == settingException.size() - 1){
    line += to_string(settingException[bob]);
  }
  else{line += to_string(settingException[bob]);
        line += ",";
      }
}
if(settingException.size() == 0){
  line += "none";
}

if(popup){
  line += " -h";
}

settingsLines[3] = line;
ofstream settingsFile;
settingsFile.open("." + dirSeparator + "tools" + dirSeparator + "settings.txt");


for(int ziccardo = 0; ziccardo < settingsLines.size()-1; ziccardo++){
    settingsFile << settingsLines[ziccardo] << endl;

  }
  settingsFile.close();

}

string simplifyString(string inString){
string str = inString;
transform(str.begin(), str.end(), str.begin(), ::toupper);
str.erase(remove(str.begin(), str.end(), ' '), str.end());

return str;

}

void clearScreen(){
  #if defined _WIN32 || _WIN64
  system("cls");
  #else
  system("clear");
  #endif
}

void createLogFile(){
  bool validSelection = false;
	vector<int> apNumbers(0);
  while(!validSelection){

	cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);
	stringstream numStream(str);
	while (numStream >> x)
		numbers.push_back(x);

	sort(numbers.begin(), numbers.end());
  bool tooLarge = false;
  apNumbers.resize(numbers.size());

	for(int tran = 0; tran < apNumbers.size(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    clearScreen();
    cout << "Invalid Selection.  Please try again" << endl;
  }
 }

 int seed = -1;

 cout << "Enter seed number (leave blank for random)" << endl;
 cout << "> ";

 string str;

 getline(cin, str);

 if(simplifyString(str) != ""){
   stringstream seedString(str);
   seedString >> seed;
 }
 else{
   CurrentTime current_time;
   seed = (int)(current_time.microseconds() % (long) 2147483647);
 }
 LogChecker logGen;
 vector<string> gameLog = logGen.generateLog(apNumbers, seed);


 ofstream logWriter;
 time_t t = time(0);
 struct tm * now = localtime(&t);

 char buffer [80];
 strftime(buffer,80,"%Y-%m-%d_%I-%M-%S-%p.",now);

 string logPath =  "SeedGenLogs" + dirSeparator;
 logPath += "Prime_Randomizer_Log-";
 logPath += buffer;
 logPath += "txt";

 logWriter.open(logPath);

 logWriter << "Seed Generator" << endl;
 logWriter << "Seed: " << seed << endl;
 logWriter << "Excluded Pickups: ";

 if(apNumbers.size() == 0){
   logWriter << "None" << endl;
 }
 else{
   for(int m = 0; m < apNumbers.size(); m++){
     logWriter << apNumbers[m] << " ";
   }
    logWriter << "\n";
 }

 for(int n = 2; n < gameLog.size()-2; n++){
   logWriter << gameLog[n] << endl;
 }
  logWriter.close();
  cout << "Log file created!" <<endl;
  cout << "Press Enter to continue...";
  cin.ignore().get();
}

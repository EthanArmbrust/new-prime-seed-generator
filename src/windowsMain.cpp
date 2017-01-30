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
#include <vector>
#include "apvector.h"
#include "logChecker.h"
#include "windows.h"
#include "randomizerTime.h"

void mainMenu();
void processOption();
void manualChecker();
void printMenu();
bool fileExists(const std::string& fileName);
void getTimeAndSeedCount(double, int);
void newTest(bool);
void newTestVeteran(bool);
void newTestEasy(bool);
void newTestHypermode(bool);
int getASeed();
apvector <int> getTheExceptions();
void newNormalOnly(bool);
void newVeteranOnly(bool);
void newHypermodeOnly(bool);
void loadScript(int, apvector <int>);
string simplifyString(string);


using namespace std;


string randomizerPath;
string rootPath;
string exceptions;
string randomizerExe = "Prime_Randomizer.exe ";
string fullRandomizer;
string theE = " -e ";
string header1 = "			    Seed Generator v1.0";
string header2 = "			        by Interslice";
string copyThat = "copy ";
string fullCopy;
string fullExceptions;
string fullCommand;
string randoPath;
string logFile;
string option;
string printOption;
string upperBound;
string lowerBound;
string command1;
string command2;
string command3;
string command4;
string logForMoving;
string manualLogFile;
bool newRando;
string newRandomizer;
string popupBlocker;
bool popup;
string hackedRando;
bool hackedRandomizer;
string versionNumber = "v0.9.5";
string currentVersion = "v0.9.5";
string bottomHelp1 = "Type $# to give a seed of ONLY a difficulty. Type HELP $ for more info.";
string bottomHelp2 = "Type \"HELP #\" for more information on an option.";
//string pretzels = "these pretzels are making me thirsty!";


const char * charCommand;
const char * charLog;
const char * charRoot;
const char * charExceptions;




int main(){

  mainMenu();



return 0;
}

void mainMenu(){

	system("cls");
	cout << header1 << endl;
	cout << header2 << endl << endl;
	cout << "1 - Generate an \"Easy\" difficulty seed \n \n";
	cout << "2 - Generate a \"Normal\" difficulty seed \n \n";
	cout << "3 - Generate a \"Veteran\" difficulty seed\n \n";
	cout << "4 - Generate a \"Hypermode\" difficulty seed\n \n";
	cout << "5 - Generate a \"Why\" difficulty seed (Coming soon) \n \n";
	cout << "6 - Check a seed \n \n";
	cout << "7 - Export seeds to text file \n \n";
  //cout << simplifyString(pretzels) << endl;
	cout << bottomHelp1 << endl;
	cout << bottomHelp2 << "\n"  << endl;
	cout << "> ";
	getline(cin, option);
	processOption();
}

void processOption(){
	system("cls");
  string temp = simplifyString(option);
  option = temp;
	if(option == "1" || option == "$1"){
		newTestEasy(false);
	}
	if(option == "2"){
	   newTest(false);
	}
	if(option == "3" || option == "$3" || option == "$ 3"){
	   newTestVeteran(false);
	}
	if(option == "4"){
		newTestHypermode(false);
	}
	if(option == "5"){
    cout << "This will be added sometime in the future" << endl;
		system("pause");
	}
	if(option == "6"){
		manualChecker();
	}
	if(option == "7"){
		printMenu();
	}

  if(option == "trial"){

  }

	if(option == "$2" || option == "$ 2"){
		newNormalOnly(false);
	}
	if(option == "$3" || option == "$ 3"){
		newVeteranOnly(false);
	}

	if(option == "$4" || option == "$ 4"){
		newHypermodeOnly(false);
	}
	if(option == "HELP1"){
		cout << "This is the easiest difficulty seed.  These seeds can be completed with little to no sequence breaking.  Good for those unfamiliar with Metroid Prime speedrunning or if you are playing on a patched version of the game." << endl;
		system("pause");

	}
	if(option == "HELP2"){
		cout << "This is the original rendition of the seed generator.  This difficulty will NOT require the player to do any Hyper Bomb Jumps or Uber Bomb Jumps, do a Suitless Magmoor run (except from the Tallon elevator to South Magmoor), do the Chozo floaty glitch without Space Jump, or any other stupid tricks.  Good for beginner speedrunners with moderate knowledge of sequence breaking.  A full list of item requirements can be found here: http://bombch.us/BNcL" << endl;
		system("pause");
	}
	if(option == "HELP3"){
		cout << "This is a step up from the previous difficulty.  Players will be expected to be able to do all 22% tricks, as well as some of the easier 21% tricks.  A full list of item requirements can be found here: http://bombch.us/BNcM " << endl;
		system("pause");
	}
	if(option == "HELP4"){
		cout << "This difficulty requires the player to do pretty much everything, minus some very difficult tricks such as Life Grove 21%, Root Cave without Space Jump, and other tricks that you wish were never discovered. " << endl;
		system("pause");
	}
	if(option == "HELP5"){
		cout << "If it is possible, you might have to do it.  To be added soon." << endl;
		system("pause");
	}

	if(option == "HELP6"){
		cout << "Allows you to manually check a seed.  Enter the exceptions and the seed when prompted.  Will return the lowest possible difficulty that it is completable on." << endl;
		system("pause");
	}
	if(option == "HELP$"){
		cout << "Gives you a seed that is completable only by a player of desired skill level. For example, $5 will generate a seed that is completable by a \"Veteran Player\", but not a \"Normal\" player \n \n" << endl;
		system("pause");
	}
	if(option == "HELP7"){
		cout << "Allows you to pick a difficulty and run the generator indefinatly while dumping completable seeds into a text file.  Lists are located in the CompletableSeeds folder." << endl;
		system("pause");
	}
	if(option == "DF"){
		cout << "df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df \n Here's your seed: 69696969 \n Exceptions: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99 \n  df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df df" << endl;
		system("pause");
	}


	mainMenu();
}


void newTest(bool print){
bool validSelection = false;

	apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	CheckFinishNormalNew(randoSeed, apNumbers);
	seedCounter++;
	while(!returnCompletableNormal()){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		CheckFinishNormalNew(randoSeed, apNumbers);
		seedCounter++;
}
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Normal_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!returnCompletableNormal()){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishNormalNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishNormalNew(randoSeed, apNumbers);
    seedCounter++;
      }
    }
  }
}

void newTestVeteran(bool print){
  bool validSelection = false;

  apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	CheckFinishVeteranNew(randoSeed, apNumbers);
	seedCounter++;
	while(!returnCompletableVeteran()){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		CheckFinishVeteranNew(randoSeed, apNumbers);
		seedCounter++;
}
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
  if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Veteran_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!returnCompletableVeteran()){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishVeteranNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishVeteranNew(randoSeed, apNumbers);
    seedCounter++;
  }

  }

}

}

void newTestEasy(bool print){
  bool validSelection = false;

  	apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	CheckFinishEasyNew(randoSeed, apNumbers);
	seedCounter++;
	while(!returnCompletableEasy()){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		CheckFinishEasyNew(randoSeed, apNumbers);
		seedCounter++;
}
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Easy_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!returnCompletableEasy()){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishEasyNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishEasyNew(randoSeed, apNumbers);
    seedCounter++;
  }

  }
 }
}

void newTestHypermode(bool print){
  bool validSelection = false;
  apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	CheckFinishHypermodeNew(randoSeed, apNumbers);
	seedCounter++;
	while(!returnCompletableHypermode()){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		CheckFinishHypermodeNew(randoSeed, apNumbers);
		seedCounter++;
}
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Hypermode_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!returnCompletableHypermode()){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishHypermodeNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishHypermodeNew(randoSeed, apNumbers);
    seedCounter++;
      }
    }
  }
}

void newNormalOnly(bool print){
  bool validSelection = false;

  	apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  bool seedGood = false;
  while(!seedGood){
  randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  seedCounter++;
  cout << "Current Seed: " << randoSeed << '\r' << flush;
  CheckFinishNormalNew(randoSeed, apNumbers);
  if(returnCompletableNormal()){
    CheckFinishEasyNew(randoSeed, apNumbers);
    if(!returnCompletableEasy()){
      seedGood = true;
    }
   }
  }
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Normal_Only_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!(returnCompletableNormal() && !returnCompletableEasy())){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishNormalNew(randoSeed, apNumbers);
    CheckFinishEasyNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishNormalNew(randoSeed, apNumbers);
    CheckFinishEasyNew(randoSeed, apNumbers);
    seedCounter++;
  }

  }

}

}


void newVeteranOnly(bool print){
  bool validSelection = false;

  	apvector<int> apNumbers(0);
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

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  bool seedGood = false;
  while(!seedGood){
  randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  seedCounter++;
  cout << "Current Seed: " << randoSeed << '\r' << flush;
  CheckFinishVeteranNew(randoSeed, apNumbers);
  if(returnCompletableVeteran()){
    CheckFinishNormalNew(randoSeed, apNumbers);
    if(!returnCompletableNormal()){
      seedGood = true;
    }
   }
  }
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Veteran_Only_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!(returnCompletableVeteran() && !returnCompletableNormal())){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishVeteranNew(randoSeed, apNumbers);
    CheckFinishNormalNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishVeteranNew(randoSeed, apNumbers);
    CheckFinishNormalNew(randoSeed, apNumbers);
    seedCounter++;
  }

  }
}
}


void newHypermodeOnly(bool print){
  bool validSelection = false;

  	apvector<int> apNumbers(0);
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



	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
    if(apNumbers[tran] > 99 || apNumbers[tran] < 0){
      tooLarge = true;
    }
	}
  validSelection = !tooLarge;
  if(!validSelection){
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
}
CurrentTime current_time;
int seedCounter = 0;
if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  bool seedGood = false;
  while(!seedGood){
  randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  seedCounter++;
  cout << "Current Seed: " << randoSeed << '\r' << flush;
  CheckFinishHypermodeNew(randoSeed, apNumbers);
  if(returnCompletableHypermode()){
    CheckFinishVeteranNew(randoSeed, apNumbers);
    if(!returnCompletableVeteran()){
      seedGood = true;
    }
   }
  }
clock_t end = clock();
double elapsed_secs = double(end-begin) / (CLOCKS_PER_SEC/100);
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
header1 = returnSeed();
header2 = returnExceptions();
if(fileExists(".\\Metroid Prime Randomizer.bat")){
  system("cls");
  cout << "Seed found!" << endl;
  cout << "Load Randomizer Script? (Y/N)" << endl;
  cout << "> ";
  string runScript;
  getline(cin, runScript);

  runScript = simplifyString(runScript);
if(runScript == "Y" || runScript == "YES"){
    system("cls");
    loadScript(randoSeed, apNumbers);
    system("cls");
    system("\"Metroid Prime Randomizer.bat\"");
  }
  }
}

else{
  int prevSeed = -1;
  system("md CompletableSeeds");
  system("cls");
  ofstream seedList;
  seedList.open(".\\CompletableSeeds\\Hypermode_Only_Seed_List.txt", ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  for(;;){ //infinite loop
  	while(!(returnCompletableHypermode() && !returnCompletableVeteran())){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
  	CheckFinishHypermodeNew(randoSeed, apNumbers);
    CheckFinishVeteranNew(randoSeed, apNumbers);
    seedCounter++;
  	}
  if(prevSeed != randoSeed){
  seedList << returnSeed() << " " << returnExceptions() << endl;
  prevSeed = randoSeed;
  resetFlags();
    }
  else{
    randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
    CheckFinishHypermodeNew(randoSeed, apNumbers);
    CheckFinishVeteranNew(randoSeed, apNumbers);
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

apvector <int> getTheExceptions(){

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);
	stringstream numStream(str);
	while (numStream >> x)
		numbers.push_back(x);

	sort(numbers.begin(), numbers.end());

	apvector<int> apNumbers(numbers.size());

	for(int tran = 0; tran < apNumbers.length(); tran++){
		apNumbers[tran] = numbers[tran];
	}
  return apNumbers;
}

void manualChecker(){
	bool tempVersion;
	string firstLine;




  cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";



  apvector <int> apNumbers = getTheExceptions();

  int inputSeed = getASeed();

	CheckFinishEasyNew(inputSeed, apNumbers);
		if(returnCompletableEasy()){
			cout << "Seed is completable (Easy Difficulty)" << endl;
			system("pause");
		}
		else{CheckFinishNormalNew(inputSeed, apNumbers);
			if(returnCompletableNormal()){
				cout << "Seed is completable (Normal Difficulty)" << endl;
				system("pause");
			}
			else{CheckFinishVeteranNew(inputSeed, apNumbers);
				if(returnCompletableVeteran()){
					cout << "Seed is completable (Veteren Difficulty)" << endl;
					system("pause");
				}
				else{CheckFinishHypermodeNew(inputSeed, apNumbers);
					if(returnCompletableHypermode()){
						cout << "Seed is completable (Hypermode Difficulty)" << endl;
						system("pause");
					}
					else{
						cout << "This seed is NOT completable (Easy through Hypermode)" << endl;
						system("pause");
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

	if(printOption == "1"){
		newTestEasy(true);
	}
	if(printOption == "2"){
		newTest(true);
	}
	if(printOption == "3"){
		newTestVeteran(true);
	}
	if(printOption == "4"){
		newTestHypermode(true);
	}
	if(printOption == "$1"){
		newTestEasy(true);
	}
	if(printOption == "$2"){
		newNormalOnly(true);
	}
	if(printOption == "$3"){
		newVeteranOnly(true);
	}
	if(printOption == "$4"){
		newHypermodeOnly(true);
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

void loadScript(int settingSeed, apvector <int> settingException){

  apvector <string> settingsLines(18, "");


  ifstream myfile;
  myfile.open(".\\tools\\settings.txt");

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

for(int bob = 0; bob < settingException.length(); bob++){
  if(bob == settingException.length() - 1){
    line += to_string(settingException[bob]);
  }
  else{line += to_string(settingException[bob]);
        line += ",";
      }
}
if(settingException.length() == 0){
  line += "none";
}

if(popup){
  line += " -h";
}

settingsLines[3] = line;
ofstream settingsFile;
settingsFile.open(".\\tools\\settings.txt");


for(int ziccardo = 0; ziccardo < settingsLines.length()-1; ziccardo++){
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

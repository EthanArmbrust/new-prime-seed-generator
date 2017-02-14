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
#include "windows.h"
#include "randomizerTime.h"

void mainMenu();
void processOption();
void manualChecker();
void printMenu();
bool fileExists(const std::string& fileName);
void getTimeAndSeedCount(double, int);
int getASeed();
vector <int> getTheExceptions();
void loadScript(int, vector <int>);
string simplifyString(string);
void multithreadTest(bool, int, bool);
string seedListName(int difficulty, bool only);





using namespace std;




string header1 = "			    Seed Generator v1.1";
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
  cout << multithreadingState;
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
		multithreadTest(false, 1, false);
	}
	if(option == "2"){
	   multithreadTest(false, 2, false);
	}
	if(option == "3"){
	   multithreadTest(false, 3, false);
	}
	if(option == "4"){
		multithreadTest(false, 4, false);
	}
	if(option == "5"){
    cout << "This will be added sometime in the future" << endl;
		cin.get();
	}
	if(option == "6"){
		manualChecker();
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

	if(option == "$2" || option == "$ 2"){
		multithreadTest(false, 2, true);
	}
	if(option == "$3" || option == "$ 3"){
		multithreadTest(false, 3, true);
	}

	if(option == "$4" || option == "$ 4"){
		multithreadTest(false, 4, true);
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
		cout << "This is a step up from the previous difficulty.  Players will be expected to be able to do all 22% tricks, as well as some of the easier 21% tricks.  A full list of item requirements can be found here: http://bombch.us/BNcM " << endl;
		cin.get();
	}
	if(option == "HELP4"){
		cout << "This difficulty requires the player to do pretty much everything, minus some very difficult tricks such as Life Grove 21%, Root Cave without Space Jump, and other tricks that you wish were never discovered. " << endl;
		cin.get();
	}
	if(option == "HELP5"){
		cout << "If it is possible, you might have to do it.  To be added soon." << endl;
		cin.get();
	}

	if(option == "HELP6"){
		cout << "Allows you to manually check a seed.  Enter the exceptions and the seed when prompted.  Will return the lowest possible difficulty that it is completable on." << endl;
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
    return ".\\CompletableSeeds\\Easy_Seed_List.txt";
  }
  if(difficulty == 2){
    if(only){
      return ".\\CompletableSeeds\\Normal_Only_Seed_List.txt";
    }
    else return ".\\CompletableSeeds\\Normal_Seed_List.txt";
  }
  if(difficulty == 3){
    if(only){
      return ".\\CompletableSeeds\\Veteran_Only_Seed_List.txt";
    }
    else return ".\\CompletableSeeds\\Veteran_Seed_List.txt";
  }
  if(difficulty == 4){
    if(only){
      return ".\\CompletableSeeds\\Hypermode_Only_Seed_List.txt";
    }
    else return ".\\CompletableSeeds\\Hypermode_Seed_List.txt";
  }
}


void barebonesSeedGen(vector<int> apNumbers, int difficulty, bool print, bool only, std::ofstream& seedList){
  int seedCounter = 0;
  CurrentTime current_time;
  LogChecker checker2;
  int randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647);
	checker2.difficultyCheck(difficulty,randoSeed,apNumbers);
	seedCounter++;

  if(!print){
  if(!only){
	while(!checker2.returnDifficulty(difficulty) && !mainThreadDone){
		randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
  	checker2.difficultyCheck(difficulty,randoSeed,apNumbers);
		seedCounter++;
    }
  }
  else{
    bool seedGood = false;
    while(!seedGood && !mainThreadDone){
    randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
    seedCounter++;
    checker2.difficultyCheck(difficulty,randoSeed, apNumbers);
    if(checker2.returnDifficulty(difficulty)){
      checker2.difficultyCheck(difficulty-1,randoSeed, apNumbers);
      if(!checker2.returnDifficulty(difficulty-1)){
        seedGood = true;
      }
     }
    }
  }
    if(!mainThreadDone){
      newThreadDone = true;
      header1 = checker2.returnSeed();
      }
    newThreadSeedCount = seedCounter;
  }
  else{
    if(!only){
      for(;;){
  	while(!checker2.returnDifficulty(difficulty)){
  		randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
    	checker2.difficultyCheck(difficulty,randoSeed,apNumbers);
  		seedCounter++;
      }
      seedList << checker2.returnSeed() << " " << checker2.returnExceptions()  << endl;
      randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
      checker2.difficultyCheck(difficulty,randoSeed,apNumbers);
     }
    }
    else{
      bool seedGood = false;
      for(;;){
      while(!seedGood){
      randoSeed = (int)((current_time.microseconds()+2000000) % (long) 2147483647) + seedCounter;
      seedCounter++;
      checker2.difficultyCheck(difficulty,randoSeed, apNumbers);
      if(checker2.returnDifficulty(difficulty)){
        checker2.difficultyCheck(difficulty-1,randoSeed, apNumbers);
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



void multithreadTest(bool print, int difficulty, bool only){
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
    system("cls");
    cout << "Invalid Selection.  Please try again" << endl;
  }
 }
 CurrentTime current_time;
 int seedCounter = 0;
 LogChecker checker;
 if(!print){

	clock_t begin = clock();

  system("cls");

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	checker.difficultyCheck(difficulty,randoSeed,apNumbers);
	seedCounter++;
  if(enableMultithreading){
  std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, std::ref(seedList));
  if(!only){
	while(!checker.returnDifficulty(difficulty) && !newThreadDone){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		checker.difficultyCheck(difficulty,randoSeed,apNumbers);
		seedCounter++;
  }
 }
 else {
   bool seedGood = false;
   while(!seedGood && !newThreadDone){
   randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
   seedCounter++;
   cout << "Current Seed: " << randoSeed << '\r' << flush;
   checker.difficultyCheck(difficulty,randoSeed, apNumbers);
   if(checker.returnDifficulty(difficulty)){
     checker.difficultyCheck(difficulty-1,randoSeed, apNumbers);
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
  checker.difficultyCheck(difficulty,randoSeed,apNumbers);
  seedCounter++;
}
}
else {
 bool seedGood = false;
 while(!seedGood && !newThreadDone){
 randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
 seedCounter++;
 cout << "Current Seed: " << randoSeed << '\r' << flush;
 checker.difficultyCheck(difficulty,randoSeed, apNumbers);
 if(checker.returnDifficulty(difficulty)){
   checker.difficultyCheck(difficulty-1,randoSeed, apNumbers);
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
getTimeAndSeedCount(elapsed_secs/100.0, seedCounter);
if(mainThreadDone){
  header1 = checker.returnSeed();
}
header2 = checker.returnExceptions();
mainThreadDone = false;
newThreadDone = false;
newThreadSeedCount = 0;

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
  system("mkdir CompletableSeeds");
  system("cls");
  seedList.open(seedListName(difficulty, only), ios::app);

  time_t now = time(0);
  char* dt = ctime(&now);

  seedList << "\nList segment started on  " << dt << endl;
  int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
  cout << "Looking for seeds..." << endl;
  if(enableMultithreading){
    std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, std::ref(seedList));
    t1.detach();}
  for(;;){ //infinite loop
    if(!only){
    while(!checker.returnDifficulty(difficulty) && !newThreadDone){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
      checker.difficultyCheck(difficulty,randoSeed,apNumbers);
      seedCounter++;
    }
    }
    else{
     bool seedGood = false;
     while(!seedGood && !newThreadDone){
     randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
     seedCounter++;
     cout << "Current Seed: " << randoSeed << '\r' << flush;
     checker.difficultyCheck(difficulty,randoSeed, apNumbers);
     if(checker.returnDifficulty(difficulty)){
       checker.difficultyCheck(difficulty-1,randoSeed, apNumbers);
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
    checker.CheckFinishNormalNew(randoSeed, apNumbers);
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

void manualChecker(){
	bool tempVersion;
	string firstLine;




  cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";



  vector <int> apNumbers = getTheExceptions();

  int inputSeed = getASeed();
  LogChecker checker;

	checker.CheckFinishEasyNew(inputSeed, apNumbers);
		if(checker.returnCompletableEasy()){
			cout << "Seed is completable (Easy Difficulty)" << endl;
      cout << "Press Enter to continue...";
			cin.ignore().get();
		}
		else{checker.CheckFinishNormalNew(inputSeed, apNumbers);
			if(checker.returnCompletableNormal()){
				cout << "Seed is completable (Normal Difficulty)" << endl;
        cout << "Press Enter to continue...";
				cin.ignore().get();
			}
			else{checker.CheckFinishVeteranNew(inputSeed, apNumbers);
				if(checker.returnCompletableVeteran()){
					cout << "Seed is completable (Veteren Difficulty)" << endl;
          cout << "Press Enter to continue...";
					cin.ignore().get();
				}
				else{checker.CheckFinishHypermodeNew(inputSeed, apNumbers);
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

	if(printOption == "1"){
		multithreadTest(true, 1, false);
	}
	if(printOption == "2"){
		multithreadTest(true, 2, false);
	}
	if(printOption == "3"){
		multithreadTest(true, 3, false);
	}
	if(printOption == "4"){
    multithreadTest(true, 4, false);

	}
	if(printOption == "$1"){
		multithreadTest(true, 1, false);
	}
	if(printOption == "$2"){
		multithreadTest(true, 2, true);
	}
	if(printOption == "$3"){
		multithreadTest(true, 3, true);
	}
	if(printOption == "$4"){
		multithreadTest(true, 4, true);
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
settingsFile.open(".\\tools\\settings.txt");


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

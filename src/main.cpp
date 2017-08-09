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
#include "BigInteger/BigUnsigned.hh"
#include "BigInteger/BigIntegerUtils.hh"
#include "BigInteger/BigUnsignedInABase.hh"
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
void manualChecker(bool verbose, bool noFloatyAllowed, bool noSpaceJump);
void printMenu();
void clearScreen();
bool fileExists(const std::string& fileName);
void getTimeAndSeedCount(double, int);
int getASeed();
void createLogFile();
vector <int> getTheExceptions();
void loadScript(int, vector <int>);
string simplifyString(string);
void multithreadTest(bool, int, bool, bool, bool);
string seedListName(int difficulty, bool only);
bool is_digits(const std::string &str);
bool stringParser(string input, string option);
int compute_checksum(BigUnsigned layout_number);
string encode_pickup_layout(vector<int> layout);
void convertSeed(bool noSpaceJump);





using namespace std;




string header1 = "			    Seed Generator v1.6 Beta 2017.8.7.01";
string header2 = "			        by Interslice";
string option;
string printOption;
string bottomHelp1 = "";
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
string permHeader1 = header1;





int main(int argc, char *argv[]){

  #if defined _WIN32 || defined _WIN64
  dirSeparator = "\\";
  #elif defined __APPLE__ || defined __linux__
  dirSeparator = "/";
  #endif


  ifstream userLogFile;
  userLogFile.open(argv[1]);

  string logHeader, logSeedNum, logExceptionsList;
  string showSpoilersOption;
  bool showSpoilers;

  if(userLogFile.is_open()){
    getline(userLogFile, logHeader);
    getline(userLogFile, logSeedNum);
    getline(userLogFile, logExceptionsList);

    clearScreen();

    cout << "Show item order spoilers? (Y/N)" << endl << ">";
    getline(cin, showSpoilersOption);

    showSpoilersOption = simplifyString(showSpoilersOption);
    showSpoilers = stringParser(showSpoilersOption, "Y");


  }
  else{
    mainMenu();
  }
  return 0;
}

void mainMenu(){

	clearScreen();
	cout << header1 << endl;
	cout << header2 << endl;
	cout << "1 - Generate an \"Easy\" difficulty seed \n \n";
	cout << "2 - Generate a \"Normal\" difficulty seed \n \n";
	cout << "3 - Generate a \"Veteran\" difficulty seed\n \n";
	cout << "4 - Generate a \"Hypermode\" difficulty seed\n \n";
	cout << "5 - Create a log file \n \n";
	cout << "6 - Check a seed \n \n";
	cout << "7 - Export seeds to text file \n \n";
  cout << multithreadingState;
  cout << "9 - Convert Seed to Layout\n \n";
  //cout << simplifyString(pretzels) << endl;
	cout << bottomHelp1 << endl;
	cout << bottomHelp2 << endl;
	cout << "> ";
	getline(cin, option);
	processOption();
}

void processOption(){
	clearScreen();
  string temp = simplifyString(option);
  option = temp;

  bool only = !(stringParser(option, "$"));
  bool noFloaty = stringParser(option, "-F");
  bool verbose = stringParser(option, "-V");
  bool noSpaceJump = stringParser(option, "-N");


  /*if(option == "L"){
    system("mkdir SeedGenLogs");
    clearScreen();
    createLogFile();
  }

  if(option == "S"){
    vector<int> bob {0,0,1,0,0,6,12,8,0,0,0,0,11,0,0,0,11,22,0,7,13,4,9,20,0,0,15,0,1,1,0,0,33,0,1,0,1,19,0,0,0,0,1,3,21,0,0,16,1,0,0,0,24,11,27,28,0,0,10,0,0,30,2,0,14,0,1,0,0,25,0,1,0,34,0,17,0,29,0,1,23,1,32,0,1,0,1,31,0,0,1,0,5,18,0,0,26,0,0,11};
    cout << encode_pickup_layout(bob) << endl;
    cin.get();
  }

  if(option == "D"){
    convertSeed();
  }
*/

	if(stringParser(option, "1") && !stringParser(option, "HELP")){
		multithreadTest(false, 1, false, false, false);
	}
	if(stringParser(option, "2") && !stringParser(option, "HELP")){
	   multithreadTest(false, 2, only, false, false);
	}
	if(stringParser(option, "3") && !stringParser(option, "HELP")){
	   multithreadTest(false, 3, only, noFloaty, false);
	}
	if(stringParser(option, "4") && !stringParser(option, "HELP")){
		multithreadTest(false, 4, only, noFloaty, noSpaceJump);
	}
	if(stringParser(option, "5") && !stringParser(option, "HELP")){
    system("mkdir SeedGenLogs");
    clearScreen();
    createLogFile();
	}
	if(stringParser(option, "6") && !stringParser(option, "HELP")){
		manualChecker(verbose, noFloaty, noSpaceJump);
	}
	if(stringParser(option, "7") && !stringParser(option, "HELP")){
		printMenu();
	}
  if(stringParser(option, "8") && !stringParser(option, "HELP")){
    enableMultithreading = !enableMultithreading;
    if(enableMultithreading){
      multithreadingState = "8 - Disable Multithreading \n \n";
    }
    else multithreadingState = "8 - Enable Multithreading \n \n";
  }

  if(stringParser(option, "9") && !stringParser(option, "HELP")){
    convertSeed(stringParser(option, "-N"));
  }


	if(stringParser(option, "1") && stringParser(option, "HELP")){
		cout << "This is the easiest difficulty seed.  These seeds can be completed with little to no sequence breaking.  Good for those unfamiliar with Metroid Prime speedrunning or if you are playing on a patched version of the game." << endl;
		cin.get();

	}
	if(stringParser(option, "2") && stringParser(option, "HELP")){
		cout << "This is the original rendition of the seed generator.  This difficulty will NOT require the player to do any Hyper Bomb Jumps or Uber Bomb Jumps, do a Suitless Magmoor run (except from the Tallon elevator to South Magmoor), do the Chozo floaty glitch without Space Jump, or any other stupid tricks.  Good for beginner speedrunners with moderate knowledge of sequence breaking.  A full list of item requirements can be found here: http://bombch.us/BNcL" << endl;
		cin.get();
	}
	if(stringParser(option, "3") && stringParser(option, "HELP")){
		cout << "This is a step up from the previous difficulty.  Players will be expected to be able to do all 22% tricks, as well as some of the easier 21% tricks.  A full list of item requirements can be found here: http://bombch.us/BNcM . Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(stringParser(option, "4") && stringParser(option, "HELP")){
		cout << "This difficulty requires the player to do pretty much everything, minus some very difficult tricks such as Life Grove 21%, Root Cave without Space Jump, and other tricks that you wish were never discovered. Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(stringParser(option, "5") && stringParser(option, "HELP")){
		cout << "Creates a log file in the folder \"SeedGenLogs\".  These logs are identical to the ones from the Randomizer, with the exception of the first line." << endl;
		cin.get();
	}

	if(stringParser(option, "6") && stringParser(option, "HELP")){
		cout << "Allows you to manually check a seed.  Enter the exceptions and the seed when prompted.  Will return the lowest possible difficulty that it is completable on. Use \"-v\" to get the item order list.  Use \"-f\" to prevent the seed from requiring floaty jump." << endl;
		cin.get();
	}
	if(stringParser(option, "$") && stringParser(option, "HELP")){
		cout << "Gives you a seed that is completable by the difficulty given or lower. For example, $5 will generate a seed that is completable by a \"Veteran\" player or lower. \n \n" << endl;
		cin.get();
	}
	if(stringParser(option, "7") && stringParser(option, "HELP")){
		cout << "Allows you to pick a difficulty and run the generator indefinatly while dumping completable seeds into a text file.  Lists are located in the \"CompletableSeeds folder\"." << endl;
		cin.get();
	}
  if(stringParser(option, "9") && stringParser(option, "HELP")){
		cout << "Allows you to convert a Claris Randomizer Seed to a Syncathetic Randomizer layout.  The Syncathetic Randomizer can be found here:\nhttps://github.com/aprilwade/randomprime" << endl;
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


void barebonesSeedGen(vector<int> apNumbers, int difficulty, bool print, bool only, bool noFloatyAllowed, bool noSpaceJump, std::ofstream& seedList){
  int seedCounter = 0;
  CurrentTime current_time;
  LogChecker checker2;
  int randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647); //1073741823 is half of INT_MAX
	checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed, noSpaceJump);
	seedCounter++;

  if(!print){
  if(!only){
	while(!checker2.returnDifficulty(difficulty) && !mainThreadDone){
		randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647) + seedCounter;
  	checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed, noSpaceJump);
		seedCounter++;
    }
  }
  else{
    bool seedGood = false;
    while(!seedGood && !mainThreadDone){
    randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647) + seedCounter;
    seedCounter++;
    checker2.difficultyCheck(difficulty,randoSeed, apNumbers, false, noFloatyAllowed, noSpaceJump);
    if(checker2.returnDifficulty(difficulty)){
      checker2.difficultyCheck(difficulty-1,randoSeed, apNumbers, false, noFloatyAllowed, noSpaceJump);
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
  		randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647) + seedCounter;
    	checker2.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed, noSpaceJump);
  		seedCounter++;
      }
      seedList << checker2.returnSeed() << " " << checker2.returnExceptions()  << endl;
      randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647) + seedCounter;
      checker2.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed, noSpaceJump);
     }
    }
    else{
      bool seedGood = false;
      for(;;){
      while(!seedGood){
      randoSeed = (int)((current_time.microseconds()+1073741823) % (long) 2147483647) + seedCounter;
      seedCounter++;
      checker2.difficultyCheck(difficulty, randoSeed, apNumbers, false, noFloatyAllowed, noSpaceJump);
      if(checker2.returnDifficulty(difficulty)){
        checker2.difficultyCheck(difficulty-1, randoSeed, apNumbers, false, noFloatyAllowed, noSpaceJump);
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



void multithreadTest(bool print, int difficulty, bool only, bool noFloatyAllowed, bool noSpaceJump){
  bool validSelection = false;

  ofstream seedList;
	vector<int> apNumbers(0);
  string str;
  while(!validSelection){

	cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";

  vector<int> numbers;

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

if(!(simplifyString(str) == "EXIT")){

 CurrentTime current_time;
 int seedCounter = 0;
 LogChecker checker;
 if(!print){

	clock_t begin = clock();

  clearScreen();

	cout << "Looking for a seed..." << endl;
	int randoSeed = (int)(current_time.microseconds() % (long) 2147483647);
	checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed, noSpaceJump);
	seedCounter++;
  if(enableMultithreading){
  std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, noFloatyAllowed, noSpaceJump, std::ref(seedList));
  if(!only){
	while(!checker.returnDifficulty(difficulty) && !newThreadDone){
		cout << "Current Seed: " << randoSeed << '\r' << flush;
		randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
		checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed, noSpaceJump);
		seedCounter++;
  }
 }
 else {
   bool seedGood = false;
   while(!seedGood && !newThreadDone){
   randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
   seedCounter++;
   cout << "Current Seed: " << randoSeed << '\r' << flush;
   checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
   if(checker.returnDifficulty(difficulty)){
     checker.difficultyCheck(difficulty-1,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
     if(!checker.returnDifficulty(difficulty-1)){
       checker.difficultyCheck(difficulty-2,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
       if(!checker.returnDifficulty(difficulty-2)){
       seedGood = true;
      }
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
  checker.difficultyCheck(difficulty,randoSeed,apNumbers, false, noFloatyAllowed, noSpaceJump);
  seedCounter++;
}
}
else {
 bool seedGood = false;
 while(!seedGood && !newThreadDone){
 randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
 seedCounter++;
 cout << "Current Seed: " << randoSeed << '\r' << flush;
 checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
 if(checker.returnDifficulty(difficulty)){
   checker.difficultyCheck(difficulty-1,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
   if(!checker.returnDifficulty(difficulty-1)){
     checker.difficultyCheck(difficulty-2,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
     if(!checker.returnDifficulty(difficulty-2)){
      seedGood = true;
    }
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
    std::thread t1(barebonesSeedGen, apNumbers, difficulty, print, only, noFloatyAllowed, noSpaceJump, std::ref(seedList));
    t1.detach();}
  for(;;){ //infinite loop
    if(!only){
    while(!checker.returnDifficulty(difficulty) && !newThreadDone){
      cout << "Current Seed: " << randoSeed << '\r' << flush;
      randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
      checker.difficultyCheck(difficulty,randoSeed,apNumbers,false, noFloatyAllowed, noSpaceJump);
      seedCounter++;
    }
    }
    else{
     bool seedGood = false;
     while(!seedGood && !newThreadDone){
     randoSeed = (int)(current_time.microseconds() % (long) 2147483647) + seedCounter;
     seedCounter++;
     cout << "Current Seed: " << randoSeed << '\r' << flush;
     checker.difficultyCheck(difficulty,randoSeed, apNumbers,false, noFloatyAllowed, noSpaceJump);
     if(checker.returnDifficulty(difficulty)){
       checker.difficultyCheck(difficulty-1,randoSeed, apNumbers, false, noFloatyAllowed, noSpaceJump);
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
}



int getASeed(){
  int inputSeed = -1;
  string str;
  cout << "Please enter the seed:" << endl;
  cout << "> ";
	getline(cin, str);

  str = simplifyString(str);

  while(str == ""){
    clearScreen();
    cout << "Error. Please enter a seed from 0 to 2147482647 or EXIT to return to the menu" << endl;
    cout << "> ";
    getline(cin,str);
    str = simplifyString(str);
  }

  if(stringParser(str, "EXIT")){
    return -1;
  }

  inputSeed = abs(stoi(str, nullptr));

  return inputSeed;
}

vector <int> getTheExceptions(){

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);

  if(stringParser(simplifyString(str), "EXIT")){
    vector<int> exiter(1);
    exiter[0] = -1;
    return exiter;
  }

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



void manualChecker(bool verbose, bool noFloatyAllowed, bool noSpaceJump){
	bool tempVersion;
	string firstLine;
  string excep;

  cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";

  vector <int> apNumbers = getTheExceptions();

  if(apNumbers.size() != 0){
  if(apNumbers[0] == -1){
    return;
  }
 }

  int inputSeed = getASeed();
  if(inputSeed == -1){
    return;
  }
  LogChecker checker;

	checker.CheckFinishEasyNew(inputSeed, apNumbers, verbose);
		if(checker.returnCompletableEasy()){
			cout << "Seed is completable (Easy Difficulty)" << endl;
      cout << "Press Enter to continue...";
			cin.get();
		}
		else{checker.CheckFinishNormalNew(inputSeed, apNumbers,verbose);
			if(checker.returnCompletableNormal()){
				cout << "Seed is completable (Normal Difficulty)" << endl;
        cout << "Press Enter to continue...";
				cin.get();
			}
			else{checker.CheckFinishVeteranNew(inputSeed, apNumbers, verbose, noFloatyAllowed);
				if(checker.returnCompletableVeteran()){
					cout << "Seed is completable";
          if(noFloatyAllowed){
            cout << " without Floaty";
          }
           cout << " (Veteran Difficulty)" << endl;
          cout << "Press Enter to continue...";
					cin.get();
				}
				else{checker.CheckFinishHypermodeNew(inputSeed, apNumbers, verbose, noFloatyAllowed, noSpaceJump);
					if(checker.returnCompletableHypermode()){
						cout << "Seed is completable";
            if(noSpaceJump){
            cout << " without Space Jump";
            }

            if(noSpaceJump && noFloatyAllowed){
              cout << " and";
            }

            if(noFloatyAllowed){
              cout << " without Floaty";
            }

            cout << " (Hypermode Difficulty)" << endl;
            cout << "Press Enter to continue...";
						cin.get();
					}
					else{
						cout << "This seed is NOT completable";
            if(noSpaceJump){
            cout << " without Space Jump";
            }
            if(noSpaceJump && noFloatyAllowed){
              cout << " and";
            }
            if(noFloatyAllowed){
              cout << " without Floaty";
            }
            cout << " (Easy through Hypermode)" << endl;
            cout << "Press Enter to continue...";
						cin.get();
					}
				}
			}
		}

	}


void printMenu(){
	cout << "Seeds and exceptions will be printed to a log file.  The seeds will be generated and recorded until the user stops the program. \n \n";
	cout << "Please select the difficulty.  Note that you may use the $ operator can be used here  See readme for details. \n \n";
	cout << "1 - Easy \n \n";
	cout << "2 - Normal \n \n";
	cout << "3 - Veteran \n \n";
	cout << "4 - Hypermode \n \n";
	cout << "EXIT - Return to Main Menu \n \n \n \n";
	cout << "> ";

	getline(cin, printOption);

  printOption = simplifyString(printOption);

  bool only = !(stringParser(printOption, "$"));
  bool noFloaty = stringParser(printOption, "-F");
  bool verbose = stringParser(printOption, "-V");
  bool noSpaceJump = stringParser(printOption, "-N");



	if(stringParser(printOption, "1")){
		multithreadTest(true, 1, false, false, false);
	}
	if(stringParser(printOption, "2")){
		multithreadTest(true, 2, only, false, false);
	}
	if(stringParser(printOption, "3")){
		multithreadTest(true, 3, only, noFloaty, false);
	}
	if(stringParser(printOption, "4")){
    multithreadTest(true, 4, only, noFloaty, noSpaceJump);
	}

	if(printOption == "EXIT"){
		return;
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
else {
	cout << "Couldn't find settings file.";
	cin.get();
	return;
}


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

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
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
  if(simplifyString(str) == "EXIT"){
    return;
  }
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
 if(simplifyString(str) == "EXIT"){
      return;
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

 logWriter << permHeader1.substr(7, permHeader1.size() - 7) << endl;
 //logWriter << "Seed Generator" << endl;
 logWriter << "Seed: " << seed << endl;
 logWriter << "Excluded pickups: ";

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
  cin.get();
}

bool stringParser(string input, string option){

  return input.find(option) != string::npos;
}

int compute_checksum(BigUnsigned layout_number){
  int s = 0;
  BigUnsigned b(32);
  BigUnsigned remainderToBe;
  while(layout_number > 0){
    layout_number.divideWithRemainder(b, remainderToBe);  //layout_number becomes remainder
    BigUnsigned swap;                                     //remainderToBe becomes quotient
    swap = remainderToBe;                                 //need to swap these
    remainderToBe = layout_number;
    layout_number = swap;
    s = (s + remainderToBe.toInt()) % 32;
  }
  return s;
}

string encode_pickup_layout(vector<int> layout){
  string TABLE = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklmnopqrstuwvxyz0123456789-_";
  BigUnsigned num(0);


  /*cout << layout.size() << " << layout size" << endl;
  cout << "layout 0: " << layout[0] << endl;
  cout << "layout 50: " << layout[50] << endl;
  cout << "layout 98: " << layout[98] << endl;
  cout << "layout 99: " << layout[99] << endl;
  */

  for(int i = 0; i < layout.size(); i++){
    //num = (num * 36) + layout[i];
    //cout << "i size: " << i << endl;
    //cout << "layout[i] = " << layout[i] << endl;
    num *= 36;
    num += layout[i];

  }
 //cout << "made num nice and big" << endl;


  int checksum = compute_checksum(num);
//  cout << "checksum " << checksum << endl;
  BigUnsigned bigChecksum(checksum);
  bigChecksum.bitShiftLeft(bigChecksum,517);
  num += bigChecksum;

  //cout << "num: " << bigUnsignedToString(num) << endl; //num is correct here

  string all_bits = bigUnsignedToString(num, 2);

  //cout << "all_bits: " << all_bits << endl;
  vector<char> even_bits(0);
  vector<char> odd_bits(0);

  for(int k = 0; k < all_bits.length(); k++){
    if(k % 2){
      odd_bits.push_back(all_bits.at(k));
    }
    else{
    even_bits.push_back(all_bits.at(k));
    }
  }
  odd_bits.shrink_to_fit();
  even_bits.shrink_to_fit();

 /*
  cout << "Even Bits: ";
  for(int bug = 0; bug < even_bits.size(); bug++){
    cout << even_bits[bug];
  }
  cout << " Size = " << even_bits.size();
  cout << "\n";

*/

  reverse(odd_bits.begin(), odd_bits.end());
  vector<char> all_bits_array(0);

  /*
  cout << "all_bits_array size = " << all_bits_array.size() << endl;

  cout << "Odd Bits: ";
  for(int bug = 0; bug < odd_bits.size(); bug++){
    cout << odd_bits[bug];
  }
  cout << " Size = " << odd_bits.size();
  cout << "\n";
  */

  for(int z = 0; z < even_bits.size(); z++){
    if(even_bits[z] == '1' || even_bits[z] == '0'){
    all_bits_array.push_back(even_bits[z]);}
    if(odd_bits[z] == '1' || odd_bits[z] == '0'){
    all_bits_array.push_back(odd_bits[z]);}
  }

  int invalidCount = 0;
  for(int badCount = 0; badCount < all_bits_array.size(); badCount++){
    if(!(all_bits_array[badCount] == '1' || all_bits_array[badCount] == '0')){
      invalidCount++;
    }
  }

  //cout << "invalidCount = " << invalidCount << endl;
  //cout << "all_bits_array size = " << all_bits_array.size() << endl;

  string all_bits_conversion = "";

  //cout << "Created all_bits_conversion" << endl;

  for(int t = 0; t < all_bits_array.size(); t++){
    all_bits_conversion += all_bits_array[t];
  }
  const std::string all_bits_const = all_bits_conversion;

  //cout << "moved bits from array to string" << endl;

  BigUnsignedInABase Lary(all_bits_const, 2);  //creates bigUnsigned in base 2

  //cout << "created Lary" << endl;

  BigUnsigned Jerry(Lary); //converts Lary to base 10 as Jerry

  string s = "";

  BigUnsigned b(64);
  BigUnsigned remainderToBe;
  for(int countEightySeven = 0; countEightySeven < 87; countEightySeven++){

    Jerry.divideWithRemainder(b, remainderToBe);          //Jerry becomes remainder
    BigUnsigned swap;                                     //remainderToBe becomes quotient
    swap = remainderToBe;                                 //need to swap these
    remainderToBe = Jerry;
    Jerry = swap;

    s = s + TABLE[remainderToBe.toInt()];
  }

  return s;
}

void convertSeed(bool noSpaceJump){
  bool validSelection = false;
	vector<int> apNumbers(0);
  while(!validSelection){

	cout << "Enter exception numbers seperated by spaces (leave blank for no exceptions) " << endl;
	cout << "> ";

  vector<int> numbers;
	string str;
	int x;

	getline(cin, str);
  if(simplifyString(str) == "EXIT"){
    return;
  }
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
   cout << seed;
 }
 if(simplifyString(str) == "EXIT"){
      return;
 }

 LogChecker logGen;
 vector<string> gameLog = logGen.generateLog(apNumbers, seed);

 vector<int> logLayout(100, -1);

 for(int bob = 2; bob < 102; bob++){

   if(gameLog[bob].substr(51, 5) == "Missi"){
     logLayout[bob-2] = 0;
   }
   if(gameLog[bob].substr(51, 5) == "Energ"){
     logLayout[bob-2] = 1;
   }
   if(gameLog[bob].substr(51,5) == "Therm"){
     logLayout[bob-2] = 2;
   }
   if(gameLog[bob].substr(51,5) == "X-Ray"){
     logLayout[bob-2] = 3;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Varia Suit"){
     logLayout[bob-2] = 4;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Gravity Suit"){
     logLayout[bob-2] = 5;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Phazon Suit"){
     logLayout[bob-2] = 6;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Morph Ball"){
     logLayout[bob-2] = 7;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Boost Ball"){
     logLayout[bob-2] = 8;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Spider Ball"){
     logLayout[bob-2] = 9;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Morph Ball Bomb"){
     logLayout[bob-2] = 10;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 53) == "Power Bomb Expansion"){
     logLayout[bob-2] = 11;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Power Bomb"){
     logLayout[bob-2] = 12;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Charge Beam"){
     logLayout[bob-2] = 13;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Space Jump Boots"){
     logLayout[bob-2] = !noSpaceJump ? 14 : 35;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Grapple Beam"){
     logLayout[bob-2] = 15;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Super Missile"){
     logLayout[bob-2] = 16;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Wavebuster"){
     logLayout[bob-2] = 17;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Ice Spreader"){
     logLayout[bob-2] = 18;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Flamethrower"){
     logLayout[bob-2] = 19;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Wave Beam"){
     logLayout[bob-2] = 20;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Ice Beam"){
     logLayout[bob-2] = 21;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Plasma Beam"){
     logLayout[bob-2] = 22;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Lifegiver"){
     logLayout[bob-2] = 23;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Wild"){
     logLayout[bob-2] = 24;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of World"){
     logLayout[bob-2] = 25;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Sun"){
     logLayout[bob-2] = 26;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Elder"){
     logLayout[bob-2] = 27;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Spirit"){
     logLayout[bob-2] = 28;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Truth"){
     logLayout[bob-2] = 29;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Chozo"){
     logLayout[bob-2] = 30;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Warrior"){
     logLayout[bob-2] = 31;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Newborn"){
     logLayout[bob-2] = 32;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Nature"){
     logLayout[bob-2] = 33;
   }
   if(gameLog[bob].substr(51,gameLog[bob].length() - 51) == "Artifact of Strength"){
     logLayout[bob-2] = 34;
   }
 }
cout << "\n\nLayout: \n" << endl;
cout << encode_pickup_layout(logLayout) << "\n" <<endl;
cout << "Press Enter to return to the main menu...";
cin.get();

}

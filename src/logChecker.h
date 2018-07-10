#include <vector>
#include <string>
#include "BigInteger/BigUnsigned.hh"

using namespace std;

class LogChecker{
private:
  std::vector<bool> isAdded;
  std::vector<bool> earlyMinesIsAdded;
  std::vector<bool> deepMinesIsAdded;
  std::vector<bool> deepPhenIsAdded;
  std::vector<string> obItems;
  std::vector<string> earlyMinesItems;
  std::vector<string> deepMinesItems;
  std::vector<string> deepPhenItems;
  string seedString;
  string seedExceptions;
  int a = 0;
  int e = 0;
  int art = 0;
  int lineLength;
  bool isCompletableEasy = false;
  bool isCompletableNormal = false;
  bool isCompletableVeteran = false;
  bool isCompletableHypermode = false;
  bool firstCheck = true;
  bool hasMissiles = false;
  bool hasMorph = false;
  bool hasBombs = false;
  bool hasSuit = false;
  bool hasBoost = false;
  bool hasSJ = false;
  bool hasGrapple = false;
  bool hasVaria = false;
  bool hasPhazon = false;
  bool hasGravity = false;
  bool hasPB = false;
  bool hasWave = false;
  bool hasIce = false;
  bool hasPlasma = false;
  bool hasSpider = false;
  bool hasXray = false;
  bool hasCharge = false;
  bool hasSuper = false;
  bool hasThermal = false;

  bool earlyMinesSJ = false;
  bool earlyMinesSpider = false;
  bool earlyMinesPB = false;
  bool earlyMinesPlasma = false;
  bool earlyMinesGravity = false;
  bool earlyMinesBoost = false;

  bool deepMinesSJ = false;
  bool deepMinesSpider = false;
  bool deepMinesPB = false;
  bool deepMinesXray = false;
  bool deepMinesPlasma = false;
  bool deepMinesCharge = false;
  bool deepMinesSuper = false;
  bool deepMinesPhazon = false;
  bool deepMinesGrapple = false;
  bool deepMinesBoost = false;
  bool deepMinesGravity = false;

  bool deepPhenBombs = false;
  bool deepPhenPlasma = false;
  bool deepPhenSJ = false;
  bool deepPhenGravity = false;
  bool deepPhenGrapple = false;
  bool deepPhenPB = false;
  bool bombsWithoutGravity = false;

  bool checkObtainedItems(bool verbose, vector<string> logline, bool noSpaceJump);
  void checkEarlyMines();
  void checkDeepMines();
  void checkFrigate();
  void checkDeepPhen();
  void countArtifacts();
  bool isHundo();
  string getItemLocation(vector<string>, string, int);


public:
LogChecker();
void difficultyCheck(int, int, vector<int>, bool, bool, bool);
vector <string> generateLog(vector<int>, int);
void CheckFinishNormalNew(int seed, vector <int> inExceptions, bool verbose);
void CheckFinishNormalNew(vector<string> newItems, bool verbose);
void CheckFinishNormalNew(string layout, bool verbose);

void CheckFinishVeteranNew(int seed, vector <int> exceptions, bool verbose, bool noFloatyAllowed);
void CheckFinishVeteranNew(string layout, bool verbose, bool noFloatyAllowed);
void CheckFinishVeteranNew(vector<string> newItems, bool verbose, bool noFloatyAllowed);

void CheckFinishEasyNew(int seed, vector <int> exceptions, bool verbose);
void CheckFinishEasyNew(string layout, bool verbose);
void CheckFinishEasyNew(vector <string> newItems, bool verbose);

void CheckFinishHypermodeNew(int seed, vector <int> exceptions, bool verbose, bool noFloatyAllowed, bool noSpaceJump);
void CheckFinishHypermodeNew(vector<string> newItems, bool verbose, bool noFloatyAllowed, bool noSpaceJump);
void CheckFinishHypermodeNew(string layout, bool verbose, bool noFloatyAllowed, bool noSpaceJump);
void benchmark(int randomizeCount);
void apvectorBenchmark(int count);
void printList();
void checkerSetup();
bool returnDifficulty(int);
bool returnCompletableVeteran();
bool returnCompletableNormal();
bool returnCompletableEasy();
bool returnCompletableHypermode();
void resetFlags();
string returnSeed();
string returnExceptions();
vector <string> getItemNames();
vector <string> getAreaNames();
vector <int> shrinkIntVector(vector <int> inVector);
vector <int> removeIntElement(vector <int> inVector, int element);
vector <string> shrinkStringVector(vector <string> inVector);
vector <string> removeStringElement(vector <string> inVector, int element);
//int compute_checksum_2(BigUnsigned layout_number);
//vector<int> decode_pickup_layout(string layout_string);
//vector<string> layoutIntToString(vector<int> intLayout);
vector <string> randomize(vector <string> originalList, vector <int> excludedItems, int seed);
}
;

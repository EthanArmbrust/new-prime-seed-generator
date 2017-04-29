#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Random.h"
#include "logChecker.h"
using namespace std;

LogChecker::LogChecker(){
	vector<bool> temp1(400, false);
	isAdded = temp1;
	vector<bool> temp2(7, false);
  earlyMinesIsAdded = temp2;
	vector<bool> temp3(9, false);
  deepMinesIsAdded = temp3;
	vector<bool> temp4(4, false);
  deepPhenIsAdded = temp4;
	vector<string> temp5(400, "");
  obItems = temp5;
	vector<string> temp6(7, "");
  earlyMinesItems = temp6;
	vector<string> temp7(9, "");
  deepMinesItems = temp7;
	vector<string> temp8(4,"");
  deepPhenItems = temp8;

}

void LogChecker::checkerSetup(){

}

void LogChecker::benchmark(int randomizeCount){

	vector <int> noExceptions(0);
	vector <string> itemInput(100, "");
	itemInput = getItemNames();
	for(int i = 0; i < randomizeCount; i++){
		vector <string> randoVector = randomize(itemInput, noExceptions, 42069 + i);

	}
}

void LogChecker::apvectorBenchmark(int count){
	for(int i = 0; i < count; i++){
		vector<string> test(100, "");
		for(int z = 0; z < 100; z++){
			test[z] = to_string(z);
		}
	}
}

void LogChecker::difficultyCheck(int difficulty, int seed, vector <int> exceptions, bool verbose, bool noFloatyAllowed){
	if(difficulty == 1){
		this->CheckFinishEasyNew(seed, exceptions, verbose);
	}
	if(difficulty == 2){
		this->CheckFinishNormalNew(seed, exceptions, verbose);
	}
	if(difficulty == 3){
		this->CheckFinishVeteranNew(seed, exceptions, verbose, noFloatyAllowed);
	}
	if(difficulty == 4){
		this->CheckFinishHypermodeNew(seed, exceptions, verbose, noFloatyAllowed);
	}
}

bool LogChecker::returnDifficulty(int difficulty){
	if(difficulty == 1){
	 return	this->returnCompletableEasy();
	}
	if(difficulty == 2){
		return	this->returnCompletableNormal();
	}
	if(difficulty == 3){
		return	this->returnCompletableVeteran();
	}
	if(difficulty == 4){
		return	this->returnCompletableHypermode();
	}
}

vector <string> LogChecker::generateLog(vector <int> exceptions, int seed){

	vector <string> itemInput(100, "");
	vector <string> areaInput(100, "");

	vector <string> logline(104, "");
	itemInput = getItemNames();


	areaInput = getAreaNames();

  vector <string> newItems = randomize(itemInput, exceptions, seed);



	for(int zorro = 2; zorro < logline.size()-2; zorro++){
		 logline[zorro] = areaInput[zorro-2] + newItems[zorro-2];
		// lineLength = logline[zorro].size() - 51;
		 //items[zorro] = logline[zorro].substr(51,lineLength);
	 }

		 return logline;
}


void LogChecker::CheckFinishNormalNew(int seed, vector <int> inExceptions, bool verbose){

if(verbose){
	cout << "Item order for Normal difficulty: " << endl;
}

bool newRando = true;
vector <string> items(104, "");
vector <string> logline(104, "");
vector <string> itemInput(100, "");
vector <string> areaInput(100, "");
vector <int> exceptions(inExceptions);
isCompletableNormal = false;

int k = 0; //for adding items to obtained list
int w = 0; //for traversing the item requirements
int z = 0; //for debugging
int m = 0; //more debugging
int resetter = 0;
a = 0;

while(resetter < 104){
	isAdded[resetter] = false;
	resetter++;
}

resetter = 0;


while(resetter < 105){
	obItems[resetter]	= "";
	resetter++;
}



	//resetting item bools
	hasMissiles = false;
	hasMorph = false;
	hasBombs = false;
	hasSuit = false;
	hasBoost = false;
	hasSJ = false;
	hasGrapple = false;
	hasVaria = false;
	hasPhazon = false;
	hasGravity = false;
	hasPB = false;
	hasWave = false;
	hasIce = false;
	hasPlasma = false;
	hasSpider = false;
	hasXray = false;
	hasCharge = false;
	hasSuper = false;

	earlyMinesSJ = false;
	earlyMinesSpider = false;
	earlyMinesPB = false;
	earlyMinesPlasma = false;



	itemInput = getItemNames();


	areaInput = getAreaNames();

  vector <string> newItems = randomize(itemInput, exceptions, seed);



	for(int zorro = 2; zorro < logline.size()-2; zorro++){
		 logline[zorro] = areaInput[zorro-2] + newItems[zorro-2];
		 lineLength = logline[zorro].size() - 51;
		 items[zorro] = logline[zorro].substr(51,lineLength);}


  firstCheck = true;
	while (checkObtainedItems(verbose, logline)){


	if(!isAdded[21]){
	obItems[k] = items[21];
	isAdded[21] = true;
	k++;}

	if(!isAdded[61]){
	obItems[k] = items[61];
	isAdded[61] = true;
	k++;}
	//cout << obItems[0] << " and " << obItems[1] << endl;
	//cout << isAdded[21] << " and " << isAdded[61] << " and " << isAdded[52] << endl;

	//THE INDEX FOR EACH ITEM IN FOR items AND isAdded is EQUAL TO n + 2 WHERE n IS THE ITEM NUMBER IN THE RANDOMIZER README
	//EX. items[2] = Main Plaza (Half-Pipe) , isAdded[61] = Alcove
	//I know it's dumb, and I apologize


	if(hasMorph && hasBoost || hasSJ){
	if(!isAdded[2]){
		obItems[k] = items[2];
		isAdded[2] = true;
		k++;}
	}
	if(hasGrapple || hasSJ){
	if(!isAdded[3]){
		obItems[k] = items[3];
		isAdded[3] = true;
		k++;}
	}
	if(hasMissiles && hasSuper && hasCharge){
	if(!isAdded[4]){
		obItems[k] = items[4];
		isAdded[4] = true;
		k++;}
	}
	if(hasMorph && hasMissiles || hasSJ){
	if(!isAdded[5]){
		obItems[k] = items[5];
		isAdded[5] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSpider){
	if(!isAdded[6]){
		obItems[k] = items[6];
		isAdded[6] = true;
		k++;}
	}
	if(hasMissiles && (hasMorph || items[7] == "Morph" || items[7] == "Morph Ball" || hasSJ || items[7] == "Space" || items[7] == "Space Jump Boots")){
	if(!isAdded[7]){
		obItems[k] = items[7];
		isAdded[7] = true;
		k++;}
	}
	if(hasMissiles && hasMorph){
	if(!isAdded[8]){
		obItems[k] = items[8];
		isAdded[8] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && hasBombs || hasMissiles && hasMorph && hasPB){
	if(!isAdded[9]){
		obItems[k] = items[9];
		isAdded[9] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[10]){
		obItems[k] = items[10];
		isAdded[10] = true;
		k++;}
	}
	if(items[11] == "Boost" || "Wave " || "Boost Ball" || "Wave Beam"){
	if(hasMorph && hasBombs && hasSJ){
	if(!isAdded[11]){
		obItems[k] = items[11];
		isAdded[11] = true;
		k++;}
	}
	}
	if((hasMorph && hasBombs && hasSJ && (hasBoost || hasWave)) || (hasWave && hasMorph && (hasSuit || e  >= 1) && hasGrapple && hasSpider && hasBoost)) {
	if(!isAdded[11]){
		obItems[k] = items[11];
		isAdded[11] = true;
		k++;}
	}
	if(hasBombs && hasMorph){
	if(!isAdded[12]){
		obItems[k] = items[12];
		isAdded[12] = true;
		k++;}
	}
	if(hasWave && hasMorph && hasSuit && hasGrapple || hasWave && hasMorph && hasSuit && hasSJ || hasWave && hasMorph && hasSJ && e >= 2){
	if(!isAdded[13]){
		obItems[k] = items[13];
		isAdded[13] = true;
		k++;}
	}
	if(hasMorph && hasPB && hasSJ && hasSuit || hasMorph && hasPB && hasGrapple && hasSuit || hasMorph && hasPB && hasSJ && e >= 3){
	if(!isAdded[14]){
		obItems[k] = items[14];
		isAdded[14] = true;
		k++;}
	}
	if(hasMissiles && hasWave && hasSJ){
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}
	if(hasMissiles && hasWave && (hasMorph || hasSJ)){
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[17]){
		obItems[k] = items[17];
		isAdded[17] = true;
		k++;}
	}
	if(hasMorph && hasBombs){
	if(!isAdded[18]){
		obItems[k] = items[18];
		isAdded[18] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[19]){
		obItems[k] = items[19];
		isAdded[19] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[20]){
		obItems[k] = items[20];
		isAdded[20] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[22]){
		obItems[k] = items[22];
		isAdded[22] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[23]){
		obItems[k] = items[23];
		isAdded[23] = true;
		k++;}
	}
	if(hasMissiles && hasMorph){
	if(!isAdded[24]){
		obItems[k] = items[24];
		isAdded[24] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[25]){
		obItems[k] = items[25];
		isAdded[25] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[26]){
		obItems[k] = items[26];
		isAdded[26] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && (hasBombs || hasPB)){
	if(!isAdded[27]){
		obItems[k] = items[27];
		isAdded[27] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && hasSpider && (hasBombs || hasPB)){
	if(!isAdded[28]){
		obItems[k] = items[28];
		isAdded[28] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasPB && (items[29] == "Bombs" || items[29] == "Morph Ball Bomb" || hasBombs)){
	if(!isAdded[29]){
		obItems[k] = items[29];
		isAdded[29] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(items[30] == "Bombs" || items[29] == "Bombs" || items[30] == "Morph Ball Bomb" || items[29] == "Morph Ball Bomb" || hasBombs){
	if(!isAdded[30]){
		obItems[k] = items[30];
		isAdded[30] = true;
		k++;}
	}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasSpider || hasMissiles && hasMorph && hasBombs && hasPB && hasBoost && hasSpider){
	if(!isAdded[31]){
		obItems[k] = items[31];
		isAdded[31] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[32]){
		obItems[k] = items[32];
		isAdded[32] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ || hasMissiles && hasMorph && hasBombs && hasIce && hasSpider){
	if(!isAdded[33]){
		obItems[k] = items[33];
		isAdded[33] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ || hasMissiles && hasMorph && hasBombs && hasBoost && hasCharge && hasSuper && hasSpider && (hasWave || hasIce)){
	if(!isAdded[34]){
		obItems[k] = items[34];
		isAdded[34] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPlasma && (hasSJ || hasSpider)){
	if(!isAdded[35]){
		obItems[k] = items[35];
		isAdded[35] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && (hasSJ || hasIce) || hasMissiles && hasMorph && hasBombs && hasWave && hasSpider && hasBoost){
	if(!isAdded[36]){
		obItems[k] = items[36];
		isAdded[36] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && (hasBoost || hasPlasma) || hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasBoost || hasPlasma)){
	if(!isAdded[37]){
		obItems[k] = items[37];
		isAdded[37] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && (hasSuit || hasWave) && hasCharge && hasSuper&& hasSpider){
	if(!isAdded[38]){
		obItems[k] = items[38];
		isAdded[38] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && (hasBoost || hasPlasma) || hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasPlasma || hasBoost)){
	if(!isAdded[39]){
		obItems[k] = items[39];
		isAdded[39] = true;
		k++;}
	}
	if(items[40] == "Space" || items[40] == "Space Jump Boots"){
	if(hasMissiles && hasMorph && hasBombs && hasPlasma && (hasSuit || (hasWave && hasSpider))){
	if(!isAdded[40]){
		obItems[k] = items[40];
		isAdded[40] = true;
		k++;}
	}
	}
	if(hasMissiles && hasMorph && hasBombs && hasPlasma && hasSJ && (hasSuit || hasWave)){
	if(!isAdded[40]){
		obItems[k] = items[40];
		isAdded[40] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && (hasPlasma || hasBoost) && (hasSuit || (hasWave && (hasSJ || hasSpider)))){
	if(!isAdded[41]){
		obItems[k] = items[41];
		isAdded[41] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasSuit && hasBombs && hasSpider){
	if(!isAdded[42]){
		obItems[k] = items[42];
		isAdded[42] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && (hasSuit || (e >= 1 && hasWave)) && ((hasBombs && hasSuit) || ((hasSJ || hasSpider) && hasWave))){
	if(!isAdded[43]){
		obItems[k] = items[43];
		isAdded[43] = true;
		k++;}
	if(!isAdded[45]){
		obItems[k] = items[45];
		isAdded[45] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || hasSpider || hasSJ) && (hasSuit || e >= 1) && hasWave){
	if(!isAdded[44]){
		obItems[k] = items[44];
		isAdded[44] = true;
		k++;}
	}

	if(items[46] == "Space" || "Spide" || "Grapp" || "Space Jump Boots" || "Spider Ball" || "Grapple Beam"){
	if(hasMissiles && hasMorph && (hasSuit || e >= 1) && hasWave){
	if(!isAdded[46]){
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}
	}

	if(hasMissiles && hasMorph && (hasSuit  || e >= 1) && hasWave && (hasSJ || hasGrapple || hasSpider)){
	if(!isAdded[46]){
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}


	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasWave && hasCharge
	&& hasSuper){
	if(!isAdded[47]){
		obItems[k] = items[47];
		isAdded[47] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSuit || e >=1) && (hasSJ || hasGrapple)){
	if(!isAdded[48]){
		obItems[k] = items[48];
		isAdded[48] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasSJ){
	if(!isAdded[49]){
		obItems[k] = items[49];
		isAdded[49] = true;
		k++;}
	if(!isAdded[52]){
		obItems[k] = items[52];
		isAdded[52] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasSuit || e >= 1) && hasWave && hasIce && hasPlasma && (hasSJ || hasSpider)){
	if(!isAdded[50]){
		obItems[k] = items[50];
		isAdded[50] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasPlasma && hasWave && hasIce && hasSpider || hasMissiles && hasMorph && hasBombs && hasWave && hasSJ){
	if(!isAdded[51]){
		obItems[k] = items[51];
		isAdded[51] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || (hasSpider && hasIce))){
	if(!isAdded[52]){
		obItems[k] = items[52];
		isAdded[52] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasSJ && hasWave && hasIce){
	if(!isAdded[53]){
		obItems[k] = items[53];
		isAdded[53] = true;
		k++;}
		}

	if(hasMissiles && hasMorph && hasBombs && hasGrapple && hasSpider && hasWave && hasIce){
	if(items[53] == "Space"){
	if(!isAdded[53]){
		obItems[k] = items[53];
		isAdded[53] = true;
		k++;}
		}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasPhazon){
		if(!isAdded[90]){
			obItems[k] = items[90];
			isAdded[90] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ){
		if(!isAdded[89]){
			obItems[k] = items[89];
			isAdded[89] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPB && hasSJ){
		if(!isAdded[88]){
			obItems[k] = items[88];
			isAdded[88] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasCharge && hasSuper){
		if(!isAdded[87]){
			obItems[k] = items[87];
			isAdded[87] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasSJ){
		if(!isAdded[86]){
			obItems[k] = items[86];
			isAdded[86] = true;
			k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasXray && hasSJ){
		if(!isAdded[85]){
			obItems[k] = items[85];
			isAdded[85] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPlasma && hasSJ && hasPB){
		if(!isAdded[84]){
			obItems[k] = items[84];
			isAdded[84] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || items[83] == "Space" || items[83] == "Space Jump Boots") && hasIce && hasPB){
		if(!isAdded[83]){
			obItems[k] = items[83];
			isAdded[83] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && (hasSJ || hasBoost || items[82] == "Space" || items[82] == "Boost" || items[82] == "Space Jump Boots" || items[82] == "Boost Ball") && hasPB){
		if(!isAdded[82]){
			obItems[k] = items[82];
			isAdded[82] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ){
		if(!isAdded[81]){
			obItems[k] = items[81];
			isAdded[81] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce){
		if(!isAdded[80]){
			obItems[k] = items[80];
			isAdded[80] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && hasSJ && hasPlasma){
		if(!isAdded[79]){
			obItems[k] = items[79];
			isAdded[79] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && hasPlasma){
		if(!isAdded[78]){
			obItems[k] = items[78];
			isAdded[78] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce){
		if(!isAdded[77]){
			obItems[k] = items[77];
			isAdded[77] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB){
		if(!isAdded[76]){
			obItems[k] = items[76];
			isAdded[76] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSpider || hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasSJ){
		if(!isAdded[75]){
			obItems[k] = items[75];
			isAdded[75] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSJ && hasBoost || hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider && hasBoost){
		if(!isAdded[74]){
			obItems[k] = items[74];
			isAdded[74] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB || hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider){
		if(!isAdded[73]){
			obItems[k] = items[73];
			isAdded[73] = true;
			k++;}
	}


	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB || hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider){
		if(items[72] == "Boost"){
		if(!isAdded[72]){
			obItems[k] = items[72];
			isAdded[72] = true;
			k++;}
	}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB && hasBoost || hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider && hasBoost){
		if(!isAdded[72]){
			obItems[k] = items[72];
			isAdded[72] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB){
		if(!isAdded[71]){
			obItems[k] = items[71];
			isAdded[71] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce || hasMissiles && hasMorph && hasBombs && hasIce && hasGravity){
		if(!isAdded[70]){
			obItems[k] = items[70];
			isAdded[70] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasCharge && hasIce && hasSuper){
		if(!isAdded[69]){
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce){
		if(!isAdded[68]){
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ || hasMissiles && hasSJ && hasPlasma){
		if(!isAdded[67]){
			obItems[k] = items[67];
			isAdded[67] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[66]){
			obItems[k] = items[66];
			isAdded[66] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[65]){
			obItems[k] = items[65];
			isAdded[65] = true;
			k++;}
	}

	if(hasMissiles && hasSJ){
		if(!isAdded[64]){
			obItems[k] = items[64];
			isAdded[64] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || hasSJ) && hasIce){
		if(!isAdded[63]){
			obItems[k] = items[63];
			isAdded[63] = true;
			k++;}
	}

	if(hasMissiles && hasMorph){
		if(!isAdded[62]){
			obItems[k] = items[62];
			isAdded[62] = true;
			k++;}
	}

	if(hasMorph){
		if(!isAdded[60]){
			obItems[k] = items[60];
			isAdded[60] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasWave && hasIce && hasSJ){
		if(!isAdded[59]){
			obItems[k] = items[59];
			isAdded[59] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasIce && hasSJ && hasPlasma && hasPB){
		if(!isAdded[58]){
			obItems[k] = items[58];
			isAdded[58] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ || hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPlasma && hasGrapple){
		if(!isAdded[57]){
			obItems[k] = items[57];
			isAdded[57] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ){
		if(!isAdded[56]){
			obItems[k] = items[56];
			isAdded[56] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || (hasSpider && hasIce && hasBombs))){
		if(!isAdded[55]){
			obItems[k] = items[55];
			isAdded[55] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || (hasSpider && hasIce))){
		if(!isAdded[54]){
			obItems[k] = items[54];
			isAdded[54] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma
	&& hasPB && hasSJ){
	if(!isAdded[91]){
		obItems[k] = items[91];
		isAdded[91] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasSuit){
	if(!isAdded[92]){
		obItems[k] = items[92];
		isAdded[92] = true;
		k++;}
	if(!isAdded[93]){
		obItems[k] = items[93];
		isAdded[93] = true;
		k++;}
	if(!isAdded[94]){
		obItems[k] = items[94];
		isAdded[94] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[95]){
		obItems[k] = items[95];
		isAdded[95] = true;
		k++;}
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}

	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasPB && hasSuit || hasMissiles && hasMorph && hasBombs && hasSuit && hasBoost && e >= 3){
	if(!isAdded[97]){
		obItems[k] = items[97];
		isAdded[97] = true;
		k++;}
	}

	if(hasMissiles && hasSuit && hasMorph && hasBombs || hasMissiles && hasSuit && hasSJ){
	if(!isAdded[98]){
		obItems[k] = items[98];
		isAdded[98] = true;
		k++;}
	}

	 if(hasMissiles && hasSuit && hasMorph && hasBombs && hasPB || hasMissiles && hasSuit && hasSJ && hasMorph && hasPB){
	if(!isAdded[99]){
		obItems[k] = items[99];
		isAdded[99] = true;
		k++;}
	}

	if(items[100] == "Plasm" || items[100] == "Plasma Beam"){
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasBoost && hasWave && hasIce){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasBoost && hasWave && hasIce && hasPlasma){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave){
	if(!isAdded[101]){
		obItems[k] = items[101];
		isAdded[101] = true;
		k++;}
	}


	w++;
	}

	countArtifacts();
	//cout << "Num of Artifacts " << a <<endl;

	if(a == 12 && hasWave && hasIce && hasPlasma && hasMissiles && hasSJ && hasPhazon)
		isCompletableNormal = true;

	int outSeed = seed;
	string newSeed = to_string(outSeed);
	seedString = "Seed: " + newSeed;

	string listOfExceptions = "";
	for(int zork = 0; zork < exceptions.size(); zork++){
	    listOfExceptions += to_string(exceptions[zork]);
			listOfExceptions += " ";
	}


	seedExceptions = "Exceptions: " + listOfExceptions;
	if(exceptions.size() == 0){
		seedExceptions = "Exceptions: None";
	}

	//if(isCompletableNormal){
		//cout << "This is completable" << endl;
		//if(isHundo())
		//cout << "This seed is completable with 100% items" <<endl;
		//else cout << "This seed is NOT completable with 100% items" << endl;
		 //}

		 if(verbose){
			 cout << "\n" << endl;
		 }

}

void LogChecker::CheckFinishVeteranNew(int seed, vector <int> inExceptions, bool verbose, bool noFloatyAllowed){

	if(verbose){
		cout << "Item order for Veteran difficulty: " << endl;
	}


vector <string> items(104, "");
vector <string> logline(104, "");
vector <string> itemInput(100, "");
vector <string> areaInput(100, "");
vector <int> exceptions(inExceptions);
isCompletableVeteran = false;

int k = 0; //for adding items to obtained list
int earl = 0; //for adding items to early mines
int bob = 0; //for adding items to deep mines
int w = 0; //for traversing the item requirements
int z = 0; //for debugging
int m = 0; //more debugging
int resetter = 0;
bool hasFloaty = false;
bool earlyMinesEscape = false;
bool deepMinesEscape = false;
a = 0;

while(resetter < 104){
	isAdded[resetter] = false;
	resetter++;
}

resetter = 0;


while(resetter < 200){
	obItems[resetter] = "";
	resetter++;
}
resetter = 0;

while(resetter < 6){
	earlyMinesItems[resetter] = "";
	resetter++;
}

resetter = 0;

while(resetter < 6){
	earlyMinesIsAdded[resetter] = false;
	resetter++;
}

resetter = 0;

while(resetter < 9){
	deepMinesItems[resetter] = "";
	resetter++;
}
resetter = 0;






	//resetting item bools
	hasMissiles = false;
	hasMorph = false;
	hasBombs = false;
	hasSuit = false;
	hasBoost = false;
	hasSJ = false;
	hasGrapple = false;
	hasVaria = false;
	hasPhazon = false;
	hasGravity = false;
	hasPB = false;
	hasWave = false;
	hasIce = false;
	hasPlasma = false;
	hasSpider = false;
	hasXray = false;
	hasCharge = false;
	hasSuper = false;

	earlyMinesSJ = false;
	earlyMinesSpider = false;
	earlyMinesPB = false;
	earlyMinesPlasma = false;
	earlyMinesGravity = false;
	earlyMinesBoost = false;

	deepMinesSJ = false;
	deepMinesSpider = false;
	deepMinesPB = false;
	deepMinesXray = false;
	deepMinesPlasma = false;
	deepMinesCharge = false;
	deepMinesSuper = false;
	deepMinesGrapple = false;
	deepMinesPhazon = false;

	bombsWithoutGravity = false;



	itemInput = getItemNames();


	areaInput = getAreaNames();

	vector <string> newItems = randomize(itemInput, exceptions, seed);



	for(int zorro = 2; zorro < logline.size()-2; zorro++){
		 logline[zorro] = areaInput[zorro-2] + newItems[zorro-2];
		 lineLength = logline[zorro].size() - 51;
		 items[zorro] = logline[zorro].substr(51,lineLength);}


	firstCheck = true;
	while(checkObtainedItems(verbose, logline)){

	checkEarlyMines();
	checkDeepMines();


	//FLOATY CHECK
	if(!noFloatyAllowed){
	if(!(items[22] == "Gravi" || items[22] == "Gravity Suit")){
	if(items[92] == "Bombs" || items[92] == "Morph Ball Bomb" || items[93] == "Bombs" || items[93] == "Morph Ball Bomb" || items[94] == "Bombs" || items[94] == "Morph Ball Bomb" || items[96] == "Bombs" || items[96] == "Morph Ball Bomb" || items[97] == "Bombs" || items[97] == "Morph Ball Bomb" || items[98] == "Bombs" || items[98] == "Morph Ball Bomb" || items[99] == "Bombs" || items[99] == "Morph Ball Bomb" || items[101] == "Bombs" || items[101] == "Morph Ball Bomb" || items[96] == "Morph" || items[96] == "Morph Ball" || items[98] == "Morph" || items[98] == "Morph Ball"){
			if(hasVaria || hasPhazon){
				if(!((items[29] == "Bombs" || items[29] == "Morph Ball Bomb") && (items[30] == "Gravi" || items[30] == "Gravity Suit"))){
					if(hasMissiles && hasMorph && hasBombs && bombsWithoutGravity){
						hasFloaty = true;
					}
					else hasFloaty = false;
				}
				else hasFloaty = false;
			}
			else hasFloaty = false;

		}
		else if(!((items[29] == "Bombs" || "Morph Ball Bomb") && (items[30] == "Gravi" || items[30] == "Gravity Suit"))){
					if(hasMissiles && hasMorph && hasBombs && bombsWithoutGravity){
						hasFloaty = true;
					}
					else hasFloaty = false;
				}
				else hasFloaty = false;
	}
	else hasFloaty = false;
}

	//EARLY MINES ESCAPE CHECK

	//EARLY MINES ARRAY VALUES
	// [0] = MAIN QUARRY
	// [1] = SECURITY ACCESS A
	// [2] = STORAGE DEPOT B
	// [3] = STORAGE DEPOT A
	// [4] = ELITE RESEARCH (LAZER)
	// [5] = ELITE CONTROL ACCESS
	// [6] = PHAZON PROCESSING CENTER

	if(hasSJ || hasGravity || hasBoost || (hasPB && hasSpider)){
		earlyMinesEscape = true;
	}
	if(earlyMinesSJ || earlyMinesGravity || earlyMinesBoost || (earlyMinesPB && earlyMinesSpider)){
		earlyMinesEscape = true;
	}

	if((hasSpider && earlyMinesPB) || (earlyMinesSpider && hasPB)){
		earlyMinesEscape = true;
	}

	if(hasSpider || earlyMinesSpider || hasSJ || earlyMinesSJ){
	if(!earlyMinesIsAdded[0]){
		earlyMinesItems[earl] = items[75];
		earlyMinesIsAdded[0] = true;
		earl++;
	}
	}
	if(!earlyMinesIsAdded[1]){
		earlyMinesItems[earl] = items[76];
		earlyMinesIsAdded[1] = true;
		earl++;}

	if(!earlyMinesIsAdded[2]){
		earlyMinesItems[earl] = items[77];
		earlyMinesIsAdded[2] = true;
		earl++;}

	if((hasPlasma || earlyMinesPlasma) && (hasPB || earlyMinesPB)){
		if(!earlyMinesIsAdded[3]){
		earlyMinesItems[earl] = items[78];
		earlyMinesIsAdded[3] = true;
		earl++;}
	}

	if(!earlyMinesIsAdded[4]){
		earlyMinesItems[earl] = items[80];
		earlyMinesIsAdded[4] = true;
		earl++;}

	if(!earlyMinesIsAdded[5]){
		earlyMinesItems[earl] = items[81];
		earlyMinesIsAdded[5] = true;
		earl++;}

	if(hasPB || earlyMinesPB){
		if(!earlyMinesIsAdded[6]){
		earlyMinesItems[earl] = items[83];
		earlyMinesIsAdded[6] = true;
		earl++;}
	}


	//DEEP MINES ESCAPING

	//DEEP MINES ARRAY NUMBERS
	//[0] = VENT SHAFT
	//[1] = PROCESSING CENTER ACCESS
	//[2] = ELITE QUARTERS
	//[3] = CENTRAL DYNAMO
	//[4] = METROID QUARENTINE B
	//[5] = METROID QUARENTINE A
	//[6] = FUNGAL HALL B
	//[7] = PHAZON MINING TUNNEL
	//[8] = FUNGAL HALL ACCESS

	if((hasPB || deepMinesPB) && ((hasSJ || deepMinesSJ) || ((hasBoost || deepMinesBoost) && (hasSpider || deepMinesSpider)))){
		deepMinesEscape = true;
	}

	if((hasSJ || deepMinesSJ) || (hasBoost || deepMinesBoost)){
		deepMinesEscape = true;
	}

	if((hasPB || deepMinesPB) && (hasPlasma || deepMinesPlasma) && (hasXray || deepMinesXray) && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		deepMinesEscape = true;
	}

	if(hasPB || deepMinesPB){
		if(!deepMinesIsAdded[0]){
		deepMinesItems[bob] = items[82];
		deepMinesIsAdded[0] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && (hasXray || deepMinesXray) && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[1]){
		deepMinesItems[bob] = items[84];
		deepMinesIsAdded[1] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && (hasXray || deepMinesXray) && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[2]){
		deepMinesItems[bob] = items[85];
		deepMinesIsAdded[2] = true;
		bob++;}
	}

	if(!deepMinesIsAdded[3]){
		deepMinesItems[bob] = items[86];
		deepMinesIsAdded[3] = true;
		bob++;}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && (hasCharge || deepMinesCharge) && (hasSuper && deepMinesSuper) && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[4]){
		deepMinesItems[bob] = items[87];
		deepMinesIsAdded[4] = true;
		bob++;}
	}

	if(hasPB || deepMinesPB){
		if(!deepMinesIsAdded[5]){
		deepMinesItems[bob] = items[88];
		deepMinesIsAdded[5] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)  && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[6]){
		deepMinesItems[bob] = items[89];
		deepMinesIsAdded[6] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)  && ((hasPhazon || deepMinesPhazon) || (e >= 8)) && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[7]){
		deepMinesItems[bob] = items[90];
		deepMinesIsAdded[7] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)  && ((hasSJ || deepMinesSJ) || ((hasSpider || deepMinesSpider) && (hasGrapple || deepMinesGrapple)))){
		if(!deepMinesIsAdded[8]){
		deepMinesItems[bob] = items[91];
		deepMinesIsAdded[8] = true;
		bob++;}
	}





	if(!isAdded[21]){
	obItems[k] = items[21];
	isAdded[21] = true;
	k++;}

	if(!isAdded[61]){
	obItems[k] = items[61];
	isAdded[61] = true;
	k++;}
	//cout << obItems[0] << " and " << obItems[1] << endl;
	//cout << isAdded[21] << " and " << isAdded[61] << " and " << isAdded[52] << endl;


	if((hasMorph && (hasBoost || hasBombs)) || hasSJ){
	if(!isAdded[2]){
		obItems[k] = items[2];
		isAdded[2] = true;
		k++;}
	}
	if(hasGrapple || hasSJ || hasFloaty){
	if(!isAdded[3]){
		obItems[k] = items[3];
		isAdded[3] = true;
		k++;}
	}
	if(hasMissiles && hasSuper && hasCharge){
	if(!isAdded[4]){
		obItems[k] = items[4];
		isAdded[4] = true;
		k++;}
	}
	if((hasMorph && hasMissiles) || hasSJ){
	if(!isAdded[5]){
		obItems[k] = items[5];
		isAdded[5] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasSpider) || hasFloaty){
	if(!isAdded[6]){
		obItems[k] = items[6];
		isAdded[6] = true;
		k++;}
	}

	if(items[7] == "Morph" || "Space" || "Morph Ball" || "Space Jump Boots"){
	if(hasMissiles){
	if(!isAdded[7]){
		obItems[k] = items[7];
		isAdded[7] = true;
		k++;}
	}
	}

	if(hasMissiles && (hasSJ || hasMorph)){
	if(!isAdded[7]){
		obItems[k] = items[7];
		isAdded[7] = true;
		k++;}
	}

	if(hasMissiles && hasMorph){
	if(!isAdded[8]){
		obItems[k] = items[8];
		isAdded[8] = true;
		k++;}
	}
	if((hasMorph && hasMissiles && hasBombs) || (hasMissiles && hasMorph && hasPB)){
	if(!isAdded[9]){
		obItems[k] = items[9];
		isAdded[9] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[10]){
		obItems[k] = items[10];
		isAdded[10] = true;
		k++;}
	}

	if((hasWave && hasMorph && hasSuit && hasGrapple && hasSpider && hasBoost && hasBombs) || (hasWave && hasMorph && hasSJ && (hasSuit || e >= 2) && hasSpider && hasBoost && hasBombs) || (hasMorph && hasBombs && hasSJ && hasBoost && hasSpider) || hasFloaty){
	if(!isAdded[11]){
		obItems[k] = items[11];
		isAdded[11] = true;
		k++;}
	}
	if(hasBombs && hasMorph){
	if(!isAdded[12]){
		obItems[k] = items[12];
		isAdded[12] = true;
		k++;}
	}
	if((hasWave && hasMorph && hasSuit && hasGrapple && hasBombs) || (hasMorph && hasBombs && hasSJ && hasWave) || (hasFloaty && hasWave)){
	if(!isAdded[13]){
		obItems[k] = items[13];
		isAdded[13] = true;
		k++;}
	}
	if((hasPB && hasMorph && hasSuit && hasGrapple && hasBombs) || (hasPB && hasMorph && hasBombs && hasSJ && (hasSuit || e >= 2)) || (hasMorph && hasBombs && hasSJ && hasWave && hasPB) || (hasFloaty && hasWave && hasPB)){
	if(!isAdded[14]){
		obItems[k] = items[14];
		isAdded[14] = true;
		k++;}
	}
	if(items[15] == "Wave " || "Wave Beam"){
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}
	}


	if(hasMissiles && hasWave && (hasSJ || (hasMorph && hasBombs))){
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}

	if(items[16] == "Wave " || "Wave Beam"){
	if(hasMorph && hasBombs && hasBoost && (hasSJ || hasMissiles)){
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}

	}
	}

	if(hasMissiles && hasWave && (hasMorph || hasSJ)){
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[17]){
		obItems[k] = items[17];
		isAdded[17] = true;
		k++;}
	}
	if(hasMorph && hasBombs){
	if(!isAdded[18]){
		obItems[k] = items[18];
		isAdded[18] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[19]){
		obItems[k] = items[19];
		isAdded[19] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && (hasBombs || (hasPB && hasSJ))){
	if(!isAdded[20]){
		obItems[k] = items[20];
		isAdded[20] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[22]){
		obItems[k] = items[22];
		isAdded[22] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[23]){
		obItems[k] = items[23];
		isAdded[23] = true;
		k++;}
	}
	if(hasMissiles && hasMorph){
	if(!isAdded[24]){
		obItems[k] = items[24];
		isAdded[24] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[25]){
		obItems[k] = items[25];
		isAdded[25] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[26]){
		obItems[k] = items[26];
		isAdded[26] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && (hasBombs || hasPB)){
	if(!isAdded[27]){
		obItems[k] = items[27];
		isAdded[27] = true;
		k++;}
	}
	if((hasMorph && hasMissiles && hasSpider && (hasBombs || hasPB)) || hasFloaty){
	if(!isAdded[28]){
		obItems[k] = items[28];
		isAdded[28] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && (hasBombs || (hasPB && (items[29] == "Bombs" || items[29] == "Morph Ball Bomb" || items[30] == "Bombs" || items[30] == "Morph Ball Bomb")))){
	if(!isAdded[29]){
		obItems[k] = items[29];
		isAdded[29] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || items[30] == "Bombs" || items[30] == "Morph Ball Bomb")){
	if(!isAdded[30]){
		obItems[k] = items[30];
		isAdded[30] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSJ || (hasPB && hasBoost && hasSpider))) || hasFloaty){
	if(!isAdded[31]){
		obItems[k] = items[31];
		isAdded[31] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[32]){
		obItems[k] = items[32];
		isAdded[32] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ || hasMissiles && hasMorph && hasBombs && hasIce && hasSpider){
	if(!isAdded[33]){
		obItems[k] = items[33];
		isAdded[33] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasBoost && hasCharge && hasSuper && hasSpider && (hasWave || hasIce)) || hasFloaty){
	if(!isAdded[34]){
		obItems[k] = items[34];
		isAdded[34] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasIce && hasPlasma && (hasSJ || hasSpider)) || (hasMorph && hasBombs && hasMissiles && hasBoost)){
	if(!isAdded[35]){
		obItems[k] = items[35];
		isAdded[35] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && (hasSJ || hasIce)) || (hasMissiles && hasMorph && hasBombs && hasWave && hasSpider)){
	if(!isAdded[36]){
		obItems[k] = items[36];
		isAdded[36] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasPlasma || hasBoost)){
	if(!isAdded[37]){
		obItems[k] = items[37];
		isAdded[37] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasCharge && hasSuper && hasSpider)){
	if(!isAdded[38]){
		obItems[k] = items[38];
		isAdded[38] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasPlasma || hasBoost)){
	if(!isAdded[39]){
		obItems[k] = items[39];
		isAdded[39] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasPlasma)){
	if(!isAdded[40]){
		obItems[k] = items[40];
		isAdded[40] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasPlasma || hasBoost)){
	if(!isAdded[41]){
		obItems[k] = items[41];
		isAdded[41] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && (hasSpider || hasBoost)){
	if(!isAdded[42]){
		obItems[k] = items[42];
		isAdded[42] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1)))){
	if(!isAdded[43]){
		obItems[k] = items[43];
		isAdded[43] = true;
		k++;}
	if(!isAdded[45]){
		obItems[k] = items[45];
		isAdded[45] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >=5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && hasWave){
	if(!isAdded[44]){
		obItems[k] = items[44];
		isAdded[44] = true;
		k++;}
	}

	if(items[46] == "Space" || "Spide" || "Grapp" || "Space Jump Boots" || "Spider Ball" || "Grapple Beam"){
	if(hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave){
	if(!isAdded[46]){
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}
	}

	if(hasMissiles && hasMorph && (hasBombs || hasSJ) && (hasSuit || e >= 1) && hasWave && (hasSJ || hasGrapple || hasSpider)){
	if(!isAdded[46]){
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}


	if(((hasMissiles && hasMorph && hasBombs && (hasSuit || (hasSJ && e >= 5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider) && (hasSuit || e >= 1))) && hasWave && hasCharge && hasSuper){
	if(!isAdded[47]){
		obItems[k] = items[47];
		isAdded[47] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || hasSJ) && hasWave && (hasSuit || e >= 1) && (hasGrapple || hasSJ)){
	if(!isAdded[48]){
		obItems[k] = items[48];
		isAdded[48] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && (hasSJ || hasSpider))){
	if(!isAdded[49]){
		obItems[k] = items[49];
		isAdded[49] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasPlasma && hasWave && hasIce && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasPlasma && hasWave && hasIce && hasSpider)){
	if(!isAdded[50]){
		obItems[k] = items[50];
		isAdded[50] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && (hasSJ || (hasSpider && hasPlasma)))){
	if(!isAdded[51]){
		obItems[k] = items[51];
		isAdded[51] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && hasSpider)){
	if(!isAdded[52]){
		obItems[k] = items[52];
		isAdded[52] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasWave && (hasSuit || e >= 1) && hasIce && (hasGrapple || hasSJ)){
	if(!isAdded[53]){
		obItems[k] = items[53];
		isAdded[53] = true;
		k++;}
		}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && (hasSJ || (hasSpider && hasGrapple)) && (hasPhazon || e >= 8) && deepMinesEscape){
		if(!isAdded[90]){
			obItems[k] = items[90];
			isAdded[90] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && (hasSJ || (hasSpider && hasGrapple)) && deepMinesEscape){
		if(!isAdded[89]){
			obItems[k] = items[89];
			isAdded[89] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPB && (hasSJ || (hasSpider && hasGrapple)) && deepMinesEscape){
		if(!isAdded[88]){
			obItems[k] = items[88];
			isAdded[88] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && (hasSJ || (hasSpider && hasGrapple)) && hasCharge && hasSuper && deepMinesEscape){
		if(!isAdded[87]){
			obItems[k] = items[87];
			isAdded[87] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && deepMinesEscape){
		if(!isAdded[86]){
			obItems[k] = items[86];
			isAdded[86] = true;
			k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasXray && (hasSJ || (hasSpider && hasGrapple)) && deepMinesEscape){
		if(!isAdded[85]){
			obItems[k] = items[85];
			isAdded[85] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasXray && (hasSJ || (hasSpider && hasGrapple)) && deepMinesEscape){
		if(!isAdded[84]){
			obItems[k] = items[84];
			isAdded[84] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && deepMinesEscape){
		if(!isAdded[83]){
			obItems[k] = items[83];
			isAdded[83] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && deepMinesEscape){
		if(!isAdded[82]){
			obItems[k] = items[82];
			isAdded[82] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){
		if(!isAdded[81]){
			obItems[k] = items[81];
			isAdded[81] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){
		if(!isAdded[80]){
			obItems[k] = items[80];
			isAdded[80] = true;
			k++;}
	}

	if(isAdded[86]){
		if(!isAdded[79]){
			obItems[k] = items[79];
			isAdded[79] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && hasPlasma && earlyMinesEscape){
		if(!isAdded[78]){
			obItems[k] = items[78];
			isAdded[78] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){
		if(!isAdded[77]){
			obItems[k] = items[77];
			isAdded[77] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && earlyMinesEscape){
		if(!isAdded[76]){
			obItems[k] = items[76];
			isAdded[76] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSpider) || (hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasSJ) && earlyMinesEscape){
		if(!isAdded[75]){
			obItems[k] = items[75];
			isAdded[75] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider)){
		if(!isAdded[74]){
			obItems[k] = items[74];
			isAdded[74] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB) || (hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider)){
		if(!isAdded[73]){
			obItems[k] = items[73];
			isAdded[73] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasPB) || (hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSpider)){
		if(!isAdded[72]){
			obItems[k] = items[72];
			isAdded[72] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce){
		if(!isAdded[71]){
			obItems[k] = items[71];
			isAdded[71] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasWave && hasIce && (hasBoost || items[70] == "Boost" || items[70] == "Gravity" || items[70] == "Boost Ball" || items[70] == "Gravity Suit")) || (hasMissiles && hasMorph && hasBombs && hasIce && hasGravity)){
		if(!isAdded[70]){
			obItems[k] = items[70];
			isAdded[70] = true;
			k++;}
	}

	if(items[69] == "Wave " || "Wave Beam")
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasCharge && hasSuper && (hasBoost || hasGravity || items[68] == "Boost" || items[68] == "Gravi" || items[68] == "Boost Ball" || items[68] == "Gravity Suit")){
		if(!isAdded[69]){
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(items[68] == "Wave " || "Wave Beam")
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasCharge && hasSuper && (hasBoost || hasGravity)){
		if(!isAdded[69]){
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasCharge && hasSuper && (hasBoost || hasGravity || hasSJ)){
		if(!isAdded[69]){
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && (hasBoost || hasGravity || hasSJ)){
	if(!isAdded[68]){
		obItems[k] = items[68];
		isAdded[68] = true;
		k++;}
	}


	if(items[68] == "Gravi" || items[68] == "Space" || items[68] == "Boost" || items[68] == "Gravity Suit" || items[68] == "Space Jump Boots" || items[68] == "Boost Ball"){
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave){
		if(!isAdded[68]){
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}
	}


	if(items[68] == "Wave " || "Wave Beam"){
	if(hasMissiles && hasMorph && hasBombs && hasIce && (hasBoost || ((items[69] == "Boost" || items[69] == "Boost Ball") && hasSuper && hasCharge) || ((hasGravity || ((items[69] == "Gravi" || "Gravity Suit") && hasSuper && hasCharge)) && (hasSJ || ((items[69] == "Space" || "Space Jump Boots") && hasCharge && hasSuper))))){
		if(!isAdded[68]){
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}
	}
	if((hasMissiles && hasMorph && hasBombs && hasSJ) || (hasMissiles && hasSJ && hasPlasma) ){
		if(!isAdded[67]){
			obItems[k] = items[67];
			isAdded[67] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[66]){
			obItems[k] = items[66];
			isAdded[66] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[65]){
			obItems[k] = items[65];
			isAdded[65] = true;
			k++;}
	}

	if(hasMissiles && hasSJ){
		if(!isAdded[64]){
			obItems[k] = items[64];
			isAdded[64] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce){
		if(!isAdded[63]){
			obItems[k] = items[63];
			isAdded[63] = true;
			k++;}
	}

	if(hasMissiles && hasMorph){
		if(!isAdded[62]){
			obItems[k] = items[62];
			isAdded[62] = true;
			k++;}
	}

	if(hasMorph){
		if(!isAdded[60]){
			obItems[k] = items[60];
			isAdded[60] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasIce && hasSJ){
		if(!isAdded[59]){
			obItems[k] = items[59];
			isAdded[59] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && hasSJ && hasPB && hasPlasma){
		if(!isAdded[58]){
			obItems[k] = items[58];
			isAdded[58] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && (hasSJ || (hasSpider && hasGrapple && hasPlasma))){
		if(!isAdded[57]){
			obItems[k] = items[57];
			isAdded[57] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && (hasSJ || (hasSpider && (items[56] == "Space" || "Space Jump Boots")))){
		if(!isAdded[56]){
			obItems[k] = items[56];
			isAdded[56] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && hasSpider)){
		if(!isAdded[55]){
			obItems[k] = items[55];
			isAdded[55] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSuit || e >= 1) && hasWave && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || e >= 1) && hasIce && hasSpider)){
		if(!isAdded[54]){
			obItems[k] = items[54];
			isAdded[54] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && (hasSJ || (hasSpider && hasGrapple)) && deepMinesEscape){
	if(!isAdded[91]){
		obItems[k] = items[91];
		isAdded[91] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasSuit){
	if(!isAdded[92]){
		obItems[k] = items[92];
		isAdded[92] = true;
		k++;}
	if(!isAdded[93]){
		obItems[k] = items[93];
		isAdded[93] = true;
		k++;}
	if(!isAdded[94]){
		obItems[k] = items[94];
		isAdded[94] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[95]){
		obItems[k] = items[95];
		isAdded[95] = true;
		k++;}
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}

	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasPB && hasSuit) || (hasMissiles && hasMorph && hasBombs && hasSuit && hasBoost && e >= 3)){
	if(!isAdded[97]){
		obItems[k] = items[97];
		isAdded[97] = true;
		k++;}
	}

	if(hasMissiles && hasSuit && hasMorph && hasBombs || hasMissiles && hasSuit && hasSJ){
	if(!isAdded[98]){
		obItems[k] = items[98];
		isAdded[98] = true;
		k++;}
	}

	 if((hasMissiles && hasSuit && hasMorph && hasBombs && hasPB) || (hasMissiles && hasSuit && hasSJ && (items[99] == "Bombs" || "Morph Ball Bomb") && hasMorph && hasPB)){
	if(!isAdded[99]){
		obItems[k] = items[99];
		isAdded[99] = true;
		k++;}
	}

	if(items[100] == "Plasm" || "Plasma Beam"){
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasBoost && (hasSuit || e >= 1) && hasWave && hasIce){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasBoost && hasWave && (hasSuit || e >= 1) && hasIce && hasPlasma){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSuit || e >= 1)){
	if(!isAdded[101]){
		obItems[k] = items[101];
		isAdded[101] = true;
		k++;}
	}


	w++;
	}
	//cout << obItems[0] << " and " << obItems[1] << " and " << obItems[2] <<
	//" and " << obItems[3] << " and " << obItems[4] << " and " << obItems[5] <<
	//" and " << obItems[6] << " and " << obItems[7] << " and " << obItems[8] <<
	//" and " << obItems[9] << " and " << obItems[10] << " and " << obItems[11] <<
	//" and " << obItems[12] << " and " << obItems[13] << " and " << obItems[14] <<
	//" and " << obItems[15] << endl;


	/*
	while(z < 110){
	cout << obItems[z] << '\n';
	z++;}
	cout << k << endl;
	*/
	/*while(m < 102){
	cout << isAdded[m] << '\n';
	m++;}
	m = 0;

	while(m < 102){
	cout << obItems[m] << '\n';
	m++;}
	m = 0;
	*/
	countArtifacts();
	//cout << "Num of Artifacts " << a <<endl;

	if(a == 12 && hasWave && hasIce && hasPlasma && hasMissiles && hasSJ && hasPhazon)
		isCompletableVeteran = true;

	int outSeed = seed;
	string newSeed = to_string(outSeed);
	seedString = "Seed: " + newSeed;

	string listOfExceptions = "";
	for(int zork = 0; zork < exceptions.size(); zork++){
	    listOfExceptions += to_string(exceptions[zork]);
			listOfExceptions += " ";
	}


	seedExceptions = "Exceptions: " + listOfExceptions;
	if(exceptions.size() == 0){
		seedExceptions = "Exceptions: None";
	}


	if(verbose){
		cout << "\n" << endl;
	}



}

void LogChecker::CheckFinishEasyNew(int seed, vector <int> inExceptions, bool verbose){

	if(verbose){
		cout << "Item order for Easy difficulty: " << endl;
	}

vector <string> items(104, "");
vector <string> logline(104, "");
vector <string> itemInput(100, "");
vector <string> areaInput(100, "");
vector <int> exceptions(inExceptions);
isCompletableEasy = false;

int k = 0; //for adding items to obtained list
int w = 0; //for traversing the item requirements
int z = 0; //for debugging
int m = 0; //more debugging
int resetter = 0;
a = 0;

while(resetter < 103){
	isAdded[resetter] = false;
	resetter++;
}

resetter = 0;


while(resetter < 105){
	obItems[resetter] = "";
	resetter++;
}



	//resetting item bools
	hasMissiles = false;
	hasMorph = false;
	hasBombs = false;
	hasSuit = false;
	hasBoost = false;
	hasSJ = false;
	hasGrapple = false;
	hasVaria = false;
	hasPhazon = false;
	hasGravity = false;
	hasPB = false;
	hasWave = false;
	hasIce = false;
	hasPlasma = false;
	hasSpider = false;
	hasXray = false;
	hasCharge = false;
	hasSuper = false;
	hasThermal = false;

	earlyMinesSJ = false;
	earlyMinesSpider = false;
	earlyMinesPB = false;
	earlyMinesPlasma = false;

	itemInput = getItemNames();


	areaInput = getAreaNames();

  vector <string> newItems = randomize(itemInput, exceptions, seed);



	for(int zorro = 2; zorro < logline.size()-2; zorro++){
		 logline[zorro] = areaInput[zorro-2] + newItems[zorro-2];
		 lineLength = logline[zorro].size() - 51;
		 items[zorro] = logline[zorro].substr(51,lineLength);}


	firstCheck = true;
	while(checkObtainedItems(verbose, logline)){


	if(!isAdded[21]){
	obItems[k] = items[21];
	isAdded[21] = true;
	k++;}

	//cout << obItems[0] << " and " << obItems[1] << endl;
	//cout << isAdded[21] << " and " << isAdded[61] << " and " << isAdded[52] << endl;


	if((hasMorph && hasBoost) || hasSJ){
	if(!isAdded[2]){
		obItems[k] = items[2];
		isAdded[2] = true;
		k++;}
	}
	if(hasGrapple && hasSJ){
	if(!isAdded[3]){
		obItems[k] = items[3];
		isAdded[3] = true;
		k++;}
	}
	if(hasMissiles && hasSuper && hasCharge){
	if(!isAdded[4]){
		obItems[k] = items[4];
		isAdded[4] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[5]){
		obItems[k] = items[5];
		isAdded[5] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSpider){
	if(!isAdded[6]){
		obItems[k] = items[6];
		isAdded[6] = true;
		k++;}
	}
	if((hasMissiles && (hasMorph || items[7] == "Morph" || items[7] == "Morph Ball")) || (hasMissiles && (hasSJ || items[7] == "Space" || items[7] == "Space Jump Boots"))){
	if(!isAdded[7]){
		obItems[k] = items[7];
		isAdded[7] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBoost){
	if(!isAdded[8]){
		obItems[k] = items[8];
		isAdded[8] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && (hasBombs || hasPB)){
	if(!isAdded[9]){
		obItems[k] = items[9];
		isAdded[9] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[10]){
		obItems[k] = items[10];
		isAdded[10] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasGrapple && hasWave && hasBoost && hasSpider && hasSuit){
	if(!isAdded[11]){
		obItems[k] = items[11];
		isAdded[11] = true;
		k++;}
	}
	if(hasBombs && hasMorph){
	if(!isAdded[12]){
		obItems[k] = items[12];
		isAdded[12] = true;
		k++;}
	}
	if(hasMorph && hasSuit && hasGrapple && hasWave){
	if(!isAdded[13]){
		obItems[k] = items[13];
		isAdded[13] = true;
		k++;}
	}
	if(hasMorph && hasGrapple && hasSuit && hasPB){
	if(!isAdded[14]){
		obItems[k] = items[14];
		isAdded[14] = true;
		k++;}
	}
	if(hasMissiles && hasWave && hasSJ && hasBoost && hasSpider && hasMorph){
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}
	if(hasMissiles && hasWave && hasMorph && hasSJ && hasBoost && hasSpider && hasGravity){
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[17]){
		obItems[k] = items[17];
		isAdded[17] = true;
		k++;}
	}
	if(hasMorph && hasBombs){
	if(!isAdded[18]){
		obItems[k] = items[18];
		isAdded[18] = true;
		k++;}
	}
	if(hasMissiles){
	if(!isAdded[19]){
		obItems[k] = items[19];
		isAdded[19] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ){
	if(!isAdded[20]){
		obItems[k] = items[20];
		isAdded[20] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){
	if(!isAdded[22]){
		obItems[k] = items[22];
		isAdded[22] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSpider && hasCharge && hasSuper){
	if(!isAdded[23]){
		obItems[k] = items[23];
		isAdded[23] = true;
		k++;}
	}
	if(hasMissiles && hasMorph){
	if(!isAdded[24]){
		obItems[k] = items[24];
		isAdded[24] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(!isAdded[25]){
		obItems[k] = items[25];
		isAdded[25] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && hasBombs && hasGravity && hasSJ){
	if(!isAdded[26]){
		obItems[k] = items[26];
		isAdded[26] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && (hasBombs || hasPB)){
	if(!isAdded[27]){
		obItems[k] = items[27];
		isAdded[27] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && hasSpider && (hasBombs || hasPB)){
	if(!isAdded[28]){
		obItems[k] = items[28];
		isAdded[28] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && ((hasPB && (items[29] == "Bombs" || items[29] == "Morph Ball Bomb")) || hasBombs)){
	if(!isAdded[29]){
		obItems[k] = items[29];
		isAdded[29] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){
	if(items[30] == "Bombs" || items[30] == "Morph Ball Bomb" || ((items[29] == "Bombs"  || items[29] == "Morph Ball Bomb") && (hasPB || items[30].substr(0,5) == "Power"))){
	if(!isAdded[30]){
		obItems[k] = items[30];
		isAdded[30] = true;
		k++;}
	}
	}
	if(hasMissiles && hasMorph && hasBombs){
		if(!isAdded[30]){
			obItems[k] = items[30];
			isAdded[30] = true;
			k++;
		}
	}

	if(hasMissiles && hasMorph && hasBombs && hasPB && hasBoost && hasSpider){
	if(!isAdded[31]){
		obItems[k] = items[31];
		isAdded[31] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[32]){
		obItems[k] = items[32];
		isAdded[32] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasIce && hasSpider){
	if(!isAdded[33]){
		obItems[k] = items[33];
		isAdded[33] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasBoost && hasCharge && hasSuper && hasSpider && (hasWave || hasIce)){
	if(!isAdded[34]){
		obItems[k] = items[34];
		isAdded[34] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPlasma && hasSpider){
	if(!isAdded[35]){
		obItems[k] = items[35];
		isAdded[35] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasWave && hasSJ && (hasIce || items[36] == "Ice B" || items[36] == "Ice Beam")) || (hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSpider) || (hasMissiles && hasMorph && hasBombs && hasWave && hasBoost && (hasIce || items[36] == "Ice B" || items[36] == "Ice Beam"))){
	if(!isAdded[36]){
		obItems[k] = items[36];
		isAdded[36] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasPlasma){
	if(!isAdded[37]){
		obItems[k] = items[37];
		isAdded[37] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasCharge && hasSuper && hasSpider){
	if(!isAdded[38]){
		obItems[k] = items[38];
		isAdded[38] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasPlasma && hasSJ){
	if(!isAdded[39]){
		obItems[k] = items[39];
		isAdded[39] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasPlasma && hasSJ){
	if(!isAdded[40]){
		obItems[k] = items[40];
		isAdded[40] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasPlasma){
	if(!isAdded[41]){
		obItems[k] = items[41];
		isAdded[41] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasSuit && hasBombs && hasSpider){
	if(!isAdded[42]){
		obItems[k] = items[42];
		isAdded[42] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasSuit && hasBombs && (hasWave || items[43] == "Wave " || items[43] == "Wave Beam")){
	if(!isAdded[43]){
		obItems[k] = items[43];
		isAdded[43] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasWave && hasSJ){
	if(!isAdded[44]){
		obItems[k] = items[44];
		isAdded[44] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[45]){
		obItems[k] = items[45];
		isAdded[45] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasWave && hasSJ && hasCharge && hasSuper && hasThermal && (hasSpider || hasGrapple || items[46] == "Spide" || items[46] == "Spider Ball" || items[46] == "Grapp" || items[46] == "Grapple Beam")){
	if(!isAdded[46]){
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasWave && hasCharge && hasSuper && hasSJ){
	if(!isAdded[47]){
		obItems[k] = items[47];
		isAdded[47] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasGrapple && hasWave && hasSJ && hasCharge && hasSuper && hasThermal){
	if(!isAdded[48]){
		obItems[k] = items[48];
		isAdded[48] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasSJ && hasBoost){
	if(!isAdded[49]){
		obItems[k] = items[49];
		isAdded[49] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasPlasma && hasWave && hasIce && hasSpider && hasSJ){
	if(!isAdded[50]){
		obItems[k] = items[50];
		isAdded[50] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasPlasma && hasSJ){
	if(!isAdded[51]){
		obItems[k] = items[51];
		isAdded[51] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce){
	if(!isAdded[52]){
		obItems[k] = items[52];
		isAdded[52] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSJ && hasWave && hasGrapple && hasIce && hasGravity && hasSpider){
	if(!isAdded[53]){
		obItems[k] = items[53];
		isAdded[53] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasGrapple && hasPhazon && hasSpider && hasXray){
		if(!isAdded[90]){
			obItems[k] = items[90];
			isAdded[90] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasGrapple && hasSpider && hasXray){
		if(!isAdded[89]){
			obItems[k] = items[89];
			isAdded[89] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPB && hasSJ && hasGrapple && hasSpider && hasXray){
		if(!isAdded[88]){
			obItems[k] = items[88];
			isAdded[88] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasCharge && hasSuper && hasGrapple && hasSpider && hasXray){
		if(!isAdded[87]){
			obItems[k] = items[87];
			isAdded[87] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity){
		if(!isAdded[86]){
			obItems[k] = items[86];
			isAdded[86] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasXray && hasSJ && hasSpider && hasGrapple){
		if(!isAdded[85]){
			obItems[k] = items[85];
			isAdded[85] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasXray && hasWave && hasPlasma && hasPB && hasXray && hasSJ && hasSpider && hasGrapple){
		if(!isAdded[84]){
			obItems[k] = items[84];
			isAdded[84] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && hasSJ && hasXray){
		if(!isAdded[83]){
			obItems[k] = items[83];
			isAdded[83] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasPB){
		if(!isAdded[82]){
			obItems[k] = items[82];
			isAdded[82] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasSpider){
		if(!isAdded[81]){
			obItems[k] = items[81];
			isAdded[81] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasBoost){
		if(!isAdded[80]){
			obItems[k] = items[80];
			isAdded[80] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity){
		if(!isAdded[79]){
			obItems[k] = items[79];
			isAdded[79] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasPB && hasPlasma){
		if(!isAdded[78]){
			obItems[k] = items[78];
			isAdded[78] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasSpider && hasPB){
		if(!isAdded[77]){
			obItems[k] = items[77];
			isAdded[77] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasPB){
		if(!isAdded[76]){
			obItems[k] = items[76];
			isAdded[76] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity && hasSpider){
		if(!isAdded[75]){
			obItems[k] = items[75];
			isAdded[75] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSJ && hasBoost && hasWave && hasSpider){
		if(!isAdded[74]){
			obItems[k] = items[74];
			isAdded[74] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSJ && hasBoost && hasWave && hasSpider){
		if(!isAdded[73]){
			obItems[k] = items[73];
			isAdded[73] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasPB && hasSJ && hasBoost && hasWave && hasSpider){
		if(!isAdded[72]){
			obItems[k] = items[72];
			isAdded[72] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasSpider && hasBoost && hasSJ){
		if(!isAdded[71]){
			obItems[k] = items[71];
			isAdded[71] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasGravity && hasWave && hasThermal && hasSJ){
		if(!isAdded[70]){
			obItems[k] = items[70];
			isAdded[70] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasCharge && hasSuper && hasThermal && hasGravity){
		if(!isAdded[69]){
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(hasWave && hasMissiles && hasMorph && hasBombs && hasIce && hasSJ && hasThermal && hasGravity){
		if(!isAdded[68]){
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}

	if(hasMissiles && hasSJ && hasPlasma && hasGrapple && hasXray){
		if(!isAdded[67]){
			obItems[k] = items[67];
			isAdded[67] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[66]){
			obItems[k] = items[66];
			isAdded[66] = true;
			k++;}
	}

	if(hasMissiles){
		if(!isAdded[65]){
			obItems[k] = items[65];
			isAdded[65] = true;
			k++;}
	}

	if(hasMissiles && hasSJ && hasGrapple && hasXray){
		if(!isAdded[64]){
			obItems[k] = items[64];
			isAdded[64] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasSJ && hasBoost && hasSpider){
		if(!isAdded[63]){
			obItems[k] = items[63];
			isAdded[63] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasGravity && hasSJ){
		if(!isAdded[62]){
			obItems[k] = items[62];
			isAdded[62] = true;
			k++;}
	}
	if((hasMorph && hasBombs && hasBoost) || hasSJ){
		if(!isAdded[61]){
			obItems[k] = items[61];
			isAdded[61] = true;
			k++;}
	}
	if(hasMorph){
		if(!isAdded[60]){
			obItems[k] = items[60];
			isAdded[60] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ && hasGrapple && hasSpider){
		if(!isAdded[59]){
			obItems[k] = items[59];
			isAdded[59] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ && hasPlasma && hasPB && hasSpider){
		if(!isAdded[58]){
			obItems[k] = items[58];
			isAdded[58] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ && hasPlasma && hasGrapple){
		if(!isAdded[57]){
			obItems[k] = items[57];
			isAdded[57] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasSJ && hasSpider && (hasGravity || items[56] == "Gravity Suit" || items[56] == "Gravi")){
		if(!isAdded[56]){
			obItems[k] = items[56];
			isAdded[56] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasSJ && hasBoost){
		if(!isAdded[55]){
			obItems[k] = items[55];
			isAdded[55] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasSJ && hasBoost){
		if(!isAdded[54]){
			obItems[k] = items[54];
			isAdded[54] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasSJ && hasGrapple && hasSpider && hasXray){
	if(!isAdded[91]){
		obItems[k] = items[91];
		isAdded[91] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasSuit){
	if(!isAdded[92]){
		obItems[k] = items[92];
		isAdded[92] = true;
		k++;}
	if(!isAdded[93]){
		obItems[k] = items[93];
		isAdded[93] = true;
		k++;}
	if(!isAdded[94]){
		obItems[k] = items[94];
		isAdded[94] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit){
	if(!isAdded[95]){
		obItems[k] = items[95];
		isAdded[95] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasSJ && hasBoost){
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasPB && hasSuit){
	if(!isAdded[97]){
		obItems[k] = items[97];
		isAdded[97] = true;
		k++;}
	}

	if(hasMissiles && hasSuit && hasMorph && hasBombs){
	if(!isAdded[98]){
		obItems[k] = items[98];
		isAdded[98] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasSJ && hasBoost && hasPB){
	if(!isAdded[99]){
		obItems[k] = items[99];
		isAdded[99] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && hasSuit && hasBoost && hasWave && hasIce && hasSpider && hasSJ && (hasPlasma || items[100] == "Plasma Beam" || items[100] == "Plasm")){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasSuit && hasSpider && hasSJ){
	if(!isAdded[101]){
		obItems[k] = items[101];
		isAdded[101] = true;
		k++;}
	}



	w++;
	}
	//cout << obItems[0] << " and " << obItems[1] << " and " << obItems[2] <<
	//" and " << obItems[3] << " and " << obItems[4] << " and " << obItems[5] <<
	//" and " << obItems[6] << " and " << obItems[7] << " and " << obItems[8] <<
	//" and " << obItems[9] << " and " << obItems[10] << " and " << obItems[11] <<
	//" and " << obItems[12] << " and " << obItems[13] << " and " << obItems[14] <<
	//" and " << obItems[15] << endl;


	/*
	while(z < 110){
	cout << obItems[z] << '\n';
	z++;}
	cout << k << endl;
	*/

	/*

	while(m < 102){
	cout << isAdded[m] << '\n';
	m++;}
	m = 0;

	*/
	 /*
	while(m < 102){
	cout << obItems[m] << '\n';
	m++;}
	m = 0;
	*/
	countArtifacts();
	//cout << "Num of Artifacts " << a <<endl;

	if(a == 12 && hasWave && hasIce && hasPlasma && hasMissiles && hasSJ && hasPhazon)
		isCompletableEasy = true;

	int outSeed = seed;
	string newSeed = to_string(outSeed);
	seedString = "Seed: " + newSeed;

	string listOfExceptions = "";
	for(int zork = 0; zork < exceptions.size(); zork++){
	    listOfExceptions += to_string(exceptions[zork]);
			listOfExceptions += " ";
	}


	seedExceptions = "Exceptions: " + listOfExceptions;
	if(exceptions.size() == 0){
		seedExceptions = "Exceptions: None";
	}

	//cout << "Number of E-Tanks: " << e << endl;

    /*
    items.clear();
    items.shrink_to_fit();
    obItems.clear();
    obItems.shrink_to_fit();
    logline.clear();
    logline.shrink_to_fit();
    areaInput.clear();
    areaInput.shrink_to_fit();
    itemInput.clear();
    itemInput.shrink_to_fit();
    newItems.clear();
    newItems.shrink_to_fit();
*/
if(verbose){
	cout << "\n" << endl;
}
}

void LogChecker::CheckFinishHypermodeNew(int seed, vector <int> inExceptions, bool verbose, bool noFloatyAllowed){

	if(verbose){
		cout << "Item order for Hypermode difficulty: " << endl;
	}

vector <string> items(104, "");
vector <string> logline(104, "");
vector <string> itemInput(100, "");
vector <string> areaInput(100, "");
vector <int> exceptions(inExceptions);
isCompletableHypermode = false;

int k = 0; //for adding items to obtained list
int earl = 0; //for adding items to early mines
int bob = 0; //for adding items to deep mines
int skinner = 0; //for adding items to deep phendrana
int w = 0; //for traversing the item requirements
int z = 0; //for debugging
int m = 0; //more debugging
int resetter = 0;
bool hasFloaty = false;
bool earlyMinesEscape = false;
bool deepMinesEscape = false;
bool deepPhenEscape = false;
a = 0;

while(resetter < 104){
	isAdded[resetter] = false;
	resetter++;
}

resetter = 0;


while(resetter < 104){
	obItems[resetter] = "";
	resetter++;
}
resetter = 0;

while(resetter < 6){
	earlyMinesItems[resetter] = "";
	resetter++;
}

resetter = 0;

while(resetter < 6){
	earlyMinesIsAdded[resetter] = false;
	resetter++;
}

resetter = 0;

while(resetter < 9){
	deepMinesItems[resetter] = "";
	resetter++;
}
resetter = 0;

while(resetter < 9){
	deepMinesIsAdded[resetter] = false;
	resetter++;
}
resetter = 0;

while(resetter < 4){
	deepPhenItems[resetter] = "";
	resetter++;
}

resetter = 0;

while(resetter < 4){
	deepPhenIsAdded[resetter] = false;
	resetter++;
}
resetter = 0;




	//resetting item bools
	hasMissiles = false;
	hasMorph = false;
	hasBombs = false;
	hasSuit = false;
	hasBoost = false;
	hasSJ = false;
	hasGrapple = false;
	hasVaria = false;
	hasPhazon = false;
	hasGravity = false;
	hasPB = false;
	hasWave = false;
	hasIce = false;
	hasPlasma = false;
	hasSpider = false;
	hasXray = false;
	hasCharge = false;
	hasSuper = false;

	earlyMinesSJ = false;
	earlyMinesSpider = false;
	earlyMinesPB = false;
	earlyMinesPlasma = false;
	earlyMinesGravity = false;
	earlyMinesBoost = false;

	deepMinesSJ = false;
	deepMinesSpider = false;
	deepMinesPB = false;
	deepMinesXray = false;
	deepMinesPlasma = false;
	deepMinesCharge = false;
	deepMinesSuper = false;
	deepMinesGrapple = false;
	deepMinesPhazon = false;
	deepMinesGravity = false;

	deepPhenBombs = false;
	deepPhenPlasma = false;
	deepPhenSJ = false;
	deepPhenGravity = false;
	deepPhenGrapple = false;
	deepPhenPB = false;

	bombsWithoutGravity = false;

	itemInput = getItemNames();


	areaInput = getAreaNames();

	vector <string> newItems = randomize(itemInput, exceptions, seed);



	for(int zorro = 2; zorro < logline.size()-2; zorro++){
		 logline[zorro] = areaInput[zorro-2] + newItems[zorro-2];
		 lineLength = logline[zorro].size() - 51;
		 items[zorro] = logline[zorro].substr(51,lineLength);}


	firstCheck = true;

	while (checkObtainedItems(verbose, logline)){

	checkEarlyMines();
	checkDeepMines();
	checkDeepPhen();

	//FLOATY CHECK
	if(!noFloatyAllowed){
	if(!(items[22] == "Gravi" || items[22] == "Gravity Suit")){
	if(items[92] == "Bombs" || items[92] == "Morph Ball Bomb" || items[93] == "Bombs" || items[93] == "Morph Ball Bomb" || items[94] == "Bombs" || items[94] == "Morph Ball Bomb" || items[96] == "Bombs" || items[96] == "Morph Ball Bomb" || items[97] == "Bombs" || items[97] == "Morph Ball Bomb" || items[98] == "Bombs" || items[98] == "Morph Ball Bomb" || items[99] == "Bombs" || items[99] == "Morph Ball Bomb" || items[101] == "Bombs" || items[101] == "Morph Ball Bomb" || items[96] == "Morph" || items[96] == "Morph Ball" || items[98] == "Morph" || items[98] == "Morph Ball"){
			if(hasVaria || hasPhazon){
				if(!((items[29] == "Bombs" || items[29] == "Morph Ball Bomb") && (items[30] == "Gravi" || items[30] == "Gravity Suit"))){
					if(hasMissiles && hasMorph && hasBombs && bombsWithoutGravity){
						hasFloaty = true;
					}
					else hasFloaty = false;
				}
				else hasFloaty = false;
			}
			else hasFloaty = false;

		}
		else if(!((items[29] == "Bombs" || "Morph Ball Bomb") && (items[30] == "Gravi" || items[30] == "Gravity Suit"))){
					if(hasMissiles && hasMorph && hasBombs && bombsWithoutGravity){
						hasFloaty = true;
					}
					else hasFloaty = false;
				}
				else hasFloaty = false;
	}
	else hasFloaty = false;
}

	//EARLY MINES ESCAPE CHECK

	//EARLY MINES ARRAY VALUES
	// [0] = MAIN QUARRY
	// [1] = SECURITY ACCESS A
	// [2] = STORAGE DEPOT B
	// [3] = STORAGE DEPOT A
	// [4] = ELITE RESEARCH (LAZER)
	// [5] = ELITE CONTROL ACCESS
	// [6] = PHAZON PROCESSING CENTER

	if(hasSJ || hasGravity || hasBoost || (hasPB && hasSpider)){
		earlyMinesEscape = true;
	}
	if(earlyMinesSJ || earlyMinesGravity || earlyMinesBoost || (earlyMinesPB && earlyMinesSpider)){
		earlyMinesEscape = true;
	}

	if((hasSpider && earlyMinesPB) || (earlyMinesSpider && hasPB)){
		earlyMinesEscape = true;
	}

	if(!earlyMinesIsAdded[0]){
		earlyMinesItems[earl] = items[75];
		earlyMinesIsAdded[0] = true;
		earl++;
	}

	if(!earlyMinesIsAdded[1]){
		earlyMinesItems[earl] = items[76];
		earlyMinesIsAdded[1] = true;
		earl++;}

	if(!earlyMinesIsAdded[2]){
		earlyMinesItems[earl] = items[77];
		earlyMinesIsAdded[2] = true;
		earl++;}

	if((hasPlasma || earlyMinesPlasma) && (hasPB || earlyMinesPB)){
		if(!earlyMinesIsAdded[3]){
		earlyMinesItems[earl] = items[78];
		earlyMinesIsAdded[3] = true;
		earl++;}
	}

	if(!earlyMinesIsAdded[4]){
		earlyMinesItems[earl] = items[80];
		earlyMinesIsAdded[4] = true;
		earl++;}

	if(!earlyMinesIsAdded[5]){
		earlyMinesItems[earl] = items[81];
		earlyMinesIsAdded[5] = true;
		earl++;}

	if(hasPB || earlyMinesPB){
		if(!earlyMinesIsAdded[6]){
		earlyMinesItems[earl] = items[83];
		earlyMinesIsAdded[6] = true;
		earl++;}
	}


	//DEEP MINES ESCAPING

	//DEEP MINES ARRAY NUMBERS
	//[0] = VENT SHAFT
	//[1] = PROCESSING CENTER ACCESS
	//[2] = ELITE QUARTERS
	//[3] = CENTRAL DYNAMO
	//[4] = METROID QUARENTINE B
	//[5] = METROID QUARENTINE A
	//[6] = FUNGAL HALL B
	//[7] = PHAZON MINING TUNNEL
	//[8] = FUNGAL HALL ACCESS

	if((hasPB || deepMinesPB) || (hasSJ || deepMinesSJ) || (hasBoost || deepMinesBoost) || (hasGravity || deepMinesGravity)){
		deepMinesEscape = true;
	}

	if(hasPB || deepMinesPB){
		if(!deepMinesIsAdded[0]){
		deepMinesItems[bob] = items[82];
		deepMinesIsAdded[0] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && ((hasXray || deepMinesXray) || ((hasBoost || deepMinesBoost) && (hasSJ || deepMinesSJ)))){
		if(!deepMinesIsAdded[1]){
		deepMinesItems[bob] = items[84];
		deepMinesIsAdded[1] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && ((hasXray || deepMinesXray) || ((hasBoost || deepMinesBoost) && (hasSJ || deepMinesSJ)))){
		if(!deepMinesIsAdded[2]){
		deepMinesItems[bob] = items[85];
		deepMinesIsAdded[2] = true;
		bob++;}
	}

	if(!deepMinesIsAdded[3]){
		deepMinesItems[bob] = items[86];
		deepMinesIsAdded[3] = true;
		bob++;}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB) && (hasCharge || deepMinesCharge) && (hasSuper && deepMinesSuper)){
		if(!deepMinesIsAdded[4]){
		deepMinesItems[bob] = items[87];
		deepMinesIsAdded[4] = true;
		bob++;}
	}

	if(hasPB || deepMinesPB){
		if(!deepMinesIsAdded[5]){
		deepMinesItems[bob] = items[88];
		deepMinesIsAdded[5] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)){
		if(!deepMinesIsAdded[6]){
		deepMinesItems[bob] = items[89];
		deepMinesIsAdded[6] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)  && ((hasPhazon || deepMinesPhazon) || (e >= 5 && (hasBoost || deepMinesBoost) && (hasGravity || deepMinesGravity)) || (e >= 9))){
		if(!deepMinesIsAdded[7]){
		deepMinesItems[bob] = items[90];
		deepMinesIsAdded[7] = true;
		bob++;}
	}

	if((hasPlasma || deepMinesPlasma) && (hasPB || deepMinesPB)){
		if(!deepMinesIsAdded[8]){
		deepMinesItems[bob] = items[91];
		deepMinesIsAdded[8] = true;
		bob++;}
	}

	//DEEP PHEN ESCAPING
	//[0] = FROST CAVE [53]
	//[1] = GRAVITY CHAMBER (UNDERWATER) [56]
	//[2] = STORAGE CAVE [58]
	//[3] = SECURITY CAVE [59]





	if(deepPhenBombs || deepPhenSJ || hasBombs || hasSJ){
		deepMinesEscape = true;
	}

	if(hasSJ || deepPhenSJ || (items[53] == "Space" || "Space Jump Boots") || hasGravity || deepPhenGravity || (items[53] == "Gravi" || "Gravity Suit")){
		if(!deepPhenIsAdded[0]){
		deepPhenItems[skinner] = items[53];
		deepPhenIsAdded[0] = true;
		skinner++;
		}
	}

	if(hasSJ || deepPhenSJ || (items[56] == "Space" || "Space Jump Boots") || hasGravity || deepPhenGravity || (items[56] == "Gravi" || "Gravity Suit")){
		if(!deepPhenIsAdded[1]){
		deepPhenItems[skinner] = items[56];
		deepPhenIsAdded[1] = true;
		skinner++;
		}
	}

	if((hasSJ || deepPhenSJ || hasBombs || deepPhenBombs || hasGrapple || deepPhenGrapple) && (hasPlasma || deepPhenPlasma) && (hasPB || deepPhenPB)){
		if(!deepPhenIsAdded[2]){
		deepPhenItems[skinner] = items[58];
		deepPhenIsAdded[2] = true;
		skinner++;
		}
	}

	if(hasSJ || deepPhenSJ || hasBombs || deepPhenBombs || hasGrapple || deepPhenGrapple){
		if(!deepPhenIsAdded[3]){
		deepPhenItems[skinner] = items[59];
		deepPhenIsAdded[3] = true;
		skinner++;
		}
	}





	if(!isAdded[21]){
	obItems[k] = items[21];
	isAdded[21] = true;
	k++;}

	if(!isAdded[61]){
	obItems[k] = items[61];
	isAdded[61] = true;
	k++;}
	//cout << obItems[0] << " and " << obItems[1] << endl;
	//cout << isAdded[21] << " and " << isAdded[61] << " and " << isAdded[52] << endl;


	if((hasMorph && (hasBoost || hasBombs)) || hasSJ){ //d
	if(!isAdded[2]){
		obItems[k] = items[2];
		isAdded[2] = true;
		k++;}
	}
	if(hasGrapple || hasSJ || hasFloaty){ //done
	if(!isAdded[3]){
		obItems[k] = items[3];
		isAdded[3] = true;
		k++;}
	}
	if(hasMissiles && hasSuper && hasCharge){ //done
	if(!isAdded[4]){
		obItems[k] = items[4];
		isAdded[4] = true;
		k++;}
	}


	if((hasMorph && hasMissiles) || hasSJ){ //done
	if(!isAdded[5]){
		obItems[k] = items[5];
		isAdded[5] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs && (hasSpider || items[6] == "Spide" || items[6] == "Spider Ball") || hasFloaty){ //done
	if(!isAdded[6]){
		obItems[k] = items[6];
		isAdded[6] = true;
		k++;}
	}


	if(hasMissiles){ //done
	if(!isAdded[7]){
		obItems[k] = items[7];
		isAdded[7] = true;
		k++;}
	}

	if(hasMissiles && hasMorph){ //done
	if(!isAdded[8]){
		obItems[k] = items[8];
		isAdded[8] = true;
		k++;}
	}

	if((hasMorph && hasMissiles && hasBombs) || (hasMissiles && hasMorph && hasPB)){ //done
	if(!isAdded[9]){
		obItems[k] = items[9];
		isAdded[9] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){ //done
	if(!isAdded[10]){
		obItems[k] = items[10];
		isAdded[10] = true;
		k++;}
	}

	if((hasWave && hasMorph && hasSuit && hasGrapple && hasSpider && hasBoost && hasBombs) || (hasWave && hasMorph && hasSJ && (hasSuit || e >= 2) && hasSpider && hasBoost && hasBombs) || (hasMorph && hasBombs && hasSJ && hasBoost && hasSpider) || hasFloaty){ //done
	if(!isAdded[11]){
		obItems[k] = items[11];
		isAdded[11] = true;
		k++;}
	}
	if(hasBombs && hasMorph){ //done
	if(!isAdded[12]){
		obItems[k] = items[12];
		isAdded[12] = true;
		k++;}
	}
	if((hasWave && hasMorph && hasSuit && hasGrapple && hasBombs) || (hasMorph && hasBombs && hasSJ && hasWave) || (hasFloaty && hasWave)){ //done
	if(!isAdded[13]){
		obItems[k] = items[13];
		isAdded[13] = true;
		k++;}
	}
	if((hasPB && hasMorph && hasSuit && hasGrapple && hasBombs) || (hasPB && hasMorph && hasBombs && hasSJ && (hasSuit || e >= 2)) || (hasMorph && hasBombs && hasSJ && hasWave && hasPB) || (hasFloaty && hasWave && hasPB)){
	if(!isAdded[14]){ //done
		obItems[k] = items[14];
		isAdded[14] = true;
		k++;}
	}
	if(items[15] == "Wave " || "Wave Beam"){ //done
	if(hasMissiles && hasMorph && hasBombs){
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}
	}


	if(hasMissiles && hasWave && (hasSJ || (hasMorph && hasBombs))){ //done
	if(!isAdded[15]){
		obItems[k] = items[15];
		isAdded[15] = true;
		k++;}
	}

	if(items[16] == "Wave " || "Wave Beam"){
	if(hasMorph && hasBombs && hasBoost && (hasSJ || hasMissiles)){ //done
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}

	}
	}

	if(hasMissiles && hasWave && (hasMorph || hasSJ)){ //done
	if(!isAdded[16]){
		obItems[k] = items[16];
		isAdded[16] = true;
		k++;}
	}
	if(hasMissiles){ //done
	if(!isAdded[17]){
		obItems[k] = items[17];
		isAdded[17] = true;
		k++;}
	}
	if(hasMorph && hasBombs){ //done
	if(!isAdded[18]){
		obItems[k] = items[18];
		isAdded[18] = true;
		k++;}
	}

	if(items[18].substr(0,5) == "Morph" || "Boost" || "Spide" ||"Artif" || "Varia" || "Gravi" ||"Phazo"){ //done
	if(hasSJ){
	if(!isAdded[18]){
		obItems[k] = items[18];
		isAdded[18] = true;
		k++;
	}
	}
	}

	if(hasMissiles){ //done
	if(!isAdded[19]){
		obItems[k] = items[19];
		isAdded[19] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && (hasBombs || (hasPB && hasSJ))){ //done
	if(!isAdded[20]){
		obItems[k] = items[20];
		isAdded[20] = true;
		k++;}
	}
	if(hasMorph && hasBombs && hasMissiles){ //done
	if(!isAdded[22]){
		obItems[k] = items[22];
		isAdded[22] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){ //done
	if(!isAdded[23]){
		obItems[k] = items[23];
		isAdded[23] = true;
		k++;}
	}
	if(hasMissiles && hasMorph){ //done
	if(!isAdded[24]){
		obItems[k] = items[24];
		isAdded[24] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){ //done
	if(!isAdded[25]){
		obItems[k] = items[25];
		isAdded[25] = true;
		k++;}
	}
	if(hasMorph && hasMissiles){ //done
	if(!isAdded[26]){
		obItems[k] = items[26];
		isAdded[26] = true;
		k++;}
	}
	if(hasMorph && hasMissiles && (hasBombs || hasPB)){ //done
	if(!isAdded[27]){
		obItems[k] = items[27];
		isAdded[27] = true;
		k++;}
	}
	if((hasMorph && hasMissiles && hasSpider && (hasBombs || hasPB)) || hasFloaty){ //done
	if(!isAdded[28]){
		obItems[k] = items[28];
		isAdded[28] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && (hasBombs || (hasPB && (items[29] == "Bombs" || items[30] == "Bombs" || items[29] == "Morph Ball Bomb" || items[30] == "Morph Ball Bomb")))){ //done
	if(!isAdded[29]){
		obItems[k] = items[29];
		isAdded[29] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || items[30] == "Bombs" || items[30] == "Morph Ball Bomb")){ //done
	if(!isAdded[30]){
		obItems[k] = items[30];
		isAdded[30] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && (hasSJ || (hasPB && hasBoost && hasSpider))) || hasFloaty){ //done
	if(!isAdded[31]){
		obItems[k] = items[31];
		isAdded[31] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){ //done
	if(!isAdded[32]){
		obItems[k] = items[32];
		isAdded[32] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasIce)){ //done
	if(!isAdded[33]){
		obItems[k] = items[33];
		isAdded[33] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasSJ) || (hasMissiles && hasMorph && hasBombs && hasBoost && hasCharge && hasSuper && hasSpider && (hasWave || hasIce)) || hasFloaty){ //done
	if(!isAdded[34]){
		obItems[k] = items[34];
		isAdded[34] = true;
		k++;}
	}
	if((hasMissiles && hasMorph && hasBombs && hasIce && hasPlasma) || (hasMorph && hasBombs && hasMissiles && hasBoost)){ //done
	if(!isAdded[35]){
		obItems[k] = items[35];
		isAdded[35] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasBombs){ //done
	if(!isAdded[36]){
		obItems[k] = items[36];
		isAdded[36] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))) && ((hasBoost && hasBombs) || hasPlasma)){ //done
	if(!isAdded[37]){
		obItems[k] = items[37];
		isAdded[37] = true;
		k++;}
	}



	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))) && (hasSuper && hasCharge && hasSpider)){ //done
	if(!isAdded[38]){
		obItems[k] = items[38];
		isAdded[38] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider && hasBombs))) && ((hasBoost && hasBombs) || hasPlasma)){ //done
	if(!isAdded[39]){
		obItems[k] = items[39];
		isAdded[39] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || (hasSpider && hasBombs)))) && (hasPlasma)){ //done
	if(!isAdded[40]){ //done
		obItems[k] = items[40];
		isAdded[40] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))) && ((hasBoost && hasBombs) || hasPlasma)){ //done
	if(!isAdded[41]){ //done
		obItems[k] = items[41];
		isAdded[41] = true;
		k++;}
	}


	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasBombs && hasWave && (hasSJ || hasSpider))) && (hasBombs || hasSpider)){ //done
	if(!isAdded[42]){ //done
		obItems[k] = items[42];
		isAdded[42] = true;
		k++;}
	}
	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))) && ((hasWave && hasSJ) || (items[43] == "Wave " && hasSJ) || hasBombs || (hasPB && hasSJ))){
	if(!isAdded[43]){ //done
		obItems[k] = items[43];
		isAdded[43] = true;
		k++;}
	}

	if(((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))) && (hasWave)){
	if(!isAdded[44]){ //done
		obItems[k] = items[44];
		isAdded[44] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasSuit) || (hasMissiles && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider))){
	if(!isAdded[45]){ //done
		obItems[k] = items[45];
		isAdded[45] = true;
		k++;}
	}

	if(items[46].substr(0,5) == "Space" || "Spide" || "Grapp"){
	if(hasMissiles && hasMorph && hasWave){
	if(!isAdded[46]){ //done
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || hasGrapple || hasSpider)){
	if(!isAdded[46]){ //done
		obItems[k] = items[46];
		isAdded[46] = true;
		k++;}
	}



	if((hasMissiles && hasMorph && hasBombs && hasWave && hasSuit) || (hasMissiles && hasWave && hasMorph && hasBombs && ((e >= 4 && (hasSJ || hasCharge) || e >= 5))) || (hasMissiles && hasMorph && hasWave && (hasSJ || hasSpider)) && (hasCharge && hasSuper)){
	if(!isAdded[47]){ //done
		obItems[k] = items[47];
		isAdded[47] = true;
		k++;}
	}


	if(hasMissiles && hasMorph && hasWave && (hasSJ || hasGrapple)){
	if(!isAdded[48]){ //done
		obItems[k] = items[48];
		isAdded[48] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasWave && hasSJ) || (hasMissiles && hasMorph && hasWave && hasIce && hasBombs)){
	if(!isAdded[49]){ //done
		obItems[k] = items[49];
		isAdded[49] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasIce && hasPlasma && (hasBombs || hasSJ || hasSpider)){
	if(!isAdded[50]){ //done
		obItems[k] = items[50];
		isAdded[50] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasWave && hasSJ) || (hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSpider) && hasPlasma)){
	if(!isAdded[51]){ //done
		obItems[k] = items[51];
		isAdded[51] = true;
		k++;}
	}

	if((hasMissiles && hasMorph && hasWave && hasSJ) || (hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSpider))){
	if(!isAdded[52]){ //done
		obItems[k] = items[52];
		isAdded[52] = true;
		k++;}
	}
	if(hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSpider || hasSJ) && (hasSJ || items[53].substr(0,5) == "Space" || hasGravity || items[53].substr(0,5) == "Gravi") && deepPhenEscape){ //done
	if(!isAdded[53]){
		obItems[k] = items[53];
		isAdded[53] = true;
		k++;}
		}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && (hasPhazon || (e >= 5 && hasBoost && hasGravity) || (e >= 9)) && deepMinesEscape){ //done
		if(!isAdded[90]){
			obItems[k] = items[90];
			isAdded[90] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && deepMinesEscape){ //done
		if(!isAdded[89]){
			obItems[k] = items[89];
			isAdded[89] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPB && deepMinesEscape){ //done
		if(!isAdded[88]){
			obItems[k] = items[88];
			isAdded[88] = true;
			k++;}
	}


	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && hasCharge && hasSuper && deepMinesEscape){
		if(!isAdded[87]){
			obItems[k] = items[87];
			isAdded[87] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && deepMinesEscape){ //done
		if(!isAdded[86]){
			obItems[k] = items[86];
			isAdded[86] = true;
			k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && deepMinesEscape && hasPlasma && hasPB && (hasXray || (hasBoost && hasSJ))){ //done
		if(!isAdded[85]){
			obItems[k] = items[85];
			isAdded[85] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && deepMinesEscape && hasPlasma && hasPB && (hasXray || (hasBoost && hasSJ))){ //done
		if(!isAdded[84]){
			obItems[k] = items[84];
			isAdded[84] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && deepMinesEscape){ //done
		if(!isAdded[83]){
			obItems[k] = items[83];
			isAdded[83] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && deepMinesEscape){ //done
		if(!isAdded[82]){
			obItems[k] = items[82];
			isAdded[82] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){ //done
		if(!isAdded[81]){
			obItems[k] = items[81];
			isAdded[81] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){ //done
		if(!isAdded[80]){
			obItems[k] = items[80];
			isAdded[80] = true;
			k++;}
	}

	if(isAdded[86]){ //done
		if(!isAdded[79]){
			obItems[k] = items[79];
			isAdded[79] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && hasPlasma && earlyMinesEscape){ //done
		if(!isAdded[78]){
			obItems[k] = items[78];
			isAdded[78] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){ //done
		if(!isAdded[77]){
			obItems[k] = items[77];
			isAdded[77] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && hasPB && earlyMinesEscape){ //done
		if(!isAdded[76]){
			obItems[k] = items[76];
			isAdded[76] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasWave && hasIce && earlyMinesEscape){ //done
		if(!isAdded[75]){
			obItems[k] = items[75];
			isAdded[75] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && (hasPB || hasBoost)){ //done
		if(!isAdded[74]){
			obItems[k] = items[74];
			isAdded[74] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && (hasPB || hasBoost)){ //done
		if(!isAdded[73]){
			obItems[k] = items[73];
			isAdded[73] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && (hasPB || hasBoost)){ //done
		if(!isAdded[72]){
			obItems[k] = items[72];
			isAdded[72] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce){ //done
		if(!isAdded[71]){
			obItems[k] = items[71];
			isAdded[71] = true;
			k++;}
	}

	if((hasMissiles && hasMorph && hasBombs && hasWave && hasIce && (hasBoost || items[70].substr(0,5) == "Boost" || items[70].substr(0,5) == "Gravi")) || (hasMissiles && hasMorph && hasBombs && hasIce && hasGravity)){
		if(!isAdded[70]){ //done
			obItems[k] = items[70];
			isAdded[70] = true;
			k++;}
	}

	if(items[69].substr(0,5) == "Wave ")
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasCharge && hasSuper && (hasBoost || hasGravity || items[68] == "Boost" || items[68] == "Gravi")){
		if(!isAdded[69]){ //done
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(items[68].substr(0,5) == "Wave ")
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasCharge && hasSuper && (hasBoost || hasGravity)){
		if(!isAdded[69]){ //done
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasCharge && hasSuper && (hasBoost || hasGravity || hasSJ)){
		if(!isAdded[69]){ //done
			obItems[k] = items[69];
			isAdded[69] = true;
			k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && (hasBoost || hasGravity || hasSJ)){
	if(!isAdded[68]){ //done
		obItems[k] = items[68];
		isAdded[68] = true;
		k++;}
	}


	if(items[68].substr(0,5) == "Gravi" || "Space" || "Boost"){
	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave){
		if(!isAdded[68]){ //done
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}
	}


	if(items[68] == "Wave "){ //done
	if(hasMissiles && hasMorph && hasBombs && hasIce && (hasBoost || (items[69].substr(0,5) == "Boost" && hasSuper && hasCharge) || ((hasGravity || (items[69].substr(0,5) == "Gravi" && hasSuper && hasCharge)) && (hasSJ || (items[69].substr(0,5) == "Space" && hasCharge && hasSuper))))){
		if(!isAdded[68]){
			obItems[k] = items[68];
			isAdded[68] = true;
			k++;}
	}
	}
	if(hasMissiles && hasSJ){ //done
		if(!isAdded[67]){
			obItems[k] = items[67];
			isAdded[67] = true;
			k++;}
	}

	if(hasMissiles){ //done
		if(!isAdded[66]){
			obItems[k] = items[66];
			isAdded[66] = true;
			k++;}
	}

	if(hasMissiles){ //done
		if(!isAdded[65]){
			obItems[k] = items[65];
			isAdded[65] = true;
			k++;}
	}

	if(hasMissiles && hasSJ){ //done
		if(!isAdded[64]){
			obItems[k] = items[64];
			isAdded[64] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && (hasBombs || hasSJ) && hasIce){ //done
		if(!isAdded[63]){
			obItems[k] = items[63];
			isAdded[63] = true;
			k++;}
	}

	if(hasMissiles && hasMorph){ //done
		if(!isAdded[62]){
			obItems[k] = items[62];
			isAdded[62] = true;
			k++;}
	}

	if(hasMorph || hasSJ){ //done
		if(!isAdded[60]){
			obItems[k] = items[60];
			isAdded[60] = true;
			k++;}
	}
	if(hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSJ || hasGrapple) && deepPhenEscape){
		if(!isAdded[59]){ //done
			obItems[k] = items[59];
			isAdded[59] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSJ || hasGrapple) && hasPlasma && hasPB && deepPhenEscape){
		if(!isAdded[58]){ //done
			obItems[k] = items[58];
			isAdded[58] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasBombs && hasIce && ((isAdded[77] && hasPlasma && hasGrapple) || hasSJ)){
		if(!isAdded[57]){ //done
			obItems[k] = items[57];
			isAdded[57] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && hasIce && (hasBombs || hasSpider || hasSJ) && (hasSJ || items[56].substr(0,5) == "Space" || hasGravity || items[56].substr(0,5) == "Gravi") && deepPhenEscape){ //done
		if(!isAdded[56]){
			obItems[k] = items[56];
			isAdded[56] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || hasIce)){
		if(!isAdded[55]){ //done
			obItems[k] = items[55];
			isAdded[55] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasWave && (hasSJ || hasIce)){
		if(!isAdded[54]){ //done
			obItems[k] = items[54];
			isAdded[54] = true;
			k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && hasIce && hasWave && hasPlasma && hasPB && deepMinesEscape){ //done
	if(!isAdded[91]){
		obItems[k] = items[91];
		isAdded[91] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasSuit){
	if(!isAdded[92]){
		obItems[k] = items[92];
		isAdded[92] = true;
		k++;}

	if(!isAdded[94]){
		obItems[k] = items[94];
		isAdded[94] = true;
		k++;}
	}

	if(hasMissiles && hasSuit){
	if(!isAdded[93]){
		obItems[k] = items[93];
		isAdded[93] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasBombs && (hasSuit || (e >= 4 && (hasSJ || hasCharge) || e >= 5))){
	if(!isAdded[95]){
		obItems[k] = items[95];
		isAdded[95] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && (hasSuit || (e >= 4 && hasSJ && (items[96].substr(0,5) == "Energ" || items[96].substr(0,5) == "Varia" || items[96].substr(0,5) == "Gravi" || items[96].substr(0,5) == "Phazo")) ||(e >= 5 && (items[96].substr(0,5) == "Energ" || items[96].substr(0,5) == "Varia" || items[96].substr(0,5) == "Gravi" || items[96].substr(0,5) == "Phazo")) || (e >= 6 && hasSJ) || (e >= 7) )){
	if(!isAdded[96]){
		obItems[k] = items[96];
		isAdded[96] = true;
		k++;}

	}

	if((hasMissiles && hasMorph && hasPB && hasSuit) || (hasMissiles && hasMorph && hasPB && e >= 5) || (hasMissiles && hasMorph && hasPB && hasSJ && e >= 4) || (hasMissiles && hasMorph && hasPB && e >= 3 && (items[97] == "Energ" || items[97] == "Varia" || items[97] == "Gravi" || items[97] == "Phazo")) || (hasMissiles && hasMorph && hasBoost && hasBombs && e >= 10) || (hasMissiles && hasMorph && hasBoost && hasBombs && e >= 5 && (items[97] == "Energ" || items[97] == "Varia" || items[97] == "Gravi" || items[97] == "Phazo"))){
	if(!isAdded[97]){
		obItems[k] = items[97];
		isAdded[97] = true;
		k++;}
	}

	if(hasMissiles && (hasSuit || (e >= 2 && (items[98].substr(0,5) == "Energ" || items[98].substr(0,5) == "Varia" || items[98].substr(0,5) == "Gravi" || items[98].substr(0,5) == "Phazo")) || (e >= 4))){
	if(!isAdded[98]){
		obItems[k] = items[98];
		isAdded[98] = true;
		k++;}
	}

	 if(hasMissiles && hasMorph && (hasBombs || items[99].substr(0,5) == "Bombs") && (hasSuit || (e >= 5 && hasSJ && (items[99].substr(0,5) == "Energ" || items[99].substr(0,5) == "Varia" || items[99].substr(0,5) == "Gravi" || items[99].substr(0,5) == "Phazo")) ||(e >= 6 && (items[99].substr(0,5) == "Energ" || items[99].substr(0,5) == "Varia" || items[99].substr(0,5) == "Gravi" || items[99].substr(0,5) == "Phazo")) || (e >= 7 && hasSJ) || (e >= 8) ) && hasPB){
	if(!isAdded[99]){
		obItems[k] = items[99];
		isAdded[99] = true;
		k++;}
	}



	if(hasMissiles && hasMorph && hasBombs && hasWave && (hasSuit || hasSJ) && ((hasPlasma || items[100].substr(0,5) == "Plasm") || hasIce)){
	if(!isAdded[100]){
		obItems[k] = items[100];
		isAdded[100] = true;
		k++;}
	}

	if(hasMissiles && hasMorph && hasWave){
	if(!isAdded[101]){
		obItems[k] = items[101];
		isAdded[101] = true;
		k++;}
	}

	w++;
	}
	//cout << obItems[0] << " and " << obItems[1] << " and " << obItems[2] <<
	//" and " << obItems[3] << " and " << obItems[4] << " and " << obItems[5] <<
	//" and " << obItems[6] << " and " << obItems[7] << " and " << obItems[8] <<
	//" and " << obItems[9] << " and " << obItems[10] << " and " << obItems[11] <<
	//" and " << obItems[12] << " and " << obItems[13] << " and " << obItems[14] <<
	//" and " << obItems[15] << endl;


	/*
	while(z < 110){
	cout << obItems[z] << '\n';
	z++;}
	cout << k << endl;
	*/
	/*while(m < 102){
	cout << isAdded[m] << '\n';
	m++;}
	m = 0;

	while(m < 102){
	cout << obItems[m] << '\n';
	m++;}
	m = 0;
	*/
	countArtifacts();
	//cout << "Num of Artifacts " << a <<endl;

	if(a == 12 && hasWave && hasIce && hasPlasma && hasMissiles && hasSJ && hasPhazon)
		isCompletableHypermode = true;

	int outSeed = seed;
	string newSeed = to_string(outSeed);
	seedString = "Seed: " + newSeed;

	string listOfExceptions = "";
	for(int zork = 0; zork < exceptions.size(); zork++){
	    listOfExceptions += to_string(exceptions[zork]);
			listOfExceptions += " ";
	}


	seedExceptions = "Exceptions: " + listOfExceptions;
	if(exceptions.size() == 0){
		seedExceptions = "Exceptions: None";
	}

	if(verbose){
		cout << "\n" << endl;
	}

}

bool LogChecker::checkObtainedItems(bool verbose, vector<string> logs){
int prevEtankCount = e;
int prevArt = art;
art = 0;
int q = 0;
e = 0;
bool foundItems = false;

while (q < 105){
	if((obItems[q] == "Missi" || obItems[q].substr(0,7) == "Missile") && !hasMissiles){
		if(verbose){

		cout << getItemLocation(logs, obItems[q]) << endl;
	  }
		hasMissiles = true;
		foundItems = true;}
	if((obItems[q] == "Morph" || obItems[q] == "Morph Ball") && !hasMorph){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasMorph = true;
		foundItems = true;}
	if((obItems[q] == "Bombs" || obItems[q] == "Morph Ball Bomb") && !hasBombs){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		if(hasGravity && !(hasVaria || hasPhazon)){
			bombsWithoutGravity = false;
		}
		else bombsWithoutGravity = true;
		hasBombs = true;
		foundItems = true;}
	if((obItems[q] == "Varia" || obItems[q] == "Varia Suit") && !hasVaria){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasSuit = true;
		hasVaria = true;
		foundItems = true;}
	if((obItems[q] == "Gravi" || obItems[q] == "Gravity Suit") && !hasGravity)
		{
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasSuit = true;
		hasGravity = true;
		foundItems = true;}
	if((obItems[q] == "Phazo" || obItems[q] == "Phazon Suit") && !hasPhazon)
		{
			if(verbose){
			cout << getItemLocation(logs, obItems[q]) << endl;
			}
		hasSuit = true;
		hasPhazon = true;
		foundItems = true;}
	if((obItems[q] == "Boost" || obItems[q] == "Boost Ball") && !hasBoost){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasBoost = true;
		foundItems = true;}
	if((obItems[q] == "Space" || obItems[q] == "Space Jump Boots") && !hasSJ){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasSJ = true;
		foundItems = true;}
	if((obItems[q] == "Grapp" || obItems[q] == "Grapple Beam") && !hasGrapple){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasGrapple = true;
		foundItems = true;}
	if((obItems[q] == "Power" || obItems[q].substr(0,5) == "Power") && !hasPB){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasPB = true;
		foundItems = true;}
	if((obItems[q] == "Wave " || obItems[q] == "Wave Beam") && !hasWave){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasWave = true;
		foundItems = true;}
	if((obItems[q] == "Ice B" || obItems[q] == "Ice Beam") && !hasIce){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasIce = true;
		foundItems = true;}
	if((obItems[q] == "Plasm" || obItems[q] == "Plasma Beam") && !hasPlasma){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasPlasma = true;
		foundItems = true;}
	if((obItems[q] == "Spide" || obItems[q] == "Spider Ball") && !hasSpider){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasSpider = true;
		foundItems = true;}
	if((obItems[q] == "X-Ray" || obItems[q] == "X-Ray Visor") && !hasXray){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasXray = true;
		foundItems = true;}
	if((obItems[q] == "Charg" || obItems[q] == "Charge Beam") && !hasCharge){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasCharge = true;
		foundItems = true;}
	if((obItems[q] == "Super" || obItems[q] == "Super Missile") && !hasSuper){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasSuper = true;
		foundItems = true;}
	if(obItems[q] == "Energ" || obItems[q].substr(0,6) == "Energy"){

		e++;}
	if((obItems[q] == "Therm" || obItems[q] == "Thermal Visor") && !hasThermal){
		if(verbose){
		cout << getItemLocation(logs, obItems[q]) << endl;
		}
		hasThermal = true;
		foundItems = true;}
	if(obItems[q] == "Artif" || obItems[q].substr(0,8) == "Artifact"){				//need to add a substring thingy when I add the full name
			art++;}

	q++;
	}
	if(e > prevEtankCount){
		foundItems = true;
	}
	if(art > prevArt){
		foundItems = true;
	}

	if(firstCheck){
		foundItems = true;
		firstCheck = false;
	}

	return foundItems;
}

string LogChecker::getItemLocation(vector<string> logLines, string item){
	int n = 2;
  //cout << n << endl;
	//cout << logLines[n] << endl;
	//cout << logLines[n].substr(51, logLines[n].length() - 51) << endl;
  //cout << logLines[19].substr(51, logLines[19].length() - 51) << endl;
	while(logLines[n].substr(51, logLines[n].length() - 51) != item){

		n++;
	}
	return logLines[n];
}

void LogChecker::checkEarlyMines(){
int fry = 0;

while(fry < 7){
	if(earlyMinesItems[fry] == "Space" || earlyMinesItems[fry] == "Space Jump Boots"){
		earlyMinesSJ = true;
	}
	if(earlyMinesItems[fry] == "Spide" || earlyMinesItems[fry] == "Spider Ball"){
		earlyMinesSpider = true;
	}
	if(earlyMinesItems[fry] == "Power" || earlyMinesItems[fry].substr(0,5) == "Power"){
		earlyMinesPB = true;
	}
	if(earlyMinesItems[fry] == "Plasm" || earlyMinesItems[fry] == "Plasma Beam"){
		earlyMinesPlasma = true;
	}
	if(earlyMinesItems[fry] == "Gravi" || earlyMinesItems[fry] == "Gravity Suit"){
		earlyMinesGravity = true;
	}
	if(earlyMinesItems[fry] == "Boost" || earlyMinesItems[fry] == "Boost Ball"){
		earlyMinesBoost = true;
	}
	fry++;
	}

}

void LogChecker::checkDeepMines(){
int cletus = 0;

while(cletus < 9){
	if(deepMinesItems[cletus] == "Space" || deepMinesItems[cletus] == "Space Jump Boots"){
		deepMinesSJ = true;
	}
	if(deepMinesItems[cletus] == "Spide" || deepMinesItems[cletus] == "Spider Ball"){
		deepMinesSpider = true;
	}
	if(deepMinesItems[cletus] == "X-Ray" || deepMinesItems[cletus] == "X-Ray Visor"){
		deepMinesXray = true;
	}
	if(deepMinesItems[cletus] == "Power" || deepMinesItems[cletus].substr(0,5) == "Power"){
		deepMinesPB = true;
	}
	if(deepMinesItems[cletus] == "Plasm" || deepMinesItems[cletus] == "Plasma Beam"){
		deepMinesPlasma = true;
	}
	if(deepMinesItems[cletus] == "Charg" || deepMinesItems[cletus] == "Charge Beam"){
		deepMinesCharge = true;
	}
	if(deepMinesItems[cletus] == "Super" || deepMinesItems[cletus] == "Super Missile"){
		deepMinesSuper = true;
	}
	if(deepMinesItems[cletus] == "Grapp" || deepMinesItems[cletus] == "Grapple Beam"){
		deepMinesGrapple = true;
	}
	if(deepMinesItems[cletus] == "Phazo" || deepMinesItems[cletus] == "Phazon Suit"){
		deepMinesPhazon = true;
	}
	if(deepMinesItems[cletus]== "Boost" || deepMinesItems[cletus] == "Boost Ball"){
		deepMinesBoost = true;
	}
	if(deepMinesItems[cletus] == "Gravi" || deepMinesItems[cletus] == "Gravity Suit"){
		deepMinesGravity = true;
	}
	cletus++;
}
}

void LogChecker::checkDeepPhen(){
int deluxor = 0;

while(deluxor < 4){
	if(deepPhenItems[deluxor] == "Bombs" || deepPhenItems[deluxor] == "Morph Ball Bomb"){
		deepPhenBombs = true;
	}
	if(deepPhenItems[deluxor] == "Space" || deepPhenItems[deluxor] == "Space Jump Boots"){
		deepPhenSJ = true;
	}
	if(deepPhenItems[deluxor] == "Gravi" || deepPhenItems[deluxor] == "Gravity Suit"){
		deepPhenGravity = true;
	}
	if(deepPhenItems[deluxor] == "Plasm" || deepPhenItems[deluxor] == "Plasma Beam"){
		deepPhenPlasma = true;
	}
	if(deepPhenItems[deluxor] == "Grapp" || deepPhenItems[deluxor] == "Grapple Beam"){
		deepPhenGrapple = true;
	}
	if(deepPhenItems[deluxor] == "Power" || deepPhenItems[deluxor].substr(0,5) == "Power"){
		deepPhenPB = true;
	}
	deluxor++;
}
}

void LogChecker::countArtifacts(){
 	int d = 0;
	while(d < 200){
	if(obItems[d] == "Artif" || obItems[d].substr(0,8) == "Artifact"){				//need to add a substring thingy when I add the full name
		a++;}
	d++;
}
}

bool LogChecker::isHundo(){
int g = 0;
 while ( g < 101 )
    {
      if (g>1){
	if(!isAdded[g])
		return false;



      }
	g++;


    }
return true;
}

bool LogChecker::returnCompletableNormal(){

return isCompletableNormal;
}


bool LogChecker::returnCompletableVeteran(){
	return isCompletableVeteran;
}

bool LogChecker::returnCompletableEasy(){
	return isCompletableEasy;
}

bool LogChecker::returnCompletableHypermode(){
	return isCompletableHypermode;
}

string LogChecker::returnSeed(){
	return seedString;
}

string LogChecker::returnExceptions(){
	return seedExceptions;
}

void LogChecker::printList(){

	vector <string> items(103, "");
vector <string> logline(103, "");
	ifstream myfile ("cuck.txt");
	int x = 0;
	bool skip = false;
	while(getline(myfile,logline[x])){
		if(x>1){
		lineLength = logline[x].size() - 51;
		items[x] = logline[x].substr(51,lineLength);}
		if(!skip)
			skip = true;
		else x++;
	}

	int sh = 0;

	while(sh < 102){
	cout << items[sh] << '\n';
	sh++;}
	sh = 0;
	cout << items[0] << endl;
	cout << items[1] << endl;
	cout << items[2] << endl;

}

void LogChecker::resetFlags(){
	isCompletableNormal = false;
	isCompletableEasy = false;
	isCompletableVeteran = false;
	isCompletableHypermode = false;
}

vector <string> LogChecker::getItemNames(){
  vector <string> itemNames(100, "");
    static const string items[] = {"Missile Expansion 1", "Missile Expansion 2", "Missile Expansion 3", "Energy Tank 1", "Missile Expansion 4", "Morph Ball", "Missile Expansion 5", "Missile Expansion 6", "Missile Expansion 7", "Energy Tank 2", "Missile Expansion 8", "Missile Expansion 9", "Power Bomb Expansion 1", "Wavebuster", "Artifact of Lifegiver", "Missile Expansion 10", "Missile Expansion 11", "Energy Tank 3", "Missile Expansion 12", "Missile Launcher", "Varia Suit", "Artifact of Wild", "Missile Expansion 13", "Charge Beam", "Missile Expansion 14", "Missile Expansion 15", "Missile Expansion 16", "Missile Expansion 17", "Morph Ball Bomb", "Missile Expansion 18", "Energy Tank 4", "Energy Tank 5", "Missile Expansion 19", "Artifact of World", "Ice Beam", "Missile Expansion 20", "Missile Expansion 21", "Artifact of Sun", "Power Bomb Expansion 2", "Missile Expansion 22", "Missile Expansion 23", "Wave Beam", "Energy Tank 6", "Boost Ball", "Spider Ball", "Missile Expansion 24", "Missile Expansion 25", "Super Missile", "Energy Tank 7", "Artifact of Elder", "Thermal Visor", "Missile Expansion 26", "Energy Tank 8", "Missile Expansion 27", "Gravity Suit", "Missile Expansion 28", "Artifact of Spirit", "Power Bomb Expansion 3", "Missile Expansion 29", "Space Jump Boots", "Missile Expansion 30", "Missile Expansion 31", "Missile Expansion 32", "Artifact of Truth", "Missile Expansion 33", "Missile Expansion 34", "Energy Tank 9", "Missile Expansion 35", "Energy Tank 10", "Missile Expansion 36", "Missile Expansion 37", "X-Ray Visor", "Artifact of Chozo", "Missile Expansion 38", "Missile Expansion 39", "Grapple Beam", "Flamethrower", "Artifact of Warrior", "Missile Expansion 40", "Missile Expansion 41", "Energy Tank 11", "Missile Expansion 42", "Energy Tank 12", "Phazon Suit", "Power Bomb", "Missile Expansion 43", "Missile Expansion 44", "Missile Expansion 45", "Artifact of Newborn", "Missile Expansion 46", "Artifact of Nature", "Missile Expansion 47", "Missile Expansion 48", "Energy Tank 13", "Artifact of Strength", "Ice Spreader", "Missile Expansion 49", "Power Bomb Expansion 4", "Plasma Beam", "Energy Tank 14"};
    for(int k = 0; k < itemNames.size(); k++){
      itemNames[k] = items[k];
    }
    return itemNames;
}

vector <string> LogChecker::getAreaNames(){
  vector <string> worldAndRoomNames(100,"");
  static const string room[] = {"Chozo - - - Main Plaza (Half-Pipe) - - - - - - - - ", "Chozo - - - Main Plaza (Grapple Ledge) - - - - - - ", "Chozo - - - Main Plaza (Tree)  - - - - - - - - - - ", "Chozo - - - Main Plaza (Locked Door) - - - - - - - ", "Chozo - - - Ruined Fountain  - - - - - - - - - - - ", "Chozo - - - Ruined Shrine (\"Beetle Battle\")  - - - ", "Chozo - - - Ruined Shrine (Half-Pipe)  - - - - - - ", "Chozo - - - Ruined Shrine (Lower Tunnel) - - - - - ", "Chozo - - - Vault  - - - - - - - - - - - - - - - - ", "Chozo - - - Training Chamber - - - - - - - - - - - ", "Chozo - - - Ruined Nursery - - - - - - - - - - - - ", "Chozo - - - Training Chamber Access  - - - - - - - ", "Chozo - - - Magma Pool - - - - - - - - - - - - - - ", "Chozo - - - Tower of Light - - - - - - - - - - - - ", "Chozo - - - Tower Chamber  - - - - - - - - - - - - ", "Chozo - - - Ruined Gallery (Missile Wall)  - - - - ", "Chozo - - - Ruined Gallery (Tunnel)  - - - - - - - ", "Chozo - - - Transport Access North - - - - - - - - ", "Chozo - - - Gathering Hall - - - - - - - - - - - - ", "Chozo - - - Hive Totem - - - - - - - - - - - - - - ", "Chozo - - - Sunchamber (Flaahgra)  - - - - - - - - ", "Chozo - - - Sunchamber (Ghosts)  - - - - - - - - - ", "Chozo - - - Watery Hall Access - - - - - - - - - - ", "Chozo - - - Watery Hall (Scan Puzzle)  - - - - - - ", "Chozo - - - Watery Hall (Underwater) - - - - - - - ", "Chozo - - - Dynamo (Lower) - - - - - - - - - - - - ", "Chozo - - - Dynamo (Spider Track)  - - - - - - - - ", "Chozo - - - Burn Dome (Missile)  - - - - - - - - - ", "Chozo - - - Burn Dome (I. Drone) - - - - - - - - - ", "Chozo - - - Furnace (Spider Tracks)  - - - - - - - ", "Chozo - - - Furnace (Inside Furnace) - - - - - - - ", "Chozo - - - Hall of the Elders - - - - - - - - - - ", "Chozo - - - Crossway - - - - - - - - - - - - - - - ", "Chozo - - - Elder Chamber  - - - - - - - - - - - - ", "Chozo - - - Antechamber  - - - - - - - - - - - - - ", "Phendrana - Phendrana Shorelines (Behind Ice)  - - ", "Phendrana - Phendrana Shorelines (Spider Track)  - ", "Phendrana - Chozo Ice Temple - - - - - - - - - - - ", "Phendrana - Ice Ruins West - - - - - - - - - - - - ", "Phendrana - Ice Ruins East (Behind Ice)  - - - - - ", "Phendrana - Ice Ruins East (Spider Track)  - - - - ", "Phendrana - Chapel of the Elders - - - - - - - - - ", "Phendrana - Ruined Courtyard - - - - - - - - - - - ", "Phendrana - Phendrana Canyon - - - - - - - - - - - ", "Phendrana - Quarantine Cave  - - - - - - - - - - - ", "Phendrana - Research Lab Hydra - - - - - - - - - - ", "Phendrana - Quarantine Monitor - - - - - - - - - - ", "Phendrana - Observatory  - - - - - - - - - - - - - ", "Phendrana - Transport Access - - - - - - - - - - - ", "Phendrana - Control Tower  - - - - - - - - - - - - ", "Phendrana - Research Core  - - - - - - - - - - - - ", "Phendrana - Frost Cave - - - - - - - - - - - - - - ", "Phendrana - Research Lab Aether (Tank) - - - - - - ", "Phendrana - Research Lab Aether (Morph Track)  - - ", "Phendrana - Gravity Chamber (Underwater) - - - - - ", "Phendrana - Gravity Chamber (Grapple Ledge)  - - - ", "Phendrana - Storage Cave - - - - - - - - - - - - - ", "Phendrana - Security Cave  - - - - - - - - - - - - ", "Tallon  - - Landing Site - - - - - - - - - - - - - ", "Tallon  - - Alcove - - - - - - - - - - - - - - - - ", "Tallon  - - Frigate Crash Site - - - - - - - - - - ", "Tallon  - - Overgrown Cavern - - - - - - - - - - - ", "Tallon  - - Root Cave  - - - - - - - - - - - - - - ", "Tallon  - - Artifact Temple  - - - - - - - - - - - ", "Tallon  - - Transport Tunnel B - - - - - - - - - - ", "Tallon  - - Arbor Chamber  - - - - - - - - - - - - ", "Tallon  - - Cargo Freight Lift to Deck Gamma - - - ", "Tallon  - - Biohazard Containment  - - - - - - - - ", "Tallon  - - Hydro Access Tunnel  - - - - - - - - - ", "Tallon  - - Great Tree Chamber - - - - - - - - - - ", "Tallon  - - Life Grove Tunnel  - - - - - - - - - - ", "Tallon  - - Life Grove (Start) - - - - - - - - - - ", "Tallon  - - Life Grove (Underwater Spinner)  - - - ", "Mines - - - Main Quarry  - - - - - - - - - - - - - ", "Mines - - - Security Access A  - - - - - - - - - - ", "Mines - - - Storage Depot B  - - - - - - - - - - - ", "Mines - - - Storage Depot A  - - - - - - - - - - - ", "Mines - - - Elite Research (Phazon Elite)  - - - - ", "Mines - - - Elite Research (Laser) - - - - - - - - ", "Mines - - - Elite Control Access - - - - - - - - - ", "Mines - - - Ventilation Shaft  - - - - - - - - - - ", "Mines - - - Phazon Processing Center - - - - - - - ", "Mines - - - Processing Center Access - - - - - - - ", "Mines - - - Elite Quarters - - - - - - - - - - - - ", "Mines - - - Central Dynamo - - - - - - - - - - - - ", "Mines - - - Metroid Quarantine B - - - - - - - - - ", "Mines - - - Metroid Quarantine A - - - - - - - - - ", "Mines - - - Fungal Hall B  - - - - - - - - - - - - ", "Mines - - - Phazon Mining Tunnel - - - - - - - - - ", "Mines - - - Fungal Hall Access - - - - - - - - - - ", "Magmoor - - Lava Lake  - - - - - - - - - - - - - - ", "Magmoor - - Triclops Pit - - - - - - - - - - - - - ", "Magmoor - - Storage Cavern - - - - - - - - - - - - ", "Magmoor - - Transport Tunnel A - - - - - - - - - - ", "Magmoor - - Warrior Shrine - - - - - - - - - - - - ", "Magmoor - - Shore Tunnel - - - - - - - - - - - - - ", "Magmoor - - Fiery Shores (Morph Track) - - - - - - ", "Magmoor - - Fiery Shores (Warrior Shrine Tunnel) - ", "Magmoor - - Plasma Processing  - - - - - - - - - - ", "Magmoor - - Magmoor Workstation  - - - - - - - - - "};
  for(int k = 0; k < worldAndRoomNames.size(); k++){
    worldAndRoomNames[k] = room[k];
  }
  return worldAndRoomNames;
}

vector <int> LogChecker::shrinkIntVector(vector <int> inVector){
  vector <int> newList(inVector.size()-1);
  if(newList.size() == 0){
    return newList;
  }

  for(int i = 0; i < newList.size(); i++){
    newList[i] = inVector[i+1];
  }
  return newList;
}

vector <int> LogChecker::removeIntElement(vector <int> inVector, int element){
  vector <int> newList(inVector.size()-1);
  if(newList.size() == 0){
    return newList;
  }

  for(int k = 0; k < element; k++){
    newList[k] = inVector[k];
  }

  for(int i = element; i < newList.size(); i++){
    newList[i] = inVector[i+1];
  }
  return newList;
}

vector <string> LogChecker::shrinkStringVector(vector <string> inVector){
  vector <string> newList(inVector.size()-1);
  if(newList.size() == 0){
    return newList;
  }

  for(int i = 0; i < newList.size(); i++){
    newList[i] = inVector[i+1];
  }
  return newList;
}
vector <string> LogChecker::removeStringElement(vector <string> inVector, int element){
  vector <string> newList(inVector.size()-1);
  if(newList.size() == 0){
    return newList;
  }

  for(int k = 0; k < element; k++){
    newList[k] = inVector[k];
  }

  for(int i = element; i < newList.size(); i++){
    newList[i] = inVector[i+1];
  }

  return newList;
}


vector <string> LogChecker::randomize(vector <string> originalList, vector <int> excludedItems, int seed){
  //originalList must have first 3 lines removed before adding!!

  vector <string> orderedItems(originalList.size(), "");
  vector <int> addedItems(originalList.size());
  vector <string> randomizedItems(originalList.size(), "");

  for(int imDumb = 0; imDumb < originalList.size(); imDumb++){
    orderedItems[imDumb] = originalList[imDumb];
  }



  for(int z = 0; z < addedItems.size(); z++){
    addedItems[z] = z;
  }


 //add excludedItems


 for(int z = 0; z < excludedItems.size(); z++){

   randomizedItems[excludedItems[z]] = orderedItems[excludedItems[z]];
 }

 for(int z = 0; z < excludedItems.size(); z++){
   orderedItems = removeStringElement(orderedItems, excludedItems[z] - z);
   addedItems = removeIntElement(addedItems, excludedItems[z] - z);


 }

 //begin Randomizing

 Random * randomizer = new Random();
 randomizer->setup(seed);
 while(orderedItems.size() > 0){

   int number = randomizer->Next(addedItems.size());
   randomizedItems[addedItems[number]] = orderedItems[0];
   //cout << "added first orderedItem to randomizedItems" << endl;
   orderedItems = shrinkStringVector(orderedItems);
   //cout << "shrank orderedItems" << endl;
   addedItems = removeIntElement(addedItems, number);
   //cout << "removed the random element from addedItems" << endl;
 }


  return randomizedItems;
}

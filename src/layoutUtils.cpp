#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "layoutUtils.h"
#include "BigInteger/BigUnsigned.hh"
#include "BigInteger/BigIntegerUtils.hh"
#include "BigInteger/BigUnsignedInABase.hh"

using namespace std;

int compute_checksum(BigUnsigned layout_number){
   int         s = 0;
   BigUnsigned b(32);
   BigUnsigned remainderToBe;

   while(layout_number > 0){
      layout_number.divideWithRemainder(b, remainderToBe); //layout_number becomes remainder
      BigUnsigned swap;                                    //remainderToBe becomes quotient
      swap          = remainderToBe;                       //need to swap these
      remainderToBe = layout_number;
      layout_number = swap;
      s             = (s + remainderToBe.toInt()) % 32;
   }
   return(s);
}


vector<int> decode_pickup_layout(string layout_string){

   string TABLE = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklmnopqrstuwvxyz0123456789-_";
   std::map<char,int> REV_TABLE;
   for(int i = 0; i < TABLE.length(); i++){
      REV_TABLE.insert(pair<char,int>(TABLE[i], i));
   }

   BigUnsigned num(0);
   
   for(int i = layout_string.length() - 1; i >= 0; i--){
      num.bitShiftLeft(num,6);
      num += REV_TABLE.find(layout_string[i])->second;
   }

   string all_bits = bigUnsignedToString(num, 2);

   //cout << "all_bits: " << all_bits << endl;
   vector<char>even_bits(0);
   vector<char>odd_bits(0);

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

   reverse(odd_bits.begin(), odd_bits.end());
   vector<char>all_bits_array(0);

   for(int z = 0; z < even_bits.size(); z++){
      if(even_bits[z] == '1' || even_bits[z] == '0'){
         all_bits_array.push_back(even_bits[z]);
      }
      if(odd_bits[z] == '1' || odd_bits[z] == '0'){
         all_bits_array.push_back(odd_bits[z]);
      }
   }

   int invalidCount = 0;
   for(int badCount = 0; badCount < all_bits_array.size(); badCount++){
      if(!(all_bits_array[badCount] == '1' || all_bits_array[badCount] == '0')){
         invalidCount++;
      }
   }

   string all_bits_conversion = "";

   for(int t = 0; t < all_bits_array.size(); t++){
      all_bits_conversion += all_bits_array[t];
   }
   const std::string all_bits_const = all_bits_conversion;

   BigUnsignedInABase Lary(all_bits_const, 2); //creates bigUnsigned in base 2
   BigUnsigned Jerry(Lary);    //converts Lary to base 10 as Jerry
   
   num = Jerry;

   BigUnsigned checksum_value(num);
   checksum_value.bitShiftRight(checksum_value, 517);

   BigUnsigned temp(checksum_value);
   temp.bitShiftLeft(temp, 517);

   num -= temp;

   int cs_value = checksum_value.toInt();

   if(cs_value != compute_checksum(num)){
	   cout << "Invalid layout: checksum failed" << endl;
   }

   vector<int> layout;
   BigUnsigned b(36);
   BigUnsigned remainderToBe;
   for(int i = 0; i < 100; i++){ 
      num.divideWithRemainder(b, remainderToBe);     //num becomes remainder
      BigUnsigned swap;                              //remainderToBe becomes quotient
      swap          = remainderToBe;                 //need to swap these
      remainderToBe = num;
      num           = swap;
     
      layout.push_back(remainderToBe.toInt());
   }
   reverse(layout.begin(), layout.end());
   return layout;

}

string encode_pickup_layout(vector<int>layout){
   string      TABLE = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklmnopqrstuwvxyz0123456789-_";
   BigUnsigned num(0);

   for(int i = 0; i < layout.size(); i++){
      num *= 36;
      num += layout[i];
   }


   int         checksum = compute_checksum(num);
   BigUnsigned bigChecksum(checksum);
   bigChecksum.bitShiftLeft(bigChecksum, 517);
   num += bigChecksum;

   //here i think?
   string all_bits = bigUnsignedToString(num, 2);

   //cout << "all_bits: " << all_bits << endl;
   vector<char>even_bits(0);
   vector<char>odd_bits(0);

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

   reverse(odd_bits.begin(), odd_bits.end());
   vector<char>all_bits_array(0);

   for(int z = 0; z < even_bits.size(); z++){
      if(even_bits[z] == '1' || even_bits[z] == '0'){
         all_bits_array.push_back(even_bits[z]);
      }
      if(odd_bits[z] == '1' || odd_bits[z] == '0'){
         all_bits_array.push_back(odd_bits[z]);
      }
   }

   int invalidCount = 0;
   for(int badCount = 0; badCount < all_bits_array.size(); badCount++){
      if(!(all_bits_array[badCount] == '1' || all_bits_array[badCount] == '0')){
         invalidCount++;
      }
   }

   string all_bits_conversion = "";

   for(int t = 0; t < all_bits_array.size(); t++){
      all_bits_conversion += all_bits_array[t];
   }
   const std::string all_bits_const = all_bits_conversion;

   BigUnsignedInABase Lary(all_bits_const, 2); //creates bigUnsigned in base 2

   BigUnsigned Jerry(Lary);                    //converts Lary to base 10 as Jerry
   //to here?
   string s = "";

   BigUnsigned b(64);
   BigUnsigned remainderToBe;
   for(int countEightySeven = 0; countEightySeven < 87; countEightySeven++){
      Jerry.divideWithRemainder(b, remainderToBe);        //Jerry becomes remainder
      BigUnsigned swap;                                   //remainderToBe becomes quotient
      swap          = remainderToBe;                      //need to swap these
      remainderToBe = Jerry;
      Jerry         = swap;

      s = s + TABLE[remainderToBe.toInt()];
   }

   return(s);
}

vector<string> layoutIntToString(vector<int> intLayout){
   vector<string> stringLayout;
   int missileCount = 0, etankCount = 0, pbCount = 0;

   for(int i : intLayout){
      string item = "";
      switch(i){
         case 0 :
	    item = "Missile " + to_string(missileCount);
	    missileCount++;
	    break;
         case 1 :
	    item = "Energy Tanki " + to_string(etankCount);
	    etankCount++;
	    break;
         case 2 :
	    item = "Thermal Visor";
	    break;
         case 3 :
	    item = "X-Ray Visor";
	    break;
         case 4 :
	    item = "Varia Suit";
	    break;
         case 5 :
	    item = "Gravity Suit";
	    break;
         case 6 :
	    item = "Phazon Suit";
	    break;
         case 7 :
	    item = "Morph Ball";
	    break;
         case 8 :
	    item = "Boost Ball";
	    break;
         case 9 :
	    item = "Spider Ball";
	    break;
         case 10 :
	    item = "Morph Ball Bomb";
	    break;
         case 11 :
	    item = "Power Bomb Expansion " + to_string(pbCount);
	    pbCount++;
	    break;
         case 12 :
	    item = "Power Bomb";
	    break;
         case 13 :
	    item = "Charge Beam";
	    break;
         case 14 :
	    item = "Space Jump Boots";
	    break;
         case 15 :
	    item = "Grapple Beam";
	    break;
         case 16 :
	    item = "Super Missile";
	    break;
         case 17 :
	    item = "Wavebuster";
	    break;
         case 18 :
	    item = "Ice Spreader";
	    break;
         case 19 :
	    item = "Flamethrower";
	    break;
         case 20 :
	    item = "Wave Beam";
	    break;
         case 21 :
	    item = "Ice Beam";
	    break;
         case 22 :
	    item = "Plasma Beam";
	    break;
         case 23 :
	    item = "Artifact of Lifegiver";
	    break;
         case 24 :
	    item = "Artifact of Wild";
	    break;
         case 25 :
	    item = "Artifact of World";
	    break;
         case 26 :
	    item = "Artifact of Sun";
	    break;
         case 27 :
	    item = "Artifact of Elder";
	    break;
         case 28 :
	    item = "Artifact of Spirit";
	    break;
         case 29 :
	    item = "Artifact of Truth";
	    break;
         case 30 :
	    item = "Artifact of Chozo";
	    break;
         case 31 :
	    item = "Artifact of Warrior";
	    break;
         case 32 :
	    item = "Artifact of Newborn";
	    break;
         case 33 :
	    item = "Artifact of Nature";
	    break;
         case 34 :
	    item = "Artifact of Strength";
	    break;
         case 35 :
	    item = "Nothing";
	    break;
      }
      stringLayout.push_back(item);   
   }
   return stringLayout;
}

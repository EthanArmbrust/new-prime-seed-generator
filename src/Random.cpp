#include <iostream>
#include <cmath>
#include "Random.h"

using namespace std;

    Random::Random(){

     }

       void Random::setup(int Seed){
         int ii;
         int mj, mk;

         //Initialize our Seed array.
         //This algorithm comes from Numerical Recipes in C (2nd Ed.)
         int subtraction = (Seed == -2147483648) ? 0x7fffffff : abs(Seed);
         mj = MSEED - subtraction;
         SeedArray[55]=mj;
         mk=1;
         for (int i=1; i<55; i++) {  //Apparently the range [1..55] is special (Knuth) and so we're wasting the 0'th position.
           ii = (21*i)%55;
           SeedArray[ii]=mk;
           mk = mj - mk;
           if (mk<0) mk+=MBIG;
           mj=SeedArray[ii];
         }
         for (int k=1; k<5; k++) {
           for (int i=1; i<56; i++) {
         SeedArray[i] -= SeedArray[1+(i+30)%55];
         if (SeedArray[i]<0) SeedArray[i]+=MBIG;
           }
         }
         inext=0;
         inextp = 21;
         Seed = 1;
       }

       int Random::Next(int maxValue){
         return (int) (this->Sample() * maxValue);
       }

       int Random::Next(int minValue, int maxValue){
         long num = maxValue - minValue;
         if (num <= 0x7fffffffL)
         {
             return (((int) (this->Sample() * num)) + minValue);
         }
         return (((int) ((long) (this->GetSampleForLargeRange() * num))) + minValue);

       }

       double Random::GetSampleForLargeRange()
       {
           int num = this->InternalSample();
           if ((this->InternalSample() % 2) == 0)
           {
               num = -num;
           }
           return ((num + 2147483646.0) / 4294967293);
       }

       int Random::InternalSample()
       {
           int inext = this->inext;
           int inextp = this->inextp;
           if (++inext >= 0x38)
           {
               inext = 1;
           }
           if (++inextp >= 0x38)
           {
               inextp = 1;
           }
           int num = this->SeedArray[inext] - this->SeedArray[inextp];
           if (num == 0x7fffffff)
           {
               num--;
           }
           if (num < 0)
           {
               num += 0x7fffffff;
           }
           this->SeedArray[inext] = num;
           this->inext = inext;
           this->inextp = inextp;
           return num;
       }

       double Random::Sample(){
         return (this->InternalSample() * 4.6566128752457969E-10);
       }

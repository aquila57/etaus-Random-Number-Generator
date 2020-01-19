#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Etaus.h"

using namespace std;

Etaus::Etaus(void)
   {
   int i;
   cout << "Etaus object is being created"  << endl;
   cout << "Seeds are being set"  << endl;
   mask = 0xffffffff;
   srand(time(NULL));
   s1 = ((rand() << 1)^(rand() >> 28)) & mask;
   s2 = ((rand() << 1)^(rand() >> 28)) & mask;
   s3 = ((rand() << 1)^(rand() >> 28)) & mask;
   prev = ((rand() << 1)^(rand() >> 28)) & mask;
   pprev = ((rand() << 1)^(rand() >> 28)) & mask;
   maxint = 65536.0;
   maxint *= 65536.0;
   //--------------------------------------------------
   // Initialize the array of Bays-Durham registers
   //--------------------------------------------------
   for (i=0;i<16384;i++)
      {
      state[i] = ((rand() << 1)^(rand() >> 28)) & mask;
      } /* for each Bays-Durham register */
   } // Etaus::Etaus

unsigned int Etaus::etaus(void)
         {
	 int ofst;
	 unsigned int tmp;
	 pprev = prev;
	 prev  = out;
	 s1 = (((s1&4294967294)<<12)^(((s1<<13)^s1)>>19))&mask;
	 s2 = (((s2&4294967288)<<4)^(((s2<<2)^s2)>>25))&mask;
	 s3 = (((s3&4294967280)<<17)^(((s3<<3)^s3)>>11))&mask;
	 s  = (s1 ^ s2 ^ s3) & mask;
	 out = (s ^ prev ^ pprev) & mask;
	 ofst = out >> 18;
	 tmp = state[ofst] & mask;
	 state[ofst] = out;
	 out = tmp;
	 out = (out ^ prev ^ pprev) & mask;
	 return out;
	 } // Etaus::etaus

unsigned int Etaus::get_etaus(void)
         {
	 return out;
	 } // Etaus::get_etaus

double Etaus::get_dbl_etaus(void)
         {
	 double num;
	 num = (double) out / maxint;
	 return num;
	 } // Etaus::get_dbl_etaus

int Etaus::get_etaus_int(int lmt)
         {
	 int x;
	 double num;
	 num = (double) out / maxint;
	 x = (int) floor(num * (double) lmt);
	 return x;
	 } // Etaus::get_etaus_int

unsigned int Etaus::get_etaus_pwr(int bits)
         {
	 unsigned int x;
	 x = out >> (32-bits);
	 return x;
	 } // Etaus::get_etaus_pwr

void Etaus::display(void)
         {
	 cout << "s1    " << s1 << endl;
	 cout << "s2    " << s2 << endl;
	 cout << "s3    " << s3 << endl;
	 cout << "s     " << s << endl;
	 cout << "out   " << out << endl;
	 cout << "prev  " << prev << endl;
	 cout << "pprev " << pprev << endl;
	 } // Etaus::display

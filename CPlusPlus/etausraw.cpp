/* etausraw.cpp - C++ Generate raw data  Version 0.1.0               */
/* Copyright (C) 2020 aquila57 at github.com                         */

/* This program is free software; you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License as    */
/* published by the Free Software Foundation; either version 2 of    */
/* the License, or (at your option) any later version.               */

/* This program is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of    */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      */
/* GNU General Public License for more details.                      */

/* You should have received a copy of the GNU General Public License */
/* along with this program; if not, write to:                        */

   /* Free Software Foundation, Inc.                                 */
   /* 59 Temple Place - Suite 330                                    */
   /* Boston, MA 02111-1307, USA.                                    */

/* This program generates binary data as input to           */
/* dieharder.                                               */

#include "Etaus.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#define TRIALS (131072)

using namespace std;

int main(void)
   {
   /*********************************************************/
   /* initialize the etaus generator                        */
   /* with the constructor routine                          */
   /*********************************************************/
   Etaus et;
   /*********************************************************/
   /* Generate unlimited binary data to be read by          */
   /* dieharder.                                            */
   /*********************************************************/
   while (1)           /* infinite loop                      */
      {
      unsigned char c1;       /* 8 bits of binary data */
      unsigned char c2;       /* 8 bits of binary data */
      unsigned char c3;       /* 8 bits of binary data */
      unsigned char c4;       /* 8 bits of binary data */
      unsigned int num;
      num = et.etaus();
      c1 = (unsigned char) (num >> 24) & 255;
      c2 = (unsigned char) (num >> 16) & 255;
      c3 = (unsigned char) (num >> 8)  & 255;
      c4 = (unsigned char) num & 255;
      printf("%c%c%c%c", c1, c2, c3, c4);
      } /* for each m-bit sample */
   return 0;
   } /* main */

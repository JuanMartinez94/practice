365#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char rgbimage[SIZE][SIZE][RGB];

int main() {

   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }

   for(int i=0; i < SIZE; i++) {
      image[i][128] = 0;
      image[128][i] = 0;
      // every 20 steps, display
      // if (i%20==0) showGSBMP(image);
   }

   // at end, display complete image
   // showGSBMP(image);
   
   // save to file
   writeGSBMP("cross.bmp", image);
   return 0;
}

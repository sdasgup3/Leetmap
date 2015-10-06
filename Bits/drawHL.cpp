#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cassert>


void drawHorizontalline(char screen[], int width, int x1, int x2, int y) {

  int start_byte  = y*width + x1 /8;
  int end_byte    = y*width + x2 /8;

  std::cout << " strat " <<  start_byte << " end " << end_byte << std::endl;

  int rem_start_byte = 8 - x1%8 ;
  int rem_end_byte =  8 - (x2%8 + 1) ;

  char* start = &screen[start_byte];
  char* end   = &screen[end_byte  + 1];

  while(start != end) {
    *start = *start | 0xFF;
    start ++;
  }
  start = &screen[start_byte];
  end   = &screen[end_byte];

  *start  = *start  & (int (pow(2,rem_start_byte)) - 1);
  *end    = *end    & ~(int (pow(2,rem_end_byte)) - 1);
}

void toBinary(int I) {

  int size = 8;
  char arr[size];
  memset(arr,0,size );

  int index = size -1;

  if(I < 0) {
    arr[0]  = 1 ;
    unsigned int u = 2147483648;
    I =  u + I;
  }

  for(;(I!=0) && (index >= 1); index --) {
    int q = I /2;
    int r = I %2;
    arr[index] = r;
    I = q;
  }
  for(int i=0; i < size; i++) {
    std::cout << int(arr[i]) << " ";
  }
  std::cout << " || ";
}



int main(int argc, char** argv) {
  int width = 8;
  int arr_size = 80;
  int height = 10;
  int x1 = 12;
  int x2 = 54;
  int y = 5;

  char screen[arr_size];
  memset(screen, 0 , arr_size);
  drawHorizontalline(screen, width, x1, x2,  y);

  for(int i = 0 ; i < height ; i++) {
    for(int j = 0 ; j < width ; j++) {
      toBinary(screen[width*i + j]);    
    }
    std::cout << "\n";
  }
  return 0;
}

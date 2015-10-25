#include<iostream>
#include<cmath>

int main(){

  unsigned x = 1;
  for(; x < 20; x++) {

  if(0 == x) {
    return 0;
  }
  unsigned y;
  int mask = 1;
  
  while(0 == (x & mask)) {
    mask = mask << 1;
  }


  if(mask ==1 ) {
    while(0 != (x & mask)) {
      mask  = mask << 1;
    }
  }
  y = x ^ (mask | mask >> 1);  

  std::cout << " " << x<< " "<< y << "\n";
  }
  return 0;


}

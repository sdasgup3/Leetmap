/*
   Write an Efficient Method to Check if a Number is Multiple of 3

Algorithm: isMutlipleOf3(n)
1) Make n positive if n is negative.
2) If number is 0 then return 1
3) If number is 1 then return 0
4) Initialize: odd_count = 0, even_count = 0
5) Loop while n != 0
    a) If rightmost bit is set then increment odd count.
    b) Right-shift n by 1 bit
    c) If rightmost bit is set then increment even count.
    d) Right-shift n by 1 bit
6) return isMutlipleOf3(odd_count - even_count)
*/


#include<iostream>
#include<cassert>


bool
MO3_v1(int x) {
  int r = x % 3;
  return r == 0;
}

bool
MO3_v2(int x) {
  if(x < 0) {
    x = -1*x;
  }

  if(x == 0) return true;
  if(x == 1) return false;

  int even_1 = 0, odd_1=0;

  for(int i = 0 ; x; i++) {
    if(i%2) {
      even_1 += (x &1); 
    } else {
      odd_1 += (x &1); 
    }
    x = x /2;
  }

  return MO3_v2(even_1 - odd_1);
  
}


int 
main()
{

  for(int i = 0 ; i < 100 ; i ++ ) {
    assert((MO3_v1(i) && MO3_v2(i)) || (false == MO3_v1(i) && false == MO3_v2(i)) );
    if(MO3_v1(i) && MO3_v2(i)) {
      std::cout << i << " " ;
    }
  }
  std::cout <<"\n";
}

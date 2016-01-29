#include<iostream>


bool
MO3(int x) {
  if(0 == x) return false;
  while(1 != x) {
    int r = x % 3;
    if(0 != r) {
      return false;
    }
    x = x /3;
  }

  return true;
}


int 
main()
{

  for(int i = 0 ; i < 100 ; i ++ ) {
    if(MO3(i)) {
      std::cout << i << " " ;
    }
  }
  std::cout <<"\n";
}

/* Invert a number
 */

#include<iostream>

int 
R(int x) {
  int size  = 8*sizeof(int);

  int mask = 1;
  for(int  i= 0 ; i < size ; i ++) {
    x = x ^ (mask << i);  
  }

  return x;
}


int 
main()
{
  for(int i = -8 ; i <= 7 ; i ++ ) {
    std::cout << i << " " << R(i) << "\n";
  }
  std::cout <<"\n";
}

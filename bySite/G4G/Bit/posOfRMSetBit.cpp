#include<iostream>


int
P(int x) {
  if(0 == x) return 0;

  x = x & (-1*x);
  int count = 0;
  while(x) {
    x = x /2;
    count++;
  }

  return count;
}


int 
main()
{

  for(int i = -8 ; i <= 7 ; i ++ ) {
    std::cout << i << " "  << P(i) << " \n" ;
  }
  std::cout <<"\n";
}

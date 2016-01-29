#include<iostream>
#include<cmath>


bool
P1(int x) {
  int count = 0;

  if(x < 0) {
    x = std::pow(2,8*sizeof(int)-1) + x;
    count = 1;
  }

  while(x) {
    count += (x&1);
    x = x /2;
  }

  return 0 != count % 2;
}

bool 
P(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n      = n & (n - 1);
    }        
    return parity;
}
 
int 
main()
{

  for(int i = -8 ; i <=  7 ; i ++ ) {
    if(P(i)) {
      std::cout << i << "Odd \n" ;
    } else {
      std::cout << i << "Even \n" ;
    }
  }
  std::cout <<"\n";
}

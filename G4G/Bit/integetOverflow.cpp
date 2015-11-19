#include<iostream>
#include<cmath>



int 
main()
{
  int i = std::pow(2, 8*sizeof(int) -1) -1;

  int n = i +1;
  std::cout << i << " " << n << "\n";

}

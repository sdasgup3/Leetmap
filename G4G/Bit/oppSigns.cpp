#include<iostream>
#include<vector>
#include<cmath>

bool
OS(int n, int m) {
  int size = 8*sizeof(int);

  int mask = 1 << size - 1;
  int sign_n = n & mask;
  int sign_m = m & mask;

  return (0 == sign_n && 0 == sign_m) || (0 != sign_n && 0 != sign_m);
}

int 
main()
{
    std::cout << OS(2,3) << "\n";
    std::cout << OS(-2,3) << "\n";
    std::cout << OS(-2,-3) << "\n";
}

#include<iostream>
#include<vector>
#include<cmath>

int
S(int n, int p1, int p2) {
  int mask1 = 1 << p1;
  int mask2 = 1 << p2;

  int bit1 = (n & mask1) ? 1:0;
  int bit2 = (n & mask2) ? 1:0;

  if(bit1 != bit2) {
    n = n ^ mask1;
    n = n ^ mask2;
  }

  return n;

}

int 
main()
{
  int num = -6;
  std::cout << S(num, 0, 2) << "\n";
  std::cout << S(num, 1, 3) << "\n";
  std::cout << S(num, 1, 2) << "\n";
}

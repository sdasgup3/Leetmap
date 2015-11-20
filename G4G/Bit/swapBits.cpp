#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>

int
SW(int x, int p1, int p2, int n) {

  if(p1 > p2) {
    return n;
  }

  if(p1+n >= p2) {
    return n;
  }

  int mask1 = (1 << n) -1, mask2 =  (1 << n) -1;
  mask1 = mask1 << p1;
  mask2 = mask2 << p2;

  int value1 = x & mask1;
  int value2 = x & mask2;

  value1 = value1 << (p2-p1);
  value2 = value2 ^ value1;
  value1 = value2 >> (p2-p1);

  x = x ^ value1 ^ value2;

  return x;

}

int 
main()
{
  int num = -6;
  std::cout << SW(47, 1, 5, 3) << "\n";
  std::cout << SW(28, 0, 3, 2) << "\n";
}

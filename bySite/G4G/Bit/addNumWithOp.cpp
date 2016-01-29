#include<iostream>
#include<vector>
#include<cmath>
#define SIZE 8*sizeof(int)

void
setBit(int &res, int pos, int bit) {
  int mask = 1 << pos;
  res = res & ~mask;
  res = res | (bit << pos);
}


int
A(int n1, int n2) {

  int mask = 1;
  int carry = 0;
  int res = 0;

  for(int i = 0 ; i <= SIZE -1 ; i ++) {
    int val1 = n1 & (mask << i) ? 1 : 0;
    int val2 = n2 & (mask << i) ? 1 : 0;

    if(carry == 0) {
      if(val1 == val2) {
        if(0 == val1) {
          setBit(res, i, 0);
          carry = 0;
        } else {
          setBit(res, i, 0);
          carry = 1;
        }
      } else {
        setBit(res, i, 1);
        carry = 0;
      }
    } else {
      if(val1 == val2) {
        if(0 == val1) {
          setBit(res, i, 1);
          carry = 0;
        } else {
          setBit(res, i, 1);
          carry = 1;
        }
      } else {
        setBit(res, i, 0);
        carry = 1;
      }
    }
  }
  return res;
}

int 
main()
{
  std::cout << A(2,3) << "\n";
  std::cout << A(-2, 1) << "\n";
  std::cout << A(-2, -3) << "\n";
  std::cout << A(std::pow(2,SIZE -1)  -1, std::pow(2,SIZE-1)) << "\n";

}

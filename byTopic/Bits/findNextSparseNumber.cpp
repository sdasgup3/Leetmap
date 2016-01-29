/*
   A number is Sparse if there are no two adjacent 1s in its binary representation. For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
Given a number x, find the smallest Sparse number which greater than or equal to x.

Examples:

Input: x = 6
Output: Next Sparse Number is 8

Input: x = 4
Output: Next Sparse Number is 4

Input: x = 38
Output: Next Sparse Number is 40

Input: x = 44
Output: Next Sparse Number is 64
*/

#include"../utils.h"

bool
checkS(int x) {
  int mask = 1;
  bool found_1 = false;
  for(int i = 0; i < 8*sizeof(int); i++) {
    if(0 != (x & (mask << i))) {
      if(false == found_1) {
        found_1 = true;
      } else {
        return false;
      } 
    }  else {
        found_1 = false;
    }
  }
  return true;
}

int 
FNS_1(int x)
{
  for(int i = x; 1; i++) {
    if(checkS(i)) {
      return i;
    }
  }
}

int 
FNS_2(int x)
{
  if(x ==0 ) {
    return x;
  }

  std::vector<int> v;

  int tmp= x;
  if(x < 0) {
    tmp = std::pow(2,8*sizeof(int)-1) + x;
  }

  while(tmp) {
    v.push_back(tmp &1);
    tmp = tmp/2;
  }
  if(x < 0) {
    v.push_back(1);
    v.push_back(0);
  } else {
    v.push_back(0);
  }

  int size = v.size();
  int first_1 = 0;

  while(1) {

    while(first_1 < size && 0 == v[first_1] ) {
      first_1++;
    }

    if(first_1 == size) {
      break;
    }

    int last_1 = first_1;
    while(last_1 < size && 1 == v[last_1] ) {
      last_1++;
    }

    if(((last_1-1) - first_1 + 1) > 1 ) {
      for(int i = first_1; i <= last_1-1; i++) {
        v[i] = 0;
      }
      if(last_1 != size) {
        v[last_1] =1;
      }
    } 
    first_1 = last_1;
  }

  std::cout << v;
  int sum = 0, i=0;
  while(i< v.size()) {
    if(v[i] == 1) {
      sum += (v[i] << i);
    }
    i++;
  }
  return sum;
}

int main()
{
  int x = 6;
  //toBinary(6); toBinary(FNS_1(6));
  //toBinary(4); toBinary(FNS_1(4));
  //toBinary(38); toBinary(FNS_1(38));
  //toBinary(44); toBinary(FNS_1(44));

  //toBinary(6); toBinary(FNS_2(6));
  //toBinary(4); toBinary(FNS_2(4));
  //toBinary(38); toBinary(FNS_2(38));
  //toBinary(44); toBinary(FNS_2(44));
  //toBinary(7); toBinary(FNS_2(7));
  toBinary(-1); toBinary(FNS_2(-1));

}

#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cassert>
//./a.out 2147483648
//./a.out 2147483647

void toBinary(int I) {
  int size = 8*sizeof(int);

  std::vector<char> V(size,0);

  if(I < 0) {
    V[0] = 1;
    I = pow(2,size -1) + I;
  }

  int index = size -1 ;

  for(; I ;index --) {
    int q = I /2;
    int r = I %2;
    V[index] = r;
    I = q;
  }

  //Print
  for(int  i = 0; i < size  ;i++) {
    std::cout << (int)V[i] ;
  }
  std::cout << std::endl;
}

int getVal(int I, int mask, int shift) {
  return ((unsigned int)(I & mask)) >> shift;
}

void setVal(int &I, int value, int clearmask) {
  I = I & ~clearmask;
  I = I | value;
}

void pairwiseSwap(int &I) {
  int mask = 3;
  int mask_2 = 2;
  int mask_1 = 1;

  for(int i = 0 ; i < 32; i+= 2, mask <<= 2, mask_2 <<= 2, mask_1 <<= 2)  {
    int val = getVal(I, mask, i);
    if(3 == val || 0 == val) {
      continue;
    }
    if(2 == val) {
      setVal(I, mask_1, mask);
    }
    if(1 == val) {
      setVal(I, mask_2, mask);
    }
  }
}

int my_atoi(char* str) {

  assert(str != NULL && "Empty argument to atoi");

  int I = 0;
  int sign = 1;
  int start = 0;

  std::string S(str);
  int len = S.length();

  if('-' == S[0]) {
    sign = -1;
    start =1;
  }

  for(int i = len -1 ,  p =1; i >= start; i--, p = p*10) {
    assert('0' <= S[i] && '9' >= S[i] && "Invalid number string");
    I = I + p*(S[i] - '0');
  }


  return sign*I;
}

int main(int argc, char** argv) {
  int I = my_atoi(argv[1]);

  int temp = I;
  std::cout << "The binary format of " << temp <<  std::endl;
  toBinary(I);

  temp = I;
  std::cout << "The binary format after pairwise swap " << std::endl;
  pairwiseSwap(temp);
  toBinary(temp);



  return 0;
}

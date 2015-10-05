#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cassert>

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

void arithRS(int &I, int shift) {
  I = I >> shift;
  if(I < 0) {
    int mask = pow(2,8*sizeof(int) -1 ) -1;
    if(shift > 1) {
      mask = mask >> (shift -1 );
    }
    I = I & mask;
  } 
}
void arithRS_v2(int &I, int shift) {
  I = (unsigned int) I >> shift;
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
  int shift = my_atoi(argv[2]);

  int temp = I;
  std::cout << "The binary format of " << temp <<  std::endl;
  toBinary(I);

  temp = I;
  arithRS_v2(temp,shift);
  std::cout << "The binary format after shifting right by " << shift <<  std::endl;
  toBinary(temp);

  temp = I;
  arithRS(temp,shift);
  toBinary(temp);


  return 0;
}

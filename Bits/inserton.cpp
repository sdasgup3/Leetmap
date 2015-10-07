#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>

int my_atoi(std::string str) {

  int len = str.length();
  int start = 0;
  int sign = 1;

  if(str[0] == '-') {
    sign = -1;
    start  = 1;
  }

  int res =0;
  int  p =1;
  for(int i = len - 1 ; i >=start ; i -- ) {
    int C = str[i] - '0';
    res = res + p*C;
    p = p*10;
  }

  return sign*res;
}

void toBinary(int I) 
{

  int size = 8*sizeof(int);

  std::vector<char> arr(size, 0);

  //sign bit
  if(I < 0) {
    arr[0]  = 1 ;
    unsigned int u = pow(2,size-1);
    I =  u + I;
  } 

  int index = size -1;
  for(;(I!=0) && (index >= 1); index --) {
    int q = I /2;
    int r = I %2;
    arr[index] = r;
    I = q;
  }
  for(int i=0; i < size; i++) {
    std::cout << int(arr[i]) << " "; 
  }
  std::cout <<std::endl;
}

int getBit(int I, int bit) {
  int mask = 0x01 << bit;
  return (I & mask) == 0 ? 0 : 1;
}

int updateBit(int &I, int bit, int value) {
  int mask = 0x01 << bit;
  int bitCleared = I & ~mask;
  I = bitCleared | (value << bit);
}

int arithRightShift(int &I, int n) {
  I = ((unsigned int) I) >> n;
}

/*
 * This is also the number of bits required to rep a number 
 */
int actualstretchOfBits(int I) {
  int count = 0;
  while(0 != I) {
    count ++;
    //I = I >> 1;  Infinite loop as >> is arithmatic shift which keeps the sign bit which is 1 here
    I = ((unsigned int)I >> 1);
  }
  return count;
}

int numbetOfOnes(int I) 
{
  int count = 0;
  while(I != 0) {
    if(1 == getBit(I,0))  {
      count ++;
    }
    I = (unsigned int) I >> 1;
  }
  return count;
}

int nearestPow2(int I) 
{
  int start = I;

  if(start == 0) return start;
  int count = 0;
  bool powerOf2 = true;
  
  if(I<0) {
    while(I != ~0) {
      if(1 == getBit(I,0)) {
        powerOf2 = false;
      }
      I =  I >> 1;
      count ++;
    }
    count --;
    //count ++; depending on the choice

  } else {
    while(I != 1) {
      if(1 == getBit(I,0)) {
        powerOf2 = false;
      }
      I = (unsigned int) I >> 1;
      count ++;
    }
    count ++;
  }

  if(powerOf2) {
    return start;
  }
  return I << (count);
}

void insertion(int &I, int value, int start, int end) {
  int bits = end-start+1;
  int mask = pow(2,bits) -1;
  mask = mask << start;
  I = I & (~mask); // clears the mask bits
  value = (value << start) & mask; // clears the rest of mask bits
  I = I | value;
}

int main(int argc, char** argv) 
{
  std::string str(argv[1]);
  int bit = 10;

  int I = my_atoi(str);
  std::cout << "The binary format of " << I <<  " " << std::endl;
  toBinary(I);
  int TI = ~I + 1; 
  std::cout << "The binary format of " << TI <<  " " << std::endl;
  toBinary(TI);

  std::cout << "The " << bit << " bit of " << TI <<  " is " << getBit(TI,bit)<< std::endl;
  updateBit(TI, bit, 1);
  std::cout << "The binary format of updated " << TI <<  " " << std::endl;
  toBinary(TI);
  std::cout << "The " << bit << " bit of " << TI <<  " is " << getBit(TI,bit)<< std::endl;

  std::cout << "The actual stretch Bits of " <<  I <<  " is " << actualstretchOfBits(I)<< std::endl;
  std::cout << "The actual stretach of " <<  TI <<  " is " << actualstretchOfBits(TI)<< std::endl;

  std::cout << "The binary format of " << I <<  " " << std::endl;
  toBinary(I);
  arithRightShift(I, 1);
  std::cout << "The binary format of " << I <<  " after arith right shift " << std::endl;
  toBinary(I);

  std::cout << "The # 1s in " << I <<  " :" << numbetOfOnes(I) << std::endl;
  std::cout << "The # 0s in " << I <<  " :" << 32 - numbetOfOnes(I) << std::endl;
  std::cout << "The # 1s in " << TI <<  " :" << numbetOfOnes(TI) << std::endl;
  std::cout << "The # 0s in " << TI <<  " :" << 32 -numbetOfOnes(TI) << std::endl;

  for(int i = 0 ; i < 20; i++) {
    std::cout << "The nearest power of 2 of " << i <<  " :" << nearestPow2(i) << std::endl;
  }
  for(int i = 0 ; i < 20; i++) {
    std::cout << "The nearest power of 2 of " << -1*i <<  " :" << nearestPow2(-1*i) << std::endl;
  }

  I = 255;
  toBinary(I);
  std::cout << "After Insertion of 10 @(2,7)\n";
  insertion(I, 10, 2,5);
  toBinary(I);

  return 0;
}

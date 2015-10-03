#include<iostream>
#include<cstring>

int my_atoi(char* str) {

  int len = 0;
  char* temp = str;

  while(*temp != '\0') {
    len ++;
    temp ++;
  }
  int sign = 1;
  int start = len -1;
  int end = 0;

  if(str[0] == '-') {
    sign = -1;
    end = 1;
  }

  int res =0;
  int  p =1;
  for(int i = start ; i >= end ; i -- ) {
    int C = str[i] - '0';
    res = res + p*C;
    p = p*10;
  }

  return sign*res;
}

void toBinary(int I) {

  int size = 8*sizeof(int);
  char arr[size];
  memset(arr,0,size );

  int index = size -1;

  if(I < 0) {
    arr[0]  = 1 ;
    unsigned int u = 2147483648;
    I =  u + I;
  } 

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

int toggle(int &I, int s1, int s2) {
  int mask1 = 0xFF << s1;
  int mask2 = 0xFF << s2;

  int val1 = I & mask1;
  int val2 = I & mask2;

  val1 = val1 << 8;
  val2 = val2 >> 8;
  //std::cout << "val1 " ; toBinary(val1);
  //std::cout << "val2 " ; toBinary(val2);

  return ( 0x00 | val1 | val2);

}

int toggleBits(int &I) {
  int res = 0x00000000;
  for(int i = 0; i < sizeof(int); i +=2) {
    res = res | toggle(I, i*8, (i+1)*8);
  }
  return res;
}

int main(int argc, char** argv) {
  int I = my_atoi(argv[1]);

  std::cout << "The binary format of " << I << " : (sizeof int) : "  << sizeof(int)  << std::endl;
  toBinary(I);


  int res = toggleBits(I);
  std::cout << "The binary format of toggled " << res << " : (sizeof int) : "  << sizeof(int)  << std::endl;
  toBinary(res);


  return 0;
}

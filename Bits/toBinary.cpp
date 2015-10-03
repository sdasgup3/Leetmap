#include<iostream>
#include<cstring>

int my_atoi(char* str) {

  int len = 0;
  char* temp = str;
  while(*temp != '\0') {
    len ++;
    temp ++;
  }

  int res =0;
  int  p =1;
  for(int i = len - 1 ; i >=0 ; i -- ) {
    int C = str[i] - '0';
    res = res + p*C;
    p = p*10;
  }

  return res;
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



int main(int argc, char** argv) {
  int I = my_atoi(argv[1]);
  std::cout << "The binary format of " << I << " : (sizeof int) : "  << sizeof(int)  << std::endl;
  toBinary(I);

  return 0;
}

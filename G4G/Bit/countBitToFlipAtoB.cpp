/*
   You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.
   */


#include<iostream>

int
B(int x, int y) {

  int z = x ^ y;
  int count = 0;

  while(z) {
    z = z & (z-1);
    count ++;
  }

  return count;
}


int 
main() {
  for(int i = 0; i < 8 ; i ++) {
    std::cout << i << " " << -1*i << " "  <<  B(i, -1*i) << "\n";
  }

}

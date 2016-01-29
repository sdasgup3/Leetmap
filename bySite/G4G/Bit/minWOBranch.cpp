#include<iostream>

/*
  if x < y
    y ^ ((x^y) & -(x<y)) = y ^ ((x^y) & -1) = y ^ x ^ y  = x

   */
int
main()
{
  int x,y;
  std::cin >> x; 
  std::cin >> y;

  std::cout << (y ^ ((x^y) & -(x<y)))  << "\n";
}

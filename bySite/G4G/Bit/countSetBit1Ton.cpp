#include<iostream>
#include<vector>
#include<cmath>

int
C(int n) {
  int count = 0;
  while(n) {
    n = n & (n-1);
    count++;
  }
  return count;
}

int 
main()
{
  int sum = 0;
  for(int i = 1;  i <= 7 ; i++) {
    sum += C(i);
  }

  std::cout << sum << "\n";
}

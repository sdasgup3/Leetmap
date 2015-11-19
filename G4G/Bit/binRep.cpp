#include<iostream>
#include<vector>
#include<cmath>

void
printBR(int  n, std::vector<int> V) {
    std::cout<< n << " : " ;
    for(int i = V.size() -1; i >= 0 ; i --) {
      std::cout << V[i] << " " ;
    }
    std::cout << "\n " ;
}

void
BR(int n) {
  int size = 8*sizeof(int);
  std::vector<int> V(size, 0);

  if(0 == n) {
    printBR(n, V);
    return;
  }

  int m = n;
  if(n < 0) {
    n = std::pow(2, size-1) + n;
    V[size -1 ] = 1;
  }

  int k = 0;
  while(n) {
    V[k++] = (n&1);
    n = n/2;
  }

  printBR(m, V);

}


int 
main()
{
  for(int i = -8;  i <= 7 ; i++) {
    BR(i);
  }
}

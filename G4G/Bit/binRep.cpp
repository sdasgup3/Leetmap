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
BR_1(int n) {
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

void
BR_2(int n) {
  int size = 8*sizeof(int);
  int mask  = std::pow(2, size-1);

  std::cout<< n << " : " ;
  for(; mask; mask = ((unsigned int)mask >> 1)) {
    if(n&mask) {
      std::cout << "1 ";
    } else {
      std::cout << "0 ";
    }
  }
    std::cout << "\n " ;
}

void
BR_3H(int n) {
  if(0 == n) 
    return;

  int tp = n&1;
  BR_3H(n/2);
  std::cout << tp << " ";
}

void
BR_3(int n) {
  std::cout<< n << " : " ;
  int size = 8*sizeof(int);

  if(0 == n) {
    std::cout << "0 ";
  } else {
    if(n< 0) {
      n = std::pow(2, size-1) + n;
      std::cout << "1 ";
    }
    BR_3H(n);
  }
  std::cout << "\n " ;
}

int 
main()
{
  for(int i = -8;  i <= 7 ; i++) {
    BR_1(i);
    BR_2(i);
    BR_3(i);
  }
}

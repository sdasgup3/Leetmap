#include<iostream>

#define SO(X) (((char *)(&X + 1))  - ((char *)&X ))
#define SOT(T)  ( { __typeof__(T) X,  (((char *)(&X + 1))  - ((char *)&X )) } )

typedef struct  {
  int x;
  double d;
} S;


int main() {
  int i;
  std::cout <<  SO(i) << " " << sizeof(i) <<  "\n";
  double f;
  std::cout <<  SO(f) << " " << sizeof(f) << "\n";

  int arr[100];
  std::cout <<  SO(arr) << " " << sizeof(arr) << "\n";

  S s;
  std::cout <<  SO(s) << " " << sizeof(s) << "\n";

  //std::cout <<  SOT(int) << "\n";
  //std::cout <<  SOT(double) << "\n";
  //std::cout <<  SOT(S) << "\n";



}

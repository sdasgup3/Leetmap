
#include"../utils.h"
/*
    Ugly Numbers
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150’th ugly number.

*/   

int
ugly_naive(int n)
{
  int count = 0;
  int i = 1;

  while(1) {
    int t =  i;

    //divide all prime factor ==2
    while(1) {
      int r  = t % 2;
      if(0 == r) {
        t = t /2;
      } else {
        break;
      }
    }

    //divide all prime factor ==2
    while(1) {
      int r  = t % 3;
      if(0 == r) {
        t = t /3;
      } else {
        break;
      }
    }

    //divide all prime factor ==2
    while(1) {
      int r  = t % 5;
      if(0 == r) {
        t = t /5;
      } else {
        break;
      }
    }

    if(1 == t) {
      count++;
      if(n == count) {
        return i;
      }
    }
    i++;
  }
}

int
ugly(int n) {

  if(1 == n) return 1;

  std::vector<int> U;
  U.push_back(1);

  int index_2 = 0;
  int index_3 = 0;
  int index_5 = 0;


  int count = 1;

  while(1) {

    int next_2 = U[index_2]*2;
    int next_3 = U[index_3]*3;
    int next_5 = U[index_5]*5;

    int next_ugly = std::min(next_2, std::min(next_3, next_5));
    U.push_back(next_ugly);
    count ++;
    if(n == count) {
      return next_ugly;
    }

    if(next_ugly == next_2) {
      index_2++;
      next_2 = U[index_2]*2;
    }
    if(next_ugly == next_3) {
      index_3++;
      next_3 = U[index_3]*3;
    }
    if(next_ugly == next_5) {
      index_5++;
      next_5 = U[index_5]*5;
    }
  }
}


int main() {

 std::cout << ugly_naive(1) << " " ;
 std::cout << ugly_naive(150) << " " ;

 std::cout << "\n";
 std::cout << ugly(1) << " " ;
 std::cout << ugly(150) << " " ;

 std::cout << "\n";
  return 0;
}

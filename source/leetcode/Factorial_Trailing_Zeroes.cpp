/* Problem Description
Given an integer n, return the number of trailing zeroes in n!.
Here we need to find the number of factors of 2s and 5s. and the result is min of those numbers
== number of 5s


* 
*/

#include"header.h"
class Solution {
public:

    int trailingZeroes(int n) {

      if(n < 5) {
        return 0;
      }

      return n/5 + trailingZeroes(n/5);
    }
};


int main() {
  Solution S;

  cout << S.trailingZeroes(10) << "\n";
  cout << S.trailingZeroes(5) << "\n";
  cout << S.trailingZeroes(6) << "\n";
  cout << S.trailingZeroes(20) << "\n";
  cout << S.trailingZeroes(30) << "\n";

  return 0;
}

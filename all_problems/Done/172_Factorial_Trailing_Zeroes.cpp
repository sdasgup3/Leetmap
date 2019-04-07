/* Problem Description
Given an integer n, return the number of trailing zeroes in n!.
Here we need to find the number of factors of 2s and 5s. and the result is min of those numbers
== number of 5s

n = 30 
we have 6 multiples of 5 

5*1 5*2 5*3 5*4 5 *5  6*5

then we need to consider what are the mutiples of 5 in 6 == 1 which is for 5*5 


* 
*/

#include"header.h"

class Solution {
public:
    int numfactor(int n, int p ) {
        if(0 == n % p) {
            return 1 + numfactor(n/p, p);
        }
        return 0;
    }
    int trailingZeroes(int n) {
        
        int sum = 0;
        if(n == 0) return 0;
        
        for(int i = 1; i <=n ;i++) {
            sum += numfactor(i, 5);
        }
        
        return sum;
        
    }
};

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

/* 
 * Problem Description
Given an integer, write a function to determine if it is a power of three.


 * Solution
 * Tags
 Math
*/

#include"header.h"
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int max_exp = log(INT_MAX)/log(3);
        int max_pow_3 = pow(3,max_exp);
        if(0 == (max_pow_3%n)) return true;
        
        return false;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n != 1) {
            if(0 != n%3) return false;
            n = n/3;
        }
        return true;
    }
};

int main() {
  Solution S;

  vector<int> D({});

  S.ValidWordAbbr(D);

  return 0;
}

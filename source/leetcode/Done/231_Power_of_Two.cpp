/* 
 * Problem Description
Given an integer, write a function to determine if it is a power of two.


 * Solution
 * Tags
 Math
*/

#include"header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n-1)) == 0; 
    }
};

int main() {
  Solution S;


  return 0;
}

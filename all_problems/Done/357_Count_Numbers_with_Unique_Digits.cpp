/* 
 * Problem Description
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Show Hint 

 * Solution
 * Tags
 Combinatorics 
 Maths
*/

#include"header.h"
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int sum = 0;
        if(0 == n) {
            return 1;
        }
        
        sum+=1;
        int digits = 1;
        
        for(int i = 0 ; i < n; i ++) {
            //find the number of distict nums
            int pow = 1;
            for(int j = 0 , maxd = 9; j < digits; j++) {
                if(j == 0) {
                    pow *= maxd;
                    continue;
                }
                
                pow*= maxd; maxd--;
            }
            
            sum += pow;
            digits ++;
        }
        
        return sum;
    }
};


int main() {
  Solution S;

  return 0;
}

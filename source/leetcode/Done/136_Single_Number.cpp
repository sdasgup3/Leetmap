/* Problem Description
   Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include"header.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0 ;
        for(int x : nums) {
            sum  = sum ^ x;
        }
        
        return sum;
    }
};


int main() {
  Solution S;

  vector<int> D({1,1,2});

  S.singleNumber(D);

  return 0;
}

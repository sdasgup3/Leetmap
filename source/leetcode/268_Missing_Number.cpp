/* Problem Description
   Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include"header.h"
class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        int s = nums.size();
        int sum = s*(s+1)/2;
        //cout << sum << "\n";
        for(int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
        
    }
    
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        int sum = 0;
        for(int i = 0 ; i <= s; i++) {
            sum ^= i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        return sum;
        
    }
};

int main() {
  Solution S;

  vector<int> D({0,1,3});
  S.missingNumber(D);

  return 0;
}

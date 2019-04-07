/* 
 * Problem Description
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 * Solution
 * Tags
 Array
*/

#include"header.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        if(0==sz) return;
        
        int count = 0, k = 0;
        for(int i = 0 ; i < sz; i++) {
            if(nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        
        for(int i = k; i < sz; i++) {
            nums[k++] = 0;
        }
        
    }
};


int main() {
  Solution S;

  vector<int> D({0,1, 0,3,12});

  S.moveZeroes(D);
  cout << D;

  return 0;
}

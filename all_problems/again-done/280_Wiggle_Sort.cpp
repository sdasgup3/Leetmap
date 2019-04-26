/* 
 * Problem Description
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


 * Solution
 Fix the anomaly
 * Tags
 Sort 
*/

#include"header.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0 ; i < sz-1; i++) {
            if(0 == i%2) {
                if(nums[i] <= nums[i+1]) {
                    continue;
                }  else {
                    int tmp = nums[i]; 
                    nums[i] = nums[i+1];
                    nums[i+1] = tmp;
                }
            } else {
                if(nums[i] >= nums[i+1]) {
                    continue;
                }  else {
                    int tmp = nums[i]; 
                    nums[i] = nums[i+1];
                    nums[i+1] = tmp;
                }
            }
        }
        
    }
};

int main() {
  Solution S;


  return 0;
}

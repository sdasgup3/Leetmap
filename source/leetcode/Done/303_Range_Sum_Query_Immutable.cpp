/* 
 * Problem Description
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 * Solution

 Partial sums
 * Tags
 Partial Sums
*/

#include"header.h"

class NumArray {
    private:
    vector<int> V;
    int sz;
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        V.resize(sz);
        for(int i = 0 ; i < sz; i++) {
            if(0 == i) {
                V[i] = nums[i];
            } else {
                V[i] = nums[i] + V[i-1];
            }
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) {
            return V[j];
        } else {
            return V[j] - V[i-1];
        }
        
    }
};


int main() {
vector<int> nums({1,2,3,4,5,6,7});

 NumArray numArray(nums);
 cout << numArray.sumRange(0, 1) << "\n";
 cout << numArray.sumRange(1, 2) << "\n";


  return 0;
}

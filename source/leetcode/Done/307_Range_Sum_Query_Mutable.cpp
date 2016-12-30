/* 
 * Problem Description

 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

 * Solution



 * Tags
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

    void update(int i, int val) {
        int val_i ;
        if(0 == i) {
            val_i = V[i];
        } else {
            val_i = V[i] - V[i-1];
        }
        for(int j = i; j < sz; j++) {
            V[j] = V[j]- val_i + val;
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
 numArray.update(1, 10);
 cout << numArray.sumRange(1, 2) << "\n";


  return 0;
}

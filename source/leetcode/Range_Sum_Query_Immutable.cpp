/* Problem Description
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include"header.h"
/*
class NumArray {
  private:
    vector<vector<int>> arr;
public:
    NumArray(vector<int> &nums) {
        int s = nums.size();
        arr.reserve(s);
        for(int i = 0 ; i < s ; i ++) {
          arr[i].reserve(s);
        }


        int sum = 0;
        for(int i = 0 ; i < s ; i ++) {
            sum = 0;
            for(int j = i ; j < s ; j ++) {
                sum += nums[j];
                arr[i][j] = sum;
            }
        }
    }

    int sumRange(int i, int j) {
        return arr[i][j];
        
    }
};
*/
class NumArray {
  private:
    vector<int> arr;
public:
    NumArray(vector<int> &nums) {
        int s = nums.size();
        arr.reserve(s);

        int sum = 0;
        for(int i = 0 ; i < s ; i ++) {
          sum += nums[i];
          arr[i] = sum;
        }
    }

    int sumRange(int i, int j) {
      if(0 == i) {
        return arr[j];
      }

      return arr[j] - arr[i-1];
        
    }
};





int main() {
  vector<int> nums = {1,4,-6};
 NumArray numArray(nums);
 cout << numArray.sumRange(0, 2) << "\n";
 cout << numArray.sumRange(1, 2) << "\n";
 cout << numArray.sumRange(0, 1) << "\n";

  return 0;
}

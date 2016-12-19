/* 
 * Problem Description
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

* 
 *
 *
 *
 *
 * Solution
*/

#include"header.h"
class Solution {
public:
    int rob(vector<int>& nums) {
      int sz = nums.size();
      vector<int>R(sz, 0);

      if(sz == 0) {
        return 0;
      }
      if(sz ==1) {
        return nums[0];
      }

      if(sz==2) {
        return max(nums[0], nums[1]);
      }
      R[0] = nums[0];
      R[1] = max(nums[0], nums[1]);

      for(int i = 2 ; i <sz ; i++) {
        R[i] = max(R[i-1], nums[i] + R[i-2]);
      }

      return R[sz-1];

    }
};

int main() {
  Solution S;
  vector<int> D({50,1,1,50});

  cout << S.rob(D);

  return 0;
}

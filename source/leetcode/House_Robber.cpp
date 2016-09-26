/* Problem Description
   You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include"header.h"
class Solution {

public:
  int rob(vector<int> &nums) {  
    int s = nums.size();
    vector<int> R(nums.size(), 0);

    if(s == 1) {
      return nums[0];
    }
    R[0] = nums[0];
    if(2 == s) {
      return std::max(nums[1], nums[0]);
    }
    R[1] = std::max(nums[1], nums[0]);

    for(int i = 2; i < s ; i ++) {
      R[i] = std::max(nums[i] + R[i-2], R[i-1]);
    }

    return R[s-1];
  }
private:

};


int main() {
  Solution S;

  int arr[] = {50,1,1,50};
  vector<int> D (arr, arr + sizeof(arr)/sizeof(arr[0]));

  cout << S.rob(D);

  return 0;
}

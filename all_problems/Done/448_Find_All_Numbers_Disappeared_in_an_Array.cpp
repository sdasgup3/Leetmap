/* 
 * Problem Description
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 * Solution
As we know the max possble numnber; make use of it


 * Tags
 Array
*/

#include"header.h"
class Solution {

public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {

    int sz = nums.size();
    int mx = sz+1;
    vector<int> res;
    if(0 == mx) return res;

    for(int i = 0 ; i < sz; i++) {
      int actual_val = nums[i] % mx;
      nums[actual_val-1] += mx;
    }

    for(int i = 0 ; i < sz; i++) {
      int actual_count = nums[i] / mx;
      if(0 == actual_count) {
        res.push_back(i+1);
      }
    }

    return res;
  }

};


int main() {
  Solution S;

  vector<int> D({4,3,2,7,8,2,3,1});

  cout << S.findDisappearedNumbers(D);

  return 0;
}

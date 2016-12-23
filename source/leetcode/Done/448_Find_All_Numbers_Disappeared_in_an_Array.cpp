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

 One big hint in solving this problem is that we know the max element possible in this array.
 WIth that we can store aux information in the array like:
 For example in 
 a[i] = k
 we can store 
 a[i] = a[i] % (n+1) + t*(n+1) 
 so that we can later get individual conponents by
 k ==  a[i] % (n+1) and
 t == a[i]/ (n+1)

  The idea here is to store the count as t

 * Tags
 Math, Array
*/

#include"header.h"
class Solution {

public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {

    vector<int> res;
    size_t sz = nums.size();
    int max = sz+1;

    for(int i = 0 ; i < sz; i++) {
      int value = nums[i]%max;
      nums[value-1] += max;
    }

    for(int i = 0 ; i < sz; i++) {
      int count = nums[i]/max;
      if(0 == count) {
        res.push_back(i+1);
      }
    }

    return res;

  }
private:

};


int main() {
  Solution S;

  vector<int> D({4,3,2,7,8,2,3,1});

  cout << S.findDisappearedNumbers(D);

  return 0;
}

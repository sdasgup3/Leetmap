/* Problem Description
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Show Tags
Show Similar Problems
* 
*/

#include"header.h"
class Solution {

public:
  int minMoves2(vector<int>& nums) {
    if(0 == sz) return 0;
        
        nth_element(nums.begin(), nums.begin()+sz/2, nums.end());
        
        int sum = 0;
        for(auto n : nums) {
            sum += abs(n-nums[sz/2]);
        }
        
        return sum;
    }
};


int main() {
  Solution S;

  vector<int> D({1,2,3});

  S.minMoves2(D);

  return 0;
}

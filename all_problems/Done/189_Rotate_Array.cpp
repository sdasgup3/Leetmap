/* Problem Description
 * Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?

Tags:
Array
*/

#include"header.h"

class Solution {
public:
    void swap(int *a, int *b ) {
        if(a == b) {
            return;
        }
        
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    void reverse(vector<int>& nums, int first, int last) {
        int lm = (last- first +1)/2 ;
        
        for(int i = 0; i < lm; i++) {
            swap(&nums[first + i], &nums[last-i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz == k) {
            return;
        } else if(k > sz) {
            k = k % sz;
        }
        
        // reverse first n-k 
        reverse(nums, 0, sz-k-1);
        //reverse rest
        reverse(nums, sz-k, sz-1);
        //reverse whole
        reverse(nums, 0, sz-1);
    }
};


int main() {
  Solution S;

  vector<int> D({1,2,3,4,5,6,7});

  S.rotate(D, 3);
  cout << D;

  return 0;
}

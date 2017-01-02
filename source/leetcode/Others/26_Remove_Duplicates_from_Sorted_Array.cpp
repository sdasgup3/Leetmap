/* Problem Description
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include"header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1 2 3  
        
        int sz = nums.size();
        if(sz <= 1) return sz;
        
        int insert = 0;
        int runner = 0;
        
        while(1) {
            
            while(runner +1  < sz && nums[runner] == nums[runner + 1]) {
                runner ++;
            }
            nums[insert++] = nums[runner];
            
            if(runner +1 == sz) break;
            runner ++;
            
        }
        
        return insert ;
    }
};


int main() {
  Solution S;

  vector<int> D = {1,3,3,3,4,4,5};

  cout << S.removeDuplicates(D);

  return 0;
}

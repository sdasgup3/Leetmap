/* Problem Description
*/

#include"header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2);

        vector<int> orig = nums;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = size-1;

        while(start < end ) {
          int val = nums[start] + nums[end];
          if(val == target) {
                    break;
          } else if(val < target) {
            start ++;
          } else {
            end --;
          }

        }

        // start and end are w.r.t  sorted nums
        //Find the actual incides in orig

        int val1 = nums[start];
        int val2 = nums[end];
        
        if(val1 != val2) {    
            result[0] = find(orig.begin(), orig.end(), nums[start]) - orig.begin();
            result[1] = find(orig.begin(), orig.end(), nums[end]) - orig.begin();
        } else {
            auto it = find(orig.begin(), orig.end(), nums[start]);
            result[0] = it - orig.begin();
            result[1] = find(++it, orig.end(), nums[end]) - orig.begin();
                    
        }

        return result;
    }
};


int main() {
  Solution S;

  vector<int> D = {0,4,3,0};
  int target = 0;

  vector<int>result = S.twoSum(D, target);
  cout << result[0] << " " << result[1] << "\n";

  return 0;
}

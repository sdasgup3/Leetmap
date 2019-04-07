/* 
 * Problem Description
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 * Solution


Tags:
Binary Search

*/

#include"header.h"
class Solution {
public:
    vector<vector<int>> twosum(vector<int>& nums, int start, int end , int target) {
        vector<vector<int>> res;
        while(start < end) {
            int tmp = nums[start] + nums[end];
            if(tmp == target) {
                res.push_back(vector<int>({nums[start], nums[end]}));
                //11 22; taregt = 3
                while(start+1 < end && nums[start+1] == nums[start]) start ++;
                while(start < end-1 && nums[end] == nums[end-1]) end--;
                start ++; end--;
            } else if(tmp > target) {
                end --;
            } else {
                start ++;
            }
        }
        
        return  res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        int sz = nums.size();
        if(0 == sz) return res;
        
        sort(nums.begin(), nums.end());
        cout << nums;
        
        for(int i = 0 ; i < sz-2 ;i++) {
            int target = -nums[i];
            cout << i << " " << target << "\n";
            auto out =  twosum(nums, i+1, sz-1, target) ;
            for(int j = 0 ; j < out.size(); j++) {
                res.push_back(vector<int>({nums[i], out[j][0], out[j][1]}));
            }

            //target 1
            // -1 -1 0 1; consider -1 once
            while(i+1 < sz-2 && nums[i] == nums[i+1]) i++;
        }
        
        
        return res;
        
    }
};

int main() {

  Solution S;
  //vector<int> nums({-1,0,1,2,-1,-4});
  vector<int> nums({-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6});
  cout << S.threeSum(nums);
  return 0;
}

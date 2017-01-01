/* 
 * Problem Description
 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
 * Solution
 * Tags
 Map
*/

#include"header.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int > result;
        unordered_map<int, int > M;
        for(int x : nums1) {
            M[x] ++;
        }
        
        for(int y : nums2) {
            if(0 != M.count(y) && M[y] != 0) {
                M[y]  = 0;
                result.push_back(y);
            }
        }
        
        return result;
    }
};

int main() {
  Solution S;

  return 0;
}

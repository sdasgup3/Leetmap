/* Problem Description
 Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

#include"header.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int s = nums.size();
        unordered_map<int, int> M;
        for(auto i : nums) {
            M[i]++;
        }
        
        vector<vector<int>> B(s+1);
        
        for(auto p : M) {
            int i = p.first;
            int n = p.second;
            B[n].push_back(i);
        }
        
        vector<int > res;
        int count = 0;
        for(int i = s; i >= 0 ; i --) {
            if(B[i].empty()) {
                continue;
            }
            
            int sz = B[i].size();
            for(int j = 0; j < sz ; j ++) {
                res.push_back(B[i][j]);
            }
        }
        vector<int> R(res.begin(), res.begin()+k);
        return R;
    }
};


int main() {
  Solution S;

  return 0;
}

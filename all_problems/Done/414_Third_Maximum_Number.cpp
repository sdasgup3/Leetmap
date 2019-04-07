/* 
 * Problem Description
 Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
 * Solution
1. Map: this will keep distinct element is sorted order
2. Priority Queue: populate the queue after refining it through a map
3. Use 3 vars


 * Tags
 Map
*/

#include"header.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, bool> M;
        
        for(auto n : nums) {
            M[n] = true;
            if(M.size() > 3) M.erase(M.begin()->first);
        }
        
        int sz = M.size();
        int val;
        map<int, bool>::iterator it = M.begin();
        
        if(sz < 3) {
            for(int i = 0 ; i < M.size(); i++) {
                val = it->first;
              //  cout << val;
                it++;
            }
            return val;
        }
        for(int i = 0 ; i <= M.size()-3; i++) {
            val = it->first;
            it++;
        }
        return val;
    }
};


int main() {
  Solution S;

  vector<int> D({});

  S.ValidWordAbbr(D);

  return 0;
}

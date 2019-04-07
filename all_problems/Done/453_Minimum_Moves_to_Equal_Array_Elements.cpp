/* Problem Description
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Tags:
Math
*/

#include"header.h"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sz = nums.size();
        int moves = 0;
        if(0 == sz) return moves;
        
        
        int mn = INT_MAX;
        for(auto i : nums) {
            mn = min(mn, i);
        }
        
        for(auto i : nums) {
            moves += (i - mn);    
        }
        
        return moves;
    }
};


int main() {
  Solution S;

  vector<int> D({1,2,3});

  cout << S.minMoves(D);

  return 0;
}

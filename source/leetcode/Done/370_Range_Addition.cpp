/* 
 * Problem Description
 Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Hint:

Thinking of using advanced data structures? You are thinking it too complicated.
For each update operation, do you really need to update all elements between i and j?
Update only the first and end element is sufficient.
The optimal time complexity is O(k + n) and uses O(1) extra space.

 * Solution

    length = 5,

     0 0 0 0  0 

    update = [1,  3,  2],
          
     0 2 0 0  -2 // The idea is upon doing PS we will get the correct result: 0 2 2 2 0
          

    update:   [2,  4,  3],

     0 2 3 0  -2  // The idea is upon doing PS we will get the correct result: 0 2 5 5 3


    update: [0,  2, -2]

     -2 2 3 2  -2  // The idea is upon doing PS we will get the correct result: -2 0 3 5 3

 * Tags
 Partial Sums
*/

#include"header.h"

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int> res(length, 0);
        
        for(auto up : updates) {
            int start = up[0];
            int end = up[1];
            int val = up[2];
            
            res[start] += val;
            if(end+1 < length) {
                res[end+1] += -1*val;
            }
            cout << res;
        }
        
        for(int i = 1; i < length; i++) {
            res[i] += res[i-1];
        }
        
        return res;
    }
};

int main() {
  Solution S;
  vector<vector<int>>V;
  V.push_back({1,3,2});
  V.push_back({2,4,3});
  V.push_back({0,2,-2});
  cout << S.getModifiedArray(5, V);


  return 0;
}

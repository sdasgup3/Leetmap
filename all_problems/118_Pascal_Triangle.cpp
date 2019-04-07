/* Problem Description
 * Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Tags:
Array
*/

#include"header.h"
class Solution {

public:
  vector<vector<int>> generate(int n) {  

    vector<vector<int>> R;

    for(int i = 0 ; i < n ; i ++) {
      int numE = i+1;
      vector<int> r(numE);

      r[0] = r[numE-1]  = 1;

      for(int j = 1; j < numE - 1; j++) {
        r[j] = R[i-1][j-1] + R[i-1][j];
      }

      R.push_back(r);

    }

    return R;

  }
private:

};


int main() {
  Solution S;

  S.generate(5);

  return 0;
}

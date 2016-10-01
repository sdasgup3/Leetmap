/* Problem Description
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include"header.h"
class Solution {

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {  

    vector<int> R;
    r = matrix.size();
    if(0 == r) {
      return R;
    }
    c = matrix[0].size();

    // define the restrictions
    int rowB = 0;
    int rowE = r-1;
    int colB  = 0;
    int colE = c -1;
    int k;

    while(rowB<= rowE && colB <= colE) {
      // >
      for( k = colB; k <= colE; k++ ) {
        R.push_back(matrix[rowB][k]);
      }
      rowB++;

      // V
      for( k = rowB; k <= rowE; k++ ) {
        R.push_back(matrix[k][colE]);
      }
      colE--;

      // <
      // By tgis time the following cond may have violated
      if(rowB<=rowE) {
        for( k = colE; k >= colB; k-- ) {
          R.push_back(matrix[rowE][k]);
        }
        rowE--;
      }

      // ^
      if(colB <= colE) {
      for( k = rowE; k >= rowB; k-- ) {
        R.push_back(matrix[k][colB]);
      }
      colB++;
      }
    }
  }
private:
  int r, c;

};


int main() {
  Solution S;

  vector<vector<int>> D;

  /*
  D.push_back({1,   2,  3,    4});
  D.push_back({14,  15, 16,   5});
  D.push_back({13,  20, 17,   6});
  D.push_back({12,   19, 18,   7});
  D.push_back({11,  10, 9,    8});
  */

  /*
  D.push_back({1});
  D.push_back({3});
  */
  D.push_back({2,3});
  cout << S.spiralOrder(D);

  return 0;
}

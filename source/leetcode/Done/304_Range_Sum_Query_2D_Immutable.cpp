/* 
 * Problem Description
 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
 * Solution

 * Tags
 Partial Sums
*/

#include"header.h"
class NumMatrix {

  private:
    vector<vector<int>> p_sum;
    int r, c;
  public:
    NumMatrix(vector<vector<int>> &matrix) {
      r = matrix.size();
      if(0==r) return
      c = matrix[0].size();

      p_sum.resize(r);
      for(int i = 0 ; i < r; i++) {
        p_sum[i].resize(c);
      }

      for(int i = 0 ; i < r; i ++) {
        for(int j = 0 ; j < c; j ++) {
          if(0 == j) {
            p_sum[i][j] = matrix[i][j] ;
          } else {
            p_sum[i][j] = matrix[i][j] + p_sum[i][j-1];
          }
        }
      }
    }

    void update(int row, int col, int val) {

      int val_orig;
      if(0 == col) {
        val_orig = p_sum[row][col];
      } else {
        val_orig = p_sum[row][col] - p_sum[row][col-1];
      }
      for(int j = col; j < c; j++) {
        p_sum[row][j]  =  p_sum[row][j] -val_orig +val;
      }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      int sum = 0;
      for(int i = row1; i<= row2; i++) {
        if(0 == col1) {
          sum += p_sum[i][col2];
        } else {
          sum += p_sum[i][col2] - p_sum[i][col1-1];
        }
      }
        
      return sum;
    }
};


int main() {

  vector<vector<int>> V;
  V.push_back({3, 0, 1, 4, 2});
  V.push_back({5, 6, 3, 2, 1});
  V.push_back({1, 2, 0, 1, 5});
  V.push_back({4, 1, 0, 1, 7});
  V.push_back({1, 0, 3, 0, 5});


  NumMatrix N(V);
  cout << V;
  
  cout << N.sumRegion(0, 1, 2, 3);
  cout <<"\n";
  N.update(1, 1, 10);
  cout << N.sumRegion(0, 1, 2, 3);
  cout <<"\n";

  cout << N.sumRegion(1, 2, 3, 4);
  cout <<"\n";
  N.update(3, 4, 10);
  cout << N.sumRegion(1, 2, 3, 4);
  cout <<"\n";


  return 0;
}

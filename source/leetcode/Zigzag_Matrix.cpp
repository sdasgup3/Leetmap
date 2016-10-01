/* Problem Description
 * Print a matrix in a spriral fashion
*/

#include"header.h"
class Solution {

public:
  void spiral(vector<vector<int>> &M, int rows, int colmn) {  
    for(int i = 0; i < rows; i++) {
      int j;
      if(0 == i%2) {
        j = 0;
        for(; j < colmn ; j++) {
          cout<< M[i][j] << " " ;
        }
      } else {
        j = colmn-1;
        for(; j >= 0 ; j--) {
          cout<< M[i][j] << " " ;
        }
      }

      cout <<"\n";
    }
  }
private:

};


int main() {
  Solution S;

  vector<vector<int>> M;
  
  vector<int> row1 = {1,2,3,4,5};
  vector<int> row2 = {6,7,8,9,10};
  vector<int> row3 = {11,12,13,14,15};
  vector<int> row4 = {16,17,18,19,20};
  M.push_back(row1);
  M.push_back(row2);
  M.push_back(row3);
  M.push_back(row4);

  S.spiral(M, 4, 5);

  return 0;
}

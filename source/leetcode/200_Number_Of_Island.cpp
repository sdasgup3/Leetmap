/* Problem Description
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
answer: 3
*/

#include"header.h"

class Solution {
  private: 
    int r , c;
public:

    void markT(int i, int j, vector<vector<char>>& grid) {
      if(grid[i][j] != '1') {
        return;
      }

      grid[i][j] = '2';

      if(i+1 < r) 
        markT(i+1, j, grid);
      if(i-1 >= 0) 
        markT(i-1, j, grid);
      if(j+1 < c) 
        markT(i, j+1, grid);
      if(j-1 >= 0) 
        markT(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

      int numI = 0;
      r  = grid.size();
      if(0 == r) 
        return numI;
      c = grid[0].size();
      if(0 == c) 
        return numI;


      for(int i = 0 ; i < r; i ++) {
        for(int j = 0 ; j < c; j ++) {
          if(grid[i][j] == '1') {
            numI ++;
            markT(i, j, grid);
          }
        }
      }

      return numI;
        
    }
};


int main() {
  Solution S;

  vector<vector<char>> G;
  G.push_back({'0','1','0','0','1'});
  G.push_back({'1','1','1','0','1'});
  G.push_back({'0','1','0','0','0'});
  G.push_back({'0','0','0','1','1'});
  G.push_back({'1','1','0','1','1'});

  cout << S.numIslands(G);

  return 0;
}

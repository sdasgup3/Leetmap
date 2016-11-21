/* Problem Description
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
* 
*/

#include"header.h"
class Solution {
  private:
public:

    void traverse(vector<vector<int>>&G, int x, int y, int r, int c, int& P) {
      if(x >= r || x < 0 || y >= c || y < 0 ) {
        return;
      }
      if(G[x][y] == 2 || G[x][y] == 0) {
        return;
      }

      //mark
      G[x][y] = 2;

      //compute P
      if(x+1 >= r || G[x+1][y] == 0) {
        P++;
      }
      if(x-1 < 0 || G[x-1][y] == 0) {
        P++;
      }
      if(y+1 >= c || G[x][y+1] == 0) {
        P++;
      }
      if(y-1 < 0 || G[x][y-1] == 0) {
        P++;
      }

      cout << x << " " << " " << y << " " << P << "\n";

      traverse(G, x+1, y, r, c, P);
      traverse(G, x-1, y, r, c, P);
      traverse(G, x, y+1, r, c, P);
      traverse(G, x, y-1, r, c, P);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
      //Create a copy
      vector<vector<int>> G = grid;
      int r = G.size();
      if(0 == r) {
        return 0;
      }

      int c = G[0].size();
      cout << G;

      //Find the first one;
      int i = 0 ,j =  0;
      bool found = false;
      for(i =  0; i < r ; i++) {
        for( j = 0; j < c; j++) {
          if(G[i][j] == 1) {
            found = true;
            break;
          }
        }
        if(true == found) {
          break;
        }
      }
      int P = 0;
      cout << i << " " << " " << j << " " << P << "\n";
      traverse(G, i, j, r, c, P);
      return P;
    }
};


int main() {
  Solution S;

  vector<vector<int>> D;
  /*
  D.push_back({0,1,0,0});
  D.push_back({1,1,1,0});
  D.push_back({0,1,0,0});
  D.push_back({1,1,0,0});
  */
  D.push_back({0});
  D.push_back({1});
  cout << S.islandPerimeter(D);

  return 0;
}

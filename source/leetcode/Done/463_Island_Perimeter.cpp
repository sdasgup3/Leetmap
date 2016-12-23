/* 
 * Problem Description
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

 * Solution
 For each 1 examine the 4 neighbours ;
 if the ngh is not 1 or its at the edge, then that will add 1 to perimeter contribution for that 1

 For ex: for the 1 at grid[0][1]
  ngh left : 0  
  ngh right : 0  
  ngh top : at edge  
  ngh left : 1  

  so the net contribution of this 1 at grid[0][1] = 3


 * Tags
*/

#include"header.h"
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        if(0 == r) {
            return 0;
        }
        int c = grid[0].size();
        int P = 0;
        
        //Find the first 1
        for(int i = 0; i < r; i++) {
            for(int j = 0 ; j < c; j++) {
                if(1 == grid[i][j]) {
                    //helper(int i, int j, P, grid, int r, int c);
                    if(i+1 >=r || grid[i+1][j] != 1 ) {
                        P++;
                    }
                    if(i-1 < 0 || grid[i-1][j] != 1 ) {
                        P++;
                    }
                    if(j+1 >=c || grid[i][j+1] != 1 ) {
                        P++;
                    }
                    if(j-1 < 0 || grid[i][j-1] != 1 ) {
                        P++;
                    }
                }
            }
        }
        return P;
    }
};


int main() {
  Solution S;


  //vector<vector<int>> grid(4);
  //grid[0] = vector<int>({0,1,0,0});
  //grid[1] = vector<int>({1,1,1,0});
  //grid[2] = vector<int>({0,1,0,0});
  //grid[3] = vector<int>({1,1,0,0});

  vector<vector<int>> grid;
  grid.push_back({0,1,0,0});
  grid.push_back({1,1,1,0});
  grid.push_back({0,1,0,0});
  grid.push_back({1,1,0,0});
  cout << S.islandPerimeter(grid);

  return 0;
}

/* 
 * Problem Description
 A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

 * Solution
for a position r,c
see its 4 nghrs
if none have 1; then count_num_island ++

foreach 1 nghrs
  find rep of own and the nhgr
  if(diff && first_nghbr)
    no change in count
  if(diff && not first_nghbr)
    count --
    make the rep same
  if(!diff)
    no change in count


 * Tags
 Union Find
*/

#include"header.h"
class Solution {
    private:
        vector<vector<int>> V;
        int count;
public:
    typedef pair<int, int> P;
    P findrep(vector<vector<P>> &REP, int r, int c) {
        while(1) {
            P p = REP[r][c];
            if(p.first == r && p.second == c) {
                return p;
            }
            r = p.first;
            c = p.second;
        }
    }
    
    void unionrep(vector<vector<P>> &REP, P p1, P p2) {
        REP[p1.first][p1.second] = {p2.first, p2.second};
    }
    
    void helper(vector<vector<P>> &REP, int x, int y, int r, int c, int m, int n, bool &first) {
        if(x >= 0 && x < m && y >= 0 && y < n &&  V[x][y] == 1) {
            P P1 = findrep(REP, x,y);
            P P2 = findrep(REP, r,c);
            if(P1 != P2) {
                if(!first)
                    count--;
                else 
                    first = false;
                unionrep(REP, P1, P2);
            }
        }
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<P>> REP(m, vector<P>(n));
        V.resize(m);
        for(int i = 0 ; i < m; i++) {
            V[i].resize(n, 0);
        }
        
        vector<int> res;
        count = 0;
        
        for(auto p : positions) {
            int r = p.first;
            int c = p.second;
            V[r][c] = 1;
            REP[r][c] = pair<int, int>(r,c);
            bool first = true;
            
           
            helper(REP, r+1, c, r, c, m,n,first);
            helper(REP, r-1, c, r, c, m,n,first);
            helper(REP, r, c+1, r, c, m,n,first);
            helper(REP, r, c-1, r, c, m,n,first);
            
            if(!first)
                res.push_back(count);
            else 
                res.push_back(++count);
        }
        
        return res;
        
    }
};



int main() {
  Solution S;

  vector<pair<int, int>> D({  {0,0},{0,1},{1,2},{2,2}, {2,0}, {1,1} });

  cout << S.numIslands2(3, 3, D);

  return 0;
}

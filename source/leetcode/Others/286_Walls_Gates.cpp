/* Proble Description
    You are given a  x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity eans an epty roo. We use the value 231 - 1 = 2147483647 to represent INF as you ay assue that the distance to a gate is less than 2147483647.

Fill each epty roo with the distance to its nearest gate. If it is ipossible to reach a gate, it should be filled with INF.

For exaple, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Solution:

We want to traverse INFs and numbers 
but need to avoid loops 
2 - INF
2--3
now we wat 3 to again correct 2


Tags:
Grid traversal
*/

#include"header.h"
class Solution {
    int r, c;
public:
    void visitN(int i, int j, int d, vector<vector<int>>& rooms) {
        if(i >= r || i < 0 || j >= c || j < 0) {
            return;
        }
        if(rooms[i][j] == 0 || rooms[i][j] == -1) {
            return;
        }
        
        if(rooms[i][j] <= d) {
          return;
        }
        rooms[i][j] = d;


        visitN(i + 1, j, d+1, rooms);
        visitN(i - 1, j, d+1, rooms);
        visitN(i, j+1, d+1, rooms);
        visitN(i, j-1, d+1, rooms);    
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        r = rooms.size();
         if( 0 == r) {
            return;
        }
        c = rooms[0].size();
        
        for(int i = 0 ; i < r ; i ++)  {
            for(int j = 0 ; j < c ; j ++) {
                if(rooms[i][j] == 0) {
                    visitN(i + 1, j, 1, rooms);
                    visitN(i - 1, j, 1, rooms);
                    visitN(i, j+1, 1, rooms);
                    visitN(i, j-1, 1, rooms);
                }
            }
        }
        
    }
};


int main() {
  Solution S;

  vector<vector<int>> rooms;

  rooms.push_back({INT_MAX, -1, 0, INT_MAX});
  rooms.push_back({INT_MAX, INT_MAX, INT_MAX, -1});
  rooms.push_back({INT_MAX, -1, INT_MAX, -1});
  rooms.push_back({0, -1, INT_MAX, INT_MAX});

  S.wallsAndGates(rooms);
  cout << rooms << "\n";

  return 0;
}

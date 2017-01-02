/* Problem Description
*/

#include"header.h"
class Solution {
    private:
    int r, c;
public:
   int getliveneigh(int i, int j, vector<vector<int>>& board) {
            if( i >= 0 && i <= r-1 && j >= 0  && j <= c-1) {
                return (board[i][j] & 2)>>1;
            }
            return 0;
        }
    void gameOfLife(vector<vector<int>>& board) {
     
        r = board.size();
        if(0 == r) {
            return;
        }
        c = board[0].size();

        for(int i = 0 ; i < r; i ++)  {
            for(int j = 0 ; j < c; j ++) {
              board[i][j]  =  board[i][j]  << 1;
            }
        }

        
        for(int i = 0 ; i < r; i ++)  {
            for(int j = 0 ; j < c; j ++) {
                int numL =0 , numD = 0;
                numL += getliveneigh(i+1, j, board);
                numL += getliveneigh(i+1, j+1, board);
                numL += getliveneigh(i+1, j-1, board);
                numL += getliveneigh(i-1, j, board);
                numL += getliveneigh(i-1, j-1, board);
                numL += getliveneigh(i-1, j+1, board);
                numL += getliveneigh(i, j+1, board);
                numL += getliveneigh(i, j-1, board);
                
                // Any live cell with fewer than two live neighbors dies, as if caused by under-population.
                if(1 == (board[i][j] & 2) >> 1 && numL < 2) {
                    board[i][j] = board[i][j]   + 0;
                }
                // Any live cell with two or three live neighbors lives on to the next generation.
                if(1 == (board[i][j] & 2) >> 1 && ( numL == 2 || numL == 3) ) {
                    board[i][j] = board[i][j]   + 1;
                }
                // Any live cell with more than three live neighbors dies, as if by over-population..
                if(1 == (board[i][j] & 2) >> 1 && ( numL > 3) ) {
                    board[i][j] = board[i][j]   + 0;
                }
                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                if(0 == (board[i][j] & 2) >> 1 && ( numL == 3) ) {
                    board[i][j] = board[i][j]   + 1;
                }
            }
        }

        for(int i = 0 ; i < r; i ++)  {
            for(int j = 0 ; j < c; j ++) {
              board[i][j]  =  board[i][j]  & 1;
            }
        }
    }
};

int main() {
  Solution S;

  vector<vector<int>> D;
  D.push_back({1,0,1,1,0});  
  D.push_back({1,0,1,1,0});  
  D.push_back({1,0,1,1,0});  
  D.push_back({1,0,1,1,0});  
  D.push_back({1,0,1,1,0});  

  S.gameOfLife(D);
  cout << D;

  return 0;
}

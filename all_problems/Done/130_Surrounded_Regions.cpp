/* Proble Description
 Given a 2D B containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the B should be:

X X X X
X X X X
X X X X
X O X X

Tags:
Grid traversal

*/

#include"header.h"
class Solution2 {
    int r, c;
public:
    void visitN(int i, int j, vector<vector<char>>& B) {
        
        if(B[i][j] == 'X' || B[i][j] == '1') {
            return;
        }

        B[i][j] = '1';
        if(i+1 < r)
            visitN(i + 1, j, B);
        if(i-1 >= 0)
            visitN(i - 1, j, B);
        if(j+1 < c)
            visitN(i, j+1,  B);
        if(j-1 >= 0)
            visitN(i, j-1,  B);    
    }
    void solve(vector<vector<char>>& B) {
        r = B.size();
         if( 0 == r) {
            return;
        }
        c = B[0].size();

        // Traverse around the corner llooking for a 'O'
        // If found mark all the connected O with 1
        for(int j = 0 ; j < c ; j ++)  {
            visitN(0, j, B);
            if(r > 1) { 
                visitN(r-1, j,B);;
            }    
        }
        
        for(int i = 0 ; i < r ; i ++)  {
            visitN(i, 0, B);
            if(c > 1) {
                visitN(i, c-1, B);      
            }
        }
        

        for(int i = 0 ; i < r ; i ++)  {
          for(int j = 0 ; j < c; j ++)  {
            if(B[i][j] == 'O') {
              B[i][j] = 'X';
            }
          }
        }
        
        
        for(int i = 0 ; i < r ; i ++)  {
          for(int j = 0 ; j < c; j ++)  {
            if(B[i][j] == '1') {
              B[i][j] = 'O';
            }
          }
        }


    }
};

class Solution {
    private:
    int r, c;
public:
    void mark(vector<vector<char>>& board, int i, int j) {
        
        if(board[i][j] == 'X' || board[i][j] == '2') {
            return;
        }
        
        board[i][j] = '2';
        if(i+1 < r) {
            mark(board, i+1, j);
        }
        
        if(j+1 < c) {
            mark(board, i, j+1);
        }
        
        if(i-1 >= 0) {
            mark(board, i-1, j);
        }
        
        if(j-1 >=0) {
            mark(board, i, j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        r  = board.size();
        if(0 == r) return;
        c = board[0].size();
        
        //top/bottom
        for(int i = 0 ; i < c; i++) {
            if(board[0][i] == 'O') {
                mark(board, 0, i);
            }
            if(r > 1)
            if(board[r-1][i] == 'O') {
                mark(board, r-1, i);
            }
        }
        
        //left/right
        for(int i = 0 ; i < r; i++) {
            if(board[i][0] == 'O') {
                mark(board, i, 0);
            }
            
            if(c>1)
            if(board[i][c-1] == 'O') {
                mark(board, i, c-1);
            }
        }
        for(int i = 0 ; i < r; i++) {
            for(int j = 0 ; j < c ; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '2') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};


int main() {
  Solution S;

  vector<vector<char>> B;

  B.push_back({'X', 'X', 'X', 'X'});
  B.push_back({'X', 'O', 'O', 'X'});
  B.push_back({'X', 'X', 'O', 'X'});
  B.push_back({'X', 'O', 'X', 'X'});

  S.solve(B);
  cout << B << "\n";

  return 0;
}

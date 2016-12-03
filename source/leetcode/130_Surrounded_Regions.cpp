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

*/

#include"header.h"
class Solution {
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

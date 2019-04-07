/* 
 * Problem Description
 Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
 * Solution
 
After reading the extremely helpful hint; a much easier approach became
apparent. The key observation is that in order to win Tic-Tac-Toe you must have
the entire row or column. Thus, we don't need to keep track of an entire n^2
board. We only need to keep a count for each row and column. If at any time a
row or column matches the size of the board then that player has won.

have a count of each row, colm and one for diagonal and one for anti_diag
for a more (r, c)

the key to understand that it acceses a diagonal  is r == c
the key to understand that it acceses a anti_diagonal  is r + c == size-1


         04
       13
     22
  31
40

where the size is 5

 * Tags
  Design
*/

#include"header.h"
class TicTacToe {
    private:
    vector<int> r;
    vector<int> c;
    int diagonal;
    int anti_diagonal;
    int size;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        diagonal = anti_diagonal = 0;
        r.resize(n, 0);
        c.resize(n, 0);
        size  = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(1 == player) {
            r[row] ++;
            c[col] ++;
            if(row == col)
                diagonal ++;
            if(row + col == (size-1))    
                anti_diagonal ++;
        } else {
            r[row] --;
            c[col] --;
            if(row == col)
                diagonal --;
            if(row + col == (size-1))  
                anti_diagonal --;
        }
        
        if(
            (r[row] == size || r[row] == -size) ||
            (c[col] == size || c[col] == -size) ||
            (diagonal == size || diagonal ==-size) ||
            (anti_diagonal == size || anti_diagonal ==-size)
            ) {
                return player;
            } else {
                return 0;
            }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */


int main() {

  return 0;
}

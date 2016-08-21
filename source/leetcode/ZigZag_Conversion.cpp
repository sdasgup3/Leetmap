/* Problem Description
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
                    
                    1 1 1 1
0 1 2 3 4 5 6 7 8 9 0 1 2 3
P A Y P A L I S H I R I N G 

0 : P
4: A
8 : H
12: N
*/

#include"header.h"

class Solution {
public:
    string convert(string s, int numRows) {

      vector<vector<int>> M(numRows);
      int row = 0 , colm = 0;
      int switch = 0, i=0;

      while(i < s.length()) {
        if(0 == sw) {
          if(row == numRows-1) {
            M[row][colm] = s[i++];
            sw =1;
          } else {
            M[row][colm] = s[i++];
            row ++;
          }
        } else {
          if(row == 0) {
          } else {
            row--;
            colm++;
            M[row][colm] = s[i++];
          }

        }
      }
      for(int i = 0 ; i < s.length(); i++) {
        if(0 == swift) {
          //Go down
          M[row][colm] = s[i];

        } else {
          //Go diagonal

        }
      }

      

        
    }
};

int main() {
  Solution S;

  S.convert("PAYPALISHIRING", 3);

  return 0;
}

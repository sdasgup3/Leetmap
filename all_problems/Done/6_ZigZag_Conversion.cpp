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
        
        /*
           *   *
           *  ** 
           * * *
           *   *
        */
        
        vector<pair<int, int>> V(numRows);
        for(int i = 0 ; i < numRows;  i++) {
            if(0 == 2*abs(numRows-1 - i) && 0 == 2*abs(0- i)){
                V[i] = pair<int, int> (1, 1 );
            } else if(0 == 2*abs(numRows-1 - i)) {
                V[i] = pair<int, int> (2*abs(0 - i), 2*abs(0 - i));
            } else if (0 == 2*abs(0 - i)) {
                V[i] = pair<int, int> (2*abs(numRows-1 - i), 2*abs(numRows-1 - i));
            } else {
                V[i] = pair<int, int> (2*abs(numRows-1 - i), 2*abs(0 - i));
            }

            cout << V[i] << "\n";
        }
        
        
        string str("");
        int l = s.length();
        
        for(int i = 0  ; i < numRows; i++) {
            str += s[i];
            int j  = i;
            int toggle = 0;
            while(1) {
                if(!toggle) {
                    j+= V[i].first;
                } else {
                    j += V[i].second;
                }
                
                if(0 == j || j >= l) {
                    break;
                }
                str += s[j];
                toggle = 1- toggle;
            }
        }
        
        return str;
        
    }
};


int main() {
  Solution S;

  cout << S.convert("ABCD", 4);
  cout << S.convert("AB", 1);
  cout << S.convert("B", 1);

  return 0;
}

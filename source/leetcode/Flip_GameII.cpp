/* Problem Description
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    bool helper(string s, int  isStartPlayer) {
        int l = s.length();
        vector<string> possibles;
      
       //cout << s << " " <<  isStartPlayer << " " << lastmove << "\n";  
        for(int i = 0 ; i <= l-2; i++) {
            if(s[i] == '+' && s[i+1] == '+') {

                string t = s;
                t[i] = t[i+1] = '-';
                possibles.push_back(t);
            }
        }
        if(0 == possibles.size()) {
            if(isStartPlayer == 0)
                return true;
            else 
                return false;
        }

        for(string t: possibles) {
          if(false == helper(t, 1-isStartPlayer)) {
            return false;
          }
        }
        return true;
    }
    
    bool canWin(string s) {
        int l = s.length();
        if(l == 1 || 0 == s.compare("--")) {
            return false;
        }
            
        for(int i = 0 ; i <= l-2; i++) {
            if(s[i] == '+' && s[i+1] == '+') {
                string t = s;
                t[i] = t[i+1] = '-';
                bool result = helper(t, 0);
                if(true == result) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


int main() {
  Solution S;

  cout << S.canWin("+++++++++");


  return 0;
}

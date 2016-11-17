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

template <class T>
ostream& operator<<(ostream &OS, vector<T> V) {
  for(int i = 0 ; i < V.size(); i++) {
    OS << V[i] << "::" ;
  }
  OS << "\n";
  return OS;
}

class Solution {

public:
  vector<string> generatePossibleNextMoves(string s) {

    vector<string> R;
    int  l = s.length();

    if(0 == l)
      return R;

    int posn = 0;
    for(; posn <= l-2; ) {
      if(s[posn] != '+') {
        posn++;
        continue;
      }
      if(s[posn+1] == '+') {
        string t = s;
        t[posn] = t[posn+1] = '-';
        R.push_back(t);
      }
      posn ++;
    }

    return R;
  }
private:

};


int main() {
  Solution S;

  cout << S.generatePossibleNextMoves("++++");
  cout << S.generatePossibleNextMoves("+-+-");
  cout << S.generatePossibleNextMoves("-------");


  return 0;
}

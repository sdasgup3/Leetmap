/* Problem Description
 * You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.


        0123456
sec:    2364677
guess:  3354576

val     index
[2]  =  0 6
[3]   = 1
[6]   = 2 4
[4]   = 3
[7] =   5 6

search 3: found at index 1 which does not match with guess index 0; but its not a bull
idea is to remove the bulls from the map first

scan once and remove the bull

[2]  =  0 6
[6]   = 2 4
[7]   = 6

7
7 7 

here 1A0B

7 7 
7
here 1A0B

*/

#include"header.h"
class Solution {

public:

  void print(unordered_map<char, vector<int>*> &M) {
      cout << " \n" ;
    for (auto x : M) {
      cout << x.first << ":" ;
      vector<int> v  = *(x.second);
      for(auto y : v ) {
        cout << y << " " ;
      }
      cout << " \n" ;
    }
  }

  string getHint1(string secret, string guess) {

    //Create a map from the values of secret to its posn
    unordered_map<char, vector<int>*> M;
    int len = guess.length();

    vector<int> guess_posn(len,0);

    int bulls=0, cows=0;

    for(int i = 0 ; i < secret.length(); i++) {
      int c = secret[i];
      if(M.count(c) == 0 ) {
        M[c] = new vector<int>;
      }
      M[c]->push_back(i);
    }

    print(M);
    //Find the bulls
    for(int i = 0 ; i < secret.length(); i++) {
      if(secret[i] == guess[i]) {
        auto it = M.find(guess[i]);
        vector<int> *v = it->second;
        for(int j = 0; j < (*v).size() ; j++ ) {
          if((*v)[j] == i) {
            guess_posn[i] = 1;
            cout << i << "\n";
            (*v)[j] = -1;
            bulls ++;
            break;
          }
        }
      }
    }

    print(M);
    cout << guess_posn;

    //Find the cows
    for(int i = 0 ; i < guess.length(); i++) {
      if(1 == guess_posn[i]) continue;
      if(0 != M.count(guess[i])) {
        auto it = M.find(guess[i]);
        vector<int> *v = it->second;
        for(int j = 0; j < (*v).size() ; j++ ) {
          if((*v)[j] != -1) {
            cows++;
            (*v)[j] = -1;
            break;
          }
        }
      } 
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }

  string getHint(string secret, string guess) {

    //Create a map from the values of secret to # of its occurance
    unordered_map<char, int> M;
    int len = guess.length();

    vector<int> guess_posn;

    int bulls=0, cows=0;

    for(char c : secret) {
      M[c]++;
    }

    // Find the Bulls
    for(int i = 0 ; i < len ; i++) {
      if(secret[i] == guess[i]) {
        bulls ++;
        M[secret[i]] --;
        guess_posn.push_back(i);
      }
    }
    
    int s = guess_posn.size();
    //Now M contains on those entries which could match only for cows
    //Find the Cows
    for(int i = 0, k = 0 ; i < len ; i++) {
      char c = guess[i];
      if(k < s && i == guess_posn[k]) {
        k++;
        continue;
      }

      //cout << c << " " << M.count(c) << " " << guess_posn[0] << "\n";
      if(0 != M.count(c) && M[c] > 0) {
        cows++;
        M[c]--;
      }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
private:

};


int main() {
  Solution S;

  cout << S.getHint("1807", "7810");
  cout << S.getHint("1123", "0111");


  return 0;
}

/* Problem Description
   Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

Tags:
Map
*/

#include"header.h"
class Solution {

public:
  bool canConstruct(string ransomNote, string magazine) {

    unordered_map<char, int> M;
    for(auto x : magazine) {
      M[x] ++;
    }
    for(auto y : ransomNote) {
      if(0 == M.count(y)) {
        return false;
      } else {
        if(M[y] == 0) {
          return false;
        }
        M[y] --;
      }
    }

    return true;
  }
private:

};


int main() {
  Solution S;

  cout << S.canConstruct("aa", "ab");

  return 0;
}

/* Problem Description
*/

#include"header.h"
class Solution {
public:
    int firstUniqChar(string s) {
      int len = s.length();
      unordered_map<char, int> M;

      for(auto x : s ) {
        M[x] ++;
      }

      for(int i = 0 ; i < len ; i ++ ) {
        if(M[s[i]] == 1) {
          return i;
        }
      }

      return -1;
    }
};

int main() {
  Solution S;

  cout << S.firstUniqChar("loveleetcode");

  return 0;
}

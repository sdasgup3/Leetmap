/* Problem Description
 * Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

#include"header.h"
class Solution {
public:
    string reverseVowels(string s) {
      int len = s.length();

      if(0 == len) return s;

      int first =  0 ; 
      int last  = len -1;
      unordered_map<int , bool> M;
      M['a'] = true;
      M['e'] = true;
      M['i'] = true;
      M['o'] = true;
      M['u'] = true;

      while(first < last) {
        while(first < last) {
          if(0 == M.count(s[first])) {
            first++;
          } else {
            break;
          }
        }

        if(first == last) {
          break;
        }
      
        while(first < last) {
          if(0 == M.count(s[last])) {
            last--;
          } else {
            break;
          }
        }

        if(first == last) {
          break;
        }

        //swap
        char t = s[first];
        s[first] = s[last];
        s[last] = t;

        first++;
        last--;
      }

      return s;
    }
};


int main() {
  Solution S;
  string s("ai");
  cout << S.reverseVowels(s);

  return 0;
}

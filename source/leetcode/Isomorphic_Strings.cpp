/* Problem Description
   Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

#include"header.h"
class Solution {

public:
    bool isIsomorphic(string s, string t) {

      for(int i = 0 ; i < s.length(); i++) {
        if(0 == M1.count(s[i])) {
          if(0 != M2.count(t[i])) {
            //to avoid a->x b->x
            return false;
          }
          M1[s[i]] = t[i];
          M2[t[i]] = s[i];
        } else {
          if(t[i] != M1[s[i]]) {
            // to avoid a->x a->y
            return false;
          }
        }
      }

      return true;
    }

private:
    unordered_map<char,char> M1;
    unordered_map<char,char> M2;

};


int main() {
  Solution S;
  string s = "egg";
  string t = "dtt";
  cout << s << " " << t << " " << S.isIsomorphic(s, t);

  s = "abc";
  t = "xyx";
  cout << s << " " << t << " " << S.isIsomorphic(s, t);

  s = "aba";
  t = "xyz";
  cout << s << " " << t << " " << S.isIsomorphic(s, t);

  s = "";
  t = "";
  cout << s << " " << t << " " << S.isIsomorphic(s, t);
  return 0;
}

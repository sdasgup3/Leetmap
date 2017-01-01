/* Problem Description
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Tags:
Array
*/

#include"header.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {

      int l = s.length();

      if(0 == l) {
        return 0;
      }
      bool arr[l];

      for(int start = 0 ; start < l; start ++) {
        for(int end = 0 ; end < l; end ++) {
          string sub = s.substr(start, end-start+1);
          if(0 != wordDict.count(sub)) {
            if(start == 0  || arr[start-1] == true) {
              arr[end] = true;
            }
          }
        }
      }
      return arr[l-1];
    }
};

int main() {
  Solution S;

  unordered_set<string> D;
  //D.insert("leet");
  //D.insert("code");
  //D.insert("buk");
  //D.insert("coke");

  cout << S.wordBreak("cokebukcodee", D);

  return 0;
}

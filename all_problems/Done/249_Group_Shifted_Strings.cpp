/* Problem Description
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Solution:
Find the key for each string and group based on that

Tags:
Map

*/

#include"header.h"
class Solution {
  public:
     vector<vector<string>> groupStrings(vector<string> strings) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> M;

        for(auto s: strings) {
            string code = get_canonical(s);
            M[code].push_back(s);
        }

        for(auto list : M) {
          result.push_back(list.second);
        }

        return result;
    }
    string get_canonical(string s) {
      //cout << s << " " ; 
      int len = s.length();
      if(0 == len) return s;

      int d = s[0] - 'a';
      string ret;

      for(auto c : s) {
        int ch = (((c - 'a') - d  + 26) %26) ;
        ret.push_back('a' + ch);
      }


      //cout << ret << "\n";
      return ret;

    }
};


int main() {
  Solution S;

  vector<string> s = {"ab", "za", "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};

  cout << S.groupStrings(s);

  return 0;
}

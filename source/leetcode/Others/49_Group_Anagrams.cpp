/* Problem Description
   Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

Tags:
Map
*/

#include"header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> M;   
      vector<vector<string>> R;
      

      for(auto str : strs) {
       // auto t = str;
       // sort(t.begin(), t.end()); or any other means to canolicalize str
       string t(26,0);
        for(char c: str) {
          t[c-'a']++;
        }

        M[t].push_back(str);
      }
      
      for(auto p : M) {
        R.push_back(p.second);
      }

      return R;

    }
};

int main() {
  Solution S;

  vector<string> D;

  D.push_back("eat");
  D.push_back("tea");
  D.push_back("tan");
  D.push_back("ate");
  D.push_back("nat");
  D.push_back("bat");

  cout << S.groupAnagrams(D);

  return 0;
}

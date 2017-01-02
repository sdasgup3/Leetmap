/* Problem Description
   Write a function to find the longest common prefix string amongst an array of strings.
*/

#include"header.h"
class Solution {

public:
  string longestCommonPrefix(vector<string>& strs) {

    string res = "";;
    int s = strs.size();
    if( s == 0 ) {
      return res;
    }

    std::sort(strs.begin(), strs.end());

    long unsigned int min_len = std::min(strs[0].length(), strs[s-1].length());

    for(int i = 0 ; i < min_len; i ++) {
      if(strs[0][i] != strs[s-1][i]) {
          return res;
      } else  {
        res.push_back(strs[0][i]);
      }
    }

    return res;
   }
  string longestCommonPrefix1(vector<string>& strs) {

    string res = "";;
    if( strs.size() == 0 ) {
      return res;
    }

    long unsigned int min_len = INT_MAX;
    for(auto str: strs) {
      min_len = std::min(min_len, str.length());     
    }

    for(int i = 0 ; i < min_len; i ++) {
      char candidate = strs[0][i];
      bool check_all_match = true; 
      for(auto str: strs) {
        if(str[i] != candidate) {
          check_all_match = false;
          break;
        }
      }

      if(false == check_all_match) {
        return res;
      } else {
        res.push_back(candidate);
      }
    }

    return res;
   }
private:

};


int main() {
  Solution S;

  vector<string> D;

  D.push_back("de");
  D.push_back("dert");
  D.push_back("dene");
  D.push_back("deke");

  cout << S.longestCommonPrefix(D);

  return 0;
}

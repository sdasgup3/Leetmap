/* Problem Description
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
          vector<string> temp;
          for(auto mem : list.second) {
            temp.push_back(mem);
          }
          result.push_back(temp);
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

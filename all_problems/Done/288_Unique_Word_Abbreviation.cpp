/* Unique Word Abbreviation

  Problem Description:

  An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

  a) it                      --> it    (no abbreviation)

       1
  b) d|o|g                   --> d1g

                1    1  1
       1---5----0----5--8
  c) i|nternationalizatio|n  --> i18n

                1
       1---5----0
  d) l|ocalizatio|n          --> l10n
  Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

  Example: 

  Given dictionary = [ "deer", "door", "cake", "card", "card" ]

  isUnique("dear") -> false // This is false due to the presence of other word door with same abbr
  isUnique("cart") -> true
  isUnique("cane") -> false
  isUnique("make") -> true 
  isUnique("card") -> true // No other word has the same abbr


Tags:
Map
*/

#include"header.h"
class Solution {
    public:
    string findAbb(string &s) {
    int len = s.length();
    if(len <= 2) {
      return s;
    }

    string res;
    res = s[0] + to_string(len-2) + s[len-1]; 

    return res;
  }

  Solution(vector<string> &dictionary) {  
    for(auto &s : dictionary) {
      string key = findAbb(s);
      M[key].insert(s);
    }
  }

  bool isUnique(string word) {
    string key = findAbb(word);
    if(0 == M.count(key)) {
      return true;
    } else if (M[key].size() == 1 && 1 == M[key].count(word)) {
      return true;
    }
    return false;
  }

private:
  unordered_map<string, unordered_set<string>> M;

};



int main() {

  vector<string> D;

  D.push_back("dear");
  D.push_back("door");
  D.push_back("cake");
  D.push_back("card");
  D.push_back("card");

  Solution S(D);

  cout << "dear" << " " << S.isUnique("dear") << "\n";
  cout << "cart" << " " << S.isUnique("cart") << "\n";
  cout << "cane" << " " << S.isUnique("cane") << "\n";
  cout << "make" << " " << S.isUnique("make") << "\n";
  cout << "card" << " " << S.isUnique("card") << "\n";


  return 0;
}

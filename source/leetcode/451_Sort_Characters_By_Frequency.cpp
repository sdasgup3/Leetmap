/* Problem Description
 * Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
#include"header.h"

class Solution {
  private:
  typedef pair<char, int> P;
public:
  bool static cmp_func(P a, P b) {
  return a.second > b.second;
}

    string frequencySort(string s) {
      int l = s.length();
      string res;
      if(l<=2) return s; 

      vector<pair<char, int>> V;
      unordered_map<char, int> M;
      for(char c: s) {
        M[c] ++;
      }
       
      for(P p : M) {
        V.push_back(p);
      }
       

      sort(V.begin(),  V.end(), cmp_func);

      for(P p : V) {
        for(int i = 0 ; i < p.second; i++) {
          res.push_back(p.first);
        }
      }

      return res;
    }
};


int main() {
  Solution S;

  string s("tree");
  cout << S.frequencySort(s) << "\n";

  s = string("cccaaa");
  cout << S.frequencySort(s) << "\n";

  s = string("Aabb");
  cout << S.frequencySort(s) << "\n";

  return 0;
}

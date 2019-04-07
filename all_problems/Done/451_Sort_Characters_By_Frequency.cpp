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


Tags:
Comparision sort
Counting sort
*/

#include"header.h"


class Solution1 {
  private:
  typedef pair<char, int> P;
public:

    string frequencySort(string s) {
      int l = s.length();
      string res;
      if(l<=2) return s; 
      
      unordered_map<char, int> M;

      for(char c: s) {
        M[c] ++;
      }
       
      sort(s.begin(),  s.end(), 
          [&](char a, char b) {
              if(M[a] > M[b]) 
                return true;

              if(M[a] == M[b]) {
                return a < b;
              }

              return false;
  
            }
          );

      return s;
    }
};

class Solution {
  private:
  typedef pair<char, int> P;
public:

    string frequencySort(string s) {
      int l = s.length();
      string res("");
      if(l<=2) return s; 
      
      unordered_map<char, int> M;

      for(char c: s) {
        M[c] ++;
      }

      vector<string> B(l+1, "");

      for(auto p : M) {
        char c = p.first;
        int n = p.second;
        B[n].append(n, c);
      }

      for(int i = l ; i >= 0 ; i--) {
          res += B[i];
      }
       

      return res;
    }
};




int main() {
  Solution S;

  string s("tree");
  cout << s << " " << S.frequencySort(s) << "\n";

  s = string("cccaaa");
  cout << s << " " << S.frequencySort(s) << "\n";

  s = string("Aabb");
  cout << s << " " << S.frequencySort(s) << "\n";

  s = string("3232444");
  cout << s << " " << S.frequencySort(s) << "\n";
  return 0;
}

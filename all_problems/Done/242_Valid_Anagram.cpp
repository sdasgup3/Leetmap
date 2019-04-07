/* 
 * Problem Description

 Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 * Solution
 * Tags
 Map
*/

#include"header.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        
        unordered_map<int, int > M;
        for(auto c : s) {
            M[c] ++;
        }
        
        for(auto c : t) {
            if(0 != M.count(c)) {
                M[c] --;
                if(M[c] == 0) {
                //if(M[c] == -1) {
                // this will leave entries wil count zero so the final return need to check that
                    M.erase(c);
                }
            } else {
                return false;
            }
        }
        
        return M.size() == 0;
    }
};

int main() {
  Solution S;

  return 0;
}

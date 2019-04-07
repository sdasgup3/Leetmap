/* Problem Description
 * Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

Solution:

Tags:
Array
*/

#include"header.h"
class Solution {
public:
    void swap(char *a, char *b) {
        if(a ==b) return;
        
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    string reverseVowels(string s) {
        int first = 0;
        int last = s.length()-1;
        unordered_map<char, bool> M;
         M['a'] = true;
        M['e'] = true;
        M['i'] = true;
        M['o'] = true;
        M['u'] = true;
        M['A'] = true;
        M['E'] = true;
        M['I'] = true;
        M['O'] = true;
        M['U'] = true;

        
        while(first < last) {
            while(first < last && 0 == M.count(s[first])) {
                first ++;
            }
            
            while(first < last && 0 == M.count(s[last])) {
                last--;
            }
            
            if(first < last) {
                swap(&s[first], &s[last]);
                first++;
                last --;
            } else {
                break;
            }
        }
        
        return s;
    }
};


int main() {
  Solution S;
  string s("ai");
  cout << S.reverseVowels(s);

  return 0;
}

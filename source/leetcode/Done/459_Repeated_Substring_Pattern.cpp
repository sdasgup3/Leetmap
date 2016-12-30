/* 
 * Problem Description
 Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 * Solution

 1. No need to find all the sunstr using double for loop
 as all the required substr need to begin with s[0]

 Consider the case 
 abc abc abc

 we need to figure out the "initial" abc and that is sufficient; no need for tracking the mid or last abc

 2. For each such substr, find its length(S) and check if str.size is a multiple of S.
 3. If yes, find the Quotient and create a new str by appending substr Q timers and check is actually forms the inout string

Tip: 
No need for checking all substr like 
a ab
search for 'a' starting form 1 posn
 
 012 345 678 
 abc abc abc

 hop at 3, 6, .. using find because they hint on possible restart (as all restarts much happen with s[0])


 * Tags
 Array
*/

#include"header.h"
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        
        int sz = str.length();
        if(0 == sz) return false;
        char start = str[0];
        
        int posn = 1;
        while(1) {
            posn = str.find(start, posn);
            if(posn == string::npos) {
                break;
            }
            
            int l_sub = posn-1-0+1;
            string sub = str.substr(0, l_sub);
            
            if(0 == (sz % l_sub)) {
                int ctr = sz/l_sub;
                string cmp_str("");
                for(int k = 0 ; k < ctr; k++) {
                    cmp_str += sub;
                }
                if(cmp_str == str) return true;
            }
            posn++;
        }
        
        return false;
    }
};


int main() {
  Solution S;

  cout << S.repeatedSubstringPattern("abab");

  return 0;
}

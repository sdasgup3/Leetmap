/* 
 * Problem Description
 Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
 * Solution
 * Tags
 Array
*/

#include"header.h"
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int l1 = word.length();
        int l2 = abbr.length();
        if(l2>l1) {
            return false;
        }
        
        int i = 0, j = 0;
        
        while(i < l2) {
            if('a' <= abbr[i] && abbr[i] <= 'z') {
                if(abbr[i] != word[j]) {
                    return false;
                }
                i++; j++;
                continue;
            }
            
            if(abbr[i] == '0') return false;
            int start = i;
            while(i< l2 && '0' <= abbr[i] && abbr[i] <= '9') {
                i++;
            }
            
            int num = stoi(abbr.substr(start, i-1-start+1));
            
            if(j+num > l1) return false;
            
            j += num;
            
        }
        
        return j == l1;
        
    }
};


int main() {
  Solution S;


  return 0;
}

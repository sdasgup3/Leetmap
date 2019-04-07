/* Problem Description
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

* 
*/

#include"header.h"
class Solution {
public:
    void reverseWords(string &s) {
        if(s.length() <= 1) return ;
        
        reverse(s.begin(), s.end());
        
        int start = 0, posn;
        while(1) {
            int posn = s.find(' ', start);
            if(posn == string::npos) {
                break;
            }
            
            reverse(s.begin() + start, s.begin() + posn);
            start = posn +1;
        }
        //"dsada dsdfsf"
        reverse(s.begin() + start, s.end());
    }
};

int main() {
  Solution S;

  string s("sky blue");
  S.reverseWords(s);

  return 0;
}

/* Problem Description
 * Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

#include"header.h"
class Solution {
public:
    void swap(char *a, char *b) {
        if(a == b) return;
        
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    void reverse(string &str, int first, int last) {
        int mid = (last - first + 1) /2 ;
        for(int i = 0 ; i < mid ; i++) {
            swap(&str[first + i], &str[last - i]);
        }
    }
    
    void reverseEachWord(string &str, int sz) {
        int posF = 0;
        while(1) {
            int posL = str.find(' ', posF);
            if(posL == string::npos) {
                reverse(str, posF, sz-1);
                break;
            }
   //         cout << str << " " <<posF << " " << posL <<   "\n";
            reverse(str, posF, posL -1);
            posF = posL+1;
        }
    }
    void reverseWords(string &s) {
    
        string str("");
        int first = 0 ;
        int len =  s.length();
        int last = len -1;
        
        //remove leading spaces
        while(first < len && s[first] == ' ') {
            first++;
        }
        
        //remove trailing spaces
        while(last >= 0 && s[last] == ' ') {
            last --;
        }

        //copy first to last skipping multiple spaces
        for(int i = first ; i <= last; ) {
            if(s[i] != ' ') {
                str.push_back(s[i]);
                i++;
            } else {
                str.push_back(s[i]);
                while(s[i] == ' ') {
                    i++;
                }
            }
        }
        
        //reverse the entire string
        int sz = str.length();
        cout << sz << "\n";
        if(0 == sz)  {
          s  = str; 
          return;
        }
        reverse(str, 0, sz-1);
        
        reverseEachWord(str, sz);
        s = str;
    }
};


int main() {
  Solution S;

  //string s("the sky is blue");
  string s(" ");
  S.reverseWords(s);
  cout << s << "\n";

  return 0;
}

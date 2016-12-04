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
        int sz =  s.length();
        if(0 == sz)  {
          return;
        }
        
        //reverse the entire string
        reverse(s, 0, sz-1);
        
        reverseEachWord(s, sz);

    }
};

int main() {
  Solution S;

  string s("sky blue");
  S.reverseWords(s);

  return 0;
}

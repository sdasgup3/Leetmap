/* Problem Description
   Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        if n == 0:
            return True
        
        if n % 2 != 0:
            return False
            
        while '()' in s or '{}' in s or '[]' in s:
            s = s.replace('{}','').replace('()','').replace('[]','')
        
        if s == '':
            return True
        else:
            return False
*/

#include"header.h"
class Solution {

public:
   bool isValid(string s) {

     Stack<char> S;

     for(int i = 0 ; i < s.length(); i++) {
       char c = s[i];
        if(c == '{' || c == '[' || c == '(') {
          S.push(c);
        } else {
          if(c == ']' && (S.isempty() || S.top() != '[')) {
              return false;
          }
          if(c == ')' && (S.isempty() || S.top() != '(')) {
              return false;
          }
          if(c == '}' && (S.isempty() || S.top() != '{')) {
              return false;
          }
          S.pop();
        }
     }

     return S.isempty() == true;
   }
private:

};


int main() {
  Solution S;

  cout << S.isValid("()[{{}}][(){}]") << "\n";

  return 0;
}

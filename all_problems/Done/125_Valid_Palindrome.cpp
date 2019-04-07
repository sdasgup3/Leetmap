/* Problem Description
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Subscribe to see which companies asked this question

Tags:
Palindrom
*/

#include"header.h"
class Solution {

public:
  bool isalphanum(char c) {
    if(c >= 'a' && c <= 'z' ) {
      return true;
    }
    if(c >= 'A' && c <= 'Z' ) {
      return true;
    }
    if(c >= '0' && c <= '9' ) {
      return true;
    }

    return false;
  }

  char to_lower(char c) {
    if(c >= 'a' && c <= 'z' ) {
      return c;
    }
    if(c >= 'A' && c <= 'Z' ) {
      return c -'A' +'a';
    }
    if(c >= '0' && c <= '9' ) {
      return c;
    }
  }
   bool isPalindrome(string s) {
      int len = s.length();

      if(len <= 1 ) return true;
     int first = 0;
     int last = len -1;

     while(1) {
      
       //Find the next alphanumeric character from start
       for(; first < len; first++) {
          if(true == isalphanum(s[first])) {
            break;
          }
       }

       //Find the next alphanumeric character from last
       for(; last >= 0; last --) {
          if(true == isalphanum(s[last])) {
            break;
          }
       }

       if(first > last) {
         break;
       }

       if(to_lower(s[first]) != to_lower(s[last])) {
        return false;
       }

       first ++; last --;
     }
      
     return true;
    }
private:

};


int main() {
  Solution S;

  cout << S.isPalindrome("A man, a plan, a canal: Panama") << "\n";
  cout << S.isPalindrome("race a car") << "\n";
  cout << S.isPalindrome("r") << "\n";

  return 0;
}

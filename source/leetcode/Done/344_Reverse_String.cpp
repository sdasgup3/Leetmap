/* 
 * Problem Description
 Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 * Solution
 * Tags
 Array
*/

#include"header.h"
class Solution {

public:
  void swap(char *a, char *b) {
    if(a == b) {
      return ;
    }
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }
  string reverseString(string s) {  
    int ln = s.length();
    if(ln <=1) {
      return s;
    }

    for(int i = 0 ; i < ln/2; i++) {
      swap(&s[i], &s[ln-1-i]);
    }

    return s;

  }
private:

};


int main() {
  Solution S;

  cout << S.reverseString("dsand");

  return 0;
}

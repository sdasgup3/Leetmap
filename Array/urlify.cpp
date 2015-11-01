/*
Write a method to replace all spaces in a string with'%20'. You may assume that
the string has sufficient space at the end of the string to hold the additional
characters, and that you are given the "true" length of the string. (Note: if imple-
menting in Java, please use a character array so that you can perform this opera-
tion in place.)
*/

#include<iostream>
#include<string>
#include<assert.h>

void urlify(std::string &s) {
  int spaces = 0;
  for(int i = s.length() -1;  i >= 0; i--) {
    if(s[i] == ' ') {
      spaces ++;
    }
  }

  int actual_length = s.length() ;
  int new_length = actual_length  - spaces + spaces*3;
  s.resize(new_length);

  for(int i = actual_length - 1, end_ptr = new_length-1; i >=0; i--) {
    if(s[i] == ' ') {
      s[end_ptr--] = '2';
      s[end_ptr--] = '0';
      s[end_ptr--] = '%'; 
    } else {
      s[end_ptr--]  = s[i]; 
    }
  }
}


int main()
{
  std::string s = "My Name Is  D        ";
  std::cout << "String: " << s << std::endl;
  urlify(s);
  std::cout << "Result: " << s << std::endl;
}

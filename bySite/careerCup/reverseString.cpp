#include<iostream>


void
reverse(std::string &str) {
  int len = str.length();
  int mid = len/2;

  for(int i = 0 ; i < mid; i++) {
    char c        = str[i];
    str[i]        = str[len-1-i];
    str[len-i-1]  = c;
  }
}

int main()
{
  std::string str("abcde");
  std::cout << str << "\n";
  reverse(str);
  std::cout << str << "\n";

  std::string str1("abcd");
  std::cout << str1 << "\n";
  reverse(str1);
  std::cout << str1 << "\n";
}

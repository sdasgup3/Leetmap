/*
	Reverse a string without using a temp variable

*/
#include<iostream>
#include<string>
using namespace std;

void reverse(string &s) {
  int len = s.length();
  for(int i = 0; i < len/2; i++) {
    //if(i != len-1 -i) {
      s[i] = s[i] ^ s[len-1-i];
      s[len-i-1] = s[i] ^ s[len-1-i];
      s[i] = s[i] ^ s[len-1-i];
    //}
  }
}

int main() {
  string s;
  
  s = string("1234");
  cout << "Before:" << s << "\n";
  reverse(s);
  cout << "After:" << s << "\n";

  s = string("12345");
  cout << "Before:" << s << "\n";
  reverse(s);
  cout << "After:" << s << "\n";

  s = string("");
  cout << "Before:" << s << "\n";
  reverse(s);
  cout << "After:" << s << "\n";

  s = string("1");
  cout << "Before:" << s << "\n";
  reverse(s);
  cout << "After:" << s << "\n";

  s = string("2222");
  cout << "Before:" << s << "\n";
  reverse(s);
  cout << "After:" << s << "\n";
  return 0;
}

#include<iostream>
#include<cstring>

using namespace std;

string
remove_all_spaces(string str) {
  int len = str.length();

  int ptr1 = 0, ptr2 = 0 ;
  for(int i = 0 ; i < len; i++) {
    if(isspace(str[i])) {
      continue;
    }
    str[ptr1++] = str[i];
  }

  str[ptr1]  = '\0';
  return str;
}


int main() {

  string str = " dsa nd ";
  cout << str.c_str() << ":" << remove_all_spaces(str).c_str() << "\n";

  return 0;
}

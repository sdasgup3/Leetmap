#include<iostream>
using namespace std;

bool
strstr(string str, string substr) {
  if(str.length() == 0 || substr.length() == 0 || substr.length() > str.length()) 
    return false;

  for(int i = 0 ; i < str.length(); i++) {

    if((str.length() - i) < substr.length())
      break;

    if(str[i] == substr[0]) {

      int j = 0, k = i;
      for(; j < substr.length(); j++, k++) {
        if(str[k] != substr[j]) {
          break;
        }
      }

      if(j == substr.length()) {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  string str, substr;

  str = string("dsand is here");
  substr = string("is");
  cout << strstr(str, substr) << "\n";

  str = string("dsand is here");
  substr = string("e");
  cout << strstr(str, substr) << "\n";
}

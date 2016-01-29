#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int
htoi(string s) {
  int ret = 0;
  int pow = 1;

  for(int i = s.length()-1; i>=0; i--, pow *=16) {
    if(s[i] == 'x' || s[i] == 'X') {
      break;
    }

    if(s[i] >= '0' && s[i] <= '9') {
      ret = ret + (s[i] - '0')*pow; 
    } else  {
      int offset = 0;
      if(s[i] >= 'a' && s[i] <= 'f') {
        offset = (s[i] - 'a');
      } else if(s[i] >= 'A' && s[i] <= 'F') {
        offset = (s[i] - 'A');
      } else {
        assert(0 && "wrong hex digits");
      }

      ret = ret + (10+offset)*pow; 
    }
  }
  return ret;
}

int main()
{
  string s = "0x23";
  cout << "Hex :" << s << " Int :" << htoi(s) << "\n";

  s = string("0x0");
  cout << "Hex :" << s << " Int :" << htoi(s) << "\n";

  s = string("0xff");
  cout << "Hex :" << s << " Int :" << htoi(s) << "\n";

  s = string("0xAb");
  cout << "Hex :" << s << " Int :" << htoi(s) << "\n";

  s = string("0x34cbDA");
  cout << "Hex :" << s << " Int :" << htoi(s) << "\n";
  return 0;
}

#include<iostream>


std::string
replace_v1(std::string str) {
  int len = str.length();
  int count_ws = 0, iter = 0;
  while(iter != len) {
    if(str[iter] == ' ') {
      count_ws ++;
    } 
    iter++;
  }

  int newlength = len - count_ws + count_ws*3;

  std::string res;
  res.resize(newlength);
  for(int i = len-1, iter = newlength-1 ; i >= 0; i--, iter--) {
    if(str[i] == ' ' ) {
      res[iter--] = '0';
      res[iter--] = '2';
      res[iter] = '#';
    } else {
      res[iter] = str[i];
    }
  }
  return res;

}

std::string
replace(std::string str) {
  int len = str.length();
  int count_ws = 0, iter = 0;
  while(iter != len) {
    if(str[iter] == ' ') {
      count_ws ++;
    } 
    iter++;
  }

  int newlength = len - count_ws + count_ws*3;

  str.resize(newlength);
  for(int i = len-1, iter = newlength-1 ; i >= 0; i--, iter--) {
    if(str[i] == ' ' ) {
      str[iter--] = '0';
      str[iter--] = '2';
      str[iter] = '#';
    } else {
      str[iter] = str[i];
    }
  }
  return str;

}

int main()
{
  std::string str;
  std::string res;

  str = std::string("ab  c  d ");
  res = replace(str);
  std::cout << str << "<--->" << res << "\n";

  str = std::string("ab  c  d");
  res = replace(str);
  std::cout << str << "<-->" << res << "\n";

}

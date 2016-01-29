#include<iostream>
#include<cstring>
#include<algorithm>
#include"../utils.h"


bool compareStr(std::string a, std::string b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  if(strcmp(a.c_str(), b.c_str()) < 0) {
    return true;
  } else {
    return false;
  }
}

void
groupAnagrams(std::string str[], int n) {
  std::sort(str, str + n, compareStr);
}


int main() {

  std::string str[] = {"123", "456", "789", "321", "654", "987", "231", "789"};
  int size = sizeof(str)/sizeof(str[0]);

  for(int i = 0 ; i < size; i++) {
    std::cout << str[i] << " ";
  }
  std::cout << " \n";

  groupAnagrams(str, size);
  for(int i = 0 ; i < size; i++) {
    std::cout << str[i] << " ";
  }

}

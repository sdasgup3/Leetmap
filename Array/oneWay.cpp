#include<iostream>
#include<string>
#include<cstring>

bool oneAway(std::string str1, std::string str2){
  int len1 = str1.length();
  int len2 = str2.length();

  if(!(len1 == len2 || len1 == len2-1 || len2 == len1-1)) {
    return false;
  }


  bool oneEdit = false ;

  if(len1 == len2) {
    for(int i = 0 ; i < len1 ; i++) {
      if(str1[i] != str2[i]) {
        if(false == oneEdit) {
          oneEdit = true;
        } else {
          return false;
        }
      }
    }
    return true;
  }

  int i,j;
  for(i = 0, j = 0 ; i < len1 && j < len2;) {
    if(str1[i] != str2[j]) {
      if(false == oneEdit) {
        oneEdit = true;
        if(len1 > len2) {
          i++;
        } else {
          j++;
        }
        continue;
      } else {
        return false;
      }
    }
    i++; j++;
  }
  if((i != len1 || j != len2) && true == oneEdit) {
    return false;
  }
  return true;
}

int main()
{
  std::string str1("pale");
  std::string str2("ple");
  bool res = oneAway(str1, str2);
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << res << std::endl;

  str1 = "pale";
  str2 = "bake";
  res = oneAway(str1, str2);
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << res << std::endl;

  str1 = "pales";
  str2 = "pale";
  res = oneAway(str1, str2);
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << res << std::endl;

  str1 = "pales";
  str2 = "bales";
  res = oneAway(str1, str2);
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << res << std::endl;

  return 0;
}

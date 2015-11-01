/*
`Detect one edit: remove, insert, replace
*/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>


bool oneAway_v1(std::string str1, std::string str2){
  int len1 = str1.length();
  int len2 = str2.length();

  if(!(len1 == len2 || len1 == len2-1 || len2 == len1-1)) {
    return false;
  }

  std::vector<int> V(256,0);
  for(int i = 0 ; i < str1.length(); i++) {
    V[str1[i]] ++;
  }

  bool oneEdit = false;
  for(int i = 0 ; i < str2.length(); i++) {
    if(0 == V[str2[i]] ) {
      if(true == oneEdit) {
        return false;
      } else {
        oneEdit = true;
      }
    } else {
      V[str2[i]] --;
    }
  } 

  oneEdit = false;
  for(int i = 0 ; i < str1.length(); i++) {
    if(V[str1[i]] == 0 ) {
      continue;
    }
    if(V[str1[i]] > 1) {
      return false;
    }
    if(V[str1[i]] > 0) {
      if(true == oneEdit) {
        return false;
      } else {
        oneEdit = true;
      }
    }
  }

  return true;
}

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

bool oneAway_v2(std::string str1, std::string str2){
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
  } else {
    int i = 0, j = 0;
    for(; i < len1, j < len2 ; ) {
      if(str1[i] != str2[j]) {
        if(false == oneEdit) {
          oneEdit = true;
        } else {
          return false;
        }
        if(len1 > len2) {
          i++;
        } else {
          j++;
        }
      } else{
        i++;j++;
      }
    }

    if(true == oneEdit && (i != len1 || j != len2)) {
      return false;
    }
    //redundant as oneEdit ==true means the are same for the common length part
    // but not for the extra's which is only one as |len1-len2| == 1
    if(false == oneEdit ) {
      if(i == len1 && j != len2 && std::abs(len2-1-j) > 1) {
        return false;
      }
      if(j == len2 && i != len1 && std::abs(len1-1-i) > 1) {
        return false;
      }
    }

  }

  return true;
}

int main()
{
  std::string str1("pale");
  std::string str2("ple");
  bool res ;
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << oneAway(str1, str2) << " " << oneAway_v2(str1, str2) << " "<< oneAway_v1(str1, str2) << std::endl;

  str1 = "pale";
  str2 = "bake";
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << oneAway(str1, str2) << " " << oneAway_v2(str1, str2) << " "<< oneAway_v1(str1, str2) << std::endl;

  str1 = "pales";
  str2 = "pale";
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << oneAway(str1, str2) << " " << oneAway_v2(str1, str2) << " "<< oneAway_v1(str1, str2) << std::endl;

  str1 = "pales";
  str2 = "bales";
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << oneAway(str1, str2) << " " << oneAway_v2(str1, str2) << " "<< oneAway_v1(str1, str2) << std::endl;

  str1 = "pales";
  str2 = "patesxz";
  std::cout << " Str1: "  << str1 << " " << "Str2: " << str2 << std::endl;
  std::cout << " oneAway: " << oneAway(str1, str2) << " " << oneAway_v2(str1, str2) << " "<< oneAway_v1(str1, str2) << std::endl;


  return 0;
}

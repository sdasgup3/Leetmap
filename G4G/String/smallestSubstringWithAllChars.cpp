#include<iostream>
#include<map>
using namespace std;

/*
 *Find the smallest window in a string containing all characters of another string
Given two strings string1 and string2, find the smallest substring in string1 containing all characters of string2 efficiently.

For Example:

Input string1: “this is a test string”
Input string2: “tist”
Output string: “t stri”
 * */

string
func(string str1, string str2) {

  map<char, int> reqMap;
  map<char, int> hasMap;
  int min_len = -1;

  //Find a map of required characters
  for(int i = 0 ; i < str2.length(); i++ ) {
    reqMap[str2[i]] ++;
  }
  
  //Find the first window satisfying the critrion
  int start = -1;
  int end = -1;
  for(int i = 0 ; i < str1.length(); i++ ) {
    //cout << str1[i] <<  "\n";

    if(reqMap.find(str1[i]) == reqMap.end()) {
      continue;
    }
    if(-1 == start) {
      start = i;
    }

    hasMap[str1[i]]++;
    //cout <<  hasMap[str1[i]] <<  " " <<  reqMap[str1[i]] <<  "\n";

    bool goon = false;
    map<char, int>::iterator itB = reqMap.begin();
    map<char, int>::iterator itE = reqMap.end();
    for(; itB != itE; itB++) {
      if(hasMap[(*itB).first] < (*itB).second) {
        goon = true;
        break;
      }
    }

    if(false == goon) {
      end = i;
      break;
    }
  }

  if(-1 == end) {
    return string("");
  }

  min_len = end-start+1;


  for(int i = end+1; i <  str1.length(); i++ ) {
    hasMap[str1[i]]++;

    if(str1[start] == str1[i]) {
      end = i;
      while(1) {
        if(reqMap.find(str1[start]) == reqMap.end()) {
          start++;
        } else {
          if(hasMap[str1[start]] > reqMap[str1[start]]) {
            hasMap[str1[start]] --;
            start++;
          } else {
            break;
          }
        }
      }
      if(end-start +1 < min_len) {
        min_len = end- start+1;
      }
    }
  }

  return str1.substr(start, min_len);
}

int main()
{
  string str1("this is a test string");
  string str2("tist");
  cout << str1 << "#" << func(str1, str2) << "\n";

  str1 = string("ADOBECODEBANC");
  str2 = string("ABC");
  cout << str1 << "#" << func(str1, str2) << "\n";

  str1 = string("acbbaca");
  str2 = string("aba");
  cout << str1 << "#" << func(str1, str2) << "\n";
}

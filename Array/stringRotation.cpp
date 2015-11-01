#include<iostream>
/*
   Assume you have a method isSubstring which checks if one word is a
   substring of another. Given two strings, si and s2, write code to check if s2 is
   a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rota-
   tion of "erbottlewat")

   */


int main() {
  std::string str1("waterbottle");
  std::string str2("erbottlewat");

  std::string str3 = str2 + str2;

  std::cout<< "Str1 : " << str1 << std::endl;
  std::cout<< "Str2 : " << str2 << std::endl;
  std::size_t found = str3.find(str1);
  if (found!=std::string::npos)
    std::cout<< "is rotation : True\n"; 
  else
    std::cout<< "is rotation : False\n"; 


  return 0;
}

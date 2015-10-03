#include<iostream>


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

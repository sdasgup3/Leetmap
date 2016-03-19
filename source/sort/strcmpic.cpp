#include<iostream>
#include<cstring>




std::string 
toLower(std::string str1) {
  std::string res;
  for(int i = 0 ; i < str1.length(); i++) {
    int c = str1[i];
    if(c >= 'A' && c <= 'Z') {
      res.push_back(c-'A' + 'a');
    } else {
      res.push_back(c);
    }
  } 
  return res;
}

int
mystrcmp(const char* a, const char* b) {
  while(*a != '\0' && *a == *b) {
    a++; b++;
  }
  return *a - *b;
}

int 
strcmpIC(std::string str1, std::string str2) {
  std::string str1_t = toLower(str1);
  std::string str2_t = toLower(str2);

  return mystrcmp(str1_t.c_str(), str2_t.c_str());
}



int 
main()
{
  std::string str1;
  std::string str2;

  str1 = std::string("dsand");
  str2 = std::string("DSAND");
  std::cout << str1 << " " << str2 << " " << strcmpIC(str1, str2) << "\n";

  str1 = std::string("abc");
  str2 = std::string("Abcd");
  std::cout << str1 << " " << str2 << " " << strcmpIC(str1, str2) << "\n";


  str1 = std::string("Abcd");
  str2 = std::string("abc");
  std::cout << str1 << " " << str2 << " " << strcmpIC(str1, str2) << "\n";

}

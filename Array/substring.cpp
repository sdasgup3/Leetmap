#include<iostream>
#include<cstring>

char* 
substring(char* str, char* substr)
{
  int str_len  = strlen(str);
  int substr_len  = strlen(substr);

  for(int i = 0 ; i < str_len ; i ++ ) {
    if(str[i] == substr[0]) {
      int j;
      for(j = 0; j < substr_len; j++) {
        if(str[i + j] != substr[j]) {
          break;
        }
      }
      if(j == substr_len) {
        return &str[i];
      }
    } 
  }
  return NULL;
}

int main()
{
  char* str     = "babad" ;
  char* substr  = "bad";
  char* res = substring(str, substr);
  std::cout << res << "\n";

  str =  "bababd";
  substr = "babd";
  res = substring(str, substr);
  std::cout << res << "\n";

  return 0;
}

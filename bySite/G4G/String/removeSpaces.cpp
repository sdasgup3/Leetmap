/* Given a string, remove all spaces from the string and return it.
Input:  "g  eeks   for ge  eeks  "
Output: "geeksforgeeks"
Expected time complexity is O(n) and only one traversal of string.
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

char*
func(char* str) {
  if(NULL == str) {
    return NULL;
  }

  cout << str << "#";

  int count = 0;
  int it = 0;

  while(str[it] != '\0') {
    if(str[it] != ' ') {
      str[count++] = str[it];
    }
    it++;
  }

  str[count] = '\0';

  return str;
}

int main()
{
  char* str = strdup("g  eeks   for ge  eeks  ");
  cout << func(str) << "\n";

  str = strdup("abc       ");
  cout << func(str) << "\n";

  str = strdup("abc       xyz");
  cout << func(str) << "\n";

  str = strdup("       xyz");
  cout << func(str)<< "\n"  ;

  str = strdup("xyz");
  cout << func(str) << "\n";
}


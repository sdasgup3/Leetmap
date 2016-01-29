#include<iostream>



int 
main()
{
  int i = 1;
  char* c = (char *)&i;
  if(*c == 1) {
    std::cout << "Little\n";
  } else {
    std::cout << "Big\n";
  }

}

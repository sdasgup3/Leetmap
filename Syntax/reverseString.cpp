#include<iostream>

void reverse(char* str)
{

  char* start = str;
  char* end = str;

  while('\0' != (*end)) {
    end++;
  }
  end --;

  while(start < end) {
    //char t = *start;
    //*start = *end;
    //*end = t;

    *start  = *start ^ *end;
    *end    = *start ^ *end;
    *start  = *start ^ *end;

    start++;
    end --;
  }
}


int main(int argc, char** argv)
{
  std::cout << "reverse of " << argv[1] << " : ";
  reverse(argv[1]);
  std::cout << argv[1] << std::endl;

  return 0;
}

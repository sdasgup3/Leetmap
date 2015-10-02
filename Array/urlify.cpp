#include<iostream>
#include<string>
#include<assert.h>

void urlify(std::string &s) {
  int training_space = 0;
  for(int i = s.length() -1;  i >= 0; i--) {
    if(s[i] == ' ') {
      training_space ++;
      continue;
    }
    break;
  }

  int actual_length = s.length()  - training_space;
  int embeded_space = 0;

  for(int i = 0;  i < actual_length; i++) {
    if(s[i] == ' ') {
      embeded_space ++;
    }
  }

  int end_ptr = actual_length + 2*embeded_space;
  assert(s.length() == end_ptr );

  for(int i = actual_length - 1; i >=0; i--) {
    if(s[i] == ' ') {
      s[end_ptr -1] = '2'; end_ptr --;
      s[end_ptr -1] = '0'; end_ptr --;
      s[end_ptr -1] = '%'; end_ptr --;
    } else {
      s[end_ptr -1]  = s[i]; end_ptr --;
    }
  }
}


int main()
{
  std::string s = "My Name Is  D        ";
  std::cout << "String: " << s << std::endl;
  urlify(s);
  std::cout << "Result: " << s << std::endl;
}

#include<iostream>
#include<string>

void
reverse(std::string &s, int start, int end) {
  int mid = (start + end)/2;
  while(start <= mid) {
    char c = s[start];
    s[start] = s[end];
    s[end] = c;
    start++;
    end--;
  }
}

void
reverseR(std::string &s, int start, int end, int mid) {
  if(start == mid) return;

  char c = s[start];
  s[start] = s[end];
  s[end] = c;
  start++;
  end--;

  reverseR(s, start, end, mid);
}

void
reverseW(std::string &str) {
  int pos = str.find_first_not_of(' ');
  while(pos != std::string::npos) {
    int end = pos;
    while(end != str.length() && str[end] != ' ') {
      end++;
    }
    reverse(str, pos, end-1);
    //reverseR(str, pos, end-1, (pos+end-1)/2);
    if(end == str.length()) {
      break;
    }
    pos = str.find_first_not_of(' ', end);
  }

}



int main()
{
  std::string s("coding for interviews");
  std::cout << s << "\n";
  reverseW(s);
  std::cout << s << "\n";
  return 0;
}

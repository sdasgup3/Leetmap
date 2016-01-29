#include<iostream>
#include<string>

void
reverse(std::string &s, int n, int iter) {
  if(n/2 + 1 == iter) {
    return;
  }
  char first = s[iter];
  char last = s[n-iter];
  s[iter] = last;
  s[n  - iter] = first;

  return reverse(s, n, iter +1);
}



int main()
{
  std::string s("dsandt");
  std::cout << s << "\n";
  reverse(s, s.size()-1, 0);
  std::cout << s << "\n\n";
  std::string t("dsand");
  std::cout << t << "\n";
  reverse(t, t.size()-1, 0);
  std::cout << t << "\n";
  return 0;
}

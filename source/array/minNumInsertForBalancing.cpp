#include<iostream>

int
minNumInsertForBalancing(std::string s) {
  int min_insert = 0;
  int i = 0;
  int sum =0;
  for(i = 0; i < s.size(); i++) {
    if(s[i] == ')') {
      if(sum == 0  ) {
        min_insert++;
      } else {
        sum --;
      }
    } else {
      sum ++;
    }
  }

  min_insert += sum;
  return min_insert;
}

int main()
{

  std::string s;
  s = std::string("(()())");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";
  s = std::string("(()");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";
  s = std::string("))");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";
  s = std::string("(())");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";
  s = std::string("))((");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";
  s = std::string(")((");
  std::cout << s << " : " << minNumInsertForBalancing(s) << "\n";

  return 0;
}

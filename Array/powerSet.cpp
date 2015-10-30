#include<iostream>
#include<vector>
#include<assert.h>
#include <algorithm>
using namespace std;

static int Count = 0;  

void 
permute_helper(std::string str, int r, std::string & ans, int step) 
{
  if(step == r) {
    std::cout << "{ " <<  ans << " }\n";
    Count++;
    return;
  }

  for(int i = 0; i < str.length(); i ++) {
    ans.push_back(str[i]);
    std::string temp(str.begin()+(i+1), str.end()); 
    permute_helper(temp, r, ans, step+1);
    ans.pop_back();
  }

}

void permute(std::string str, int r) 
{
  std::string ans("");
  permute_helper(str, r, ans, 0);
}

void
computePower(std::string str) {

  int n = std::pow(2,str.length())-1;
  int len = str.length();
  std::string ans("");

  for(int i = 0 ; i <= n; i++) {
    int mask = 1;
    for(int testBit  = 0 ; testBit < len; testBit ++) {
      if(i & (mask << testBit)) {
        ans.push_back(str[testBit]);
      }
    }
    std::cout << "{ " <<  ans << " }\n";
    Count++;
    ans.clear();
  }

}

int main() {
  std::string str("12345");
  int r = 0;
  for(; r <= str.length();r++) {
    permute(str,r);
  }
  std::cout << Count << "\n";

  Count=0;
  computePower(str);
  std::cout << Count << "\n";

  return 0;
}

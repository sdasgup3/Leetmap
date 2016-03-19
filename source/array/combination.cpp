#include<iostream>
#include<vector>
#include<assert.h>
#include <algorithm>
using namespace std;

static int Count = 0;  

std::ostream& operator<< (std::ostream& stream, vector<int> v) 
{
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;


}

void fill_v(int pos, int start, int end, int n, int r, vector<int> soln) 
{

  if(pos == r) {
    Count ++;
    cout << soln;
    return;
  }

  for(int i = start; i < end; i ++) {
    soln.push_back(i);
    fill_v(pos +1, i + 1, end + 1,  n,  r, soln);
    soln.pop_back();
  }
}


void permute_v(int n, int r) 
{
  vector<int> soln;
  fill_v(0, 0, n - r + 1, n, r, soln);

}

void 
permute_helper(std::string str, int r, std::string & ans, int step) 
{
  if(step == r) {
    std::cout << ans << "\n";
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
  std::string ans;
  permute_helper(str, r, ans, 0);
}

int main() {
  std::string str("12345");
  int r = 1;
  for(r = 1; r <= str.length();r++) {
    cout << str <<  " r = " << r << endl;
    permute(str,r);
    cout << " Number Of Soln: " << Count << endl;
    Count = 0;
  }

  return 0;
}

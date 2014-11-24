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

void fill(int pos, int start, int end, int n, int r, vector<int> soln) 
{

  if(pos == r) {
    Count ++;
    cout << soln;
    return;
  }

  for(int i = start; i < end; i ++) {
    soln.push_back(i);
    fill(pos +1, i + 1, end + 1,  n,  r, soln);
    soln.pop_back();
  }
}


void permute(int n, int r) 
{
  vector<int> soln;
  fill(0, 0, n - r + 1, n, r, soln);

}

int main() {
  int n = 5;
  int r = 1;
  cout << " n = " << n << " r = " << r << endl;
  permute(n,r);
  cout << " Number Of Soln: " << Count << endl;

  return 0;
}

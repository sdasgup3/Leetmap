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

void fill(int pos, vector<int> exclude, int n, int r) 
{

  if(pos == r) {
    cout << exclude;
    Count ++;
    return;
  }

  for(int i = 0; i < n; i ++) {
    if(std::find(exclude.begin(), exclude.end(), i) != exclude.end()) {
      continue;
    }
    exclude.push_back(i);
    fill(pos +1, exclude,  n,  r);
    exclude.pop_back();
  }
}


void permute(int n, int r) 
{
  vector<int> exclude;
  fill(0, exclude, n, r);

}

int main() {
  int n = 5;
  int r = 3;
  cout << " n = " << n << " r = " << r << endl;
  permute(n,r);
  cout << " Number Of Soln: " << Count << endl;

  return 0;
}

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

void swap(int *p, int *q)
{
  int t = *p;
  *p = *q;
  *q = t;
}

void permute(int arr[], int start, int n) 
{
  if(start == n - 1) {
    for (int i = 0 ; i < n ; i ++ ) {
      cout << arr[i] << " ";
    }
    cout << endl;
    Count ++;
    return;
  }
  for(int j = start; j < n ; j++) {
    swap(arr + start, arr+ j);
    permute (arr, start + 1, n);
    //swap(arr + j, arr+ start);
    swap(arr + start, arr+ j);
  }
}

int main() {
  int arr[] = {1,2,3, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> v (arr, arr + n);
  cout << v;
  permute(arr, 0, n);
  cout << " Number Of Soln: " << Count << endl;

  return 0;
}

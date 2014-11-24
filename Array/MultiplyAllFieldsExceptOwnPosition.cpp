#include<iostream>
#include<vector>
#include<assert.h>
#include <algorithm>
using namespace std;

//http://www.careercup.com/question?id=5179916190482432
//1 2 3 4
          // front 
//i = 0     1     
//i = 1     1
//i = 2     1*2
//i = 3   1*2*3
          // rear  similarly


void prod(int arr[], int n) 
{

  vector <int> front (n);
  vector <int> rear (n);

  front[0] = 1;
  rear[n-1] = 1;

  for(int i = 1 ; i < n ; i ++) {
    front[i] = front[i-1]*arr[i-1];
  }
  for(int i = n-2 ; i >= 0 ; i --) {
    rear[i] = rear[i+1]*arr[i+1];
  }
  for(int i =0 ; i < n ; i++) {
    cout << "Prod of " << arr[i] << " :" << front[i]*rear[i] << endl;
  }

}

int main() {
  int arr[] = {1,2,3,4};
  int n = sizeof(arr)/sizeof(arr[0]);

  prod(arr,n);
  return 0;
}

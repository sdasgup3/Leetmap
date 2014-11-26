/*
   http://www.geeksforgeeks.org/rearrange-given-array-place/
   Given an array arr[] of size n where every element is in range from 0 to
   n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This
   should be done with O(1) extra space.
 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl << endl;;
  return stream;
}

void rearr(vector<int>& v) 
{
  int n = v.size();

  for(int i= 0; i < n ; i ++) {
    //v[v[i]] % n: to get previous value
    v[i] =  v[i] + (v[v[i]] % n)*n;
  }
  for(int i= 0; i < n ; i ++) {
    v[i] = v[i]/n;
  }

}



int main() {
  int arr2[]  = {3, 2, 0, 1};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  rearr(v2);
  cout << v2;

  int arr3[]  = {4, 0, 2, 1, 3};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  rearr(v3);
  cout << v3;

  int arr4[]  = {1, 0, 0, 0};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  rearr(v4);
  cout << v4;



  return 0;
}

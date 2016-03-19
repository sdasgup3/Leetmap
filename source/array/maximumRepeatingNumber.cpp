/*
   http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/
Given an array of size n, the array contains numbers in rafunc from 0 to k-1
where k is a positive integer and k <= n. Find the maximum repeating number in
this array. For example, let k be 10 the given array be arr[] = {1, 2, 2, 2, 0,
2, 0, 2, 3, 8, 0, 9, 2, 3}, the maximum repeating number would be 2. Expected
time complexity is O(n) and extra space allowed is O(1). Modifications to array
are allowed.


 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

void func(vector<int> v, int k) 
{
  for (int i = 0 ; i < v.size(); i++ ) {
    v[v[i]%k] += k;
  }

  int max = v[0]; int index = 0;;
  for (int i = 0 ; i < v.size(); i++ ) {
    if(v[i] > max) {
      max = v[i];
      index = i;
    }
  }

  cout << "The max repeating value: " << index << endl;

}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr2[]  = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}; //i < k and k <= n
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  func(v2, 10);

  int arr3[]  = {2, 3, 3, 5, 3, 4, 1, 7};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  func(v3,8);

  int arr4[]  = {1,2,3,4,5,5,5,4,3,2,1};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  func(v4,6);



  return 0;
}

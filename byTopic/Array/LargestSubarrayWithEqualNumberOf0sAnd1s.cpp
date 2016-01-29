/*
   Given an array containing only 0s and 1s, find the largest subarray which
   contain equal no of 0s and 1s. Expected time complexity is O(n).

Examples:

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6 (Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4
http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
 */

#include<iostream>
#include<vector>
#include<assert.h>
#include<stdlib.h>
using namespace std;

void func(int v[], int n) 
{
  int max_size_so_far = 0 ;
  int index = 0 ;

  for(int i = 0 ; i < n; i ++) {
    int start = i;
    int size = 1;
    int partial_sum = (v[i] == 0 ? -1 : 1);
    for(int j = start + 1 ; j < n; j ++) {
      partial_sum += (v[j] == 0 ? -1 : 1);
      size ++;
      if(partial_sum == 0 ) {
        if(max_size_so_far < size) {
          max_size_so_far = size;
          index = start;
        }
      }
    }
  }
  if(max_size_so_far == 0 ) {
    cout << "No such subarray\n";
  } else {
    cout << index << " to " << index + max_size_so_far - 1 << endl;
  }

}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() 
{
  int arr2[]  = {1, 0, 1, 1, 1, 0, 0};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  func(arr2, sizeof(arr2)/sizeof(arr2[0]));

  int arr3[]  = {1, 1, 1, 1};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  func(arr3, sizeof(arr3)/sizeof(arr3[0]));

  int arr4[]  = {0, 0, 1, 1, 0};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  func(arr4, sizeof(arr4)/sizeof(arr4[0]));

  return 0;
}

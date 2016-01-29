/*
http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/

Find the minimum distance between two numbers
Given an unsorted array arr[] and two numbers x and y, find the minimum
distance between x and y in arr[]. The array might also contain duplicates.
You may assume that both x and y are different and present in arr[].

Examples:
Input: arr[] = {1, 2}, x = 1, y = 2
Output: Minimum distance between 1 and 2 is 1.

Input: arr[] = {3, 4, 5}, x = 3, y = 5
Output: Minimum distance between 3 and 5 is 2.

Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.

Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
Output: Minimum distance between 3 and 2 is 1.

 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

void func(vector<int> v, int x, int y) 
{
  int n = v.size();
  int start = -1; int end = -1; 
  int distance = n;

  for(int i = 0; i < n ; i ++ ) {
    if(x == v[i] || y == v[i]) {
      start = i;
      break;
    }
  }

  assert(start != -1 && "x or y not found");

  while(1) {
    for(int i = start + 1; i < n ; i ++ ) {
      if(v[start] != v[i] && ( x == v[i] || y == v[i])) {
        end = i;
        break;
      }
    }
    if(-1 == end) {
      break;
    }

    if((end - start) <  distance) {
      distance = end - start;
    }

    start = end;
    end = -1;
  }

  cout << "The min distance between " << x << " and " << y << " is " << distance << endl;
  return;

}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr2[]  = {1, 2}; 
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  func(v2, 1,2);

  int arr3[]  = {3,4,5};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  func(v3,3,5);

  int arr4[]  = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  func(v4,3, 6);

  int arr5[]  = {2, 5, 3, 5, 4, 4, 2, 3};
  vector<int> v5(arr5, arr5 + sizeof(arr5)/sizeof(arr5[0]));
  cout << v5;
  func(v5,3, 2);


  return 0;
}

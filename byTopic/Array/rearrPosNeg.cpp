/*
   http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
Rearrange positive and negative numbers in O(n) time and O(1) extra space
An array contains both positive and negative numbers in random order. Rearrange
the array elements so that positive and negative numbers are placed
alternatively. Number of positive and negative numbers need not be equal. If
there are more positive numbers they appear at the end of the array. If there
are more negative numbers, they too appear in the end of the array.

For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

The solution is to first separate positive and negative numbers using partition process of QuickSort. In the partition process, consider 0 as value of pivot element so that all negative numbers are placed before positive numbers. Once negative and positive numbers are separated, we start from the first negative number and first positive number, and swap every alternate negative number with next positive number.
 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;



void rearr(vector<int> v) 
{
  int n = v.size();
  int start = 0;
  int end = n;

  while(start < end) {
    if(v[start] < 0 && start < end) {
      start ++;
    }
    if(start >= end) {
      break;
    } else if(v[start] >= 0) {
      if(v[end] >= 0 && start < end) {
        end --;
      }
      if(start >= end) {
        break;
      } else if (v[end] < 0) {
        int temp = v[start];
        v[start]  = v[end];
        v[end]  = temp;
      }
    }
  }

  int num_pos  =  n - end;
  int num_neg  =  n -  num_pos;
  int p = 0 , ng = 0 ;
  while(p < num_pos && ng < num_neg) {
    cout << v[ng++] << " " <<  v[end + p++]  << " ";
  }
  if(p >= num_pos) {
    while(ng < num_neg) {
      cout << v[ng++] << " " ;
    }
  }
  if(ng >= num_neg) {
    while(p < num_pos) {
      cout << v[p++] << " " ;
    }
  }
}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr2[]  =  {-1, 2, -3, 4, 5, 6, -7, 8, 9};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  rearr(v2);
  cout << endl;

  int arr3[]  = {-1,1, -1, 1, -1};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  rearr(v3);
  cout << endl;

  int arr4[]  = {1,1,1,1,-1,-1,-1,-1,-1};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  rearr(v4);
  cout << endl;

  int arr5[]  = {-1,-1,-1,-1,-1};
  vector<int> v5(arr5, arr5 + sizeof(arr5)/sizeof(arr5[0]));
  cout << v5;
  rearr(v5);
  cout << endl;


  return 0;
}

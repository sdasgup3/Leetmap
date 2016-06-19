/*
 Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].

Examples:
Input: arr[] = {1, 2}, x = 1, y = 2
Output: Minimum distance between 1 and 2 is 1.

Input: arr[] = {3, 4, 5}, x = 3, y = 5
Output: Minimum distance between 3 and 5 is 2.

Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.

Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
Output: Minimum distance between 3 and 2 is 1.

Cases to consider: 2 2  3 : Here the min dis between 2 and 3 is 1 not 2 


*/

#include<iostream>
using namespace std;

class Solution {

  public:
    int findMinDistance(int arr[], int size, int x, int y) {
      int pivot = -1;
      int result = size;


      for(int i = 0; i< size; i++) {
        if(arr[i] == x || arr[i] == y) {
          pivot = i;
          break;
        } 
      }

      if(-1 == pivot) {
        return -1;
      }


      for(int i = pivot + 1; i < size; i ++) {
        if(arr[i] == x || arr[i] == y) { 
          if(arr[i] != arr[pivot]) {
            result = min(result, i - pivot);
            pivot = i;
          } else {
            pivot = i;
          } 
        }
      }

      return result;
    }

};

int main() {
  Solution S;

  int arr1[] = {2, 5, 3, 5, 4, 4, 2, 3};
  cout << S.findMinDistance(arr1, sizeof(arr1)/sizeof(int), 3,2) << endl;

  int arr2[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4,  3};
  cout << S.findMinDistance(arr2, sizeof(arr2)/sizeof(int), 3,6) << endl;


  int arr3[] = {1, 2};
  cout << S.findMinDistance(arr3, sizeof(arr3)/sizeof(int), 1,2) << endl;

  int arr4[] = {3, 4, 5};
  cout << S.findMinDistance(arr4, sizeof(arr4)/sizeof(int), 3,5) << endl;
}

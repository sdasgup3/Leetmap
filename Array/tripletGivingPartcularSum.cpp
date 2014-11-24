//Find a triplet that sum to a given value

#include<iostream>
#include<vector>
#include<assert.h>
#include<stdlib.h>
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

bool findSum_1(int arr[], int n, int sum) 
{
  //Method 1
  for(int i = 0 ; i < n - 2 ; i ++ ) {
    for(int j = i + 1 ; j < n-1; j++) {
      for(int k = j + 1 ; k < n ; k++) {
        if(arr[i] + arr[j] + arr[k] == sum) {
          cout << "Triplet is :" << arr[i] << " " << arr[j] << " " << arr[k] << " " << endl;
          return true;
        }
      }
    }
  }
  return false;
}

int compare(const void *a,const void *b) 
{
  return *((int *)a) - *((int *)b) ; 
}

bool findSum_2(int arr[], int n, int sum) 
{
  //Method 1
  qsort(arr, n, sizeof(int), compare);


  for(int i = 0 ; i < n - 2 ; i ++ ) {
    int start = i + 1;
    int end = n  - 1;
    while (start < end) {
      if(arr[i] + arr[start] + arr[end] == sum) {
        cout << "Triplet is :" << arr[i] << " " << arr[start] << " " << arr[end] << " " << endl;
        return true;
      } else if(arr[i] + arr[start] + arr[end] < sum) {
        start ++;
      } else if (arr[i] + arr[start] + arr[end] > sum) {
        end --;
      }
    }
  }
  return false;
}

int main() {
  int arr[] = {1, 4, 45, 3, 10, 9};
  //int arr[] = {1, 99, 45, 3, 11, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 22;

  bool result = findSum_2(arr,n, sum);
  return 0;
}

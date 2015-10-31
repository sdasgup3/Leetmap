#include<iostream>
#include"../utils.h"


int
searchBinary(int arr[], int start, int end, int k) {
  while(start <= end) {
    int mid = (start + end)/2;
    if(arr[mid] == k ) {
      return mid;
    } else if(k > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1; 
}


int
searchRotBinary(int arr[], int n, int k) {
  int start = 0;
  int end = n-1;

  while(start <= end) {
    int mid = (start + end)/2;

    if(arr[mid] == k ) {
      return mid;
    } else {
      if(arr[start] < arr[mid]) {
        if(k < arr[mid] && arr[start] <= k) {
          return searchBinary(arr, start, mid -1, k);
        } else {
          start = mid +1;
        }
      } else if(arr[mid] < arr[end]) {
        if(k > arr[mid] && k <= arr[end]) {
          return searchBinary(arr, mid+1, end, k);
        } else {
          end = mid -1;
        }
      } else if(arr[mid] == arr[start] && arr[mid] == arr[end]) { // either  x .y.. |x|  xx or x xx |x| y  x
        if(end - mid > 0 && arr[mid + 1 ] != arr[end]) { 
          start = mid +1;
        } else if(mid - start > 0 && arr[start + 1] != arr[mid]) {
            end  = mid -1;
        }
      } else {
        if(arr[mid] != arr[start]) {
          end = mid -1;
        } else {
          start = mid +1;
        }

      }
    }
  }
  return -1; 
}

int main()
{
  int arr[] = {15, 16, 19, 20, 25, 1,3,4,5,7,10,14};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  for(int i = 0 ; i < size; i ++) {
    int k = arr[i];
    std::cout << k << " " << searchRotBinary(arr, size, k) << "\n";
  }
  int k = 100;
  std::cout << k << " " << searchRotBinary(arr, size, k)<< "\n";
  k=0;
  std::cout << k << " " << searchRotBinary(arr, size, k)<< "\n";
  k=-1;
  std::cout << k << " " << searchRotBinary(arr, size, k)<< "\n";

  int arr1[] = {10,15,20,0,5};
  size = sizeof(arr1)/sizeof(arr1[0]);
  print(arr1, size);
  for(int i = 0 ; i < size; i ++) {
    int k = arr1[i];
    std::cout << k << " " << searchRotBinary(arr1, size, k) << "\n";
  }

  int arr2[] = {50,5,20,30,40};
  size = sizeof(arr2)/sizeof(arr2[0]);
  print(arr2, size);
  for(int i = 0 ; i < size; i ++) {
    int k = arr2[i];
    std::cout << k << " " << searchRotBinary(arr2, size, k) << "\n";
  }

  int arr3[] = {12,12,9,10,11,12};
  size = sizeof(arr3)/sizeof(arr3[0]);
  print(arr3, size);
  for(int i = 0 ; i < size; i ++) {
    int k = arr3[i];
    std::cout << k << " " << searchRotBinary(arr3, size, k) << "\n";
  }

  int arr4[] = {8,9,10,11,8,8};
  size = sizeof(arr4)/sizeof(arr4[0]);
  print(arr4, size);
  for(int i = 0 ; i < size; i ++) {
    int k = arr4[i];
    std::cout << k << " " << searchRotBinary(arr4, size, k) << "\n";
  }

}





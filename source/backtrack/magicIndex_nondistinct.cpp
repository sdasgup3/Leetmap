#include<iostream>

int magicIndex(int arr[], int n) {
  if(0 == n ) return -1;

  int start = 0;
  int end = n-1;
  int mid ;
  while(start <= end) {
    mid = start + (end - start)/2;
    if(mid == arr[mid]) {
      return mid;
    } else if(mid < arr[mid]) {
      for(int i = arr[mid]; i < end ; i ++) {
        if(i == arr[i]) {
          return i;
        }
      }
      end = mid - 1;
    } else {
      for(int i = arr[mid]; i >= start ; i--) {
        if(i == arr[i]) {
          return i;
        }
      }
      start = mid + 1;
    }
  }
  return -1;
}


int main() {

  //int arr[]  = {-10,  -5, 2, 2, 2,   3,  4,  5,  9,  12, 13};
  //index:     {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10
  int arr[]  = {0, -5,  6,  6,  6,  7,  7,  8,  9,  12, 13};

  std::cout << "Magic index :" << magicIndex(arr, 11) << "\n"; 
  return 0;
}

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
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}


int
binsearch(int arr[], int n, int k) {
  if(0 == n ) return -1;
  int start = 0;
  int end = n-1;
  while(start <= end) {
    int mid = start + (end - start)/2;
    if(k == arr[mid]) {
      return mid;
    } else if(k > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int main() {

  int arr[]  = {-1,0,2,4,5,6,7,8};

  for(int i = 0 ; i < 10; i++) {
    std::cout << "find " << i << " :" << binsearch(arr, 8, i) << "\n"; 
  }

  std::cout << "Magic index :" << magicIndex(arr, 8) << "\n"; 
  return 0;
}

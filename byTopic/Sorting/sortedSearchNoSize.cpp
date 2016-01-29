#include<iostream>
#include"../utils.h"


int
binSearch(int arr[], int start, int end, int k) {
  while(start <= end) {
    int mid = (start + end)/2;
    if(arr[mid] == k ) {
      return mid;
    } else if(arr[mid] == -1 ) {
      end  = mid -1;
    } else if(arr[mid] < k ) {
      start = mid +1;
    } else {
      end = mid -1;
    }
  }

  return -1;

}

int 
search(int arr[], int k) {

  if(arr[0] == -1) {
    return -1;
  }

  int index = 1;
  while(arr[index] != -1) {
    index = index*2;
  }
  
  return binSearch(arr, 0, index, k);
}


int main()
{
  int arr[] = {1,2,3,4,5, -1,-1,-1,-1,-1,-1,-1,-1};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  for(int i = 0; i < size && arr[i] != -1; i++) {
    std:: cout << arr[i] << " " << search(arr, arr[i]) << "\n";
  }

    std:: cout << 100 << " " << search(arr, 100) << "\n";
}

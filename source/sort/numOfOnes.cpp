#include<iostream>
#define row 5
#define colm 8

int
findStart(int *arr, int n) {
  int start = 0;
  int end = n-1;

  while(start <= end) {
    int mid = (start+ end)/2; 
    if(arr[mid] == 0) {
      if(mid + 1 <= end && arr[mid+1] == 1) {
        return mid+1;
      }
      start = mid +1;
    } else if(arr[mid] == 1) {
      if(mid - 1 >= start && arr[mid-1] == 0) {
        return mid;
      }
      end = mid -1;
    }
  }

  if(arr[0] == 1) {
    return 0;
  }
  return -1;  
}


int
numOfOnes(int arr[][colm]) {
  int count = 0;  
  for(int i = 0; i < row; i++) {
    int k = findStart(arr[i], colm);
    if(-1 != k) {
      count += (colm -1 -k + 1);
    }
  }
  return count;
}

int main()
{
  int arr[row][colm]  = {
      {0,0,0,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {0,0,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,1},
      {0,0,0,0,0,0,0,1},
  };

  std::cout << numOfOnes(arr);
}

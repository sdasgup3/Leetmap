
#include"../utils.h"
/*
Largest Sum Contiguous Subarray
Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

Kadane’s Algorithm:
runningsum = std::max(runningsum + arr[i], arr[i])
max_sum = std::max(max_sum, runningsum)

*/   

int
kadane(int *arr, int size, int &start, int &end)
{
  int maxsum = INT_MIN ;
  int runningsum=0;

  int i;
  start =0;
  end = 0;

  for(i = 0 ; i < size ; i++) {
    if(runningsum + arr[i] >= arr[i]) {
      runningsum = runningsum + arr[i];
    } else {
      runningsum = arr[i];
      start = i;
    }

    if(runningsum > maxsum ) {
      maxsum = runningsum;
      end = i;
    }
  }

  return maxsum;
}


int main() {

  int start, end;
  int arr[] = {-2,0,-3,4,5, 1, -2};
  int n= sizeof(arr)/sizeof(arr[0]);
  print(arr,n);
  std::cout << "\nMaxSum: " << kadane(arr, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  print(arr1,n);
  std::cout << "\nMaxSum: " << kadane(arr1, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  print(arr2,n);
  std::cout << "\nMaxSum: " << kadane(arr2, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  print(arr3,n);
  std::cout << "\nMaxSum: " << kadane(arr3, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;

  int arr4[] = {-5,-100,-1};
  n = sizeof(arr4)/sizeof(arr4[0]);
  print(arr4,n);
  std::cout << "\nMaxSum: " << kadane(arr4, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;

  int arr5[] = {2,3,-1,2};
  n = sizeof(arr5)/sizeof(arr5[0]);
  print(arr5,n);
  std::cout << "\nMaxSum: " << kadane(arr5, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;
  return 0;
}

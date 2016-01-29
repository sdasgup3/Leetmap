#include<iostream>

using namespace std;

int kadane(int* arr, int n, int &start, int &end) {
  int max_sum = arr[0];
  int max_start=0, max_end=0;
  int running_sum = 0;
  start = end = 0;

  for(int i = 0 ; i < n ; i ++) {
    running_sum += arr[i];
    if(running_sum < arr[i]) {
      running_sum = arr[i];
      start = i;
    }
    if(running_sum >= max_sum) {
      max_sum = running_sum;
      end  =  i;
      max_start = start;
      max_end = end;
    }
  }

  start = max_start;
  end = max_end;
  return max_sum;

}

void print(int* arr, int n) {
  for(int i = 0 ; i < n ; i ++) {
    cout << arr[i] << " " ;
  }

  cout << "\n";

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

  int arr6[] = {2,1,-5,0};
  n = sizeof(arr6)/sizeof(arr6[0]);
  print(arr6,n);
  std::cout << "\nMaxSum: " << kadane(arr6, n, start, end) ;
  std::cout << "%" << start << " " << end << " \n" ;
  return 0;
}

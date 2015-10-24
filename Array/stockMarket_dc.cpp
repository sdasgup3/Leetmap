#include<iostream>
#include<climits>


int
dc(int *arr, int n) {
  if(n == 2) {
    return (arr[1] - arr[0]);
  }
  if(n ==3) {
    return std::max(arr[1]-arr[0], std::max(arr[2]-arr[0], arr[2]-arr[1]));
  }

  int mid = n/2;
  int left_profit = dc(arr, mid);
  int right_profit = dc(arr + mid, n  - mid);

  int left_min = arr[0];
  for(int i = 0 ; i < mid; i++) {
    left_min = std::min(left_min, arr[i]);
  }

  int right_max = arr[mid];
  for(int i = mid ; i < n; i++) {
    right_max = std::max(right_max, arr[i]);
  }

  return std::max(left_profit, std::max(right_profit, (right_max - left_min)));
}

void 
print(int arr[], int n) {
  for(int i = 0 ; i < n ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
  std::cout << " \n" ;
}

int main() {

  int arr[] = {-2,0,-3,4,5, 1, -2};
  int n= sizeof(arr)/sizeof(arr[0]);
  print(arr, n);
  std::cout << "\nMaxProfit: " << dc(arr, n) ;
  std::cout << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  print(arr1, n);
  std::cout << "\nMaxProfit: " << dc(arr1, n) ;
  std::cout << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  print(arr2, n);
  std::cout << "\nMaxProfit: " << dc(arr2, n) ;
  std::cout << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  print(arr3, n);
  std::cout << "\nMaxProfit: " << dc(arr3, n) ;
  std::cout << " \n" ;

  int arr4[] = {-1,5,100,-1000, 1000};
  n = sizeof(arr4)/sizeof(arr4[0]);
  print(arr4, n);
  std::cout << "\nMaxProfit: " << dc(arr4, n) ;
  std::cout << " \n" ;
  return 0;
}


#include<iostream>

void 
print(int arr[], int n) {
  for(int i = 0 ; i < n ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
}

int
maxS(int arr[], int n) {
  int sum_so_far ;
  int max_sum;

  sum_so_far = max_sum  = arr[0];

  for(int i=1; i< n; i++) {
    sum_so_far = std::max(sum_so_far+arr[i], arr[i]);
    max_sum = std::max(max_sum, sum_so_far);
  }

  return max_sum;
}


int main() {

  int arr[] = {-2,0,-3,4,5, 1, -2};
  int n= sizeof(arr)/sizeof(arr[0]);
  print(arr,n);
  std::cout << "\nMaxSum: " << maxS(arr, n) ;
  std::cout << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  print(arr1,n);
  std::cout << "\nMaxSum: " << maxS(arr1, n) ;
  std::cout << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  print(arr2,n);
  std::cout << "\nMaxSum: " << maxS(arr2, n) ;
  std::cout << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  print(arr3,n);
  std::cout << "\nMaxSum: " << maxS(arr3, n) ;
  std::cout << " \n" ;

  int arr4[] = {-5,-100,-1};
  n = sizeof(arr4)/sizeof(arr4[0]);
  print(arr4,n);
  std::cout << "\nMaxSum: " << maxS(arr4, n) ;
  std::cout << " \n" ;

  int arr5[] = {2,3,-1,2};
  n = sizeof(arr5)/sizeof(arr5[0]);
  print(arr5,n);
  std::cout << "\nMaxSum: " << maxS(arr5, n) ;
  std::cout << " \n" ;
  return 0;
}

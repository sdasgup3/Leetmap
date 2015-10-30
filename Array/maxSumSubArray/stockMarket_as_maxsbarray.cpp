#include<iostream>
#include<climits>

void 
print(int arr[], int n) {
  for(int i = 0 ; i < n ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
  std::cout << " \n" ;
}

int   
maxsubarray(int arr[], int n)
{
  int sum_so_far ;
  int max_sum;

  sum_so_far = max_sum  = arr[0];

  for(int i=1; i< n; i++) {
    sum_so_far = std::max(sum_so_far+arr[i], arr[i]);
    max_sum = std::max(max_sum, sum_so_far);
  }

  return max_sum;
}

int
dc(int *arr, int n) {
  //int* delta = new int[n-1];
  int delta[n-1];
  for(int i = 0 ; i < n-1 ; i ++ ) {
    delta[i]  = arr[i+1] - arr[i];
  }

  print(arr, n);
  print(delta, n-1);
  return maxsubarray(delta,n-1);

}


int main() {

  int arr[] = {-2,0,-3,4,5, 1, -2};
  int n= sizeof(arr)/sizeof(arr[0]);
  std::cout << "\nMaxProfit: " << dc(arr, n) ;
  std::cout << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  std::cout << "\nMaxProfit: " << dc(arr1, n) ;
  std::cout << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  std::cout << "\nMaxProfit: " << dc(arr2, n) ;
  std::cout << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  std::cout << "\nMaxProfit: " << dc(arr3, n) ;
  std::cout << " \n" ;

  int arr4[] = {-1,5,100,-1000, 1000};
  n = sizeof(arr4)/sizeof(arr4[0]);
  std::cout << "\nMaxProfit: " << dc(arr4, n) ;
  std::cout << " \n" ;

  int arr5[] = {1, 3, 6, 5, 7};
  n = sizeof(arr5)/sizeof(arr5[0]);
  std::cout << "\nMaxProfit: " << dc(arr5, n) ;
  std::cout << " \n" ;
  return 0;
}

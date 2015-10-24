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
maxsubarray(int *delta, int n)
{
  int max = 0;
  int sum = 0;
  for(int i = 0 ; i < n ; i ++ ) {
    if(delta[i] <= 0 ) {
      if(sum > max) {
        max = sum;
        sum = 0;
      }
    } else {
      sum += delta[i];
    }
  }
  if(sum > max) {
    max = sum;
    sum = 0;
  }
  return max;
}

int
dc(int *arr, int n) {
  int* delta = new int[n-1];
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
  return 0;
}

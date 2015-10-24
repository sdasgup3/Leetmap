
#include<iostream>
#include<climits>

int 
computeP(int arr[], int i) {
  int max = INT_MIN;
  int profit = 0;

  int soldAt = arr[i];
  for(int j = 0; j < i; j++) {
    profit = soldAt - arr[j];
    if(profit > max) {
      max  = profit;
    }
  }

  return max;
}


int
sm(int arr[], int n) {
  int max_profit = INT_MIN;
  int profit = 0;

  for(int i = n-1 ; i >= 0 ; i --) {
    profit = computeP(arr, i);
   // std::cout << i << " " << profit << " \n";
    if(profit > max_profit) {
      max_profit = profit;
    }
  }
  return max_profit;
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
  std::cout << "\nMaxProfit: " << sm(arr, n) ;
  std::cout << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  print(arr1, n);
  std::cout << "\nMaxProfit: " << sm(arr1, n) ;
  std::cout << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  print(arr2, n);
  std::cout << "\nMaxProfit: " << sm(arr2, n) ;
  std::cout << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  print(arr3, n);
  std::cout << "\nMaxProfit: " << sm(arr3, n) ;
  std::cout << " \n" ;

  return 0;
}

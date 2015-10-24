
#include<iostream>

void 
print(int arr[], int n) {
  for(int i = 0 ; i < n ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
}

int
maxS(int arr[], int n) {
  print(arr,n);

  bool allneg = true;
  for(int i = 0 ; i  < n ; i ++ ) {
    if(arr[i] >= 0) {
      allneg = false;
    }
  }

  if(allneg) {
    int max = arr[0];
    for(int i = 0 ; i  < n ; i ++ ) {
      max = std::max(max, arr[i]);
    }
    return max;
  }

  int max1 = 0; int max2 = 0;

  for(int i = 0 ; i  < n ; i ++ ) {
    if(arr[i] <= 0) {
      if(max2 > max1) {
        max1 = max2;
        max2 = 0;
      }
    } else {
      max2 += arr[i];
    }
  }

  if(max2 > max1) {
    max1 = max2;
    max2 = 0;
  }
  return max1;
}


int main() {

  int arr[] = {-2,0,-3,4,5, 1, -2};
  int n= sizeof(arr)/sizeof(arr[0]);
  std::cout << "\nMaxSum: " << maxS(arr, n) ;
  std::cout << " \n" ;

  int arr1[] = {1,2,3,4};
  n = sizeof(arr1)/sizeof(arr1[0]);
  std::cout << "\nMaxSum: " << maxS(arr1, n) ;
  std::cout << " \n" ;


  int arr2[] = {2,3,-2,-3};
  n = sizeof(arr2)/sizeof(arr2[0]);
  std::cout << "\nMaxSum: " << maxS(arr2, n) ;
  std::cout << " \n" ;

  int arr3[] = {-1,5,100,-1000};
  n = sizeof(arr3)/sizeof(arr3[0]);
  std::cout << "\nMaxSum: " << maxS(arr3, n) ;
  std::cout << " \n" ;

  int arr4[] = {-5,-100,-1};
  n = sizeof(arr4)/sizeof(arr4[0]);
  std::cout << "\nMaxSum: " << maxS(arr4, n) ;
  std::cout << " \n" ;
  return 0;
}

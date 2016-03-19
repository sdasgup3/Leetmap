#include<iostream>
#include<stdlib.h>
#include<cmath>
#include"../utils.h"

int
myceil(float a) {
  int _a = a;
  if((float)_a < a) {
    return _a +1;
  } else {
    return _a;
  }
}

void countSort(int arr[], int n, int count[], int base, int exp)
{
  for(int i = 0; i < base; i ++) {
    count[i] = 0 ;
  }

  for(int i = 0; i < n; i ++) {
    count[(arr[i]/exp) % base ] ++;
  }

  for(int i = 1; i < base; i ++) {
    count[i]  += count[i-1];
  }
}



int main()
{
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr)/sizeof(arr[0]);
  print<int>(arr, n);

  int base = 10;
  int count[base];
  int output[n];
  int max_num = arr[0];

  for(int i = 0; i < n; i ++) {
    max_num = std::max(arr[i], max_num);
  }

  int k = myceil(std::log(max_num)/std::log(10)) + 1;


  for(int i = 1 , exp = 1; i < k ; i++, exp = exp*10) {
    countSort(arr, n, count, base, exp );

    for(int i = n-1; i >= 0; i --) {
      output[count[(arr[i] / exp ) % base] - 1 ] = arr[i];
      count[(arr[i] / exp ) % 10] --;
    }

    for(int i = 0; i < n; i ++) {
      arr[i] = output[i];
    }
  }
  print<int> (arr, n);

  return 0;
}


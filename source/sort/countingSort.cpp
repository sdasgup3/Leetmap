#include<iostream>
#include<stdlib.h>
/*
http://www.geeksforgeeks.org/radix-sort/
*/

using namespace std;

void swap(int *a, int *b)
{
  int temp  = *a;
  *a = *b;
  *b = temp;
}


void countSort(int arr[], int n, int count[], int k, bool for_pos)
{

  for(int i = 0; i <= k; i ++) {
    count[i] = 0 ;
  }

  for(int i = 0; i < n; i ++) {
    if(arr[i] >= 0 && for_pos) {
      count[arr[i]] ++;
    } else if(arr[i] < 0 && false == for_pos){
      count[-1*arr[i]] ++;
    }
  }

  for(int i = 1; i <= k; i ++) {
    count[i]  += count[i-1];
  }
}



int main()
{
  int arr[] = {11,19,0,-1,5,6,16,-3,6,0,14,18,7,21,18,-6,-8};
  //int arr[] = {2,1,-1,-2};

  int k_pos = 0;
  int k_neg = 0;
  int num_negs = 0;

  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++) {
    cout << arr[i]  << " ";
    if(arr[i] >= 0) {
      if(k_pos < arr[i]) {
        k_pos = arr[i];
      }
    } else {
      num_negs ++;
      if(k_neg > arr[i]) {
        k_neg = arr[i];
      }
    }
  }

  cout <<endl;

  int count_pos[k_pos + 1];
  int count_neg[-1*k_neg + 1];
  int n = sizeof(arr)/sizeof(arr[0]);

  countSort(arr, n, count_pos, k_pos, true );
  countSort(arr, n, count_neg, -1*k_neg, false );

  int output[n];
  for(int i = n-1; i >= 0; i --) {
    if(arr[i] >= 0) {
      output[num_negs + count_pos[arr[i]] - 1 ] = arr[i];
      count_pos[arr[i]] --;
    } else {
      output[num_negs - count_neg[-1*arr[i]]] = arr[i];
      count_neg[-1*arr[i]] --;
    }
  }

  for(int i = 0; i < n; i ++) {
    arr[i]  = output[i];
  }

  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++) {
    cout << arr[i] << " ";
  }
  cout <<endl;
  return 0;
}


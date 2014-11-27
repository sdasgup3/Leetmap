#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *a, int *b)
{
  int temp  = *a;
  *a = *b;
  *b = temp;
}


void countSort(int arr[], int n, int k_pos, int k_neg)
{
  int count_pos[k_pos + 1];
  int count_neg[k_neg + 1];

  for(int i = 0; i <= k_pos; i ++) {
    count_pos[i] = 0 ;
  }
  for(int i = 0; i <= k_neg; i ++) {
    count_neg[i] = 0 ;
  }

  for(int i = 0; i < n; i ++) {
    if(arr[i] >= 0) {
      count_pos[arr[i]] ++;
    } else {
      count_neg[-1*arr[i]] ++;
    }
  }

  for(int i = 1; i <= k_pos; i ++) {
    count_pos[i]  += count_pos[i-1];
  }
  for(int i = 1; i <= k_neg; i ++) {
    count_neg[i]  += count_neg[i-1];
  }

  int num_negs = 0;
  for(int i = 1; i <= k_neg; i ++) {
    if(num_negs < count_neg[i]) {
      num_negs  = count_neg[i];
    }
  }


  int output[n];
  for(int i = 0; i < n; i ++) {
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
}



int main()
{
  int arr[] = {11,19,0,-1,5,6,16,-3,6,0,14,18,7,21,18,-6,-8};
  //int arr[] = {1,0,-1,-2};

  int max_pos = 0;
  int min_neg = 0;
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++) {
    cout << arr[i]  << " ";
    if(arr[i] >= 0) {
      if(max_pos < arr[i]) {
        max_pos = arr[i];
      }
    } else {
      if(min_neg > arr[i]) {
        min_neg = arr[i];
      }
    }
  }
  cout <<endl;

  countSort(arr, sizeof(arr)/sizeof(arr[0]), max_pos, -1*min_neg );
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++) {
    cout << arr[i] << " ";
  }
  cout <<endl;
  return 0;
}


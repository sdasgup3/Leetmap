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


void countSort(int arr[], int n, int count[], int k, int exp, bool for_pos)
{

  for(int i = 0; i <= k; i ++) {
    count[i] = 0 ;
  }

  for(int i = 0; i < n; i ++) {
    if(arr[i] >= 0 && for_pos) {
      count[(arr[i]/exp) % k ] ++;
    } else if(arr[i] < 0 && false == for_pos){
      count[((-1*arr[i])/exp) % k ] ++;
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
  //int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

  int range = 10;
  int max_num = arr[0];
  int num_negs = 0;
  int n = sizeof(arr)/sizeof(arr[0]);

  for(int i = 0; i < n; i ++) {
    cout << arr[i]  << " ";
    if(arr[i] < 0) {
      num_negs ++;
      if(max_num < -1*arr[i]) {
        max_num = -1*arr[i];
      }
    } else {
      if(max_num < arr[i]) {
        max_num = arr[i];
      }
    }
  }
  cout <<endl;

  int count_pos[10];
  int count_neg[10];
  int output[n];

  for(int exp = 1 ; (max_num / exp)  != 0 ; exp = exp* 10) {
    countSort(arr, n, count_pos, 10, exp, true );
    countSort(arr, n, count_neg, 10, exp, false );

    for(int i = n-1; i >= 0; i --) {
      if(arr[i] >= 0) {
        output[num_negs + count_pos[(arr[i] / exp ) % 10] - 1 ] = arr[i];
        count_pos[(arr[i] / exp ) % 10] --;
      } else {
        output[ num_negs - count_neg[((-1*arr[i])/exp)%10 ]  ] = arr[i];
        count_neg[((-1*arr[i])/exp)%10] --;
      }
    }
    for(int i = 0; i < n; i ++) {
      arr[i]  = output[i];
    }
  }


  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++) {
    cout << arr[i] << " ";
  }
  cout <<endl;
  return 0;
}


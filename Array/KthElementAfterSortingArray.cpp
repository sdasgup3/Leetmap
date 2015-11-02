#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *a, int *b)
{
  int temp  = *a;
  *a = *b;
  *b = temp;
}

int qSelect(int arr[], int low, int high)
{
  int saved_low = low;
  int pivot = arr[low];
  while(low <= high) {
    if(arr[low] <= pivot) {
      low++;
      continue;
    }
    if(arr[high] > pivot) {
      high --;
      continue;
    }
    if(low < high) {
      swap(arr+low, arr+high);
    } 
  }
  swap(arr + saved_low, arr+high);
  return high;
}

void myQsort(int arr[], int start, int end)
{
  int len = end -start +1;
  if(len <= 1 ) {
    return ;
  }


  int loc  = qSelect(arr, start, end);
  cout << "LOcation fixed " <<  loc << endl;

  myQsort(arr, start, loc - 1 );
  myQsort(arr, loc + 1, end );
}



int KthElementInArray(int arr[], int n, int k ) 
{
  int start = 0;
  int end = n-1;

  if(k < start || k > end) {
    return -1;
  }

 int loc = -1;
  while(1) {
    if (loc == k) {
      return arr[k];
    } else if (k > loc) {
      loc = qSelect(arr, loc + 1, end);
    } else {
      loc = qSelect(arr, start , loc - 1);
    }
  }
}

int main()
{
  int arr[] = {3,6,9,1,2};
  cout<< KthElementInArray(arr, sizeof(arr)/sizeof(arr[0]), 1) << endl;
  cout<< KthElementInArray(arr, sizeof(arr)/sizeof(arr[0]), 0) << endl;
  cout<< KthElementInArray(arr, sizeof(arr)/sizeof(arr[0]), 4) << endl;
  return 0;
}


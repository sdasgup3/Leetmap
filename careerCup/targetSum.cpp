#include<iostream>
#include<map>


void
swap(int *p, int*q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int arr[], int start, int end) {
  int low = start;
  int high = end;
  int pivot = arr[start];

  while(low <= high) {
    while(arr[low] <= pivot && low <= end) {
      low++;
    }

    while(arr[high] > pivot && high >= 0) {
      high --;
    }

    if(low < high) {
      swap(&arr[low], &arr[high]);
    }
  }

  swap(&arr[start], &arr[high]);
  return high;
}

void 
Qsort(int arr[], int start, int end) {
  if(start >= end) {
    return;
  }

  int q = partition(arr, start, end);
  Qsort(arr, start, q-1);
  Qsort(arr, q+1, end);
}

void print(int arr[], int n)  {
  for(int i = 0 ; i < n ; i ++) {
    std::cout << arr[i] << " " ;
  }
  std::cout<< "\n";
}

bool
targetSum_v1(int arr[], int n, int x) {
  int p1 = 0;
  int p2 = n-1;

  while(1) {
    if(p1 == n || p2 == -1) {
      break;
    }
    int k = arr[p1] + arr[p2];
    if(x == k) {
      return true;
    } else if(x > k) {
      p1 ++;
    } else {
      p2 --;
    }
  }

  return false;
}

bool
targetSum_v2(int arr[], int n, int x) {

  std::map<int, int> M;

  for(int i = 0 ; i < n ; i ++) {
    std::map<int, int>::iterator I = M.find(x-arr[i]);
    if(I != M.end()) {
      return true;
    }
    M[arr[i]] = 1;
  }

  return false;
}

int main()
{
  int arr[] = {15, 12, 10, 8, 7, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  print(arr, size);
  Qsort(arr, 0, size-1);
  print(arr, size);

  std::cout << targetSum_v1(arr, size, 18);
  std::cout << targetSum_v2(arr, size, 18);

  std::cout << targetSum_v1(arr, size, 10);
  std::cout << targetSum_v2(arr, size, 10);


}

#include<iostream>

int 
partition(int arr[], int start, int end) {
  int low = start;
  int high = end;
  int pivot = arr[start];

  while(low < high) {
    while(arr[low] <= pivot && low <= end) {
      low ++;
    }
    while(arr[high] > pivot && high >= 0) {
      high --;
    }

    if(low < high) {
      int temp = arr[low];
      arr[low]  = arr[high];
      arr[high] = temp;
    }
  }
  arr[start] = arr[high];
  arr[high] = pivot;
  return high;
}

int KthMin(int arr[], int start, int end, int k) {
  if(start > end) {
    return -1;
  }

  int p = partition(arr, start, end);
  if(k == p ) {
    return arr[k];
  }
  if(k > p) {
    KthMin(arr, p+1, end, k);
  } else {
    KthMin(arr, start, p-1, k);
  }

}

int main() {
  int arr[] = {4,5,1,8,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  int k = 0;
  
  for(k = 0 ; k <= size; k++) {
    int n = KthMin(arr, 0, size-1, k);
    std::cout << "K = " << k << " Ans : " << n << "\n";
  }
}

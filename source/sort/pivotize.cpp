#include<iostream>


void pivotize(int *arr, int n, int pivot)
{
  if(0 == n) return;
  int start = 0;
  int last = n-1;

  int i = 0,j;
  while(start <= last) {
    while(pivot >= arr[start]) {
      start++;
    }
    while(pivot < arr[last]) {
      last--;
    }
    if(start < last) {
      //std::cout << start << " " << last << std::endl;
      int temp = arr[start];
      arr[start] = arr[last];
      arr[last] = temp;
    }
  }

}

void swap(int *p ,int *q) {
  int temp = *p;
  *p = *q;
  *q = temp;
}

void pivotize_inone(int *arr, int n, int pivot1, int pivot2)
{
  if(0 == n) return;
  int start = 0;
  int last = n-1;
  int last_zero = -1;

  int i = 0,j;
  while(start <= last) {
    while(pivot1 >= arr[start]) {
      if(arr[start] <= pivot2) {
        for(int i = 0 ; i < start; i++) {
          if(arr[i] == 0 ) {
            last_zero = i;
            break;
          }
        }
        if(last_zero != -1) {
          swap(&arr[start], &arr[last_zero]);  
        }
      }

      start++;
    }
    while(pivot1 < arr[last]) {
      last--;
    }
    if(start < last) {
      //std::cout << start << " " << last << std::endl;
      swap(&arr[start], &arr[last]);

      if(arr[start] <= pivot2) {
        for(int i = 0 ; i < start; i++) {
          if(arr[i] == 0 ) {
            last_zero = i;
            break;
          }
        }
        if(last_zero != -1) {
          swap(&arr[start], &arr[last_zero]);  
        }
      }

    }
  }

}


int main()
{
  int arr[] = {1,2,-3,4,-5,0,8,-7,0,0,1};
  int size = sizeof(arr)/sizeof(arr[0]);

  for(int i = 0 ; i < size; i++) {
    std::cout << arr[i] << " " ;
  }
  std::cout << "\n";

  pivotize(arr, size, 0);

  for(int i = 0 ; i < size; i++) {
    std::cout << arr[i] << " " ;
  }
  std::cout << "\n";

  pivotize(arr, size, -1);
  for(int i = 0 ; i < size; i++) {
    std::cout << arr[i] << " " ;
  }
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";

  int arr1[] = {1,2,-3,4,-5,0,8,-7,0,0,1};
  int size1 = sizeof(arr1)/sizeof(arr1[0]);
  for(int i = 0 ; i < size1; i++) {
    std::cout << arr1[i] << " " ;
  }
  std::cout << "\n";
  pivotize_inone(arr1, size1, 0, -1);
  for(int i = 0 ; i < size1; i++) {
    std::cout << arr1[i] << " " ;
  }
  std::cout << "\n";


  return 0;
}

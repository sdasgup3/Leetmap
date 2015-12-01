#include<iostream>

int
equilibrium(int *arr, int size)
{
  if(size ==0) {
    return 0;
  }

  int front[size];
  int rear[size];

  front[0] = arr[0];
  rear[size-1] = arr[size-1];

  for(int i = 1; i < size ; i++) {
    front[i] = arr[i] + front[i-1];
  }

  for(int i = size-2; i >=0   ; i--) {
    rear[i] = arr[i] + rear[i+1];
  }

  if(rear[1] == 0) {
    return 0;
  }

  if(front[size-2] == 0) {
    return size-1;
  }

  for(int i = 1; i <=size-1; i++ ) {
    if(front[i-1] == rear[i+1]) {
      return i;
    }
  }
}



int main()
{
  int arr[] = {1,2,3,-6,2};
  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout << equilibrium(arr, size);


}


#include<iostream>

void 
swap(int *a, int *b) {
  if(a == b) return;

  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}
int 
myrand(int i, int n) {
  int s = n - i  +1;
  int r = rand()%s;
  return i + r;
}

void
shuffle(int arr[], int n) {
  srand(time(NULL));
  for(int i = 0 ; i  < n ; i ++ ) {
    swap(&arr[i], &arr[myrand(i,n-1)]);
  }
}


int main() {

  int arr[] = {1,2,3,4,5};

  for(int i = 0 ; i < 5 ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
  std::cout << " \n" ;

  shuffle(arr, 5);

  for(int i = 0 ; i < 5 ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
  std::cout << " \n" ;
  return 0;

}

#include<iostream>
#define N 10

int fib(int n, int *arr) {
  if(n == 1 || n == 0) {
    return arr[n];
  }

  arr[n] = fib(n-1, arr) + arr[n-2];
  return arr[n];
}

int main() {
  int *arr = new int[N];
  arr[0]=0;
  arr[1]=1;
  fib(N, arr);

  for(int i = 0 ; i < N; i ++) {
    std::cout << arr[i] << " " ;
  }
  std::cout <<"\n" ;

  return 0;
}

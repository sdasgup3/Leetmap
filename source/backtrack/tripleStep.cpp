#include<iostream>
#define N 30

int tripleStep(int n, int *arr) {
  if(n==3 || n==2 || n == 1 || n == 0) {
    return arr[n];
  }

  arr[n] = tripleStep(n-1, arr) + arr[n-2] + arr[n-3];
  return arr[n];
}

int main() {
  int *arr = new int[N];
  arr[0]=0;
  arr[1]=1; //1
  arr[2]=2; //11;2
  arr[3]=4; // 111; 21;12;3
  tripleStep(N, arr);

  for(int i = 0 ; i < N; i ++) {
    std::cout << arr[i] << " " ;
  }
  std::cout <<"\n" ;

  return 0;
}

#include<iostream>
#define N 10


void swap(int &a, int &b) {
  /*
  a = a + b;
  b = a - b;
  a = a - b;

  a = a * b;
  b = a/b;
  a = a/b;
  */
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main() {
  int arr[N][N];		

  for(int  i = 0; i < N; i++) {
    for(int  j = 0; j < N; j++) {
      arr[i][j] = i*N+j;
    }
  }

  for(int  i = 0; i < N; i++) {
    for(int  j = 0; j < N; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for(int  i = 0; i < N; i++) {
    for(int  j = 0; j < i; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }

  for(int  i = 0; i < N; i++) {
    for(int  j = 0; j < N; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

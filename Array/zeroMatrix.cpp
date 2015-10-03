#include<iostream>


void zeroMatrix(int arr[][5], int row, int colm)
{
  bool colm_zeros[colm]; 
  std::fill(colm_zeros, colm_zeros + colm, false);

  for(int i=0 ; i < row; i++) {
    bool this_row_zero = false;
    for(int j = 0; j < colm; j++) {
      if(0 == arr[i][j]) {
        colm_zeros[j] = true;
        this_row_zero = true;;
      }
    }
    if(true == this_row_zero) {
      for(int j = 0; j < colm; j++) {
        arr[i][j] = 0;
      }
    }
  }

  for(int i=0 ; i < colm; i++) {
    if(colm_zeros[i]) {
      for(int j = 0; j < row; j++) {
        arr[j][i] = 0;
      }
    }
  }
}
void mat_print(int arr[][5], int row, int colm)
{
  for(int i=0 ; i < row; i++) {
    for(int j=0 ; j < colm; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


int main()
{
  int row=5;
  int colm =5;
  int arr[5][5] = {
          {1,2,3,5,9},
          {1,0,3,6,9},
          {1,2,0,4,9},
          {1,2,3,4,9},
          {1,2,1,4,9},
  };

  mat_print(arr, row, colm);
  zeroMatrix(arr, row, colm);
  mat_print(arr, row, colm);

  return 0;
}

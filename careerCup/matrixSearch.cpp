#include<iostream>


int 
rec_search(int arr[4][5], int r, int c , int x, int y, int k) {
  if(x == r || y == -1) {
    return 0;
  }

  if(arr[x][y] == k) {
    return 1;
  }
  if(arr[x][y] > k) {
    return rec_search(arr, r, c, x, y-1, k);
  } else {
    return rec_search(arr, r, c, x+1, y, k);
  }
}



int 
search(int arr[4][5], int r, int c ,  int k) {
  int _x = 0;
  int _y = c-1;

  return rec_search(arr, r, c, _x, _y, k);
}



int main()
{
  int arr[4][5] = {
    {10, 20, 30, 40, 50},
    {15, 25, 35, 45, 55},
    {27, 29, 37, 48, 58},
    {32, 33, 39, 50, 60},
  };
  int  k = 39;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 5; j++) {
      k = arr[i][j];
      std::cout << " k = " << k << " " << search(arr, 4,5, k) << "\n";
    }
  }
      k = 100;
      std::cout << " k = " << k << " " << search(arr, 4,5, k) << "\n";
}


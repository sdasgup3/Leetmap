
#include"../utils.h"
/*
   Maximum size square sub-matrix with all 1s
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

For example, consider the below binary matrix.

 
   0  1  1  0  1 
   1  1  0  1  0 
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0
The maximum square sub-matrix with all set bits is

    1  1  1
    1  1  1
    1  1  1

*/   
#define R 6
#define C 5

int
printMaxSubSquare(int M[R][C]) 
{
  int max_top_r = -1;
  int max_bottom_r = -1;
  int max_left_c = -1;
  int max_right_c= -1;
  int max =  0;

  for(int i = 0; i < C ; i ++) {
    for(int j = i; j < C; j++) {
      
      int temp[R];
      for(int k = 0; k < R; k++) {
        temp[k] = 0;
        for(int m = i ; m <= j; m++) {
          if(M[k][m]==0) {
            temp[k] = 0;
            break;
          }
          temp[k] += M[k][m];
        }
      }
      //Find longest streak of 1s in temp
      int n = 0;
      while(1) {
        if(n == R) {
          break;
        }
        if(0 == temp[n]) {
          n++;
          continue;
        }

        int start = n;
        while(n < R && temp[n] != 0) {
          n++;
          if(j-i + 1 == start - n +1) {
            break;
          }
        }
        int end = n;

        if(end - start +1 != j - i + 1) {
          continue;
        }

        int sum = 0;
        for(int ii = start; ii <= end; ii++) {
          sum += temp[ii];
        }

        //std::cout << i << " "  << j  << " " << start << " " <<  end  << " " << sum << "\n";

        if(sum > max) {
          max = sum;
          max_top_r = start;
          max_bottom_r = end;
          max_left_c = i;
          max_right_c = j;
        }
      }

    }
  }

  std::cout << max_top_r << " " << max_bottom_r << " " << max_left_c << " " <<  max_right_c  << "\n";
}


int main() {
    
   int M[R][C] =  {
                    {0, 1, 1, 0, 1}, 
                    {1, 1, 0, 1, 0}, 
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}
   };
                
  printMaxSubSquare(M);

   int N[R][C] =  {
                    {1, 1, 1, 1, 1}, 
                    {1, 1, 1, 1, 1}, 
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1}
   };
                
  printMaxSubSquare(N);
  return 0;
}

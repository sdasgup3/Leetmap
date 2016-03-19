
#define ROW 4
#define COL 5
#include<iostream>

void 
print(int arr[], int n) {
  for(int i = 0 ; i < n ; i ++ ) {
    std::cout << arr[i] << " " ;
  }
}

int
kadane(int arr[], int n, int *start, int *end) {
  int sum_so_far ;
  int max_sum;

  sum_so_far = max_sum  = arr[0];
  *start = 0;
  *end = 0;

  for(int i=1; i< n; i++) {
    //sum_so_far = std::max(sum_so_far+arr[i], arr[i]);
    if(sum_so_far+arr[i] > arr[i]) {
      sum_so_far = sum_so_far+arr[i];
    } else {
      sum_so_far = arr[i];
      *start = i;
    }

    //max_sum = std::max(max_sum, sum_so_far);
    if(max_sum < sum_so_far) {
      max_sum = sum_so_far;
      *end  = i;
    }
  }

  return max_sum;
}
 
void findMaxSum(int arr[][COL])
{
  int max_sum = arr[0][0];
  int temp [ROW];
  int left, right, top, bot, x,y;

  for(int lc = 0 ; lc < COL; lc++) {
    for(int rc = lc ; rc < COL; rc++) {

      int width = rc-lc+1;
      for(int r = 0 ; r < ROW; r++) {
        temp[r] = 0;
        for(int i = 0; i < width; i++) {
          temp[r] += arr[r][lc + i];
        }
      }

      int max_so_far = kadane(temp, ROW, &x, &y);
      if(max_so_far > max_sum) {
        max_sum = max_so_far;
        left = lc;
        right = rc;
        top = x;
        bot = y;
      }
    }
  }

    // Print final values
  printf("(Top, Left) (%d, %d)\n", top, left);
  printf("(Bottom, Right) (%d, %d)\n", bot, right);
  printf("Max sum is: %d\n", max_sum);
}

int main()
{
    int M[ROW][COL] = {
                        {1,   2, -1, -4, -20},
                        {-8, -3,  4,  2, 1},
                        {3,   8,  10, 1, 3},
                        {-4, -1,  1,  7, -6}
                      };
 
    findMaxSum(M);
 
    return 0;
}

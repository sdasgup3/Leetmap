/*
   https://oj.leetcode.com/problems/trapping-rain-water/
 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Solution {
public:
    int addContribution(int start, int start_v, int end, int A[], int n) {
      int res = 0;
      for(int i = start + 1 ; i < end ; i++) {
        if((start_v - A[i]) > 0 ) {
          res += (start_v - A[i]);
        }
      }
      return res;
    }

    int findNxtBigIndex(int arr[], int n, int nextB_i, int value) {
      for(int i =nextB_i +1; i < n; i ++ ) {
        if(arr[i] >= value) {
          return i;
        }
      }
      return -1;
    }
    int trap(int A[], int n) {
      int count = 0 ;
      if(n == 0)
        return count;

      int nextB_i = 0;
      int value = A[nextB_i];
      while(1) {
        if(nextB_i == n - 1) {
          break;
        }

        int m = findNxtBigIndex(A, n, nextB_i, value );
        while(m == -1) {
          value --;
          if(value == -1) {
            break;
          }
          m = findNxtBigIndex(A, n, nextB_i, value);
        }
        if(m == -1) {
           break
        }
        count += addContribution(nextB_i, value, m, A, n);
        nextB_i = m;
        value = A[nextB_i];
      }
      return count;
    }
  

};

int main() {
  Solution S;
  int arr2[]  = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << S.trap(arr2, sizeof(arr2)/sizeof(arr2[0]) ) << endl;;


  return 0;
}

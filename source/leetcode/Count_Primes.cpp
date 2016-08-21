/* Problem Description
 * Count the number of prime numbers less than a non-negative number, n.
*/

#include"header.h"
class Solution {

public:
  Solution() {
    count = 0;
  }

  int countPrimes(int n) {
    if(n <= 2) {
      return 0;
    }

    //int *arr = new int[n+1]; 
    int arr[n+1]; 
    for(int i = 2; i <n; i++) {
      if(arr[i] != 1) {
        count++;
        //cout << i << "\n";
        for(int k = i,  l = 1; k*l < n; l++) {
          arr[k*l] = 1;
        }
      }
    }

    return count;
  }
private:
  int count;

};


int main() {
  Solution S;

  cout << S.countPrimes(1500000) << "\n";

  return 0;
}

/* Problem Description
 * Count the number of prime numbers less than a non-negative number, n.
Let's say m = sqrt(n) then m × m = n. Now if n is not a prime then n can be written as n = a × b, so m × m = a × b. Notice that m is a real number whereas n, a and b are natural numbers.

Now there can be 3 cases:

a > m ⇒ b < m
a = m ⇒ b = m
a < m ⇒ b > m
In all 3 cases, min(a, b) ≤ m. Hence if we search till m, we are bound to find at least one factor of n, which is enough to show that n is not prime.
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

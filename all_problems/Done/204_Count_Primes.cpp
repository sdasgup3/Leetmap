/* Problem Description
 * Count the number of prime numbers less than a non-negative number, n.

 *Solution
 How to determine if a number is prime
Let's say m = sqrt(n) then m × m = n. Now if n is not a prime then n can be written as n = a × b, so m × m = a × b. Notice that m is a real number whereas n, a and b are natural numbers.

Now there can be 3 cases:

a > m ⇒ b < m
a = m ⇒ b = m
a < m ⇒ b > m
In all 3 cases, min(a, b) ≤ m. Hence if we search till m, we are bound to find at least one factor of n, which is enough to show that n is not prime.

In this problem:
take a vector<bool> V(n, true)
denoting that all the numbners are prime

now one we get a prime p do 
V[p*i] = false such that p < p*i < n

*Tags
Math

*/

#include"header.h"
class Solution {

public:

  int countPrimes(int n) {
    if(n <= 2) {
      return 0;
    }

    vector<bool> V(n, true);

    for(int i = 2; i <n; i++) {
      if(V[i] == true) {
        count++;
        for(int k = 2; k *i < n ; k++) {
          V[i*k] = false;
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

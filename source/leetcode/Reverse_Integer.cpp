/* Problem Description
 * Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

Subscribe to see which companies asked this question

Overflow cond: sum*10 + rem > INTMAX or sum > (INTMAX - rem )  / 10
Underflow cond: sum*10 + rem < INTMIN or sum < (INTMAX - rem )  / 10

*/

#include"header.h"
class Solution {

public:
  int reverse(int x) {
    int sum = 0;

    while(x) {
      int rem = x %10;

      cout << sum << ": ";
      if((rem >= 0 && sum > (INT_MAX - rem)/10) ||
          (rem <0 && sum < (INT_MIN-rem)/10)) {
        return 0;
      } 

      sum = sum*10 + rem; 
      x = x/10;
    }
       
    return sum;
  }
private:

};


int main() {
  Solution S;

  int n = -123;
  cout << n << ":" << S.reverse(n) << "\n\n";

  n = 2147483647;
  cout << n << ":" << S.reverse(n) << "\n\n";

  n = -2147483648;
  cout << n << ":" << S.reverse(n) << "\n\n";

  return 0;
}

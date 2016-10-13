/* Problem Description
 * Implement pow(x, n).
*/

#include"header.h"

class Solution {
  private:
    double sum;
public:

    void helper(int count, double x, int n) {
      double y = x;
      for(int i = 0; i < count; i++) {
          y *= y; 
      }
      sum *= y;
      n = n - std::pow(2, count);
      if(0 == n) return ;
      count = log(n)/log(2);
      helper(count, x, n);

    }
    double myPow(double x, int n) {
      
      if(0 == n || 1 == x) {
        return 1.0;
      }
      if(0 == x) {
        return 0.0;
      }
      
      double residue =  1;
      bool invert  = false;
      if(n < 0) {
        invert = true;
        if(n == INT_MIN) {
          residue = 1/x;
          n++;
        }
        n = -1*n;
      }
      sum  = 1;

      int count = log(n)/log(2);
      helper(count, x, n);

      if(invert) {
        return residue * (1/sum);
      }
      return sum;
        
    }
};

int main() {
  Solution S;

  cout << S.myPow(8.88023, 3) << "\n";

  return 0;
}

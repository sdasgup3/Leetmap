/* Problem Description
 * There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
*/

#include"header.h"

class Solution {
public:
    int numWays(int n, int k) {
      if(0 ==n || 0 == k ) return 0;
        
        vector<int> S(n+1), D(n+1), R(n+1);
        
        if(1 == n) return k;
        
        S[2] = k;
        D[2] = k*(k-1);
        
        for(int i = 3 ; i <= n; i++) {
            S[i] = D[i-1];
            D[i] = (S[i-1] + D[i-1])*(k-1);
        }
        
        return S[n] + D[n];
    }
};


int main() {
  Solution S;

  cout << S.numWays(10, 2);

  return 0;
}

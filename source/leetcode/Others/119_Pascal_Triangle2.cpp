/* Problem Description
 * Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

C(n,k) = n!/ k! (n-k)! =  C(n, n-k)
C(n, k) = (n-k+1)/(k)  * C(n,k-1)

*/

#include"header.h"
class Solution {

public:
   vector<int> getRow(int rowIndex) {

     int numE = rowIndex  + 1;
     vector<int> R(numE);
     unsigned long l;

     for(int  r = 0 ; r <= rowIndex/2 ; r ++) {
        if(r == 0) {
          R[r] = R[rowIndex - r] = 1;
        } else {
           l = (rowIndex - r  + 1) * (unsigned long)R[r-1] / r;
          R[r] = R[rowIndex -r] = l;
        }
     }

     return R;
        
    }

  /*
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        long current_multiplier = 1;
        for (int n = 1; n <= rowIndex / 2; ++n) {
            current_multiplier *= (rowIndex - n + 1);
           cout << "l: " << current_multiplier <<  " " ;
            current_multiplier /= n;
           cout << current_multiplier <<  "\n " ;
            result[n] = current_multiplier;
        }
        for (int n = rowIndex / 2 + 1; n < rowIndex; ++n) {
            result[n] = result[rowIndex - n];
        }
        return result;
        
    }
    */

private:

};


int main() {
  Solution S;

  cout << S.getRow(30);

  return 0;
}

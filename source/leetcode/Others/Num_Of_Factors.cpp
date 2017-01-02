/* Problem Description
 * Find #factors in a given num
*/

#include"header.h"
class Solution {

public:
  int fact(int n, int p) {  

    if(n%p == 0 ) {
      return 1 + fact(n/p, p);
    } 

    return 0;


  }
private:

};


int main() {
  Solution S;

  cout << S.fact(125,5);

  return 0;
}

/* 
 * Problem Description

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Show Hint 

 * Solution
num  ans
---------
0   0

1   9
...
9   9

10  1
...
18  9


19  1
...
27  9

 * Tags
 Math
*/

#include"header.h"
class Solution {

public:
  ValidWordAbbr(vector<string> &dictionary) {  


  }
private:

};


int main() {
  Solution S;

  vector<string> D;

  D.push_back("dear");

  S.ValidWordAbbr(D);

  return 0;
}

/* Problem Description
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
  
In decimal after 0...9, there come 10, i.e the digit at the tenth place is
not same as the one in ones place, whereas in excel tile After 
Z comes AA

First lets map 0 - A
25 - Z

If there is any number between 0 - 25; %26 is same which will be mapped appropriately.
For 26, the rem string  is 10; the tenth digit need to be recuded by 1 to get AA
for 

N   rem string(26)  exp
1     1         A
25    25        Y
26    10         Z    XXXXXXXXXXXXX expected 01

27    11        AA
28    12        AB
51    1<25>     AY
52    20        BZ  XXXXXXXXXXXXX      expected 11

*/

#include"header.h"
class Solution {

public:
  string convertToTitle(int n) {
    vector<int> digits;


    while(n) {
      int rem = n%26;
      digits.push_back(rem);
      n = n/26;
    } 

    int len = digits.size();

    string retval;
    for(int i = len-1; i >= 0 ; i--) {
      if(digits[i] == 0) {
        retval.push_back('Z');
      } else {
        retval.push_back('A' + digits[i] - 1);
      }
    }

    return retval;
  }
private:

};


int main() {
  Solution S;

  for(int i = 1 ; i < 100; i++) {
    cout << i << ":" << S.convertToTitle(i) << "\n";
  }

  return 0;
}

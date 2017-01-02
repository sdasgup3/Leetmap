/* Problem Description
 * Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include"header.h"
class Solution {

public:
  int singleNumber(vector<int>& nums) {
    vector<int> bits(32,0);
    for(int n : nums) {
      int k = 0;
      while(n) {
        bits[k] += n & 1;
        n = ((unsigned)n >> 1);
        k++;
      }
    }

    int sum = 0,  p = 1;
    int k = 0;
    for(;k <32; k++, p = p*2) {
      bits[k] %= 3;
      sum += bits[k]*p;
    }

    return sum;

  }
private:

};


int main() {
  Solution S;

  vector<int> D({-1,4,-1,-1});

  cout << S.singleNumber(D);

  return 0;
}

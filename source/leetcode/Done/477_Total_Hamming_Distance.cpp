/* 
 * Problem Description
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.


 * Solution

 Find the contribution to HD by the LSB of all the numbers
 If out of n numers p gas 0 in their lsb and q has 1; then total contrib == pq

 repeat the same for other bit positions

 * Tags
 Bits
*/

#include"header.h"
class Solution {
public:

       int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        int sz = nums.size();

        for(int i = 0 ; i < 32; i++) {
          int p = 0;
          int q = 0;
          for(int j = 0 ; j < sz; j++) {
            if(0 == nums[j] %2) {
              p ++;
            } else {
              q++;
            }
            nums[j] = ((unsigned int)nums[j]) >> 1;
          }

          count += p*q;
        }
        return count;
    }
};


int main() {
  Solution S;

  vector<int> V({4,14,2});

  cout << S.totalHammingDistance(V);

  return 0;
}

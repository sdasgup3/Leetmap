/* Problem Description
 * Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

#include"header.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bits;
        
        while(n) {
            int rem = n %2;
            bits.push_back('0' + rem);
            n = n /2;
        }
        int len  = bits.length();

        string actual;

        for(int i = 0 ; i < 32-len; i++) {
          actual.push_back('0');
        }
        for(int i = len-1 ; i >= 0; i--) {
          actual.push_back(bits[i]);
        }


        len  = actual.length();
        for(int i = 0 ; i < len /2 ; i++) {
          char c = actual[i];
          actual[i] = actual[len-1-i];
          actual[len-1-i] = c;
        }
        
        cout << actual << "\n";
        uint32_t sum = 0;
        for(int i = 0 ; i < actual.length(); i++) {
            sum = sum*2 + (actual[i] - '0');
        }
        
        return sum;
    }
};


int main() {
  Solution S;

uint32_t n = 43261596;
  cout << n << " " << S.reverseBits(n) << "\n";

  return 0;
}

/* Problem Description
 * Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Tags:
Bits
*/

#include"header.h"


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        
        vector<int> store(32, 0);
        uint32_t runner = n;
        int k = 0;
        //FInd all the bits of n
        while(runner) {
            store[k++] = runner%2;
            runner = runner/2;
        }
        
        //Reverse store
        for(int i = 0 ; i < 16; i++) {
            int tmp = store[i];
            store[i] = store[31-i];
            store[31-i] = tmp;
        }
        //Create the new unsigned int
        uint32_t sum = 0;
        //for(int i = 0, p = 1 ; i < 32; i++, p *= 2) {
        //    sum += store[i]*p;
        //}
        for(int i = 0 ; i < 32; i++) {
            if(store[i] == 1) {
              sum += (1 << i);
            }
        }
        
        return sum;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
     //ABCD-> CD AB -> DC BA          
     
     n = (n >> 16) | (n << 16);
     n = ((n & 0xff00ff00) >> 8)  | ((n & 0x00ff00ff) << 8); 
     n = ((n & 0xf0f0f0f0) >> 4)  | ((n & 0x0f0f0f0f) << 4); 
     n = ((n & 0xcccccccc) >> 2)  | ((n & 0x33333333) <<2);
     n = ((n & 0xaaaaaaaa) >> 1)  | ((n & 0x55555555) << 1);
     
     return n;
    }
};


int main() {
  Solution S;

uint32_t n =   2147483648; // (10000000000000000000000000000000);
  cout << n << " " << S.reverseBits(n) << "\n";

  return 0;
}

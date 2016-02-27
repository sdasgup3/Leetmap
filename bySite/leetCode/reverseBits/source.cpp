#include<iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t low_index = 1;
        uint32_t high_index = 1 << 31;
        
        for(int i = 1; i <= 16; i++, low_index = low_index << 1, high_index = high_index >> 1) {
            uint32_t low_bit = (n & low_index);
            uint32_t high_bit = (n & high_index) ;
            
            if(0 == low_bit && 0 == high_bit) {
                continue;
            }
            if(0 != low_bit && 0 != high_bit) {
                continue;
            }
            
            n = n ^ low_index;
            n = n ^ high_index;
            
        }
        
        return n;
    }
};


int main()
{
  Solution S;
  S.reverseBits(4294967295);
}

/* Problem Description
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:

You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?



* 
*/

#include"header.h"
class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> R(num+1);
        
        R[0] = 0;
        if(0 == num) return R;
        R[1] = 1;
        if(1 == num) return R;
        
        int r = log(num)/log(2);
        int p = pow(2,r);
        int rem = num%p;
        
        int last_but_one_r = r-1;
        
        if(last_but_one_r >=1) {
            int start =2;
            int end = 4;
            while(1) {
                int k = 0;
                for(int i = start ; i < end;i++, k++) {
                    R[i] = 1 + R[k];
                }
                start *=2;
                end *=2;
                if(start == p) {
                break;
                }
            }
            
        }
        for(int i = 0 ; i <= rem;i++) {
                R[p + i] = 1 + R[i];
        }
        
        return R;
    }

    vector<int> countBits(int num) {
        vector<int> R(num+1);
        
        R[0] = 0;
        if(0 == num) return R;
        R[1] = 1;
        if(1 == num) return R;
        
        for(int i = 2 ; i <= num;i++) {
            if(0 != i%2) { // if odd
                R[i] = R[i-1] + 1;
            } else {
              R[i] = R[i>>1];
            }
        }
        
        return R;
    }
};

int main() {
  Solution S;


  cout << S.countBits(3);

  return 0;
}

/* Problem Description
   Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*Solution

max carry that can have == 1
max value == 9
so max result == 0

Also we dont have to irete over th fulllength of the array
the moment we get a non 9, we can stop

Also note 

sz-1 ...                 0
(lsb)                   (msb)

so we start from msb and at the very end if we have a carry that means all the digits were previously 9
and now they are all 0s. So we have to extend the length and put 1 at index 0 (new msb)


*Tags
Bits



*/

#include"header.h"
  class Solution {
public:
    vector<int> plusOne_v2(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1 ; i >= 0; i--) {
            int q = (digits[i] + carry)/10;
            int r = (digits[i] + carry)%10;
            digits[i] = r;
            carry = q;
        }
        
        vector<int> ans;
        if(carry) {
            ans.resize(digits.size() +1);
            ans[0] = carry;
            for(int i = 0 ; i  < digits.size(); i++) {
                ans[i+1] = digits[i];
            }
            return ans;
        }
        return digits;
    }


  vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1 ; i >= 0; i--) {
          if(digits[i] == 9) {
            digits[i] = 0;
          } else {
            digits[i]++;
            return digits;
          }
        }

        digits.push_back(1);
        return digits;
  }
};


int main() {
  Solution S;
  vector<int> d = {9};

  cout << S.plusOne(d);

  return 0;
}

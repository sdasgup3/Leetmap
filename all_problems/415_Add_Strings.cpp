/* 
 * Problem Description
 Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * Solution
 * Tags
 * Bits
*/

#include"header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        
        if(!l1) {
            return num2;
        }
        if(!l2) {
            return num1;
        }
        
        string res;
        int carry = 0, i = l1-1, j = l2-1;
        
        for(; i>=0 && j>= 0; i--, j--) {
            int val1 = num1[i] - '0';
            int val2 = num2[j] - '0';
            
            int sum = (val1 + val2 + carry)%10;
            carry = (val1 + val2 + carry)/10;
            res.push_back(sum + '0');
        }
        
        if(i != -1) {
            for(; i>=0 ; i--) {
                int val1 = num1[i] - '0';
                
                int sum = (val1 +  carry)%10;
                carry = (val1 + carry)/10;
                res.push_back(sum + '0');
            }
        }   
        
        if(j != -1) {
            for(; j>=0 ; j--) {
                int val1 = num2[j] - '0';
                
                int sum = (val1 +  carry)%10;
                carry = (val1 + carry)/10;
                res.push_back(sum + '0');
            }
        }
           
        
        if(carry) {
            res.push_back('1');
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
        
    }
};


int main() {
  Solution S;


  return 0;
}

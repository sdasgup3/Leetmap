/* 
 * Problem Description
 Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 * Solution

The length  == # of even frequency characters + # of odd freq char -1 + 1 (if there is any odd frequency)

 * Tags
 Palindrom
 Map
*/

#include"header.h"
class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int>M;
        
        for(auto  c  : s) {
            M[c] ++;
        }
        int sum = 0 ; 
        bool odd = false;
        
        for(auto p : M) {
            if(p.second%2 == 0) {
                sum += p.second;
            } else {
                odd = true;
                sum += (p.second-1);
            }
        }
        return odd? sum +1: sum;
    }
};


int main() {

  return 0;
}

/* 
 * Problem Description
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
 * Solution
 * Tags
 Array
*/

#include"header.h"
class Solution {
public:
    bool isStrobogrammatic(string s) {
        int l = s.length();
        if(0 == l) return true;
        
        for(int i = 0 ; i <= l/2; i++) {
            
            if(s[i] == s[l-1-i] && (s[i] == '0' || s[i] == '1' || s[i] == '8')) {
                continue;
            } 
            
            if(
                s[i] != s[l-1-i] && 
                ( 
                    (s[i] == '6' && s[l-1-i] == '9')  || 
                    (s[i] == '9' && s[l-1-i] == '6') 
                ) ) {
                continue;
            }
            return false;
        }
        return true;
    }
};


int main() {
  Solution S;

  return 0;
}

/* Problem Description
*/

#include"header.h"

class Solution {
public:
    bool isPalindrome(int n) {
        if(n < 0) return false;
        int m = n, c =0;
        while(m) {
            c++;
            m =  m /10;
        }
        
        while(c > 1) {
            int lsb = n%10;
            n = n /10;
            c -= 2;
            int p = pow(10,c);
            int msb = n/p;
            
            if(msb != lsb) return false;
            
            n = n%p;
        }
        
        return true;
    }
    /*
    public boolean isPalindrome(int x) {
    if (x<0 || (x!=0 && x%10==0)) return false;
    int rev = 0;
    while (x>rev){
    	rev = rev*10 + x%10;
    	x = x/10;
    }
    return (x==rev || x==rev/10);
}
*/
};

int main() {
  Solution S;

  S.isPalindrome(-234);

  return 0;
}

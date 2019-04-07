

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        //0 represents me, 1 my friend
        if(n < 0) {
            return true;
        }
        
        return helper(n,0);
    }
    
    bool helper(int n, int who) {
        if(n < 0) {
            return false;
        }
        if(n <= 3 ) {
            if(0 == who) {
                return true; //I got zero marbles
            } else {
                return false;
            }
        }
        
        return helper(n-1, 1-who) || helper(n-2, 1-who) || helper(n-3, 1-who);
    }
};

int main() {
  Solution S;
  cout << S.canWinNim(1348820612);
}

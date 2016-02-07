#include<iostream>
#include<climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      
        
        int ret = 0;
      
        
        while(x) {
            int rem = x%10;
            x = x/10;
            cout << ret << "\n";
            if(ret > INT_MAX/10 || ret < INT_MIN/10 ) return 0;
            ret = 10*ret + rem;
        }
        
       
        return ret;
        
    }
};

int main() {
	Solution S;
	int x  = 2147483647;
	int x  = -2147483648;
	std::cout << S.reverse(x) << "\n";
}

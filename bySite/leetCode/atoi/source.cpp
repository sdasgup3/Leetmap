
#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        
        int len=  str.length();
        if(0 == len) return 0;
        
        bool isneg = false;
        int index = 0;
        
        for( ; str[index] == ' '; index++ ) {
        }
        
        if(str[index] == '-') {
            isneg = true;
            index++;
        } else if(str[index] == '+') {
            index++;
        }
        
        
        int ret = 0;
        for(int i = index ; i < len; i++ ) {
            if(str[i] == ' ') continue;
            if(!(str[i] >= '0' && str[i] <= '9')) return 0;
            ret = 10*ret + (str[i] - '0');
        }
        
        if(isneg) {
            return -1*ret;
        }
        
        return ret;
        
    }
};


int main() {
	Solution S;
	std::cout << S.myAtoi("1") << "\n";

}


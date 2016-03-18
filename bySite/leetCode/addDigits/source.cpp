class Solution {
public:
int addDigits1(int num) {
        
            return (num-1)%9 +1;
        
    }
    int addDigits(int num) {
        if(num <= 9) {
            return num;
        } else {
            return (num-10)%9 +1;
        }
        
    }
};

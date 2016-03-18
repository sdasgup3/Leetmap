Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

- For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

- Follow up:
Could you do it without any loop/recursion in O(1) runtime?

```c++
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
```


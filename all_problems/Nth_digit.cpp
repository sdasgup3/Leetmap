#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int digit(int n, int r, int total) {
        int c1 = total  - r ;
        int c2 = total -1 - r ;
        int p1 = pow(10, c1);
        int p2 = pow(10, c2);
        return (n %p1)/p2;
    }
    int findNthDigit(int n) {
        int d = 1;
        
        while(n - d* 9*pow(10,d-1) > 0) {
            n -= d * 9 * pow(10, d-1);
            cout <<  n << " " <<  d * 9*pow(10, d-1) << "\n";
            d ++;
        }
        
        int index = (n-1) / d;
        int R = (n-1) % d;
        int start = pow(10,d-1) ;
        cout << start << "\n";
        int num = start + index ;
        cout << num << " "  << R << "\n";
        return digit(num, R, d);
    }
};

int main() {
  Solution S;
  std::cout << S.findNthDigit(1000000000);
}

  

#include<cmath>
#include<iostream>
using namespace std;

bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double f = log(n)/log(3);
        cout << (double)f <<" "  << (double)((int)f) << endl;
        if(f != (double)((int)f)) {
            return false;
        }
        return true;
    }


int main ()
{
isPowerOfThree(243);

}

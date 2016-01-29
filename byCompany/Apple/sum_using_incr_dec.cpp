/* sum 2 ints using incr and decrement*/

#include<iostream>
#include<cmath>

using namespace std;

int sum(int a, int b) {
  int abs_a = abs(a);
  int abs_b = abs(b);


  int sum, inr;
  if(abs_a > abs_b) {
    sum = a;
    inr = b;
  } else {
    sum = b;
    inr = a;
  }

  if(inr >= 0) {
    for(int i = inr; i > 0; i--) {
      sum++;
    }
  } else {
    for(int i = inr; i < 0; i++) {
      sum--;
    }
  }

  return sum;
}

int main() {
  int a, b;

  a = 5; b = 6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = -5; b = 6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 5; b = -6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = -5; b = -6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 0; b = -6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 0; b = 6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 10000; b = 6;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 0; b = 0;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";

  a = 100; b = -100;
  cout << "a=" << a << " b=" << b << " sum= " << sum(a,b) << "\n";
}

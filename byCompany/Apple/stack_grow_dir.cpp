#include<iostream>
using namespace std;

int* 
func() {
  int x;
  return (&x);
}

int main() {
  int x;
  int *y = func();
  if(&x > y) {
    cout << "Donwards\n";
  } else {
    cout << "Upwards\n";
  }
}

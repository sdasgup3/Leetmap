#include<iostream>
#include<vector>
#include<cmath>



int 
NP2(int x)
{
  if(0 == x) {
    return 1;
  }

  if(0 != x && 0 == (x & (x-1)) ) {
    return x;
  }

  std::vector<int> v(8*sizeof(int), 0);
  int tmp = x, k=0;
  if(tmp < 0) {
    tmp = std::pow(2,8*sizeof(int)-1) + tmp;
    v[8*sizeof(int)-1] = 1;
  }
  while(tmp) {
    v[k++] = tmp&1;
    tmp = tmp/2;
  }

  int last_1;

  for(last_1 = v.size()-1; last_1 >=0; last_1-- ) {
    if(1 == v[last_1]) {
      break;
    }
  }

  std::cout << last_1 << "\n";
  return (int)std::pow(2, last_1+1);
}

int 
NP1(int x)
{
  if(0 == x) {
    return 1;
  }

  if(0 != x && 0 == (x & (x-1)) ) {
    return x;
  }

  int last_1=0;
  while(x) {
    x = x/2;
    last_1++;
  }

  std::cout << last_1 << "\n";
  return (int)std::pow(2, last_1);
}

int 
NP3(int x)
{
  if(0 == x) {
    return 1;
  }

  if(0 != x && 0 == (x & (x-1)) ) {
    return x;
  }

  int last_1 = std::ceil(std::log(x)/std::log(2));
  std::cout << last_1 << "\n";
  return (int)std::pow(2, last_1);
}

unsigned int 
NP4(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n) {
        p <<= 1;
    }
    return p;
}
 

int main() {
  for(int i = 0 ; i < 50; i++) {
    std::cout << i << " " << NP4(i) << "\n";
  }
  std::cout << -1 << " " << NP4(-1) << "\n";
}


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

  for(int i = 0 ;i <= last_1; i++) {
    v[i] = 0;
  }
  v[last_1+1] =1;


  int sum = 0, i = 0;
  while(i < v.size()) {
    sum += (v[i] << i);
    i++;
  }

  return sum;
}


int main() {
  for(int i = 0 ; i < 50; i++) {
    std::cout << i << " " << NP2(i) << "\n";
  }
  std::cout << -1 << " " << NP2(-1) << "\n";
}


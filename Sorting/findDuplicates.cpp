#include<iostream>
#include"../utils.h"
#include<vector>


int
my_rand(int start, int end) {
  int len = end-start +1;
  return start + (rand()%len);
}

void
findDuplicates(std::vector<int> V) {
  int store[1024];
  for(int i = 0 ; i < 1024; i++) {
    store[i] = 0;
  }

  for(int i = 0 ; i < V.size(); i++) {
    int whichInt = V[i]/32;
    int whichBit = V[i]%32;
    int bitval =  store[whichInt] & (1 << whichBit);
    //std::cout << V[i] << " " << whichInt << " " << whichBit << " " << bitval << "\n";

    if(0 != bitval) {
      std::cout << "DUP:" << V[i] << "\n";
    } else {
      store[whichInt] = store[whichInt] | (1 << whichBit);
    }
  }
}

int main() {

  std::vector<int> V;
  srand(time(NULL));

  for(int i = 0; i < 1000; i++) {
    V.push_back(my_rand(1, 32000));
  }
  print<int>(V);

  findDuplicates(V);

}







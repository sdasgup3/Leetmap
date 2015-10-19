#include<iostream>
#include<vector>
#include<list>

int getbit(int n, int bit) {
  int mask = 1 << bit;
  int ret = n & mask;
  return ret >> bit;
}


void 
powerset(int arr[], int n, std::list<std::vector<int>*> &PS) {

  int max =  1 << n;
  for(int i = max-1 ; i >=0 ; i --) {
    std::vector<int>* v = new std::vector<int>;
    for(int k = 0; k < n; k++) {
      if(getbit(i, k)) {
        v->push_back(arr[k]);
      }
    }
    PS.push_back(v);
  }
}



int main() {

  int arr[]  = {1,2,3,4,5}; 
  int n  = sizeof(arr)/sizeof(arr[0]);
  std::list<std::vector<int>*> PS;

  powerset(arr, n, PS);

  for(std::vector<int> *v: PS) {
    std::cout << "{ "; 
    for(int j =0; j < (*v).size(); j++) {
      std::cout << (*v)[j] << " "; 
    }
    std::cout << " }" << " \n"; 
  }

  return 0;
}

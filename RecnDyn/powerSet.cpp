#include<iostream>
#include<vector>
#include<list>

void 
combination(int arr[], int n, int r, std::list<std::vector<int>*> &PS) {
  if(r == 0) {
    return;
  }

  for(int i = 0 ; i <= n -r ; i ++) {
    for(int j = i+1 ; j <= n-r + 1 && r -1 > 0; j ++) {
      std::vector<int> *v  =  new std::vector<int>(r);
      int l = 0;
      (*v)[l++] = arr[i];

      for(int k = j ; k < j+r-1 && k < n; k ++) {
        (*v)[l++] = arr[k];
      }
    PS.push_back(v);
    }
  }
}



int main() {

  int arr[]  = {1,2,3,4,5}; 
  int n  = sizeof(arr)/sizeof(arr[0]);
  std::list<std::vector<int>*> PS;

  for(int r = 2 ; r <= 2; r ++ ) {
    combination(arr, n, r, PS);
  }

  for(std::vector<int> *v: PS) {
    std::cout << "{ "; 
    for(int j =0; j < (*v).size(); j++) {
      std::cout << (*v)[j] << " "; 
    }
    std::cout << " }" << " \n"; 
  }

  return 0;
}

#include<iostream>
#include<vector>
#include<climits>

static int count = 0;

std::vector<int> 
mergeN(std::vector<std::vector<int>> A, int n) {
  std::vector<int > R;

  std::vector<int> ptr(n,0);

  while(true) {
    int min = INT_MAX;
    int min_pointer;
    int count_end = 0;

    for(int i = 0 ; i < n ; i ++) {
      if(ptr[i] != A[i].size()) {
        if(min > A[i][ptr[i]]) {
          min = A[i][ptr[i]];
          min_pointer = i;
        }
      } else {
        count_end ++;
      }
    }
    if(count_end == n) {
      break;
    }
    R.push_back(min);
    count ++;
    if(8 == count) {
      std::cout << R.back();
    }
    ptr[min_pointer] ++;
  }
  return R;
}



int main()
{
  std::vector<std::vector<int>> A;
  std::vector<int> v1{5,15,15,20};
  std::vector<int> v2{4,8,12,16};
  std::vector<int> v3{7,14,21,28};
  std::vector<int> v4{1,2,3,4};

  A.push_back(v1);
  A.push_back(v2);
  A.push_back(v3);
  A.push_back(v4);
  int k = 8;
  std::vector<int > R = mergeN(A,4);

  for(int i = 0 ; i < R.size(); i ++) {
    std::cout << R[i] << " "; 
  }
  std::cout << "\n";
}

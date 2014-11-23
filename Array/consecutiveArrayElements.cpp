/*
The idea is to check for following two conditions. If following two conditions are true, then return true.
1) max – min + 1 = n where max is the maximum element in array, min is minimum element in array and n is the number of elements in array.
2) All elements are distinct.
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int findMax(vector<int> v) {
  int ret = v[0];
  for(vector<int>::iterator i = v.begin(), j = v.end(); i != j ; i++) {
    if(ret <= *i) {
      ret = *i;
    }
  }
  return ret;
}

int findMin(vector<int> v) {
  int ret = v[0];
  for(vector<int>::iterator i = v.begin(), j = v.end(); i != j ; i++) {
    if(ret >= *i) {
      ret = *i;
    }
  }
  return ret;
}

bool isConsecutive(vector<int> v) {

  int n = v.size();
  if(n  == 0)
    return false;

  int max = findMax(v);
  int min = findMin(v);

  if(max - min + 1 != n ) {
    return false;
  }

  /*Method 1: Auxiliary array
  vector<bool> arr(n);

  for(int i = 0 ; i < n ; i++) {
    arr[i] = false;
  }

  for(int i = 0 ; i < n ; i++) {
    if(arr[v[i] - min] == false) {
      arr[v[i] - min] = true;
    } else {
      return false  ;
    }
  }
  //Method1 Ends*/


  //Method2: Modifying aaray
  int offset = max + 1;
 
  for(int i = 0 ; i < n ; i++) {
    int actual = v[i];
    if(actual >= offset) {
      actual -= offset;
    } 
    if(v[actual - min] >= offset) {
      return false;
    } else {
      v[actual - min] += offset;
    }
  }
  //Method2 Ends

  return true;  
}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr[]  = {5, 2, 3, 1, 4};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
  cout << v;
  std::cout << "isConsecutive: " << isConsecutive(v) << endl;

  int arr2[]  = {83, 78, 80, 81, 79, 82};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  std::cout << "isConsecutive: " << isConsecutive(v2) << endl;

  int arr3[]  = {34, 23, 52, 12, 3};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  std::cout << "isConsecutive: " << isConsecutive(v3) << endl;

  int arr4[]  = {7, 5, 5, 3, 4};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  std::cout << "isConsecutive: " << isConsecutive(v4) << endl;



  return 0;
}

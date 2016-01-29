/*
   http://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
   Given an unsorted array of size n. Array elements are in range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in array. Find these two numbers.
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
std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}

bool findRepeatAndMissing_v(vector<int> v) {
  vector <int> repeating;
  vector <int> missing;
  int n = v.size();

  for(int i = 0 ; i < n ; i++) {
    int actual = v[i] ;
    if(actual < 0 ) {
      actual = -1*actual;
    }
    if(v[actual - 1 ] < 0) {
      repeating.push_back(actual); 
    } else {
      v[actual - 1] = -1*v[actual - 1 ];
    }
  }

  for(int i = 0 ; i < n ; i++) {
    if(v[i] >= 0) {
      missing.push_back(i + 1);
    }
  }

  cout << "Repeating : " << endl;
  cout <<   repeating;
  cout << "Missing : " << endl;
  cout << missing;

  return true;  
}


bool findRepeatAndMissing(vector<int> v) {
  int max = findMax(v);
  int k = max+1;

  for(int i = 0;i < v.size(); i++) {
    int posn = v[i]%k -1;
    v[posn] += k;  
  }

  for(int i = 0;i < v.size(); i++) {
    int value = v[i]/k;
    if(0 == value) {
      std::cout << i+1 << " is Missing\n";
    } else if(2 == value) {
      std::cout << i+1 << " occurs twice \n";
    }
  }
}


int main() {
  int arr[]  = {4, 3, 6, 2, 1, 1};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
  cout << v;
  findRepeatAndMissing(v);
  findRepeatAndMissing_v(v);

  int arr2[]  = {3, 1, 3};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  findRepeatAndMissing(v2);
  findRepeatAndMissing_v(v2);

  int arr3[]  = {7, 3, 4, 5, 5, 6, 2};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  findRepeatAndMissing(v3);
  findRepeatAndMissing_v(v3);
  return 0;
}

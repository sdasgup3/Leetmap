#include<iostream>
#include<map>

using namespace std;


/**
 * Write a function that determines whether a array contains duplicate 
 * characters within k indices of each other
 */
bool  findDupWithinKIndices(int arr[], int n, int k) 
{
  map<int, bool> hash;
  for(int i = 0 ; i < n ;  i ++) {
    if(i > k) {
      hash.erase(arr[i - (k + 1)]);  
    }
    if(hash.find(arr[i]) != hash.end()) {
      return true;
    } else {
      hash[arr[i]] = true;
    }
  }
  return false;
}




int main()
{
  int arr[] = {1,2,3,11,2,5,6};
  cout << "Result : " << findDupWithinKIndices(arr, sizeof(arr)/sizeof(arr[0]), 3) << endl;
  return 0;
}

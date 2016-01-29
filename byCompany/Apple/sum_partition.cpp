/*
  partition a given set into two subssets st the sum of each will be the same 
*/

#include<iostream>
using namespace std;

bool 
partition_helper(int* arr, int n, int sum)
{
  if(n < 0) return false;

  if(arr[n] == sum) return true;

  if(arr[n] > sum) {
    return partition_helper(arr, n-1, sum);
  }

  return partition_helper(arr, n-1, sum) || 
    partition_helper(arr, n-1, sum-arr[n]);
}

bool 
partition(int* arr, int n) {

  int sum = 0;
  for(int i = 0; i < n;  i++) {
    sum += arr[i];
  }

  if(sum % 2 != 0) {
    cout << "sum not even\n";
    return false; 
  }

  return partition_helper(arr, n-1, sum/2);

}


int main() {
  int arr[] = {1,5,11,5};
  cout << partition(arr, sizeof(arr)/sizeof(arr[0])) << "\n";;

  int arr1[] = {1,5,3};
  cout << partition(arr1, sizeof(arr1)/sizeof(arr1[0])) << "\n";;

  int arr2[] = {3,1,5,9,12};
  cout << partition(arr2, sizeof(arr2)/sizeof(arr2[0])) << "\n";;

  int arr3[] = {3,1,1,2,2,1};
  cout << partition(arr3, sizeof(arr3)/sizeof(arr3[0])) << "\n";;

  int arr4[] = {8,4,4,4};
  cout << partition(arr4, sizeof(arr4)/sizeof(arr4[0])) << "\n";;


}

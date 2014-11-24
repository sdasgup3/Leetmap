//Find subarray with given sum
//http://www.geeksforgeeks.org/find-subarray-with-given-sum/

#include<iostream>
#include<vector>
#include<assert.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

static int Count = 0;  

std::ostream& operator<< (std::ostream& stream, vector<int> v) 
{
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;


}

vector< vector<int> > allSoln;
void fill(int pos, int start, int end, int n, int r, vector<int> soln) 
{

  if(pos == r) {
    Count ++;
    //cout << soln;
    allSoln.push_back(soln);
    return;
  }

  for(int i = start; i < end; i ++) {
    soln.push_back(i);
    fill(pos +1, i + 1, end + 1,  n,  r, soln);
    soln.pop_back();
  }
}


void combination(int n, int r) 
{
  vector<int> soln;
  fill(0, 0, n - r + 1, n, r, soln);

}



bool findSum_1(int arr[], int n, int sum) 
{
  //Method 1
  for(int i = 1 ; i <= n ; i ++ ) {
    combination(n, i);
  }

  for(vector< vector<int> >::iterator i = allSoln.begin(), 
        j = allSoln.end(); i!=j; i++ ) {
    vector<int>& x = *i;
    int temp = 0;
    for(vector<int> :: iterator i = x.begin(), j = x.end(); i!=j; i++) {
      temp += arr[*i];
    }
    if(temp == sum) {
      for(vector<int> :: iterator i = x.begin(), j = x.end(); i!=j; i++) {
        cout<< arr[*i] << " ";
      }
      cout << endl;
    }
  }

  return false;
}

int compare(const void *a,const void *b) 
{
  return *((int *)a) - *((int *)b) ; 
}

bool findSum_2(int arr[], int n, int sum) 
{
  //Method 2: Slising window
  int start = 0 , end = 0;
  int partial_sum = arr[start];

  while (end < n) {
    if(partial_sum < sum) {
      partial_sum += arr[++end];
    }else if(partial_sum == sum) {
      cout << "The interval is : " << start << " " << end << endl;
      return true;
    }else if (partial_sum > sum) {
      partial_sum -= arr[start ++];
      if(start == n) {
        break;
      }
      if(start  > end) {
        partial_sum += arr[++end];
      }
    }
  }

  return false;
}

int main() {
  //int arr[] = {1, 4, 20, 3, 10, 5};
  //int sum = 33;

  //int arr[] = {1, 4, 0, 0, 3, 10, 5};
  //int sum = 7;

  //int arr[] = {1, 4, 0};
  //int sum = 0;

   int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
   int sum = 23;

  int n = sizeof(arr)/sizeof(arr[0]);

  //bool result = findSum_1(arr,n, sum);
  bool result = findSum_2(arr,n, sum);
  return 0;
}

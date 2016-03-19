/*
   Given an unsorted array of positive integers. Find the number of triangles
   that can be formed with three different array elements as three sides of
   triangles. For a triangle to be possible from 3 values, the sum of any two
   values (or sides) must be greater than the third value (or third side).  For
   example, if the input array is {4, 6, 3, 7}, the output should be 3. There
   are three triangles possible {3, 4, 6}, {4, 6, 7} and {3, 6, 7}. Note that
   {3, 4, 7} is not a possible triangle.  As another example, consider the
   array {10, 21, 22, 100, 101, 200, 300}. There can be 6 possible triangles:
   {10, 21, 22}, {21, 100, 101}, {22, 100, 101}, {10, 100, 101}, {100, 101,
   200} and {101, 200, 300}
   http://www.geeksforgeeks.org/find-number-of-triangles-possible/
 */

#include<iostream>
#include<vector>
#include<assert.h>
#include<stdlib.h>
using namespace std;

int compare(const void*a, const void* b)
{
  return *((int *)a) - *((int *)b);
}

int countTria(int v[], int n) 
{
  qsort(v,n, sizeof(int), compare);
  int count = 0;
  //fix c
  // if we can find a dn b such that a + b > c, then its assured that
  // the other two invariants will also be true because c >=a and c >= b
  // and hence c+a > b abd c + b > a.

  for(int i= n-1 ;i >=  2  ; i--) {
    int c = v[i];

    int a = 0;
    int b = i - 1;
    while (a < b) {
      if(v[a] + v[b] <= c) {
        a ++;
      } else {
        count += (b  - a);  
        b --;
      }
    }
  }
  return count;
}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr2[]  = {4, 6, 3, 7};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  cout << "Possible Trialgles: " << countTria(arr2, sizeof(arr2)/sizeof(arr2[0])) << endl;

  int arr3[]  = {10, 21, 22, 100, 101, 200, 300};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  cout << "Possible Trialgles: " << countTria(arr3, sizeof(arr3)/sizeof(arr3[0])) << endl;




  return 0;
}

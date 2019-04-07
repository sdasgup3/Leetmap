/* Problem Description
   Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.


*Solution
Do the merge from the end
that way you will be be erasing the to be used contents of nums1
say the last element of nums1 is 7 ; if it is the larger that any element of nums2 then it will get relocated; else if it is the
smallest among all the lems of nums2, then it will remain in its own place

*Tags
Merge Sort
*/

#include"header.h"
class Solution {

public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

      int i= m-1 , j = n-1, k = m+n-1;
      while(i >=  0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i];
          i--;
        } else if(nums1[i] < nums2[j]) {
          nums1[k--] = nums2[j];
          j--;
        } else {
          nums1[k--] = nums1[i];
          nums1[k--] = nums2[j];
          i--; j--;
        }
      }

      if(j != -1) {
        for(; j>=0; j--  ) {
          nums1[k--] = nums2[j];
        }
      }
    }
private:

};

ostream& operator<<(ostream& OS, vector<int>& V) {
  for(int i = 0 ; i < V.size(); i++) {  
    OS<< V[i] << " " ;
  }
  OS << "\n";
} 

int main() {
  Solution S;

  vector<int> nums1 = {1,2,3,4,5,6};
  vector<int> nums2 = {3,5,7,8,9};
  int m  = nums1.size();
  int n  = nums2.size();

  nums1.resize(n+m, 0);

  S.merge(nums1, m, nums2, n);
  cout << nums1;

  return 0;
}

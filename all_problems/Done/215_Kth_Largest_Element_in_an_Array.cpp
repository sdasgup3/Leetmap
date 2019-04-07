/* 
 * Problem Description
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
 * Solution
 1. Priority Queue
Insertion: O(n)
extraction: klogn

2. Qucikselect
kn

 * Tags
 QuickSelect
 Priority Queue
*/

#include"header.h"
class Solution {

//public:
//    int findKthLargest2(vector<int>& nums, int k) {
//      auto cmp = [](int a, int b) {return a < b;};
//      priority_queue<int, vector<int>, decltype(cmp)> Q(cmp, nums);
//
//      int val;
//      for(int i = 0 ; i < k; i++) {
//        val = Q.top();
//        Q.pop();
//      }
//        
//      return val;
//    }
//
//    void swap(int *a, int *b) {
//      if(a == b) return;
//
//      *a = *a ^ *b;
//      *b = *a ^ *b;
//      *a = *a ^ *b;
//    }
//    class Solution {
public:
    void swap(int *a, int *b) {
        if(a == b) return;
        *a   = *a ^ *b;
        *b   = *a ^ *b;
        *a   = *a ^ *b;
        return;
    }
    
    int QS( vector<int>& nums, int first, int last) {
        int p = nums[first];
        int low = first;
        int high = last;
        cout << p << " " << low << " " << high << "\n";
        while(low < high) {
            while(p >= nums[low] && low <= last) {
                low++;
            }
            while(p < nums[high] && high >= 0) {
                high--;
            }
            
            if(low < high) {
                swap(&nums[low], &nums[high]);
            }
            
        }
        swap(&nums[first], &nums[high]);
        return high;
    }
        
    int findKthLargest(vector<int>& nums, int k) {
        int first = 0 ; 
        int last = nums.size()-1;
        k = nums.size() - k  +1;
        cout << k << "\n";
        while(1) {
            int p = QS(nums, first, last);
           cout << p << "\n";
            if (p+1 == k) return nums[p];
            if (p+1 < k) {
                first = p+1;
            } else {
                last = p-1;
            }
        }
        
    }

   // int QS(vector<int> &nums, int first, int last) {
   //   int pivot = nums[first];
   //   int pivot_ind = first;
   //   while(first < last) {

   //     while(first < last && nums[first] >= pivot) {
   //       first++;
   //     }
   //     while(nums[last] < pivot) {
   //       last--;
   //     }

   //     if(first < last) {
   //       swap(&nums[first], &nums[last]);
   //     }
   //   }

   //   swap(&nums[pivot_ind], &nums[last]);

   //   return last;
   // }

   // int findKthLargest1(vector<int>& nums, int k) {

   //   int first = 0;
   //   int last  = nums.size()-1;

   //   cout << nums;
   //   while(1) {
   //     int index = QS(nums, first, last);
   //     cout << index;
   //     cout << nums;
   //     if(index == k-1) {
   //       return nums[index];
   //     } else if(k-1 > index){ 
   //       first = index +1;
   //     } else {
   //       last = index -1;
   //     }
   //   }
   //     
   //   return -1;
   // }

   // int findKthLargest(vector<int>& nums, int k) {

   //   auto cmp = [](int a, int b) {return a> b; };
   //   nth_element(nums.begin(), nums.begin()+k-1, nums.end(), cmp);
   //   return nums[k-1];

   // }
private:

};


int main() {
  Solution S;

  vector<int> D({3,2,1,5,6,4});

  cout << S.findKthLargest(D, 2);

  return 0;
}


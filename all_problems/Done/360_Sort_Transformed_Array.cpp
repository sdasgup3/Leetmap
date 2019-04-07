/* 
 * Problem Description
 Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
 * Solution

 y = ax2 + bx+ c 
arr : a sorted array

for a > 0; 
 for x : arr
  y decreases till  a point and then increases afterwards

for a < 0; 
 for x : arr
  y increaes till  a point and then decreases afterwards

for a == 0; 
 for x : arr
  y is either ascending or descending

Case1:
4 3 2 0 10 20 30
 1. take two pointers one at forst and other at last and do merge sort
 The req of merge sort is that both the array must be sorted in the SAME DIRECTION
 taking first and last will serve this req

 2. reverse the array (as the merged array after step one is descending)

Case2:
-3 -2 -1  0 -20 -40
 1. take two pointers one at forst and other at last and do merge sort
 The req of merge sort is that both the array must be sorted in the SAME DIRECTION
 taking first and last will serve this req
 2. the merged array after step one is ascending

Case 3 is same as Case 2
 1 2 3 
 take first  == 1 last == 3 and do mergesort 

 3 2 1 
 take first  == 1 last == 3 and do mergesort 


 * Tags
 Merge Sort
*/

#include"header.h"
class Solution {
public:

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        int sz = nums.size();
        vector<int> res, one, two;
        
        if(0 == sz)  return res;
        int first = 0;
        int last = sz-1;
        
        if(a < 0) {
            while(first <= last) {
                int val1 = nums[first]*nums[first]*a + b*nums[first] + c;
                int val2 = nums[last]*nums[last]*a + b*nums[last] + c;
                
                if(val1 <= val2) {
                    res.push_back(val1);
                    first++;
                }  else {
                    res.push_back(val2);
                    last--;
                }  
        
            }
        } else {
            while(first <= last) {
                int val1 = nums[first]*nums[first]*a + b*nums[first] + c;
                int val2 = nums[last]*nums[last]*a + b*nums[last] + c;
                
                if(val1 >= val2) {
                    res.push_back(val1);
                    first++;
                }  else {
                    res.push_back(val2);
                    last--;
                }  
        
            }
            reverse(res.begin(), res.end());
        }
        
        return res;
        
    }
};

int main() {
  Solution S;


  return 0;
}

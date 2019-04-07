/* 
 * Problem Description
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Solution
 1. count them individually and place it later
 2. quciksort
 012210 - > use 0 as pivot
 00 1221
    ^  ^
    |  |

    work on only between these indecies and use pivot 1
    Or u may use from 0 to n-1


 * Tags
 Sort
*/

#include"header.h"
class Solution {

public:
  void sortColors1(vector<int>& nums) {
        int red = 0;
        int blue  = 0;
        int white = 0;
        
        for(auto n : nums) {
            if(n == 0) { 
                red ++;
            } else if(n==1)  { 
                white++;
            } else { 
                blue ++;
            }
        }
        
        int k = 0;
        for(int i = 0 ; i < red; i++) {
            nums[k++] = 0;
        }
        
        for(int  i = 0  ; i < white; i++) {
            nums[k++] = 1;
        }
        
        for(int  i = 0  ; i < blue; i++) {
            nums[k++] = 2;
        }
        
    }

  void Qsort(int pivot, int start, int end, vector<int>&nums) {

    while(start < end) {
      while(start < end && nums[start] <= pivot) {
          start ++;
      }
      while(nums[end] > pivot) {
          end --;
      }

      if(start < end) {
        int t = nums[start];
        nums[start] = nums[end];
        nums[end] = t;
      }
    }

  }

  void sortColors(vector<int>& nums) {
    int sz = nums.size();

    if(0 == sz || 1 == sz) {
      return ;
    }

    Qsort(0, 0, sz-1, nums);
    Qsort(1, 0, sz-1, nums);
  }
private:

};


int main() {
  Solution S;
  vector<int> D({0,1,2,2,1,0});
  S.sortColors(D);
  cout << D;

  return 0;
}


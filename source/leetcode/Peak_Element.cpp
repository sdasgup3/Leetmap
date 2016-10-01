/* Problem Description
 * A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
ums

1. find mid
2. if nums[mid] < mums[mid+1]==> low mid+1
3. if nums[mid] > nums[mid+1] ==> high = mid

*/

#include"header.h"
class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid = (low+high)/2;
            if(num[mid] < num[mid+1])
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};


int main() {
  Solution S;

  vector<int> D({1,2,1,3,4,5,6,7});

  cout << S.findPeakElement(D);

  return 0;
}

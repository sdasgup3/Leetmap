/* 
 * Problem Description
 
Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 * Solution
 
 The idea is to find max number of non 0verlapping interval
 Ans = size - that number

Case1:
 ----------------
    -------- -------------

M = 2
ans = 1

-------------------
 ------------
        --------------
M = 0
ans = 3

----------- ----------- ---
M = 3
Ans = 0

Now the problem is
after sorting with starts

------- 1
    ---------2 
        ----------3   

        Here 3 overlaps with 2 but NOT with 1 and our goal to return 2 as the max number of non overlapping intervals (1 and 3)

        and 
----------1
 ----- 2
       --------3
        Here 3 overlaps with 1 but NOT with 2 and our goal to return 2 as the max number of non overlapping intervals (1 and 2)

       After we know that 1 and 2 are overlapping 3 might be nonoverlapping with either 1 or 2. So which interval (1or2) to consider for the iteration
       for interval 3

       The idea is to use end = min(1.end, 2.end) to be considered for the iteration for interval 3


 * Tags
 Sort
Intervals
*/

#include"header.h"
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int sz = intervals.size();
        if(0 == sz) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), 
        [&](Interval a, Interval b) {
            return a.start < b.start;
        }
        
        );
        
        int end = intervals[0].end;
        int max_no_i = 1;
        for(int i = 1; i < sz ; i ++) {
            if(end > intervals[i].start) {
                
                end = min(end, intervals[i].end);
            } else {
                end = intervals[i].end;
            max_no_i ++;
                
            }
        }
        
        return sz - max_no_i;
    }
};

int main() {
  Solution S;


  return 0;
}

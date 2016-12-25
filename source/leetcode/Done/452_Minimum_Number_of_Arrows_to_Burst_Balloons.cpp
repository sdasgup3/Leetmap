/* 
 * Problem Description
 There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
 * Solution

  1111111111111
      222222222222
       33333
We need to find that region 33333

1-----4
   2------------7
     3---5   6-----10

     inti_arrow = 4 == size
s = 1
e  = 4

next:
start = 2;
end = 4;
init_arrow--;


next:
start = 3;
end = 4;
init_arrow--;

next:
start = 6;
end = 10;


 * Tags
*/

#include"header.h"
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int sz = points.size();
        if(0 == sz) return 0;
        sort(points.begin(), points.end());
        
        int start = points[0].first;
        int end  = points[0].second;
        
        int res = sz;
        for(int i = 1 ; i < sz; i++) {
            if(points[i].first <= end) {
                end = min(end, points[i].second);
                start = points[i].first;
                res--;
                cout << start << end << "\n";
            }  else {
                start = points[i].first;
                end = points[i].second;
            }   
        }
        
        return res;
    }
};


int main() {
  Solution S;


  return 0;
}

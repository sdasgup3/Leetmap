/* 
 * Problem Description
 Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
 * Solution
1. find the max encloising rectangle
area of that  = Sum(all input rectangle)

2. Let the input rectangle be 
 (0 0 1 1) (0 0 1 1) (0 1 2 2)
 max area  = 4 
 inout area  = 4 
 but we have overlapping rects

 To mitigate that store the 4 points of each input rect
 But if a point is already there remove it 
 that way at the end we must have only 4 points of the max encloising rectangle


 * Tags
 Math
*/

#include"header.h"
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX;
        int y1  = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        string s;
        int area = 0;
        unordered_map<string, int> M; 
        for(auto rect : rectangles) {
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);
            int a = (rect[2] - rect[0])*(rect[3] - rect[1]); 
            area += (rect[2] - rect[0])*(rect[3] - rect[1]); 
            
            
            //store the four corners
            s = to_string(rect[0]) + " " + to_string(rect[1]);
            if(M.count(s)) M.erase(s) ; else M[s] = 0;
            s = to_string(rect[0]) + " " + to_string(rect[3]);
            if(M.count(s)) M.erase(s) ; else M[s] = 0;
            s = to_string(rect[2]) + " " + to_string(rect[1]);
            if(M.count(s)) M.erase(s) ; else M[s] = 0;
            s = to_string(rect[2]) + " " + to_string(rect[3]);
            if(M.count(s)) M.erase(s) ; else M[s] = 0;
            
        }
     
        if(area != (x2-x1)*(y2-y1)) {
            return false;
        }
        
        if(4 != M.size()) {
            return false;
        }
        
        if(0 == M.count(to_string(x1) + " " + to_string(y1)) || 
            0 == M.count(to_string(x1) + " " + to_string(y2)) ||
            0 == M.count(to_string(x2) + " " + to_string(y1)) ||
            0 == M.count(to_string(x2) + " " + to_string(y2)) )
            return false;
        
        return true;
    }
};

int main() {
  Solution S;

  return 0;
}

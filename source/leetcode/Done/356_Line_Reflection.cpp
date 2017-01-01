/* 
 * Problem Description
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.

 * Solution
Its NOT a median problem
244
The solution is 3
if we use median  = 4 there cant be a solution


 * Tags
 Map
 Average
*/

#include"header.h"
class Solution {
     bool isReflected(vector<pair<int, int>>& points) {
        
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        unordered_map<int, unordered_map<int, bool>> M;
        
        for(int i = 0 ; i < points.size(); i++)  {
            min_x = std::min(min_x, points[i].first);
            max_x = std::max(max_x, points[i].first);
            M[points[i].first][points[i].second] = true;
        }
        
        int double_mirror_x = ((min_x + max_x));
        
        
        for(int i = 0 ; i < points.size(); i++)  {
            int to_find = double_mirror_x - points[i].first;
         //   cout << to_find << " " << points[i].second << "\n";
            if(0 == M.count(to_find) || 0 == M[to_find].count(points[i].second)) return false;
        }
        
        return true;
    }
};

int main() {
  Solution S;
  vector<pair<int, int>> D;
  //D.push_back(P(0,0));
  //D.push_back(P(1,0));
  D.push_back(P(16,0));
  D.push_back(P(-16,0));
  D.push_back(P(16,0));

  cout  << S.isReflected(D);

  return 0;
}

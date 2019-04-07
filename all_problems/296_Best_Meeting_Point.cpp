/* Problem Description
 * A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Tags:
Median
*/

#include"header.h"

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        
        for(int i = 0 ;i <grid.size();i++ ) {
            for(int  j = 0 ; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        //Note rows is already sorted
        int med_r = rows[rows.size()/2];
        nth_element(cols.begin(), cols.begin() + cols.size()/2, cols.end());
        int med_c = cols[cols.size()/2]; 
        int dist = 0;
        for(auto r : rows) {
            dist += abs(r- med_r);
        }
        for(auto c : cols) {
            dist += abs(c- med_c);
        }
        return dist;
    }
};


int main() {

  vector<vector<int>> D;

  S.minTotalDistance(D);

  return 0;
}

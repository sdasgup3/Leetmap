/* Problem Description
 * given a matrix sorted in rows and colums; search a target
*/

#include"header.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        size_t r = matrix.size();
        size_t c = matrix[0].size();
        
        if(0 == r) {
            return false;
        }
        
        int s_r = 0;
        int s_c = c-1;
        while (1) {
            if(s_c >= c || s_c < 0 || s_r >= r || s_r < 0) {
                return false;
            }
            int temp = matrix[s_r][s_c];
            if(temp == target) {
                return true;
            } else if(temp > target) {
                s_c --;
            } else {
                s_r ++;
            }
        }
        
        return false;
    }
};

int main() {
  Solution S;

  return 0;
}

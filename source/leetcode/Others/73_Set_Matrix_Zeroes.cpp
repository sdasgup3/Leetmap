/* Problem Description

Solution:

Tags:
Array
*/

#include"header.h"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        if(0 == r) return ;
        int c = matrix[0].size();
        //vector<int> col;
        int keyR = -1; bool first = true; 
        
        for(int i = 0 ; i < r; i++) {
            bool isrowZ = false;
            for(int j = 0 ; j < c ;j ++) {
                if(matrix[i][j] == 0 ) {
                    if(first) {
                        keyR = i;
                        first = false;
                    }
                    
                    isrowZ = true;
                    
                    matrix[keyR][j] = 0;
                }
            }
            
            if(isrowZ && i != keyR) {
                for(int j = 0 ; j < c ; j++) {
                    matrix[i][j] = 0;
                }
            }
        } 
        
        if(-1 == keyR) {
            return;
        }
        
        for(int k = 0 ; k < c; k++) {
            if(matrix[keyR][k] == 0) {
                for(int i = 0 ; i < r; i++) {
                    matrix[i][k] = 0;
                }
            }
        }
        
        for(int i = 0 ; i < c ; i++) {
            matrix[keyR][i] = 0;
        }
        
    }
};


int main() {
  Solution S;
  return 0;
}

/* Problem Description
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include"header.h"

class Solution {
    private:
    vector<int> V;
public:
    int numTrees(int n) {
        V.resize(n+1, 0);
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        V[0] = 1;
        V[1] =  1;
        V[2]  = 2;
        
        for(int i = 3; i <= n; i++) {
            for(int j = i-1, k = 0; j >= 0 ; j --, k++) {
                V[i] += V[j]*V[k]; 
            }    
        }
        
        return V[n];
        
    }
};


int main() {

  return 0;
}

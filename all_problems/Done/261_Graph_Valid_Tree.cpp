/* Problem Description
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Tags:
Union FInd
*/

#include"header.h"

class Solution {
    private:
    vector<int> V;
public:
    int find(int x) {
        while(x != V[x] ) {
            x = V[x];
        }
        return x;
    }
    
    void Union(int x, int y) {
        int rep_x = find(x);
        int rep_y = find(y);
        V[rep_x] = rep_y;
    } 
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n <=1 ) 
            return true;
        
        V.reserve(n);
        
        for(int i = 0 ; i < n ;i++) {
            V[i] = i;
        }
        int con_comp = n;
        for(auto p : edges) {
            int rep_x = find(p.first);
            int rep_y = find(p.second);
            if(rep_x != rep_y) {
                Union(p.first, p.second);
                con_comp --;
            } else {
                return false;
            }
        }
        return con_comp == 1;
    }
};


int main() {
  Solution S;

  vector<pair<int, int>> E;

  E.push_back(pair<int, int>(0,1));
  E.push_back(pair<int, int>(2,3));

  cout << S.validTree(4, E);

  return 0;
}

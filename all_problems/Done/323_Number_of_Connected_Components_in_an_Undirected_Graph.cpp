/* 
 * Problem Description
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 * Solution
 * Tags
 Union FInd
*/

#include"header.h"
class Solution {
private:
    vector<int> V;
public:
    int find(int x) {
        int res = x;
        while(res != V[res]) {
            res = V[res];
        }
        return res;
    }
    
    void myunion(int x, int y) {
        auto xrep    = find(x);
        auto yrep    = find(y);
        V[yrep] = xrep;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        if(0 == n) {
            return 0;
        }
        
        V.reserve(n);
        for(int i = 0 ; i < n; i++) {
            V[i] = i;
        }
        int res = n;
        
        for(auto p: edges) {
            int first = p.first;
            int second = p.second;
            
            int rep_first = find(first);
            int rep_second = find(second);
            
            //cout << first << " " << rep_first << " " << second << " " << rep_second << "\n";   
            if(rep_first != rep_second) {
                myunion(first, second);
                res--;
            }
        }
        
        return res;
    }
};


int main() {
  Solution S;


  return 0;
}

/* Problem Description
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

Tags:
dfs
*/

#include"header.h"
class Solution {
  private:
    unordered_map<int , vector<int>> M; // i -> j, k where there exist edges like i->j, i->k 
    vector<int> dfs_num;
    vector<int> order;
    vector<bool> visited;
    int num_assign;
public:

    void dfs_visit(int v) {
      if(true == visited[v]) {
        return;
      }
      visited[v] = true;
      
      vector<int> adj = M[v];
      for(auto n : adj) {
        dfs_visit(n);
      }

      dfs_num[v] = num_assign;
      order[num_assign] = v;
      num_assign --;
    }

    vector<int> canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

      dfs_num.resize(numCourses, -1);
      order.resize(numCourses, -1);
      visited.resize(numCourses, false);
      num_assign = numCourses-1;

      vector<int> res;

      for(auto p: prerequisites) {
        //there is an edge from second to first
        M[p.second].push_back(p.first);
      }

      for(int i = 0 ; i < numCourses; i++) {
        if(false == visited[i] ) {
          dfs_visit(i);
        }
      }

      for(auto p: prerequisites) {
        //= is for circular node
        if(dfs_num[p.second] >= dfs_num[p.first]) {
          return res;
        }
      }
       
      return order;
    }
};

int main() {
  Solution S;

  vector<pair<int, int>> V;
  V.push_back(pair<int, int>(1,0));
  V.push_back(pair<int, int>(2,0));
  V.push_back(pair<int, int>(3,1));
  V.push_back(pair<int, int>(2,3));

  cout << S.canFinish(4, V);

  return 0;
}

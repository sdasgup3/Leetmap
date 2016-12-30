/* 
 * Problem Description


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
Show Company Tags
Show Tags
Show Similar Problems

 * Solution

Have a map of orig->cloned node
1--2
1 and 2 are nghb of each other 
check if 1 is already cloned 
  if not clone it and populate the map


 * Tags
 Recursion
*/

#include"header.h"
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
class Solution {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> M;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        UndirectedGraphNode *n;
        if(M.count(node)) {
            return M[node];
        } else {
            n = new UndirectedGraphNode(node->label);
            M[node] = n;
            for(auto ngh : node->neighbors) {
                n->neighbors.push_back(cloneGraph(ngh));
            }
            return M[node];
        }
        
    }
};


int main() {

  return 0;
}

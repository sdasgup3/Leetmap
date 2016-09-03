/* Problem Description
 * Create a binary tree using the BFS traversal order
*/

#include"header.h"
class Solution {

public:
  BTNode* CreateBT(vector<int> &v) {  

    int n = v.size();
    BTNode* root = NULL;

    if(0 == n) {
      root;
    }

    queue<BTNode*> Q;

    root = new BTNode(v[0]);
    Q.push(root);

    for(int i = 1 ; i < n ; i ++ ) {
      BTNode *t = Q.front();
      if(t->left == NULL) {
        t->left = new BTNode(v[i]);
      } else if(t->right == NULL) {
        t->right = new BTNode(v[i]);
        Q.pop();
        Q.push(t->left);
        Q.push(t->right);
      } 
    }
    return root;
  }
private:

};


int main() {
  Solution S;

  vector<int> v = {1, 2,3,4,5,6,7};

  std::cout << S.CreateBT(v);

  return 0;
}

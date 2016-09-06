/* Problem Description
*/

#include"header.h"



class Solution {

public:
   TreeNode* CreateBT(vector<int> &v) {  

    int n = v.size();
    TreeNode* root = NULL;

    if(0 == n) {
      root;
    }

    int c = 0;
    queue<TreeNode*> Q;

    root = new TreeNode(v[c++]);
    Q.push(root);

    while(!Q.empty()) {
      TreeNode *t = Q.front();
      Q.pop();
      if(-1 == v[c]) {
        t->left = NULL;
      } else {
        t->left = new TreeNode(v[c]);
        Q.push(t->left);
      }
      c++;

      if(-1 == v[c]) {
        t->right = NULL;
      } else {
        t->right = new TreeNode(v[c]);
        Q.push(t->right);
      }
      c++;
    }
    return root;
  }

  int minDepth(TreeNode* root) {  
    if(!root) {
      return 0;
    }

    if(!root->left && !root->right) {
      return 1;
    }

    if(root->left && !root->right) {
      return minDepth(root->left) + 1;
    }

    if(!root->left && root->right) {
      return minDepth(root->right) + 1;
    }

    return std::min(minDepth(root->left),minDepth(root->right)) + 1;

  }
private:

};


int main() {
  Solution S;

  vector<int> v = {1,-1,2, 3,4,-1, -1, 5,6,7,-1,-1,-1, -1,-1};
  TreeNode* T = S.CreateBT(v);;
  cout << T;

  cout << S.minDepth(T);

  return 0;
}

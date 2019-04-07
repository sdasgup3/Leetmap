/* 
 * Problem Description
 * Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 *
 *
 *
 *
 *
 * Solution
*/

#include"header.h"
class Solution {
public:

    void reverse(vector<int> &v) {

      int sz = v.size();
      for(int i = 0 ; i < sz/2; i++) {
        //swap(v[i], v[sz-1-i])
        int t = v[i];
        v[i] = v[sz-1-i];
        v[sz-1-i] = t;
      }
    }
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> result;
      stack<TreeNode *> S;
      if(root)
        S.push(root);

      while(!S.empty()) {
        TreeNode *temp = S.top();
        S.pop();
        result.push_back(temp->val);
        if(temp->left)  {
          S.push(temp->left);
        }
        if(temp->right) {
          S.push(temp->right);
        }
      }

      reverse(result);

      return result;
        
    }
};

int main() {
  Solution S;
   TreeNode *root = new TreeNode(5, 
              new TreeNode(8, NULL, NULL), 
              new TreeNode(7, 
                  new TreeNode(6, NULL, NULL),
                  new TreeNode(4, NULL, NULL)
                          )
              );

  cout << root;

  cout << S.postorderTraversal(root);

  return 0;
}

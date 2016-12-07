/* Problem Description
 * Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

#include"header.h"
class Solution {
public:
    void helper(TreeNode* root) {
      if(!root) return;
      TreeNode *temp = root->left;

      root->left = root->right;
      root->right = temp;
      helper(root->left);
      helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {

      if(!root) return root;
      helper(root);
      return root;
    }
};

int main() {
  Solution S;

   TreeNode *root = new TreeNode(1, 
              new TreeNode(2, NULL, NULL), 
              new TreeNode(3, 
                  new TreeNode(4, NULL, NULL),
                  new TreeNode(5, NULL, NULL)
                          )
              );

  cout << S.invertTree(root);

  return 0;
}

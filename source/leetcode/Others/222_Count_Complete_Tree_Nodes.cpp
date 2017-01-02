/* Problem Description
 * Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

#include"header.h"
class Solution {
public:
    int getLeftHeight(TreeNode *root) {
      if(!root) return 0;

      return 1 + getLeftHeight(root->left);
    }

    int getRightHeight(TreeNode *root) {
      if(!root) return 0;

      return 1 + getRightHeight(root->right);
    }

    int getNodes (TreeNode *root) {
      if(!root) {
        return 0;
      }

      return 1 + getNodes(root->left) + getNodes(root->right);
    }

    int countNodes(TreeNode* root) {
      if(!root) {
        return 0;
      }

      int lh = getLeftHeight(root); 
      int rh = getRightHeight(root); 

      if(lh == rh) {
        return std::pow(2, lh) -1;
      } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
      }
    }
};


int main() {
  Solution S;

  TreeNode *T1 = new TreeNode(1, NULL, NULL);
  TreeNode *T3 = new TreeNode(3, NULL, NULL);
  TreeNode *T5 = new TreeNode(5, NULL, NULL);
  TreeNode *T7 = new TreeNode(7, NULL, NULL);
  TreeNode *T2 = new TreeNode(2, T1, T3);
  TreeNode *T6 = new TreeNode(6, T5, T7);
  TreeNode *T4 = new TreeNode(4, T2, T6);


  cout << S.countNodes(T4);

  TreeNode *S1 = new TreeNode(1, NULL, NULL);
  TreeNode *S3 = new TreeNode(3, NULL, NULL);
  TreeNode *S5 = new TreeNode(5, NULL, NULL);
  TreeNode *S2 = new TreeNode(2, S1, S3);
  TreeNode *S6 = new TreeNode(6, S5, NULL);
  TreeNode *S4 = new TreeNode(4, S2, S6);
  cout << S.countNodes(S4);
  return 0;
}

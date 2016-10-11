/* Problem Description
 * Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

#include"header.h"
class Solution {
public:

    int helper(TreeNode* root, int isleft) {
      if(NULL == root->left && NULL == root->right ) {
        if(isleft) {
          return root->val;
        } else {
          return 0;
        }
      }

      if(root->left && root->right) {
        return helper(root->left,  1) + helper(root->right, 0);
      } else if(root->right){
        return helper(root->right, 0);
      } else  {
        return helper(root->left, 1);
      }

    }
   int sumOfLeftLeaves(TreeNode* root) {
    if(!root) {
      return 0;
    }
    
    if(NULL == root->left && NULL == root->right ) {
      return 0;
    }
  
      if(root->left && root->right) {
        return helper(root->left,  1) + helper(root->right, 0);
      } else if(root->right){
        return helper(root->right, 0);
      } else  {
        return helper(root->left, 1);
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


  cout << S.sumOfLeftLeaves(T4);

  TreeNode *S1 = new TreeNode(1, NULL, NULL);
  TreeNode *S3 = new TreeNode(3, NULL, NULL);
  TreeNode *S5 = new TreeNode(5, NULL, NULL);
  TreeNode *S2 = new TreeNode(2, S1, S3);
  TreeNode *S6 = new TreeNode(6, S5, NULL);
  TreeNode *S4 = new TreeNode(4, S2, S6);
  cout << S.sumOfLeftLeaves(S4);
  return 0;
}

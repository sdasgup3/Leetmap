/* 
 * Problem Description
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 * Solution
 *
 *You cannot have 
  int minDepth(TreeNode *root) {  
    if(!root) {
      return 0;
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));

  }

  Because the queastion is regarding path to leaf
  For 5
     /
   8 
  This will return 1, but the asnswer is 2

Tags:
Tree


*/

#include"header.h"
class Solution {

public:
  int minDepth(TreeNode *root) {  
    if(!root) {
      return 0;
    }

    if(!root->left && !root->right) {
      return 1;
    }

    if(!root->left && root->right) {
      return 1 + minDepth(root->right);
    }
    if(root->left && !root->right) {
      return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));

  }
private:

};


int main() {
  Solution S;
   TreeNode *root = new TreeNode(5, new TreeNode(8, NULL, NULL), NULL);
  cout << S.minDepth(root);

  return 0;
}

/* Problem Description
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¿The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¿

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

#include"header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int val1 = p->val;
        int val2 = q->val;
        int rootVal = root->val;
        
        if (
            (val1 == rootVal || val2 == rootVal)   || 
                (val1 < rootVal && val2 > rootVal) || 
                (val2 < rootVal && val1 > rootVal)
           ){
            return root;
        } else if(val1 < rootVal && val2 < rootVal) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};




int main() {
  Solution S;

    TreeNode *root = new TreeNode(10, 
              new TreeNode(2, NULL, NULL), 
              new TreeNode(30, 
                  new TreeNode(14, NULL, NULL),
                  new TreeNode(50, NULL, NULL)
                          )
              );

  cout << (S.lowestCommonAncestor(root, root->left, root->right))->val;

  return 0;
}

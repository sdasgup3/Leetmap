/* Problem Description
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ¿The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¿

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    bool whichSide(TreeNode *root, TreeNode *p) {
        if(!root) return false;
        
        if(root == p) {
            return true;
        }
        
        return whichSide(root->left, p) || whichSide(root->right, p);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return root;
        
        if(p == root || q == root) {
            return root;
        }
        
        bool isPLeft = whichSide(root->left, p);
        bool isQLeft = whichSide(root->left, q);
        if(( true == isPLeft && false == isQLeft) || (false == isPLeft && true == isQLeft)) {
            return root;
        }
        
        if(isPLeft && isQLeft) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return  lowestCommonAncestor(root->right, p, q);
        }
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

  cout << S.lowestCommonAncestor(root, root->left, root->right)->val;

  return 0;
}

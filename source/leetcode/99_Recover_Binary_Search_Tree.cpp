/* Problem Description
 * Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
  private:
    TreeNode *first, *second, *previous;
public:
    Solution() {
      previous  = NULL;
      first  = NULL;
      second  = NULL;
    }
    void dostuff(TreeNode* root) {
      if(!previous) {
        previous = root; 
        return;
      }
      if(previous->val > root->val) {
        if(!first) {
          first = previous;
        } else {
          second = root;
        }
      }
      previous = root; 
    }
    void traverse(TreeNode *root) {
      if(root) {
        traverse(root->left);
        dostuff(root);
        traverse(root->right);
      }
    }
    void recoverTree(TreeNode* root) {
      traverse(root);

      int temp = first->val;
      first->val = second->val;
      second->val = temp;
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
  S.recoverTree(root);
  cout << root;

  return 0;
}

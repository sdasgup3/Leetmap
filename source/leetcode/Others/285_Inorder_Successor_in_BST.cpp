/* 
 * Problem Description
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
 *
 *
 *
 *
 * Solution

Tags:
Tree
*/

#include"header.h"
class Solution {
    private:
    stack<TreeNode*> S;
public: 
    void populate(TreeNode *root) {
        while(root) {
            S.push(root);
            root = root->left;
        }
    }
    TreeNode *findSucc() {
      if(S.empty()) {
        return NULL;
      }
        TreeNode* temp = S.top();
        S.pop();
        populate(temp->right);
        return temp;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        populate(root);
        TreeNode *next = findSucc();
        while(next && p != next) {
          next = findSucc();
        }
        return findSucc();
    }
};


int main() {
  Solution S;
  TreeNode *n6 = new TreeNode(6, NULL, NULL);
  TreeNode *n8 = new TreeNode(8, NULL, NULL);
   TreeNode *root = new TreeNode(5, 
              new TreeNode(2, NULL, NULL), 
              new TreeNode(7, 
                  n6,
                  n8
                          )
              );

  cout << root;

  TreeNode *res = S.inorderSuccessor(root,n8 );
  if(res)
  cout << res->val;
  else 
  cout << "nulla";

  return 0;
}

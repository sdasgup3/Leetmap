/* 
 * Problem Description
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
 *
 *
 *
 *
 * Solution
 * Most intuitive  Solution with min max ranges has many problems
 * min  = INT_MIN
 * max  = INT_MAX
 *
 * BUGGY1:
 * Consider the tree
 * [INT_MAX]
 * We will chack  in root->val == INT_MAX < max && INT_MAX > min, which return false even tough it is a valid case
 *
 *BUGGY2: Skip testing when min == INT_MIN or MAX==INT_MAX
 Consider the tree
 [INT_MAX, INT_MAX] there all the tests will be skiped
 * 
*/

#include"header.h"
class Solution {
public:
    //BUGGY
    bool val3(TreeNode *root, int min, int max) {
        if(!root) {
            return true;
        }
        if( ( min != INT_MIN && root->val <= min) || 
            ( max != INT_MAX && root->val >= max)) {
            return false;
        }
        if( (root->val <= min) || 
            (root->val >= max)) {
            return false;
        }
        
        return val3(root->left, min, root->val) && val3(root->right, root->val, max);
    }
    //BUGGY2
    bool val2(TreeNode *root, int min, int max) {
        if(!root) {
            return true;
        }
        if( ( min != INT_MIN && root->val <= min) || 
            ( max != INT_MAX && root->val >= max)) {
            return false;
        }
        
        return val2(root->left, min, root->val) && val2(root->right, root->val, max);
    }

    // NON BUGGY
    bool val1(TreeNode *root, TreeNode *min, TreeNode *max) {
        if(!root) {
            return true;
        }
        if( ( min != NULL && root->val <= min->val) || 
            ( max != NULL && root->val >= max->val)) {
            return false;
        }
        
        return val1(root->left, min, root) && val1(root->right, root, max);
    }
    // NON BUGGY
    bool val0(TreeNode *root, TreeNode *min, TreeNode *max) {
        if(!root) {
            return true;
        }
        if( ( min != NULL && root->val <= min->val) || 
            ( max != NULL && root->val >= max->val)) {
            return false;
        }
        
        return val0(root->left, min, root) && val0(root->right, root, max);
    }
    bool isValidBST1(TreeNode* root) {
      return val0(root, NULL, NULL);
    }

private:
    TreeNode *prev;
    bool res;
  public:
    void traverse(TreeNode *root, bool &res) {
      if(root) {
        traverse(root->left, res);
        if(prev && prev->val >= root->val && true == res) {
          res =false;
        }
        prev = root;
        traverse(root->right, res);
      }

    }

    bool isValidBST(TreeNode* root) {
      prev = NULL;
      res = true;
      traverse(root, res);    

      return res;
    }
};

int main() {
  Solution S;

   TreeNode *root = new TreeNode(5, 
              new TreeNode(40, NULL, NULL), 
              new TreeNode(7, 
                  new TreeNode(6, NULL, NULL),
                  new TreeNode(40, NULL, NULL)
                          )
              );

  cout << root;
cout << S.isValidBST(root);

  return 0;
}

/* Problem Description
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
  Solution:
         1
        / \
       2   5
      / \   \
     3   4   6

   while(root)  
     root_l = root->left;
     root_r = root->right;

     root->left = NULL;
     root->right = root_l;
     last = find_the_rightmost_non_null_node(root_l);
     last->right = root_r;
      
     root= root->right;

  

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
    Solution() {
    }
    void flatten(TreeNode* root) {
      while(root) {
        if(root->left) {
          TreeNode *tmpr = root->right;
          TreeNode *tmpl = root->left;
          root->left = NULL;
          root->right = tmpl;
          
          TreeNode *last = NULL;
          while(tmpl) {
            last = tmpl;
            tmpl = tmpl->right;
          }
          last->right = tmpr;
        }

        root = root->right;
      }

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
  S.flatten(root);
  cout << root;

  return 0;
}

/* Problem Description
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
    bool rec(TreeNode* root, int sum) {
        if(!root->left && !root->right) {
            return 0 == sum-root->val;
        }
        
         if(!root->left && root->right) {
            return rec(root->right, sum - root->val);
        }
        if(root->left && !root->right) {
            return rec(root->left, sum - root->val);
        }
         return rec(root->left, sum - root->val) || rec(root->right, sum - root->val) ;
      
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        
        if(!root->left && !root->right) {
            return 0 == sum-root->val;
        }
        
         if(!root->left && root->right) {
            return rec(root->right, sum - root->val);
        }
        if(root->left && !root->right) {
            return rec(root->left, sum - root->val);
        }
         return rec(root->left, sum - root->val) || rec(root->right, sum - root->val) ;
        
    }
};


int main() {
  Solution S;


  return 0;
}

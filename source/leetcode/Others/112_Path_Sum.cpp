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
    bool dfs(TreeNode* root, int sum) {
        if(!root) return false;
        
        if(0 == (sum - root->val)) {
            if(!root->left && !root->right) {
               
                return true;
             }
        }
        
        return dfs(root->left, sum - root->val) || dfs(root->right, sum - root->val);
    }
  
     bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};


int main() {
  Solution S;


  return 0;
}

/* 
 * Problem Description
 Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
 * Solution
 * Tags
 Tree
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
    vector<string> V;
public:
    void helper(TreeNode* root, string str) {
        str += to_string(root->val);
        
        if(!root->left && !root->right) { //this is sa leaf
            V.push_back(str);
            return;
        }
        
        str += "->";
        if(root->left && root->right) { //this is sa leaf
            helper(root->left, str);
            helper(root->right, str);
            return;
        }
        
        if(root->left) {
            helper(root->left, str);
            return;
        }
        
        if(root->right) {
            
            helper(root->right, str);
            return;
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return V;
        
        string str("");
        helper(root, str);
        
        return V;
    }
};


int main() {
  Solution S;

  vector<int> D({});

  S.ValidWordAbbr(D);

  return 0;
}

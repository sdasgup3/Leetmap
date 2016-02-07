/**
 * Definition for a binary tree node.
 */

#include<iostream>
using namespace std;


 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } treeNode;

class Solution {
public:
    int max;
    
    int rec_add(TreeNode* root, int val) {
        
        if(NULL == root) return 0;
        
        if(NULL == root->left && NULL == root->right) {
            return (10*val  + root->val);
        }
        
        return rec_add(root->left, 10*val + root->val) + 
            rec_add(root->right, 10*val + root->val);
        
    }
    int sumNumbers(TreeNode* root) {
        return rec_add(root,0);
    }
};
int main() {
	Solution S;

        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
    
	std::cout << S.sumNumbers(root) << "\n";

}


#include<iostream>
#include<vector>

using namespace std;


 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } treeNode;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root) return false;
        
        if(root->val == sum && NULL == root->left && NULL == root->right) return true;
        //if(root->val > sum) return false;
        
        int temp  = sum - root->val;
        
        return hasPathSum(root->left, temp)
                || hasPathSum(root->right, temp);
    }
};

int main() {
	Solution S;

        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(-3);
        root->left->left = new TreeNode(1);
    
	std::cout << S.hasPathSum(root,0) << "\n";

}

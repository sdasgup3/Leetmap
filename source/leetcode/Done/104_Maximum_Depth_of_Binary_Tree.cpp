/* Problem Description
    a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Tags:
Tree
*/

#include"header.h"
class Solution {

public:

  int helper(TreeNode *root) {
    if (!root) {
      return 0;
    }

    return 1 + max(helper(root->left), helper(root->right));
  }

  int findH(TreeNode *root) {  
    if(!root) {
      return 0;
    }

    return 1 + max(helper(root->left), helper(root->right));
  }

  int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    
    return res;
}
private:

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

  cout << S.maxDepth(root);

  return 0;
}

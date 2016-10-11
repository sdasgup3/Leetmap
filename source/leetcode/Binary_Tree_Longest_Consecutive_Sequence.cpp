/* Problem Description
 * Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
  int max_count = 0 ;
public:
  Solution() : max_count(0) {}
    void helper(TreeNode *root, int prev_val, int count) {
      if(!root) {
        max_count = std::max(count, max_count);
        return;
      }

      if(root->val  == prev_val + 1) {
        helper(root->left, root->val, count +1);
        helper(root->right, root->val, count +1);
      } else {
        max_count = std::max(count, max_count);
        helper(root->left, root->val, 1);
        helper(root->right, root->val, 1);
      }

    }

    int longestConsecutive(TreeNode* root) {
      helper(root->left, root->val, 1);
      helper(root->right, root->val, 1);
      return max_count;
        
    }
};


int main() {
  Solution S;

  TreeNode *T1 = new TreeNode(1, NULL, NULL);
  TreeNode *T3 = new TreeNode(3, NULL, NULL);
  TreeNode *T5 = new TreeNode(5, NULL, NULL);
  TreeNode *T7 = new TreeNode(7, NULL, NULL);
  TreeNode *T2 = new TreeNode(2, T1, T3);
  TreeNode *T6 = new TreeNode(6, T5, T7);
  TreeNode *T4 = new TreeNode(4, T2, T6);


  cout << S.longestConsecutive(T4);

  TreeNode *S1 = new TreeNode(1, NULL, NULL);
  TreeNode *S3 = new TreeNode(3, NULL, NULL);
  TreeNode *S5 = new TreeNode(5, NULL, NULL);
  TreeNode *S2 = new TreeNode(2, S1, S3);
  TreeNode *S6 = new TreeNode(6, S5, NULL);
  TreeNode *S4 = new TreeNode(4, S2, S6);
  cout << S.longestConsecutive(S4);
  return 0;
}

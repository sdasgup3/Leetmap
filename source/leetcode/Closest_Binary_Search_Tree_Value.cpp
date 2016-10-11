/* Problem Description
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.


Problem with initi max with INT_MIN or max with INT_MAX 
consider the one node BST; in this case min or max will still retain this custom put value which 
is non existant in the BST
*/

#include"header.h"
class Solution {
public:

    int helper(TreeNode* root, double target, int min, int max) {
      if(!root) {
        std::cout << min << " "  << max << "\n"; 
        return std::abs(target-min) < std::abs(target - max) ? min: max;     
      }

      if( target > root->val) {
        min = root->val;
        helper(root->right, target, min, max);
      } else {
        max  = root->val;
        helper(root->left, target, min, max);
      }

    }

    int closestValue(TreeNode* root, double target) {
      if(!root) {
        return -1;
      }
      int min, max;

      if(target > root->val) {
        min = max = root->val;
        //max = INT_MAX;
        return helper(root->right, target, min, max);
      } else {
        max = max = root->val;
        //min = INT_MAX;
        return helper(root->left, target, min, max);
      }
        
    }
};

int main() {
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  Solution S;

  TreeNode *T1 = new TreeNode(1, NULL, NULL);
  TreeNode *T3 = new TreeNode(3, NULL, NULL);
  TreeNode *T5 = new TreeNode(5, NULL, NULL);
  TreeNode *T7 = new TreeNode(7, NULL, NULL);
  TreeNode *T2 = new TreeNode(2, T1, T3);
  TreeNode *T6 = new TreeNode(6, T5, T7);
  TreeNode *T4 = new TreeNode(4, T2, T6);

  cout << S.closestValue(T4, 6.5) << "\n";
  cout << S.closestValue(T4, 3.4) << "\n";
  cout << S.closestValue(T4, 2.1)<< "\n";
  cout << S.closestValue(T4, 5.7)<< "\n";

  TreeNode *S0 = new TreeNode(0, NULL, NULL);
  cout << S.closestValue(S0, 2147483648.0)<< "\n";

  return 0;
}

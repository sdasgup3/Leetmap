/* Problem Description
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include"header.h"
class Solution {
  private:
    int sum;
public:
    Solution(): sum(0) {}

    void helper(TreeNode* root, string s) {

      if(NULL == root->left && NULL == root->right) {
        s  += std::to_string(root->val);
        cout << s << "\n";
        sum += std::stoi(s);
        return;
      }

      if(root->left && root->right) {
        helper(root->left,s + std::to_string(root->val) );
        helper(root->right,s + std::to_string(root->val) );
      } else if(root->left) {
        helper(root->left,s + std::to_string(root->val) );
      } else {
        helper(root->right,s + std::to_string(root->val) );
      }
    }

  int sumNumbers(TreeNode* root) {

    if(!root) {
      return sum;
    }

    if(NULL == root->left && NULL == root->right) {
      return root->val;
    }

      if(root->left && root->right) {
        helper(root->left,std::to_string(root->val) );
        helper(root->right,std::to_string(root->val) );
      } else if(root->left) {
        helper(root->left,std::to_string(root->val) );
      } else {
        helper(root->right,std::to_string(root->val) );
      }
    return sum;
        
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


  cout << S.sumNumbers(T4) << "\n";

  TreeNode *S1 = new TreeNode(1, NULL, NULL);
  TreeNode *S3 = new TreeNode(3, NULL, NULL);
  TreeNode *S5 = new TreeNode(5, NULL, NULL);
  TreeNode *S2 = new TreeNode(2, S1, S3);
  TreeNode *S6 = new TreeNode(6, S5, NULL);
  TreeNode *S4 = new TreeNode(4, S2, S6);
  cout << S.sumNumbers(S4) << "\n";
  return 0;
}

/* Problem Description
   Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

#include"header.h"
class Solution {
public:
    void rec (vector<TreeNode*> buffer) {
      int size = buffer.size();
      vector<TreeNode* > buffer2;
      for(int i = 0 ; i < size; i++) {
        TreeNode* root = buffer[i];
        if(root->left) {
          buffer2.push_back(root->left);
        }
        if(root->right) {
          buffer2.push_back(root->right);
        }
      }

      if(0 == buffer2.size()) {
        push(buffer);
      } else {
        rec(buffer2);
        push(buffer);
      }
      return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      if(!root) return R;

      vector<TreeNode*> buffer;
      buffer.push_back(root);
      rec(buffer);
        
      return R;
    }

    void push(vector<TreeNode*> B) {
      vector<int> S;
      for(int i = 0 ; i < B.size(); i++) {
        S.push_back(B[i]->val);
      }
      R.push_back(S);
    }
private:
    vector<vector<int>> R;
};


int main() {
  Solution S;

  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  cout << S.levelOrderBottom(root);
  


  return 0;
}

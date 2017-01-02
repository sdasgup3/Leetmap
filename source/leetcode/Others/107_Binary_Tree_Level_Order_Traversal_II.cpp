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

Tags:
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode *> buff1, buff2;
        vector<vector<int>> res;
        
        if(!root) return res;
        if(root) buff1.push_back(root);
        int sz = buff1.size();
        
        while(0 != sz) {
            vector<int> tmp;
            for(int i= 0 ; i< sz;i++) {
                tmp.push_back(buff1[i]->val);
                
                if(buff1[i]->left) {
                    buff2.push_back(buff1[i]->left);
                }
                
                if(buff1[i]->right) {
                    buff2.push_back(buff1[i]->right);
                }
            }
            
            res.push_back(tmp);
            buff1 = buff2;
            buff2.clear();
            sz = buff1.size();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

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

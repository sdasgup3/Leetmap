/* Problem Description
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

In each node store, numElem(LS) + numElems(RS) + 1
* 
*/

#include"header.h"

class Solution {
  private:
    int count;
    int soln;


public:
    Solution() : count(0) {}
  bool helper1(TreeNode *root, int k) {
    if(root) {
      if(true == helper(root->left,  k)) {
        return true;
      }
      count++;
      if(k == count) {
        soln = root->val;
        return true;
      }
      if(true == helper(root->right, k)) {
        return true;
      }
    }
      return false;
  }

  int helper(TreeNode *root, int k) {
    Stack<TreeNode *> S;
    S.push(root);
    int count = 0;
    int result = 0;

    while(!S.isempty()) {
      TreeNode *t = S.top();
      if(t != NULL) {
        S.pop();
        S.push(t->right);
        S.push(t);
        S.push(t->left);
      } else {
        count ++;
        S.pop();
        if(S.isempty()) {
          return result;
        }
        TreeNode *v = S.top();
        result = v->val;
        S.pop();
        if(count == k) {
          return result;
        }
      }
    }
          return result;
  }
  int kthSmallest(TreeNode* root, int k) {
     return helper(root, k);
  }
private:

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



  cout << S.kthSmallest(T4, 3);

  return 0;
}

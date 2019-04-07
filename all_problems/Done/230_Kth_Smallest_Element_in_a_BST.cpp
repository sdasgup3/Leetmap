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
  int kthSmallest1(TreeNode* root, int k) {
     return helper(root, k);
  }







  void fill(TreeNode *root) {
    while(root) {
      S.push(root);
      root = root->left;
    }
  }
  int kthSmallest(TreeNode *root, int k) {
    fill(root);
    int count = 0 ;
    while(1) {
      TreeNode *t = S.top();
      S.pop();
      count ++;
      fill(t->right);
      if(k == count) {
        return t->val;
      }
    }
  }

  int kthSmallest_follow_up(TreeNode *root, int k) {
    
    while(1) {
      int l_c = 0;
      if(root->left) {
        l_c = root->left->count;
      }
      if(k == l_c + 1) {
        return root->val;
      }

      if(k > (l_c +1) ) {
        k -= (l_c+1);
        root = root->right;
      } else {
        root = root->left;
      }
    }
  }
private:
    Stack<TreeNode*> S;

};

void bst_add(TreeNode **root, int n) {
    if(NULL == *root) {
      *root = new TreeNode(n, NULL, NULL, 1);
     return;
    } 

    (*root)->count++;
    if(n > (*root)->val ) {
      bst_add(&((*root)->right), n);
    } else {
      bst_add(&((*root)->left), n);
    }
}

int main() {
  Solution S;
  TreeNode* root = NULL;
  bst_add(&root, 4);
  bst_add(&root, 2);
  bst_add(&root, 6);
  bst_add(&root, 1);
  bst_add(&root, 3);
  bst_add(&root, 5);
  bst_add(&root, 7);
  
  for(int i = 1; i <= 7 ; i++) {
    cout << S.kthSmallest(root, i) << "\n";
    cout << S.kthSmallest_follow_up(root, i) << "\n";
  }

  return 0;
}

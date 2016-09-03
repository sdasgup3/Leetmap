/* Problem Description
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

#include"header.h"
class Solution {

public:

  int findHeightCheck(TreeNode* root, int & h) {
    if(!root) {
      h = 0;
      return true;
    }
    int h1, h2;
    bool b1  = findHeightCheck(root->left, h1);
    bool b2 = findHeightCheck(root->right, h2);
    h = std::max(h1,h2) + 1;
    return b1 & b2 & abs(h1-h2) <=1;
  }
  bool isBalanced(TreeNode* root) {  
    if(!root) return true;
    int h;

    return findHeightCheck(root, h) ;

  }
private:

};


int main() {
  Solution S;

  TreeNode* T = new TreeNode(1);
  T->left = new TreeNode(2);
  T->left->left = new TreeNode(3);
  T->right = new TreeNode(4);
  T->right->left = new TreeNode(5);
  //T->right->left->right = new TreeNode(6);

  std::cout << S.isBalanced(T);

  return 0;
}

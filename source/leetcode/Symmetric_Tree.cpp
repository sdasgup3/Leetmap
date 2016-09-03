/* Problem Description
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

Note that 3 and $ are not equal

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

*/

#include"header.h"
class Solution {

public:
  bool isMirrorItr(stack<TreeNode*> &S) {

    while(!S.empty()) {
      TreeNode* r1 = S.top(); 
      S.pop();
      TreeNode* r2 = S.top(); 
      S.pop();
      
      if((r1 && !r2) || (!r1 && r2)) {
        return false;
      } else {
        //both null or both non -null
        if(!r1 && !r2) {
          continue;
        } else {
          if( r1->val != r2->val) {
            return false;
          }
          S.push(r1->left);
          S.push(r2->right);
          S.push(r1->right);
          S.push(r2->left);
        }
      }
    }

    return true;
  }
  bool isSymmetricItr(TreeNode *root) {  
    if(!root) return true;

    stack<TreeNode*> S;
    S.push(root->left); S.push(root->right);

    return isMirrorItr(S);

  }

  bool isMirror(TreeNode *r1, TreeNode* r2) {

    if((r1 && !r2) || (!r1 && r2)) {
      return false;
    } else {
      //both null or both non -null
      if(!r1 && !r2) {
        return true;
      } else {
        return r1->val == r2->val && isMirror(r1->left, r2->right) && isMirror(r1->right , r2->left);
      }
    }
  }

  bool isSymmetric(TreeNode *root) {  
    if(!root) return true;

    return isMirror(root->left, root->right);

  }
private:

};


int main() {
  Solution S;

  vector<int> v = {1,2,2,3,4,5,3};

  TreeNode* T = CreateBT(v);
  std::cout << T;
  std::cout << S.isSymmetricItr(T);

  return 0;
}

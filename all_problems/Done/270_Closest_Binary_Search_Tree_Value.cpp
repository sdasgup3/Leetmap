/* Problem Description
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.


Problem with initi max with INT_MIN or max with INT_MAX 
consider the one node BST; in this case min or max will still retain this custom put value which 
is non existant in the BST

Solution:
maintain min max for each node
avoid min == max == INT_MAX/INT_MIN

because at the end its diff to ficure out if INT_MIN or INT_MAX 
actually arise in the BST of its the same init values

Wither use root->val as init val or use NULL

Tags:
Tree
*/

#include"header.h"
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        int min = root->val;
        int max = root->val;
        
        while(root) {
            if(target == root->val) {
                return root->val;
            } 
            if(target > root->val) {
                min = root->val;
                root = root->right;
            } else {
                max = root->val;
                root = root->left;
            }
        }
        
        return abs(target-min) < abs(target - max) ? min: max;
        
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        TreeNode* min = NULL;
        TreeNode* max = NULL;
        
        while(root) {
            if(target == root->val) {
                return root->val;
            } 
            if(target > root->val) {
                min = root;
                root = root->right;
            } else {
                max = root;
                root = root->left;
            }
        }
        
        if(!min) return max->val;
        if(!max) return min->val;
        
        return abs(target-min->val) < abs(target - max->val) ? min->val: max->val;
        
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

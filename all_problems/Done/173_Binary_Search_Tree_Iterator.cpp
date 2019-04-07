/* Problem Description
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

#include"header.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    private:
    stack<TreeNode *> S;
public:
    void populate(TreeNode *root) {
        while(root) {
            S.push(root);
            root = root->left;
        }
    } 
    BSTIterator(TreeNode *root) {
        populate(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return S.empty() == false;
        
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * temp = S.top();
        S.pop();
        populate(temp->right);
        return temp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


int main() {
  Solution S;

  return 0;
}

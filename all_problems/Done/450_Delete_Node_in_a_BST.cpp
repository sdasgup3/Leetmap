/* 
 * Problem Description
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
 *
 *
 *
 *
 * Solution
    5
   / \
  3   6
 / \   \
2   4   7

Let delete node   = 3 
find the prev also = 5


*/

#include"header.h"
class Solution {
public:
    TreeNode **search(TreeNode **root, int key) {
      if(!(*root)) {
        return NULL;
      }

      if((*root)->val == key) {
        return root;
      }
      
      if((*root)->val < key) {
        return search(&((*root)->right), key);
      } else {
        return search(&((*root)->left), key);
      }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
      TreeNode **found = search(&root, key);

      if(found == NULL) {
        return root;
      }

      TreeNode *tobedeleted = *found;

      TreeNode *left = (*found)->left;
      TreeNode *right = (*found)->right;

      if(right) {

        TreeNode *last  = NULL;
        TreeNode *runner  = right;
        while(runner) {
          last = runner;
          runner = runner->left;
        }

        last->left = left;

        *found = right;
      } else if(left) {
        *found = left;
      } else {
        *found = NULL;
      }

      delete tobedeleted;
      return root;
    }
};

int main() {
  Solution S;

   TreeNode *root = new TreeNode(5, 
              new TreeNode(2, new TreeNode(1, NULL, NULL), NULL), 
              new TreeNode(7, 
                  new TreeNode(6, NULL, NULL),
                  new TreeNode(8, NULL, NULL)
                          )
              );

  cout << root;

  cout << S.deleteNode(root, 2);

  return 0;
}

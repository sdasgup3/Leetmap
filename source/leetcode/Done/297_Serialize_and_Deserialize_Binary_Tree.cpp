/* 
 * Problem Description
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 * Solution

Case 1: Find pre/inorder, and serialize itto string
DO NOT WORK
  2
 / \
 2  2

In: 222
Pre:222
Using the algo we will get 
  2
    \
    2
     \
      2

not matching.

WHY??

first root is 2 (from pre)
search that in Inorder and we get index 0 of Inorder as the result of the search whereas the actual is 1

 * Tags

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string s("");
      if(!root) return s;

      queue<TreeNode *> Q;
      Q.push(root);

      while(!Q.empty()) {

        TreeNode *r = Q.front();
        Q.pop();

        if(!r) {
          s += "N#";
          continue;
        }
        
        s += to_string(r->val);
        s += "#";

        Q.push(r->left);
        Q.push(r->right);
      }

      cout << s << "\n";
      return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

      if(data == "") {
        return NULL;
      }

      int first = 0;
      int ind = data.find('#', first);
      TreeNode *root = new TreeNode(stoi(data.substr(first, ind-1 -first +1)));
      first = ind+1;

      queue<TreeNode *> Q;
      Q.push(root);

      while(!Q.empty()) {
        TreeNode *r = Q.front();
        Q.pop();

        ind = data.find('#', first);
        if(data[ind -1] == 'N') {
          r->left = NULL;
        } else {
          r->left = new TreeNode(stoi(data.substr(first, ind-1 -first +1)));
          Q.push(r->left);
        }
        first  = ind+1;

        
        ind = data.find('#', first);
        if(data[ind -1] == 'N') {
          r->right = NULL;
        } else {
          r->right = new TreeNode(stoi(data.substr(first, ind-1 -first +1)));
          Q.push(r->right);
        }
        first  = ind+1;
      }

      return root;
        
    }

};


int main() {
   TreeNode *root = new TreeNode(1, 
              new TreeNode(2, NULL, NULL), 
              new TreeNode(2,  
                  new TreeNode(6, NULL, NULL),
                  new TreeNode(4, NULL, NULL)
                          )
              );

   cout << root;

 Codec codec;
 cout << codec.deserialize(codec.serialize(root));

  return 0;
}

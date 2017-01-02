/* 
 * Problem Description
 * Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 *
 *
 *
 *
 * Solution
 * Use level order  traversal and for each level connect all the members
*/

#include"header.h"
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> buff1, buff2;
        if(root)
            buff1.push_back(root);
        int sz = buff1.size();
        while(0 != sz) {
            
            //connect
            buff1[sz-1]->next = NULL;
            for(int i = 0 ; i <= sz-2; i++) {
                buff1[i]->next = buff1[i+1];
            }
            
            for(int i = 0 ; i < sz ; i++) {
                if(buff1[i]->left) {
                    buff2.push_back(buff1[i]->left);
                }
                
                if(buff1[i]->right) {
                    buff2.push_back(buff1[i]->right);
                }
            }                
            
            buff1 = buff2;
            buff2.clear();
            sz = buff1.size();
        }
    }
};

int main() {
  Solution S;

  return 0;
}

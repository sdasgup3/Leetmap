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

        vector<TreeLinkNode*> buffer1;
        vector<TreeLinkNode*> buffer2;
        if(root)
            buffer1.push_back(root);
        int sz =     buffer1.size();
        vector<int> res;

        while(sz) {
            //connect
            TreeLinkNode* next  = NULL;
            for(int i = sz-1 ; i >=0 ; i--) {
                buffer1[i]->next = next;
                next = buffer1[i];
            }
            
            for(auto n : buffer1) {
                if(n->left)
                    buffer2.push_back(n->left);
                if(n->right)
                    buffer2.push_back(n->right);
            }
            buffer1 = buffer2;
            buffer2.clear();
            sz = buffer1.size();
            cout << sz << "\n";
        } 
        
        return ;
    }
};

int main() {
  Solution S;

  return 0;
}

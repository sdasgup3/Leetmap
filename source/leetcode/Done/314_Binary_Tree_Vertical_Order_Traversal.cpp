/* 
 * Problem Description
 Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
 * Solution

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
    \
     \10
       \
        \
         100  

  First job is to find the leftw and rightw wrt 3
  Use dfs or bfs; store a pair (root, posn)
  start with (3,0)

for every left move do +1 for right move do -1
also keep track of max positive and min negative value
max positive val == leftw
min positive value  == rightw

   0
  /\
 /  \
 +1  -1
    /\
   /  \
  0   -2
    \
     \-2
       \
        \
         -3

leftw  = 1
rightw = -3

So we will be having leftw + 1 + rightw columns.

colum [leftw==1] = 3,15
colm[0] = 9
colm[2] = 7,10
colm[3] = 100

Here if we do dfs then 10 will beb visited before 7 and the problem say that the visit should be from top to bottom
so we will do bfs
again we will store pair{root, colm} in queue starting with {3, leftw==1}





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
class Solution {
public:
    void fill(TreeNode *root,  int c, vector<vector<int>> &res) {
        queue<pair<TreeNode*, int>>Q;
        Q.push({root, c});
        
        while(!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            
            root = p.first;
            c = p.second;
            
            res[c].push_back(root->val);
            if(root->left)
                Q.push({root->left, c-1});
            if(root->right)
                Q.push({root->right, c+1});
        }
        
    }
    
    void findwidth(TreeNode *root, int &left, int &right) {
        queue<pair<TreeNode*, int>>Q;
        Q.push({root, 0});
        
        left = 0;
        right = 0;
        int  c;
        
        
        while(!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            
            root = p.first;
            c = p.second;
            
            left = max(left, c);
            right = min(right, c);
            
            if(root->left)
                Q.push({root->left, c+1});
            if(root->right)
                Q.push({root->right, c-1});
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        //Find left width & right width
        int leftw, rightw;
        findwidth(root, leftw, rightw);
       
        //Init the matrix
        int c = 1+ leftw+(-1*rightw);
        res.resize(c);
        
        fill(root,  leftw, res);
        
        return res;
        
    }
};


int main() {
  Solution S;


  return 0;
}

#include "header.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct CNode {
    TreeNode* node;
    //int depth;
    int posn;
    
    CNode(TreeNode* _n, int _posn) {
        node = _n;
        posn = _posn;
    }
};

class Solution {
    int M;
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<CNode*> Q;
        if(!root) return 0;
        M = 1;
        
        CNode* R = new CNode(root, 1);
        Q.push(R);
        Q.push(NULL);
        
        vector<CNode*> V;
        while(!Q.empty()) {
            
            if(Q.size() == 2) {
                CNode* T = new CNode(Q.front()->node, 1);
                Q.push(T);
                Q.push(NULL);
                Q.pop();
                Q.pop();
            }
            
            auto n = Q.front();
            Q.pop();
            
            
            if(n == NULL) {
                M = std::max(M, V[V.size()-1]->posn -  V[0]->posn  +1);
                V.clear();
                if(Q.empty()) break;
                Q.push(NULL);
                
            } else {
                V.push_back(n);
                if(n->node->left) {
                    CNode* L = new CNode(n->node->left, n->posn * 2);
                    Q.push(L);
                }
                
                if(n->node->right) {
                    CNode* R = new CNode(n->node->right, n->posn * 2  +1);
                    Q.push(R);
                }
            }
        }
        
        return M;
        
    }
};

int main() {
  Solution S;
  cout << S.widthOfBinaryTree(NULL);
}

#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<climits>
#include <algorithm>
#include <sstream> // isstringstream
#include <iterator> //istream_iterator


using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* CreateBT(vector<int> &v) {  

    int n = v.size();
    TreeNode* root = NULL;

    if(0 == n) {
      root;
    }

    queue<TreeNode*> Q;

    root = new TreeNode(v[0]);
    Q.push(root);

    for(int i = 1 ; i < n ; i ++ ) {
      TreeNode *t = Q.front();
      if(t->left == NULL) {
        t->left = new TreeNode(v[i]);
      } else if(t->right == NULL) {
        t->right = new TreeNode(v[i]);
        Q.pop();
        Q.push(t->left);
        Q.push(t->right);
      } 
    }
    return root;
  }


template <typename T>
ostream& operator << (ostream& OS, vector<T> V) {
  for(int i = 0 ; i < V.size(); i ++) {
    OS << V[i] << " " ;
  }
  OS << "\n" ;
}

ostream& operator<< (ostream& OS, TreeNode *BT) {

  if(NULL  == BT) return OS;

  vector<TreeNode*> Buffer1; 
  vector<TreeNode*> Buffer2; 

  Buffer1.push_back(BT);

  while(false == Buffer1.empty()) {
    for(int i = 0 ; i < Buffer1.size(); i++) {
      OS << Buffer1[i]->val << " " ;  
      if(NULL != Buffer1[i]->left) {
        Buffer2.push_back(Buffer1[i]->left);
      }
      if(NULL != Buffer1[i]->right) {
        Buffer2.push_back(Buffer1[i]->right);
      }
    }

    Buffer1 = Buffer2;
    Buffer2.clear();
    OS <<  "\n " ;  
  }
}
 
const char C = ' ';

template <typename T>
class Stack {
  private:
    vector<T> V;
    int sp;

  public:
    Stack() {
         sp = -1;
    }

    void push(T val) {
      V.push_back(val);
      sp++;
    }

    void pop() {
      if(-1 == sp) {
        cerr << "Cannot pop\n";
        return;
      }
      V.pop_back();
      sp--;
    }

     T top() {
      if(-1 == sp) {
        cerr << "Cannot top\n";
        return T();
      }
      return V[sp];
    }

    bool isempty() {
      return sp == -1;
    }
};

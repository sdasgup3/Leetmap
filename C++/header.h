#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator> //istream_iterator
#include <map>
#include <queue>
#include <sstream> // isstringstream
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T> class ListNode {
public:
  ListNode() { next = NULL; }
  T val;
  ListNode *next;
  ListNode(T x) : val(x), next(NULL) {}
};

template <typename T> class TreeLinkNode {
public:
  TreeLinkNode() { left = right = next = NULL; }
  T val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(T x) : val(x), left(NULL), right(NULL), next(NULL) {}
  TreeLinkNode(T xx, TreeLinkNode *x, TreeLinkNode *y, TreeLinkNode *z)
      : val(xx), left(x), right(y), next(z) {}
};

template <typename T> class TreeNode {
public:
  TreeNode() { left = right = NULL; }
  T val;
  TreeNode *left;
  TreeNode *right;
  int count; // leftsubtree + 1 + rightsubtree
  TreeNode(T x) : val(x), left(NULL), right(NULL), count(0) {}
  TreeNode(T x, TreeNode *l, TreeNode *r)
      : val(x), left(l), right(r), count(0) {}
  TreeNode(int x, TreeNode *l, TreeNode *r, int c)
      : val(x), left(l), right(r), count(c) {}
};

template <typename T> class Testing {
public:
  Testing() {}
  ListNode<T> listnode;
  TreeLinkNode<T> treelinknode;
  TreeNode<T> treenode;
  vector<T> v;
};

template <typename T> ostream &operator<<(ostream &OS, vector<T> V) {
  for (int i = 0; i < V.size(); i++) {
    OS << V[i] << " ";
  }
  OS << "\n";
}

template <typename T> ostream &operator<<(ostream &OS, vector<vector<T>> V) {
  for (int i = 0; i < V.size(); i++) {
    OS << V[i] << " ";
  }
  OS << "\n";
}

template <typename T> ostream &operator<<(ostream &OS, pair<T, T> P) {
  OS << P.first << " " << P.second;
  OS << "\n";
}

template <typename T> ostream &operator<<(ostream &OS, ListNode<T> *root) {
  while (root) {
    OS << root->val << " ";
    root = root->next;
  }
  OS << "\n";
}

template <typename T> ostream &operator<<(ostream &OS, TreeNode<T> *BT) {

  if (NULL == BT)
    return OS;

  vector<TreeNode<T> *> Buffer1;
  vector<TreeNode<T> *> Buffer2;

  Buffer1.push_back(BT);

  while (false == Buffer1.empty()) {
    for (int i = 0; i < Buffer1.size(); i++) {
      OS << Buffer1[i]->val << " ";
      if (NULL != Buffer1[i]->left) {
        Buffer2.push_back(Buffer1[i]->left);
      }
      if (NULL != Buffer1[i]->right) {
        Buffer2.push_back(Buffer1[i]->right);
      }
    }

    Buffer1 = Buffer2;
    Buffer2.clear();
    OS << "\n ";
  }
}

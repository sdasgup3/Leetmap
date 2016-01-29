#include<iostream>
#include<vector>
#include<list>
#include<climits>

class btnode {
  public:
    btnode(int a, btnode* l, btnode* r, btnode* p): v(a), left(l), right(r), parent(p) { }
    int v;
    btnode* left;
    btnode* right;
    btnode* parent;
};


btnode*
successor(btnode* root, btnode* node) 
{
  if(NULL == node) { 
    return NULL;
  }

  if(node->right) {
    if(node->right->left) {
      btnode* leftmost = node->right->left;
      while(leftmost->left) {
        leftmost = leftmost->left;
      }
      return leftmost;
    } else {
      return node->right;
    }
  } else {
    btnode* temp = node;
    btnode* parent = node->parent;
    while(parent && parent->right == temp) {
      temp = parent;
      parent = parent->parent;
    }
    return parent;
  }
}

int main()
{
  btnode* root  = new btnode(20, NULL,NULL, NULL);
  btnode* l  = new btnode(10, NULL,NULL, root);
  btnode* r  = new btnode(33, NULL,NULL, root);
  root->left = l;
  root->right = r;

  btnode* l1  = new btnode(9, NULL,NULL, l);
  btnode* r1  = new btnode(15, NULL,NULL, l);
  l->left = l1;
  l->right = r1;
  l1->left  = new btnode(8, NULL,NULL, l1);
  l1->right  = NULL;
  r1->left  = NULL;
  r1->right  = new btnode(19, NULL,NULL, r1);

  btnode* l2  = new btnode(26, NULL,NULL, r);
  btnode* r2  = new btnode(37, NULL,NULL, r);
  r->left = l2;
  r->right = r2;
  l2->right  = NULL;
  l2->left  = NULL;
  r2->left  = new btnode(34, NULL,NULL, r2);
  r2->right  = new btnode(38, NULL,NULL,r2);

  std::cout << "Succ of " << root->v << " : " << successor(root, root)->v << "\n";
  std::cout << "Succ of " << root->left->v << " : " << successor(root, root->left)->v << "\n";
  std::cout << "Succ of " << root->left->left->v << " : " << successor(root, root->left->left)->v << "\n";
  std::cout << "Succ of " << root->right->v << " : " << successor(root, root->right)->v << "\n";
  std::cout << "Succ of " << root->right->left->v << " : " << successor(root, root->right->left)->v << "\n";
  std::cout << "Succ of " << root->left->left->left->v << " : " << successor(root,root->left->left->left )->v << "\n";
  std::cout << "Succ of " << root->left->right->right->v << " : " << successor(root,root->left->right->right )->v << "\n";

  return 0;
}

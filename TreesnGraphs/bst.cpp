#include<iostream>


typedef struct _Node{
  int v;
  struct _Node* left;
  struct _Node* right;
} node;


void
insert(node** root, int v) {
  node* n = new node;
  n->v = v;
  n->left = NULL;
  n->right = NULL;

  if(NULL  == *root) {
    *root = n;
    return;
  }

  if(v <= (*root)->v) {
    if((*root)->left) {
      insert(&((*root)->left), v);
    } else {
      (*root)->left = n;
    }
  } else{
    if((*root)->right) {
      insert(&((*root)->right), v);
    } else {
      (*root)->right = n;
    }
  }
}

void
inorder(node* root) {
  if(NULL == root) return;

  inorder(root->left);
  std::cout << root->v << " "; 
  inorder(root->right);
}

int main()
{
  node* root = NULL;

  insert(&root,8);
  insert(&root,4);
  insert(&root,10);
  insert(&root,2);
  insert(&root,6);
  insert(&root,20);

  inorder(root);
  std::cout << " \n"; 

  return 0;
}

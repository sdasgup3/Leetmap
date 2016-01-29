#include<iostream>


typedef struct _Node{
  int v;
  struct _Node* left;
  struct _Node* right;
} node;


void
insert(node** root, int v) {

  if(NULL  == *root) {
    node* n = new node;
    n->v = v;
    n->left = NULL;
    n->right = NULL;
    *root = n;
    return;
  }

  if(v <= (*root)->v) {
    if((*root)->left) {
      insert(&((*root)->left), v);
    } else {
      node* n = new node;
      n->v = v;
      n->left = NULL;
      n->right = NULL;
      (*root)->left = n;
    }
  } else{
    if((*root)->right) {
      insert(&((*root)->right), v);
    } else {
      node* n = new node;
      n->v = v;
      n->left = NULL;
      n->right = NULL;
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
void 
deleteBST(node* root)
{

  if(NULL == root) {
    return;
  }
  deleteBST(root->left);
  deleteBST(root->right);
  delete root;
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
  deleteBST(root);


  return 0;
}

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

int
sum(node* root) {
  if(NULL == root) return 0;

  return sum(root->left) + root->v + sum(root->right);

}

int
minpath_sum(node* root) {
  if(NULL == root) return 0;

  int left_sum = minpath_sum(root->left);
  int right_sum = minpath_sum(root->right);

  if(left_sum <= right_sum) {
    return root->v + left_sum;
  } else {
    return root->v + right_sum;
  }
}

int main()
{
  node* root = NULL;

  insert(&root,8);
  insert(&root,7);
  insert(&root,10);
  insert(&root,6);
  insert(&root,8);

  inorder(root);
  std::cout << " \n"; 

  std::cout << "Sum " << sum(root) << "\n"; 
  std::cout << "Min path sum " << minpath_sum(root) << "\n"; 

  return 0;
}

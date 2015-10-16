#include<iostream>
#include<climits>


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

  if(NULL == root) {
    return 0;
  }

  if(NULL  == root->left && NULL == root->right) {
    return root->v;
  }
  if(NULL  == root->left && NULL != root->right) {
    return root->v + minpath_sum(root->right);
  }
  if(NULL  != root->left && NULL == root->right) {
    return root->v + minpath_sum(root->left);
  }
  if(NULL  != root->left && NULL != root->right) {
    int left_sum = minpath_sum(root->left);
    int right_sum = minpath_sum(root->right);
    return root->v + std::min(left_sum, right_sum);
  }
}


void 
printMinPath(node* root, node* target) {
  if(NULL == root) return;

  std::cout << " " << root->v ;
  if(root == target) {
    std::cout << "\n ";
    return;
  }

  if(target->v <= root->v) {
    printMinPath(root->left, target);
  } else {
    printMinPath(root->right, target);
  } 
}

void
minpath_sum_v2(node* root, int* min_sum, int current, node** min_leaf) {

  if(NULL == root) {
    return ;
  }

  current += root->v; 

  if(NULL  == root->left && NULL == root->right) {
    if(current < *min_sum) {
      *min_sum = current;
      *min_leaf = root;
    }
    return ;
  }

  minpath_sum_v2(root->left, min_sum, current, min_leaf);
  minpath_sum_v2(root->right, min_sum, current, min_leaf);
}

void
deleteBST(node * root) {
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
  insert(&root,7);
  insert(&root,10);
  insert(&root,6);
  insert(&root,8);

  inorder(root);
  std::cout << " \n"; 

  std::cout << "Min path sum " << minpath_sum(root) << "\n"; 
  int min_sum = INT_MAX;
  node* min_leaf = NULL;
  minpath_sum_v2(root, &min_sum, 0, &min_leaf);
  std::cout << "Min path sum " << min_sum <<  "\n"; 
  printMinPath(root, min_leaf);
  deleteBST(root);

  root = NULL;

  insert(&root,10);
  insert(&root,11);
  insert(&root,12);
  insert(&root,13);
  insert(&root,14);
  inorder(root);
  std::cout << " \n"; 
  std::cout << "Min path sum " << minpath_sum(root) << "\n"; 
  min_sum = INT_MAX;
  min_leaf = NULL;
  minpath_sum_v2(root, &min_sum, 0, &min_leaf);
  std::cout << "Min path sum " << min_sum <<  "\n"; 
  printMinPath(root, min_leaf);
  deleteBST(root);

  root = NULL;
  insert(&root,10);
  insert(&root,-2);
  insert(&root,7);
  insert(&root,13);
  insert(&root,14);
  inorder(root);
  std::cout << " \n"; 
  std::cout << "Min path sum " << minpath_sum(root) << "\n"; 
  min_sum = INT_MAX;
  min_leaf = NULL;
  minpath_sum_v2(root, &min_sum, 0, &min_leaf);
  std::cout << "Min path sum " << min_sum <<  "\n"; 
  printMinPath(root, min_leaf);
  deleteBST(root);

  return 0;
}

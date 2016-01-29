
#include<iostream>

typedef struct _Node {
  int data;
  struct _Node* left;
  struct _Node* right;
} node;



void 
insert(node** root, int data)
{

  if(NULL == *root) {
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    *root = n;
  } else {
    if(data <= (*root)->data) {
      if((*root)->left) {
        insert(&((*root)->left), data);
      } else {
        node* n = new node;
        n->data = data;
        (*root)->left = n;
      }
    } else {
      if((*root)->right) {
        insert(&((*root)->left), data);
      } else {
        node* n = new node;
        n->data = data;
        (*root)->right = n;
      }
    }
  }
}

void minBST(node** root, int *arr, int start, int end)
{
  if(start > end) {
    return;
  }

  int mid = start + (end - start)/2;
  insert(root, arr[mid]);

  //left half
  int left_end = mid -1;
  minBST(&((*root)->left), arr, start, left_end);

  //right half
  int right_start = mid +1;
  minBST(&((*root)->right), arr, right_start, end);
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

void 
print(node* root)
{

  if(NULL == root) {
    return;
  }
  print(root->left);
  std::cout << " "<< root->data  ;
  print(root->right);
  delete root;
}

int main()
{
  node* root = NULL;
  int arr[] = {1,2,3,4,5,6,7,8,9};

  int end = sizeof(arr)/sizeof(arr[0]);
  minBST(&root, arr, 0, end-1); 
  print(root);
}

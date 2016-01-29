#include<iostream>

class bstNode {
  public:
    bstNode(int a, bstNode* l, bstNode* r): value(a), left(l), right(r), leftchidren(0) { }
    int value;
    bstNode* left;
    bstNode* right;
    int leftchidren;
};
bstNode* root = NULL;

void
insert(bstNode** root, int k) {

  if(NULL == *root) {
    bstNode* n = new bstNode(k, NULL, NULL);
    *root = n;
    return;
  }

  if(k <= (*root)->value) {
    (*root)->leftchidren ++;
    insert(&((*root)->left), k);
  } else {
    insert(&((*root)->right), k);
  }
}



int
bstSearch(bstNode* root, int k, int &count) {
  if(NULL == root) {
    return count;
  }

  if(root->value == k) {
    count +=  root->leftchidren;
  } else if(k <= root->value){
    bstSearch(root->left, k, count);
  } else {
    count += root->leftchidren + 1;
    bstSearch(root->right, k, count);
  }
}

int
getRank(int k) {
  int count = 0;
  bstSearch(root, k, count);
  return count;
}


int main()
{
  insert(&root, 20);
  insert(&root, 15);
  insert(&root, 25);
  insert(&root, 10);
  insert(&root, 23);
  insert(&root, 5);
  insert(&root, 13);
  insert(&root, 24);

  int k;

  k = 20; std::cout << k << " " << getRank(k) << "\n";
  k = 15; std::cout << k << " " <<getRank(k) << "\n";
  k = 25; std::cout << k << " " <<getRank(k) << "\n";
  k = 10; std::cout << k << " " <<getRank(k) << "\n";
  k = 23; std::cout << k << " " <<getRank(k) << "\n";
  k = 5; std::cout  << k << " " <<getRank(k) << "\n";
  k = 13; std::cout << k << " " <<getRank(k) << "\n";
  k = 24; std::cout << k << " " <<getRank(k) << "\n";

}


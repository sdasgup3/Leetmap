#include<iostream>
#include<vector>
#include<list>
#include<climits>

class btnode {
  public:
    btnode(int a, btnode* l, btnode* r): value(a), left(l), right(r) { }
    int value;
    btnode* left;
    btnode* right;
};


int
LS(btnode* root, btnode* parent, int len) 
{
  if(NULL == root) {
    return 0;
  }

  int length;
  if(NULL == parent) {
    length = 1;
  } else if(parent->value + 1 == root->value) {
    length = len + 1;
  } else {
    length = 1;
  }
  
  return std::max(length, std::max(LS(root->left, root, length), LS(root->right, 
          root, length)));
}

int main()
{
  btnode* root = new btnode(1, 
            NULL,
            new btnode(3, 
              new btnode(2, NULL,NULL),
              new btnode(4, 
                NULL,
                new btnode(5, NULL,NULL))));

  std::cout << LS(root, NULL, 0) << "\n";

  root = NULL;
  root = new btnode(2, 
            NULL,
            new btnode(3, 
              new btnode(2, 
                new btnode(1, NULL, NULL),
                NULL),
              NULL));
  std::cout << LS(root, NULL, 0) << "\n";


  return 0;
}

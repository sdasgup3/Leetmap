#include<iostream>
#include<vector>
#include<list>

class btnode {
  public:
    btnode(int a, btnode* l, btnode* r): v(a), left(l), right(r) { }
    int v;
    btnode* left;
    btnode* right;
};

int checkHeight(btnode* root) {
  if(NULL == root) return 0;

  int left_h = checkHeight(root->left);
  if(-1 == left_h) {
    return -1;
  }
  int right_h = checkHeight(root->right);
  if(-1 == right_h) {
    return -1;
  }

  if(std::abs(left_h - right_h) > 1) {
    return -1;
  } 

  return std::max(left_h, right_h)  + 1;
}

int main()
{
  btnode* root = new btnode(1, 
            new btnode(2, 
              new btnode(4, 
                new btnode(8, NULL,NULL),
                NULL),
              new btnode(5, 
                NULL,
                new btnode(9, NULL,NULL))),
            new btnode(3, 
              new btnode(6, 
                new btnode(10, NULL,NULL),
                new btnode(11, NULL,NULL)), 
              NULL));

  std::cout << ((checkHeight(root) == -1) ? false: true) << "\n " ;
  return 0;
}

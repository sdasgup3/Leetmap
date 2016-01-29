/*check is two binary trees are mirrors*/


#include<iostream>
using namespace std;

class btnode {
  public:
    int value;
    btnode* left;
    btnode* right;
    btnode(int v, btnode* l, btnode* r) { 
      value = v;
      left = l;
      right = r;
    }

};

bool isMirror(btnode* root1, btnode* root2) {

  if(NULL == root1 && NULL == root2) {
    return true;
  }

  if(( NULL == root1 && NULL != root2) || 
      (NULL == root2 && NULL != root1) ||
      (root1->value != root2->value)) {
    return false;
  } 

  if(true == isMirror(root1->left, root2->right)
        && true == isMirror(root1->right, root2->left)) {
      return true;
  } else {
    return false;
  }

}

int main()
{
  btnode* root1 = new btnode(1, 
                  new btnode(2, new btnode(4, NULL, NULL) , new btnode(5, NULL, NULL)),
                  new btnode(6, NULL, NULL)
                  );

  btnode* root2 = new btnode(1, 
                  new btnode(6, NULL, NULL),
                  new btnode(2, new btnode(5, NULL, NULL) , new btnode(6, NULL, NULL))
                  );

  cout << isMirror(root1, root2) << "\n";
}

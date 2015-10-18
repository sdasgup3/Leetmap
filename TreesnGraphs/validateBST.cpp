#include<iostream>
#include<vector>
#include<list>
#include<climits>

class btnode {
  public:
    btnode(int a, btnode* l, btnode* r): v(a), left(l), right(r) { }
    int v;
    btnode* left;
    btnode* right;
};


bool
validateBST(btnode* root, int& prev) 
{
  if(NULL==root) return true;

  if(false == validateBST(root->left, prev)) {
      return false;
  }
  //std::cout << "Checking " << prev  << " "  << root->v << "\n";
  if(root->v < prev) {
    return false;
  } else {
    prev = root->v;
  }
  if(false == validateBST(root->right, prev)) {
    return false;
  }

  return true;
}

bool
validateBST_v2(btnode* root, int min, int max) 
{
  if(NULL==root) return true;

  std::cout << "Checking " << min  << " "  << root->v << " " << max <<"\n";
  bool cond = root->v > min && root->v <= max;
  if(false == cond) {
    return false;
  }

  if(false == validateBST_v2(root->left, min, root->v))
    return false;
  if(false == validateBST_v2(root->right, root->v, max))
    return false;

  return true;
}

int main()
{
  btnode* root = new btnode(20, 
            new btnode(10, 
              new btnode(9, 
                new btnode(8, NULL,NULL),
                NULL),
              new btnode(15, 
                NULL,
                new btnode(19, NULL,NULL))),
            new btnode(33, 
              new btnode(26, NULL,NULL),
              new btnode(37, 
                new btnode(34, NULL,NULL),
                new btnode(38, NULL,NULL))));

  int max   = INT_MAX;
  int min   = INT_MIN;
  int prev  = INT_MIN;
  std::cout << validateBST(root, prev) << "\n";
  std::cout << validateBST_v2(root, min, max) << "\n";

  return 0;
}

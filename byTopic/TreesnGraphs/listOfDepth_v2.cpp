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


void
listOfDepths(std::vector<std::list<btnode*>*> &L, btnode* root) {

  std::list<btnode*> *current = new std::list<btnode*>;
  current->push_back(root);

  while(false == current->empty()) {
    L.push_back(current);
    std::list<btnode*> *parent  = current;
    current = new std::list<btnode*>;
    for(std::list<btnode*>::iterator  I = (*parent).begin(), 
                                      E = (*parent).end();
        I != E; I++) {
      if((*I)->left)
        current->push_back((*I)->left);
      if((*I)->right)
        current->push_back((*I)->right);
    }
  }
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
              new btnode(6, NULL,NULL),
              new btnode(7, 
                new btnode(10, NULL,NULL),
                new btnode(11, NULL,NULL))));

  std::vector<std::list<btnode*>*> L;
  listOfDepths(L, root);

  for(int i = 0 ; i  < L.size(); i++) {
    std::list<btnode*> *l = L[i];
    for(btnode* b:*l) {
      std::cout << b->v << " " ;
    }
    std::cout << "\n";
  }
  return 0;
}

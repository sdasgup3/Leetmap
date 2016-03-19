#include<iostream>
#include<vector>

class btnode {
  public:
    btnode(int a, btnode* l, btnode* r): v(a), left(l), right(r) { }
    int v;
    btnode* left;
    btnode* right;
};

class listnode {
  public:
    btnode* data;
    listnode* next;
};


class queue {
  private  :
    int size;
    listnode* head;
    listnode* last;
  public:
    queue(): head(NULL), last(NULL), size(0) {}
    void enq(btnode* node) {
      if(NULL == node) return;

      listnode* n  = new listnode;
      n->data = node;
      n->next = NULL;

      if(NULL == head) {
        head = last = n;
      } else {
        last->next = n;
        last  = n;
      }
      size++;
    }

    btnode* deq() {
      if(NULL == head) return NULL;

      size--;
      listnode* tbd = head;
      btnode* ret = tbd->data;
      head = head->next;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return size == 0;
    }
};

void
insertL(listnode** head, btnode* node)
{
  listnode* n = new listnode;
  n->data = node;
  n->next = NULL;

  if(*head == NULL) {
    *head = n;
  } else {
    listnode* temp = *head;
    while(temp->next) {
      temp= temp->next;
    }
    temp->next = n;
  }
}

void
listOfDepths(std::vector<listnode*> &L, btnode* root) {
  queue Q;

  btnode* marker = root;
  Q.enq(root);
  listnode* lroot = NULL;

  while(false == Q.isEmpty()) {
    btnode* n = Q.deq();
    insertL(&lroot, n);
    
    Q.enq(n->left);
    Q.enq(n->right);

    if(marker == n) {
      L.push_back(lroot);
      lroot = NULL;
      marker = n->right;
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

  std::vector<listnode*> L;
  listOfDepths(L, root);

  for(int i = 0 ; i  < L.size(); i++) {
    listnode* l = L[i];
    while(l) {
      std::cout << l->data->v << " " ;
      l = l->next;
    }
    std::cout << "\n";
  }
  return 0;
}

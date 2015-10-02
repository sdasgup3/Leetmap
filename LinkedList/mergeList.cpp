#include<iostream>
#include<vector>
using namespace std;

class listNode {
  public:
    int value;
    listNode* next;
    listNode(int val) {
      cout << " In listNode Cons "<< val <<  "\n";
      value = val;
      next = NULL;
    }
};


class linkedList {

  private:
    listNode* head;
    listNode* curr;

  public:
    linkedList() {
      head = NULL;
      curr = NULL;
    }
  
    void addNode(listNode* node) {
      if(NULL == curr) {
        curr = node;
        head = node;
      } else {
        curr->next =  node;
        curr = node;
      }
    }

    listNode* getHead() {
      return head;
    }

    listNode* getCurr() {
      return curr;
    }
    void advance() {
      curr = curr->next;
    }

    void print(){
      listNode* c = head;
      while(NULL != c) {
        cout << c->value << " ";
        c = c->next;
      }
      cout << endl;
    }

};


linkedList* merge(linkedList* L1, linkedList* L2) {
  linkedList* res = new linkedList;
  listNode* node1; 
  listNode* node2; 

  listNode* itr1 = L1->getHead();
  listNode* itr2 = L2->getHead();

  while((itr1) != NULL && (itr2) != NULL) {
    if(itr1->value <= itr2->value) {
      listNode* n = new listNode(itr1->value);
      res->addNode(n);
      itr1 = itr1->next;
    } else {
      listNode* n = new listNode(itr2->value);
      res->addNode(n);
      itr2 = itr2->next;
    }
  }
  if(NULL == itr1) {
    while((itr2) != NULL) {
      listNode* n = new listNode(itr2->value);
      res->addNode(n);
      itr2 = itr2->next;
    }
  }
  if(NULL == itr2) {
    while((itr1) != NULL) {
      listNode* n = new listNode(itr1->value);
      res->addNode(n);
      itr1 = itr1->next;
    }
  }
  return res;
}


int main() {
  linkedList* L1 = new linkedList;
  linkedList* L2 = new linkedList;

  int init_val1[] = {1,3,5,7,9};
  int init_val2[] = {2,2,2, 4,6,8,10};
  
  vector<int> v1(init_val1, init_val1 + (sizeof(init_val1)/sizeof(init_val1[0])));
  vector<int> v2(init_val2, init_val2 + (sizeof(init_val2)/sizeof(init_val2[0])));


  listNode** N1 = new listNode*[v1.size()];
  listNode** N2 = new listNode*[v2.size()];

  for(int i = 0; i < v1.size(); i++) {
    N1[i] = new  listNode(v1[i]);
  }

  for(int i = 0; i < v2.size(); i++) {
    N2[i] = new  listNode(v2[i]);
  }

  for(int i = 0; i < v1.size(); i++) {
    L1->addNode(N1[i]);
  }

  for(int i = 0; i < v2.size(); i++) {
    L2->addNode(N2[i]);
  }

  L1->print();
  L2->print();

  linkedList* L3 = merge(L1, L2);
  L3->print();

  return 0;
}


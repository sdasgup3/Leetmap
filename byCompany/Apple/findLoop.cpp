#include<iostream>

using namespace std;

typedef struct linkedlist {
  int data;
  struct linkedlist* next;
} list;


list* 
push(list* head, int d) {
  list* n = new list();
  n->data =  d;
  n->next = NULL;

  if(NULL == head) {
    head = n;
  } else {
    n->next = head;
    head = n;
  }
  return head;
}

void 
print(list* head) {
  while(NULL != head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

bool
detectloop(list* head) {
  list* sptr = head;
  list* fptr = head;

  while(fptr) {
    sptr = sptr->next;
    if(NULL == fptr->next) {
      break;
    }
    fptr = fptr->next->next;

    if(sptr == fptr) {
      return true;
    }
  }

  return false;

}

int main()
{
  list* head = NULL;

  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);

  print(head);

  cout << detectloop(head) << "\n";
  head->next->next->next->next->next->next = head->next->next->next;

  cout << detectloop(head) << "\n";
}

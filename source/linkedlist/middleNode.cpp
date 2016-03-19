#include<iostream>

typedef struct Node{
  int data;
  struct Node* next;
} node;



void push(node** head, int data) {
  node* n_node = new node;
  n_node->data = data;
  n_node->next = NULL;

  if(*head == NULL) {
    *head = n_node;
  } else {
    //n_node->next = *head;
    //*head = n_node;
    node* temp = *head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = n_node;
  }
}

void print(node* head) {
  if(NULL == head) {
    return ;
  }

  node* slow = head;
  node* fast = head;

  while(fast && fast->next) {
    std::cout << fast->data << " ";
    std::cout << fast->next->data <<  " ";
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast) {
      break;
    }
  }
  if(fast)
    std::cout << fast->data << " ";
  std::cout << "\n";
}

node* middleNode(node* head) {

  if(NULL == head) return NULL;

  node* ptr1 = head;
  if(NULL == ptr1->next) {
    return ptr1;
  }

  node* ptr2 = ptr1->next->next;

  while(NULL != ptr2) {
    ptr1 = ptr1->next;
    if(NULL == ptr2->next) break;
    ptr2 = ptr2->next->next;
  }
  return ptr1;
}

void deleteMiddle(node* n) {

  if(NULL == n || NULL == n->next) return ;

  node* ptr1 = n;
  node* ptr2 = n->next;

  while(true) {
    ptr1->data = ptr2->data;
    if(NULL == ptr2->next) {
      ptr1->next = NULL;
      delete ptr2;
      break;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
}

int main() {
  node* head= NULL;
  node* d;

  push(&head,1); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1 : d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,2); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,3); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,4); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,5); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,6); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,7); 
  print(head);
  d = middleNode(head);
  std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
  deleteMiddle(d);
  print(head);

  push(&head,8); 
  push(&head,9); 
  push(&head,10); 
  push(&head,11); 
  push(&head,12); 
  push(&head,13); 
  while(NULL != head->next) {
    print(head);
    d = middleNode(head);
    std::cout << " Middle Node " << (d == NULL? -1: d->data) << std::endl;
    deleteMiddle(d);
  }
  delete head;
}

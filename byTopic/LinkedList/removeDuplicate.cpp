#include<iostream>
#include<map>

typedef struct Node{
  int data;
  struct Node* next;
} node;


void removeDuplicate_v1(node** head) 
{
  std::map<int, int> M;
  node *n = *head;

  if(n == NULL) return;

  while(NULL != n) {
    M[n->data] = 0;
    n = n->next;
  }
  
  n = *head;
  M[n->data]  =1;
  while(NULL != n->next) {
    if(1 == M[n->next->data]) {
      node* tobeDel = n->next;
      n->next = n->next->next;
      delete tobeDel;
    } else {
      M[n->next->data] = 1;
      n = n->next;
    }
  }
}

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

void deleteList(node* head) {

  while(head ) {
    node* tobeDel = head;
    head = head->next;
    delete tobeDel;
  }
}

void removeDuplicate_v2(node** head) 
{
  std::map<int, int> M;
  node *n = *head;

  if(n == NULL) return;

  while(NULL != n) {
    M[n->data] = 0;
    n = n->next;
  }
  
  node* current = *head;
  node* prev = NULL;
  while(NULL != current) {
    if(1 == M[current->data]) {
      node* tobeDel = current;
      current = current->next;
      prev->next = current;
      delete tobeDel;
    } else {
      M[current->data] = 1;
      prev = current;
      current = current->next;
    }
  }
}

void removeDuplicate_v3(node** head) 
{
  node* current = *head;
  node* runner ;
  node* prev;
  while(NULL != current) {
    runner = current->next;
    prev = current;
    while(runner) {
      if(runner->data == current->data) {
        node* tobeDel = runner;
        runner = runner->next;  
        prev->next = runner;   
        delete tobeDel;
      } else {
        prev = runner;
        runner = runner->next;  
      }
    }
    current = current->next;
  }
}

int main() {
  node* head= NULL;
  push(&head,1); push(&head,2); push(&head,3); push(&head,4); push(&head,1); push(&head,2); push(&head,3); push(&head,4);
  print(head);
  //removeDuplicate_v1(&head);
  //removeDuplicate_v2(&head);
  removeDuplicate_v3(&head);
  print(head);
  deleteList(head);

  std::cout << "\n";

  head= NULL;
  push(&head,1); push(&head,2); push(&head,3); push(&head,4); push(&head,1); push(&head,2); push(&head,3); push(&head,6);
  print(head);
  //removeDuplicate_v1(&head);
  //removeDuplicate_v2(&head);
  removeDuplicate_v3(&head);
  print(head);
  deleteList(head);

  std::cout << "\n";
}

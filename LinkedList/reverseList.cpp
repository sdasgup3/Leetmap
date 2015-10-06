#include<iostream>

typedef struct Node{
  int data;
  struct Node* next;
} node;


void reverseList(node** head) 
{
  if(NULL == *head) {
    return ;
  }

  node* prev = NULL;
  node* curr = *head;
  node* next = curr->next;

  while(NULL != next) {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = curr->next;
  }

  curr->next = prev;
  *head = curr;
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
  while(NULL != head) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}


int main() {
  node* head= NULL;

  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);

  print(head);

  reverseList(&head);
  
  print(head);

}

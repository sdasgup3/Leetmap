#include<iostream>

typedef struct Node{
  int data;
  struct Node* next;
} node;


void removeLoop(node** head, node*ptrInLoop) {

  node* ptr1 = *head;  
  node* ptr2;  

  while(true) {
    ptr2 = ptrInLoop;  
    while(ptr2->next != ptrInLoop && ptr2->next != ptr1) {
      ptr2 = ptr2->next;
    }
    if(ptr2->next == ptr1) {
      ptr2->next = NULL;
      return;
    }
    ptr1 = ptr1->next;
  }
}

void detectnRemoveLoop(node** head) 
{
  if(NULL == *head) {
    return ;
  }

  node* slow = *head;
  node* fast = *head;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast) {
      std::cout << "Loop Detected\n";
      removeLoop(head, slow);
      break;
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
  std::cout << "\n";
}


int main() {
  node* head= NULL;

  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  push(&head,6);
  push(&head,7);

  head->next->next->next->next->next->next =  head->next->next;

  print(head);

  detectnRemoveLoop(&head);
  
  print(head);

}

#include<iostream>

typedef struct Node{
  char data;
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

void reverseList(node **head) {
  if(head == NULL) return;

  node* prev = *head;
  node* current = (*head)->next;

  prev->next = NULL;

  while(NULL !=  current) {
    node* temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }
  *head = prev;
}

node* findMiddle(node *head) {
  node* ptr1 = head;
  if(ptr1->next == NULL) return ptr1;

  node* ptr2 = ptr1->next->next;

  while(NULL != ptr2) {
    ptr1 = ptr1->next;
    if(ptr2->next == NULL) return ptr1;
    ptr2 = ptr2->next->next;
  }
  return ptr1;
}

int isPalindrom(node* head) {

  if(NULL == head) return 0;

  node* ptr1 = head;
  node* middle = findMiddle(head);
  if(NULL == middle) return 0;

  node* ptr2 = middle->next;
  middle->next  = NULL;
  std::cout << "Middle : " << ptr2->data << "\n";

  reverseList(&ptr2);

  while(ptr1 && ptr2) {
    if(ptr1->data != ptr2->data) {
      return 0;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  if(ptr2) {
    return 0;
  }
  if(ptr1 != NULL) {
    if(ptr1->next != NULL ) {
      return 0;
    }
  }
  return 1;
}

int main() {
  node* head= NULL;
  node* d;

  push(&head,'a'); 
  push(&head,'b'); 
  push(&head,'c'); 
  push(&head,'x'); 
  push(&head,'y'); 
  push(&head,'z'); 
  push(&head,'c'); 
  push(&head,'b'); 
  push(&head,'a'); 

  print(head);
  std::cout << " Is Palindrom : " << isPalindrom(head) << "\n";


}

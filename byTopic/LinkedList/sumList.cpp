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

node* sumList(node* head1, node* head2) {

  if(NULL == head1 ) return head2;
  if(NULL == head2 ) return head1;

  node* ptr1 = head1;
  node* ptr2 = head2;
  node* head = NULL;

  int c =0;
  while(ptr1 && ptr2) {
    int sum = c + ptr1->data + ptr2->data;
    c = sum/10;
    push(&head, sum%10);

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  if(NULL == ptr1) {
    while(ptr2) {
      int sum = c + ptr2->data;
      c = sum/10;
      push(&head, sum%10);
      ptr2 = ptr2->next;
    }
  }

  if(NULL == ptr2) {
    while(ptr1) {
      int sum = c + ptr1->data;
      c = sum/10;
      push(&head, sum%10);
      ptr1 = ptr1->next;
    }
  }
  return head;
}

int main() {
  node* head1= NULL;
  node* head2= NULL;

  push(&head1,10); 
  push(&head1,11); 
  push(&head1,12); 
  push(&head1,13); 
  push(&head1,1); 

  push(&head2,2); 
  push(&head2,3); 
  push(&head2,4); 
  push(&head2,5); 
  push(&head2,6); 
  push(&head2,7); 
  push(&head2,8); 
  push(&head2,9); 


  node* head = sumList(head1, head2);
  print(head1);
  print(head2);
  print(head);

  reverseList(&head1);
  reverseList(&head2);
  reverseList(&head);
  print(head1);
  print(head2);
  print(head);
}

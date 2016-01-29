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

void addToFront(node** head, node* n) {
  n->next = NULL;
  n->next = *head;
  *head = n;
}
void addToEnd(node** last, node* n) {
  n->next = NULL;
  (*last)->next = n;
  *last = n;
}

void partition(node** head, int k) {

  if(NULL == head) return;

  node* last = *head;

  while(NULL != last->next) {
    last = last->next;
  }
  node* lastPtr = last;

  node* current = *head;
  node* prev = NULL;
  node* tobereordered;

  while(true) {
    //print(*head);
    if(current == lastPtr) break;

    if(current->data < k) {
      tobereordered = current;
      current = current->next;
      //std::cout <<  current->data << " " <<  tobereordered->data << " \n"; 
      if(NULL == prev) {
        //std::cout <<" null prev\n"; 
        *head = current;
        prev = tobereordered;
      } else {
        prev->next = current;
      }

      addToFront(head, tobereordered);
      continue;
    }
    if(current->data > k) {
      tobereordered = current;
      current = current->next;
      if(NULL == prev) {
        *head = current;
      } else {
        prev->next = current;
      }

      addToEnd(&last, tobereordered);
      continue;
    } 
    prev = current;
    current = current->next;
  }
}

int main() {
  node* head= NULL;
  node* d;

  push(&head,10); 
  push(&head,11); 
  push(&head,12); 
  push(&head,13); 
  push(&head,1); 
  push(&head,2); 
  push(&head,3); 
  push(&head,4); 
  push(&head,5); 
  push(&head,6); 
  push(&head,7); 
  push(&head,8); 
  push(&head,9); 

  for(int i=0; i < 15; i++) {
    print(head);
    std::cout << "Partiotion with " << i<<"\n";
    partition(&head, i);
  }
    print(head);


  delete head;
}

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

int kthTolast_v2(node* head, int k, int len = 0) {
  if(k >= len) {
    std::cout << "Wrong k value\n";
    return -1;
  }

  node* ptr1 = head;
  int i = len - k -1;
  while(i !=0) {
    ptr1 = ptr1->next;
    i--;
  }

  return ptr1->data;
}

int kthTolast(node* head, int k, int len = 0) {
  if(k >= len) {
    std::cout << "Wrong k value\n";
    return -1;
  }

  node* ptr1 = head;
  node* ptr2 = head;
  int i = k;
  while(ptr2 && i !=0) {
    ptr2 = ptr2->next;
    i--;
  }
  if(NULL == ptr2) {
    std::cout << "Wrong k value\n";
    return -1;
  }

  while(ptr2->next) {
    ptr2=ptr2->next;
    ptr1=ptr1->next;
  }

  return ptr1->data;
}

int rec_call(node* head, int * b) {
  if(NULL == head->next) {
    int ret = 0;
    if(*b == 0) {
      ret = head->data;
    }
    (*b) --;
    return ret; 
  }
  int ret = rec_call(head->next, b);
  if((*b) == 0) {
    ret = head->data;
  }   
  (*b) --;
  return ret;
}

int kthTolast_rec(node* head, int k, int len = 0) {
  if(k >= len) {
    std::cout << "Wrong k value\n";
    return -1;
  }

  if(NULL == head) {
    std::cout << "Head NULL \n";
    return -1;
  }
  int *bucket = new int;
  *bucket = k;
  rec_call(head, bucket);

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

  print(head);

  int k = 0;
  for(;k <= 10; k++) {
    std::cout << k << " To Last " << kthTolast(head, k, 7) << std::endl;
    std::cout << k << " To Last " << kthTolast_v2(head, k, 7) << std::endl;
    std::cout << k << " To Last " << kthTolast_rec(head, k, 7) << std::endl;
  }

}

#include<iostream>
#include<map>

typedef struct Node{
  int data;
  bool visited;
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
    std::cout << fast->data << " - ";
    std::cout << fast->next->data <<  " -  ";
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

int getIntesectionNode_v1(node* head1, node* head2) {
  node* ptr1 = head1;
  while(NULL != ptr1) {
    ptr1->visited = true;
    ptr1 = ptr1->next;
  }

  node* ptr2 = head2;
  while(NULL != ptr2) {
    if(true == ptr2->visited) {  
      return ptr2->data;
    }
    ptr2 = ptr2->next;
  }

  return -1;
}

int getIntesectionNode_v2(node* head1, node* head2) {

  std::map<node*, bool> M;
  node* ptr1 = head1;
  while(NULL != ptr1) {
    M[ptr1] = true;
    ptr1 = ptr1->next;
  }

  node* ptr2 = head2;
  while(NULL != ptr2) {
    if(true == M[ptr2]) {  
      return ptr2->data;
    }
    ptr2 = ptr2->next;
  }

  return -1;
}

int length(node* head) {
  int len = 0;
  while(NULL != head) {
    head = head->next;
    len ++;
  }
  return len;
}

int getIntesectionNode_v3(node* head1, node* head2) {

  int len1 = length(head1);
  int len2 = length(head2);

  int diff = abs(len1 - len2);
  node* ptr1 = head1;
  node* ptr2 = head2;

  if(diff != 0) {
    if(len1 > len2) {
      for(int i = 0; i< diff; i++) {
        ptr1 = ptr1->next;
      }
    } else {
      for(int i = 0; i< diff; i++) {
        ptr2 = ptr2->next;
      }
    }
  }

  while(ptr1 && ptr2) {
    if(ptr1 == ptr2) {
      return ptr1->data;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return -1;
}

int getIntesectionNode_v4(node* head1, node* head2) {

  int len1 = length(head1);
  int len2 = length(head2);
  node* ptr1 = head1;

  //Make a cycle out of the first list
  node* lastPtr1 = head1;
  for(int  i = 0; i < len1 -1 ; i++) {
    lastPtr1 = lastPtr1->next;
  }
  lastPtr1->next = head1;

  //Set two pointers in list2, len1 apart
  node* ptr2_1 = head2;
  node* ptr2_2 = head2;
  for(int  i = 0; i < len1 ; i++) {
    ptr2_2 = ptr2_2->next;
  }
  std::cout << ptr2_1->data << " " << ptr2_2->data << "\n";

  while(ptr2_2 && ptr2_2 == ptr2_1) {
    ptr2_2 = ptr2_2->next;
    ptr2_1 = ptr2_1->next;
  }

  //Break the loop in list1
  lastPtr1->next = NULL;

  if(NULL == ptr2_2) return -1;

  return ptr2_2->data;

}
int main() {
 
  node* newNode;
  node* head1 = (node*) malloc(sizeof(node));
  head1->data  = 10;
 
  node* head2 = (node*) malloc(sizeof(node));
  head2->data  = 3;
 
  newNode = (node*) malloc (sizeof( node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (node*) malloc (sizeof( node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (node*) malloc (sizeof( node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (node*) malloc (sizeof( node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
  print(head1);
  print(head2);

  printf("\n The node of intersection is %d \n", getIntesectionNode_v1(head1, head2));
  printf("\n The node of intersection is %d \n", getIntesectionNode_v2(head1, head2));
  printf("\n The node of intersection is %d \n", getIntesectionNode_v3(head1, head2));
  printf("\n The node of intersection is %d \n", getIntesectionNode_v4(head1, head2));
 
}

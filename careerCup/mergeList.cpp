#include<iostream>
typedef struct _S {
  int data;
  struct _S* next;
} node;

void
insert(node** head, int d) {
  node* n = new node;
  n->next = NULL;
  n->data  = d;

  if(*head == NULL) {
    *head = n;
  } else {
    n->next = *head;
    *head = n;
  }
}

void
print(node* head) {
  while(head) {
    std::cout << head->data << " ";
    head= head->next;
  }
  std::cout << "\n===\n";
}

node*
merge(node* head1, node* head2) {
  if(head1 == NULL) {
    return head2;
  }
  if(head2 == NULL) {
    return head1;
  }

  node *ret =  NULL;
  node *X =  NULL;
  node *Y =  NULL;
  node *T =  NULL;
  if(head1->data <= head2->data ) {
    T = head1;
    Y = head2;
    ret  = head1;
  } else {
    T = head2;
    Y = head1;
    ret  = head2;
  }

  while(T && Y) {

    if(T->data <= Y->data) {
      X = T;
      T = T->next;
    } else {
      X->next = Y;
      X = Y;
      Y = Y->next;
      X->next = T;
    }

  }

  if(NULL == T) {
    X->next = Y;
  }

  return ret;
}

int main()
{
  node* head1 = NULL;
  node* head2 = NULL;

  insert(&head1, 9);
  insert(&head1, 7);
  insert(&head1, 5);
  insert(&head1, 3);
  insert(&head1, 1);
  print(head1);
  
  insert(&head2, 10);
  insert(&head2, 8);
  insert(&head2, 6);
  insert(&head2, 4);
  insert(&head2, 2);
  print(head2);

  node* head = merge(head1, head2);
  print(head);
} 

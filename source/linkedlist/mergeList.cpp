#include<iostream>
#include<cassert>

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

node* merge(node* head1, node* head2) {

  if(NULL == head1 ) return head2;
  if(NULL == head2 ) return head1;

  node* ptrToAdd = NULL;
  node* runner_1 = head1;
  node* runner_2 = head2;

  while(runner_2 && runner_1) {
    if(runner_1->data < runner_2->data) {
      ptrToAdd = runner_1;
      runner_1 = runner_1->next;
    } else if(runner_1->data >= runner_2->data) {

      if(runner_1->data == runner_2->data) {
        runner_1 = runner_1->next;
        if(NULL == ptrToAdd) {
          ptrToAdd = runner_1;
        } else {
          ptrToAdd = ptrToAdd->next;
        }
      }

      node* nodeToRem = runner_2;
      runner_2 = runner_2->next;
      head2 = runner_2;


      if(NULL == ptrToAdd) {
        nodeToRem->next =  runner_1;
        ptrToAdd = nodeToRem;
        head1 = ptrToAdd;
      } else {
        nodeToRem->next = ptrToAdd->next;
        ptrToAdd->next = nodeToRem;
        ptrToAdd = ptrToAdd->next;
      }

    } 
    //print(head1);
    //print(head2);
    //std::cout << "===\n";
  }

  if(runner_1 == NULL) {
    while(runner_2) {
      node* nodeToRem = runner_2;
      runner_2 = runner_2->next;
      
      if(NULL == ptrToAdd) {
        nodeToRem->next =  runner_1;
        ptrToAdd = nodeToRem;
        head1 = ptrToAdd;
      } else {
        nodeToRem->next = ptrToAdd->next;
        ptrToAdd->next = nodeToRem;
        ptrToAdd = ptrToAdd->next;
      }
    }
  }

  return head1;
}


void deleteList(node* head) {
  while(head) {
    node* del = head;
    head= head = head->next;
    delete del;
  }
}

node* M(node* head1, node* head2) {

  if(NULL == head1 ) return head2;
  if(NULL == head2 ) return head1;

  node* X, *Y, *R, *T;
  T = NULL;
  if(head1->data <= head2->data) {
    X = head1; Y = head2; 
  } else {
    X = head2; Y = head1;
  }

  T = X; 
  X = X->next;
  R = T;

  while(X) {
    if(X->data <= Y->data) {
      T = X;
      X = X->next;
    } else {
      //if(T) {
        T->next = Y;
      //}
      T = Y;
      Y = X;
      X = T->next;
    } 
  }
  T->next =Y;

  return R;
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


  print(head1);
  print(head2);
  node* head = M(head1, head2);
  print(head);
  deleteList(head);


  head1= NULL;
  head2= NULL;

  push(&head1,0); 
  push(&head1,2); 
  push(&head1,4); 
  push(&head1,6); 
  push(&head1,7); 
  push(&head1,8); 
  push(&head1,10); 

  push(&head2,1); 
  push(&head2,3); 
  push(&head2,5); 
  push(&head2,7); 
  push(&head2,9); 
  push(&head2,11); 
  push(&head2,12); 
  push(&head2,13); 


  print(head1);
  print(head2);
  head = M(head1, head2);
  print(head);
  deleteList(head);

  return 0;
}

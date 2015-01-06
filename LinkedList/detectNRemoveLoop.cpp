#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to remove loop. Used by detectAndRemoveLoop() */
void removeLoop(struct node *, struct node *);
 
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct node *loop_node, struct node *head)
{
   struct node *ptr1;
   struct node *ptr2;
 
   /* Set a pointer to the beging of the Linked List and
      move it one by one to find the first node which is
      part of the Linked List */
   ptr1 = head;
   while(1)
   {
     /* Now start a pointer from loop_node and check if it ever
       reaches ptr2 */
     ptr2 = loop_node;
     while(ptr2->next != loop_node && ptr2->next != ptr1)
     {
         ptr2 = ptr2->next;
     }
 
     /* If ptr2 reahced ptr1 then there is a loop. So break the
        loop */
     if(ptr2->next == ptr1)
        break;
 
     /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
     else
       ptr1 = ptr1->next;
   }
 
   /* After the end of loop ptr2 is the last node of the loop. So
     make next of ptr2 as NULL */
   ptr2->next = NULL;
}
 
/* UTILITY FUNCTIONS */
/* Given a reference (pointer to pointer) to the head
  of a list and an int, pushes a new node on the front
  of the list. */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    getchar();
    return 0;
}


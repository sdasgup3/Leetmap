/* Problem Description
Given a linked list, remove the nth node from the end of list and return its .

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid. ************************
Try to do this in one pass.

Distinguish between 
A B C n  =2 
and 
A B C n  =3 



*/

#include"header.h"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* root, int n) {
      if(!root) return root;

      ListNode* runner = root;
      int i = 0 ;
      while(i < n+1) {
        if(!runner) break;
        runner = runner->next;
        i++;  
      }

      if(i != (n+1)) {
        root = root->next;
        return root;
      }

      ListNode* runner2 = root;
      while(runner) {
        runner = runner->next;
        runner2 = runner2->next;
      }

      runner2->next = runner2->next->next;

      return root;
        
    }
};


int main() {
  Solution S;
  ListNode* r = new ListNode(1);
  r->next = new ListNode(2);
  r->next->next = new ListNode(3);
  r->next->next->next = new ListNode(4);

  cout << S.removeNthFromEnd(r, 4);

  return 0;
}

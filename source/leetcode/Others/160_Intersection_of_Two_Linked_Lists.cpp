/* Problem Description
   Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include"header.h"
class Solution {

public:
  int findLength(ListNode* head) {
    int len = 0;
    while(head) {
      len++;
      head = head->next;
    }
    return len;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if(!headA || !headB) {
      return NULL;
    }
    //Method 1
    //Find length of headA
    int len_A = findLength(headA);

    //Find length of headB
    int len_B = findLength(headB);

    ListNode* runner1 = headA;
    ListNode* runner2  = headB;
    //Make the longer List point to the same level of node
    // as in smaller node
    if(len_A > len_B) {
      for(int i = 0 ; i < len_A - len_B; i++) {
        runner1 = runner1->next; 
      }
    } else if(len_B > len_A) {
      for(int i = 0 ; i < len_B - len_A; i++) {
        runner2 = runner2->next; 
      }
    }

    while(runner1 && runner2) {
      if(runner1 == runner2) {
        return runner1;
      } 
      runner1 = runner1->next;
      runner2 = runner2->next;
    }

    return NULL;

  }
private:

};


int main() {
  Solution S;

  ListNode* headA = new ListNode(10);
  ListNode* headB = new ListNode(20);
  headA->next = headB;

  cout << S.getIntersectionNode(headA, headB)->val << "\n";

  return 0;
}

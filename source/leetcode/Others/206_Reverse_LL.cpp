/* Problem Description
Reverse a singly linked list.

Tags:
List
 *
*/

#include"header.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while(next) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }

        curr->next = prev;
        return curr;
        
    }
};

int main() {
  Solution S;

  ListNode* root;

  S.reverseList(root);

  return 0;
}

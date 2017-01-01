/* Problem Description
 * Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Tags:
List
*/

#include"header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        //Find the length
        int len = 0;
        ListNode* runner = head;
        ListNode* prev = NULL;
        while(runner) {
            prev = runner;
            runner= runner->next;
            len ++;
        }
        
        if(k == len) {
            return head;
        } else if(k > len) {
            k = k % len;
        }
        //make a circle
        prev->next = head;
        
        //traverse till n-k and brak the circle
        prev = NULL;
        runner = head;
        for(int i = 1 ; i <= len - k ; i ++) {
            prev =  runner;
            runner = runner->next;
        }
         
        prev->next = NULL;
        return runner;
    }
};


int main() {
  Solution S;
  ListNode *head = new ListNode(1);
  head->next =  new ListNode(2);
  head->next->next =  new ListNode(3);
  head->next->next->next =  new ListNode(4);
  head->next->next->next->next =  new ListNode(5);
  head->next->next->next->next->next =  new ListNode(6);
  head->next->next->next->next->next->next =  new ListNode(7);


  cout << head;
  cout << S.rotateRight(head, 3);

  return 0;
}

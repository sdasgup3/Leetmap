/* Problem Description
   Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Solution:

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* insert = NULL, *next = NULL;
        
        ListNode *runner = head;
        while(1) {
            while(runner->next && runner->val == runner->next->val) {
                runner = runner->next;
            }    
            
            if(!insert) {
                head = runner;
                insert = head;
            } else {
                insert->next = runner;
                insert = insert->next;
            }
            
            if(runner->next == NULL) break;
            
            runner = runner->next;
        }
        
        
        insert->next = NULL;
        
        return head;
    }
};


int main() {
  Solution S;
  return 0;
}

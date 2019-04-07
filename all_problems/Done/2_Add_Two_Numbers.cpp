/* 
 * Problem Description
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 * Solution
 * Tags
 * Bits, List
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        
        ListNode *res = NULL, *head = NULL;
        int carry = 0;
        
        while(l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;
            
            int sum = (val1 + val2 + carry)%10;
            carry = (val1 + val2 + carry)/10;
            if(res == NULL) {
                head = new ListNode(sum);
                res = head;
            } else {
                res->next =  new ListNode(sum);
                res = res->next;
            }
            
            l1 = l1->next; l2 = l2->next;
        }
        
        if(l1) {
            while(l1) {
                int val1 = l1->val;
            
                int sum = (val1 + carry)%10;
                carry = (val1 + carry)/10;
                res->next =  new ListNode(sum);
                res = res->next;
                
                l1 = l1->next; 
            }
        }   
        
        if(l2) {
            while(l2) {
                int val1 = l2->val;
            
                int sum = (val1 + carry)%10;
                carry = (val1 + carry)/10;
                res->next =  new ListNode(sum);
                res = res->next;
                l2 = l2->next;
            }
        }   
        
        if(carry) {
            res->next =  new ListNode(carry);
            res = res->next;
        }
        
        return head;
        
    }
};


int main() {
  Solution S;

  return 0;
}

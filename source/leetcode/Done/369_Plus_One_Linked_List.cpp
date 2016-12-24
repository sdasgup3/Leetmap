/* 
 * Problem Description
 Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
 *
 * Solution

 MSB                 LSB

 head->next->next->NULL

 9 9 8 9
 find the rightmost non 9 = 8
 if 8->next != NULL ; make 8->val++ and all the subsequent vals as 0

  9 9 9 
 find the rightmost non 9 = NULL

Trick:
Here we need the seq 
    non-9 ..all 9s..
for that we have to find the rightmost non 9 by scannign the entire list

 * Tags
 Lists
*/

#include"header.h"
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(!head) {
            head = new ListNode(1);
            return head;
        }
        
    
        ListNode *runner  = head, *non9  = NULL;

        
        //Find the rightmost non 9
        while(runner) {
            if(runner->val != 9) {
                non9 = runner;
            }
            runner = runner->next;
        }
        
        if(!non9) {
            ListNode *tmp = new ListNode(1);
            tmp->next = head;
            head = tmp;
            non9 = head;
        } else {
            non9->val ++;
        }
        
        runner = non9->next;
        while(runner) {
            runner->val = 0;
            runner = runner->next;
        }
        
        return head;
    }
};

int main() {

  return 0;
}

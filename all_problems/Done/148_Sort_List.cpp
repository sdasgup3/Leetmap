/* 
 * Problem Description
 Sort a linked list in O(n log n) time using constant space complexity.

 * Solution
1. Have all the nodes stored in Priority queue (min) and pop it in ascending order
DONT forget to make next = NULL for the last node

2. Merge Sort

4 3 2 1 0

divide the list in half
            (4 3)      (2 1 0)
            /  \        /     \
           4    3      2      1 0
                             /   \
                            1    0

  and the conquer using merge

The normal divide algorith does this
1: mid = 1
1->2 mid = 1
1->2->3 mid = 2

To sort a list like 
2->1 using mid will divide the list into NULL and 2->1, but to merge we need individual atoms
so we have to have a special case for list length 2 which will divide it into individual atoms

Algorithm:
if(list length = 0 or 1)
 return list

if(list length 2) {
  list1 = list ; 
  list2 = head->next
  list1->next  = null
} else {
  //Use the mod also to find the mid
  // also make sure to do node->next = NULL for the node prior to mid
  // obtain to lists list1 and list 2
}

h1 = recusive(list1)
h2 = recusive(list2)
return mergeList(h1, h2);

 * Tags
 Lists
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
    ListNode* sortList1(ListNode* head) {
        if(!head) return head;
        
        auto cmp = [&](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode* , vector<ListNode*>, decltype(cmp)> Q(cmp);
        
        while(head) {
            Q.push(head);
            head = head->next;
        }
        head = NULL;
        ListNode* runner = NULL;
        while(!Q.empty()) {
            if(!head) {
                head = Q.top();
                Q.pop();
                runner = head;
            } else {
                runner->next = Q.top();
                Q.pop();
                runner = runner->next;
            }
            //cout << runner->val << " " << "\n";
        }
        runner->next = NULL;
        
        return head;    
    }



     ListNode *mergeList(ListNode*l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val <= l2->val) {
            l1->next = mergeList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        
        if(!head->next) return head;
        
        
        ListNode *prev = NULL;
        ListNode *runner1 = head;
        ListNode *runner2 = head->next->next;
        
        if(!head->next->next) {
            //For length 2
            prev = head;
            runner1 = head->next;
        } else {
            // for length > 2
            while(runner2) {
                prev = runner1;
                runner1 = runner1->next;
                runner2 = runner2->next;
                if(!runner2) break;
                runner2  = runner2->next;
            }
        }
        
        prev->next = NULL;
        
        ListNode *h1 = sortList(head);
        ListNode *h2 = sortList(runner1);
        
        return mergeList(h1, h2);
            
    }
};


int main() {
  Solution S;

  ListNode*head = new ListNode(2);
  head->next = new ListNode(1);


  cout << S.sortList(head);

  return 0;
}

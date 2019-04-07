/* 
 * Problem Description

 Merge k sorted list

 * Solution
 1. merge two at a time
 2. Use a priorty queue
 * Tags
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
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        
       if(!l1) return l2;
       if(!l2) return l1;
       
       if(l1->val <= l2->val) {
           l1->next = merge2(l1->next, l2);
           return l1;
       } else {
           l2->next = merge2(l1, l2->next);
           return l2;
       }
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        int sz  = lists.size();
        if(0 == sz) {
            return res;
        }
        if(1 == sz) {
            return lists[0];
        }
        
        for(int i= 0 ; i < sz; i++) {
            res = merge2(res, lists[i]);    
        }
       
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int sz = lists.size();
      if(0 == sz) return NULL;

      if(1 == sz ) return lists[0];

      auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
      };
      priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> Q(cmp);

      for(int i = 0 ; i < sz; i++) {
        if(lists[i])
          Q.push(lists[i]);
      }

      ListNode *runner, *head = NULL;
      while(!Q.empty()) {
        ListNode *tmp = Q.top();
        Q.pop();
        if(tmp->next)
          Q.push(tmp->next);

        if(!head) {
          head=tmp;
          runner = head;
        } else {
          runner->next = tmp;
          runner = runner->next;
        }
      }

      runner->next = NULL;
      return head;
    }
};


int main() {
  Solution S;


  return 0;
}

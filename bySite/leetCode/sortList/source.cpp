#include<iostream>
#include<vector>

using namespace std;


  typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  } ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) {
            return l2;
        }
        
        if(l2 == NULL) {
            return l1;
        }
        
        ListNode* x, *y, *p , *ret;
        
        if(l1->val <= l2->val) {
            ret = l1; p = l1; x = p->next; y = l2;
        } else {
            ret = l2; p = l2; x = p->next; y = l1;
        }
        
        while(x) {
            if(x->val <= y->val) {
                p = x;
                x = p->next;
            } else {
                p->next = y;
                p = y;
                y = x;
                x = p->next;
            }    
        }
        
        p->next = y;
        return ret;
    }

    ListNode* findMid(ListNode* head) {
      //if(NULL == head) return head;
        
      ListNode* mid = head, *runner = mid;
      if(NULL == (runner = runner->next) || NULL == (runner = runner->next)) {
          return mid;
      }
      
      while(1) {
          mid = mid->next;
          if(NULL == (runner = runner->next) || NULL == (runner = runner->next)) {
              return mid;
          }
      }
    }
    
    ListNode* MS(ListNode* head) {
        //Check if head is the only node
        if(head->next == NULL) return head;
        
        //Find the mode node and divide the list into 2 halfs
        ListNode* mid = findMid(head);
        ListNode *l1 = head; 
        ListNode* l2 = mid->next;
        mid->next = NULL;
        
        //Recursive calls
        ListNode* s1 = MS(l1); 
        ListNode* s2 = MS(l2);
        
        //Merge the two halfs
        return mergeTwoLists(s1,s2);
    }
    
    ListNode* sortList(ListNode* head) {
        if(NULL == head || NULL == head->next) return head;
        
        return MS(head);
   
    }
};


int main() {
	Solution S;
        ListNode* l1 = NULL;
	S.sortList(l1);

}

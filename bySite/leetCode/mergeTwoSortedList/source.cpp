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
};


int main() {
	Solution S;
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
	S.mergeTwoLists(l1,l2);

}

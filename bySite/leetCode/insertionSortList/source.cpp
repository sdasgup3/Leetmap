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
  ListNode* insertionSortList(ListNode* head) {
        if(NULL == head || NULL == head->next) {
            return head;
        }
        
        ListNode* mergedList = head;
        ListNode* mergedList_last = head;
        
        ListNode* runner = head->next;
        mergedList->next = NULL;
        
        ListNode* prev = NULL, *check = NULL, *runner_next;
        
        while(runner) {
            
            if(runner->val >= mergedList_last->val) {
                mergedList_last->next = runner;
                mergedList_last = runner;
                runner = runner->next;
                mergedList_last->next = NULL;
            } else if (runner->val < mergedList->val){
                runner_next = runner->next;
                runner->next = mergedList;
                mergedList = runner;
                runner = runner_next;
            } else {
                prev = NULL;
                check = mergedList;
                while(check) {
                    if(check->val <= runner->val) {
                        prev = check;
                        check = check->next;
                    } else {
                        break;
                    }
                }
                runner_next = runner->next;
                prev->next = runner;
                runner->next = check;
                runner = runner_next;
            }
        }
        return mergedList;
    }
};


int main() {
	Solution S;
        ListNode* l1 = NULL;
	S.insertionSortList(l1);

}

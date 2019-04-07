/* 
 * Problem Description
 
Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
 * Solution
 * Tags
 Reservoir Sampling
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
    private:
    ListNode*h;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count = 0;
        int val;
        ListNode *runner = h;
        while(runner) {
            count ++;
            if(count == 1) {
                val = runner->val;
            } else {
                if(0 == rand()%count) {
                    val = runner->val;
                }
            }
            runner = runner->next;
        }
        
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */


int main() {
  Solution S;


  return 0;
}

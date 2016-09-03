/* Problem Description
 * Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

#include"header.h"
class Queue {
public:
    Queue(): front_active(false) {}

    // Push element x to the back of queue.
    void push(int x) {
      if(front_active) {
        while(!S_front_at_top.empty()) {
          S_back_at_top.push(S_front_at_top.top());
          S_front_at_top.pop();
        }
      }
      S_back_at_top.push(x);
      front_active = false;

    }

    // Removes the element from in front of queue.
    void pop(void) {
      if(false == front_active) {
        while(!S_back_at_top.empty()) {
          S_front_at_top.push(S_back_at_top.top());
          S_back_at_top.pop();
        }
      }

      if(S_front_at_top.empty() == false)
        S_front_at_top.pop();
      front_active = true;
    }

    // Get the front element.
    int peek(void) {

      if(false == front_active) {
        while(!S_back_at_top.empty()) {
          S_front_at_top.push(S_back_at_top.top());
          S_back_at_top.pop();
        }
      }

      front_active = true;
      if(S_front_at_top.empty() == false)
        return S_front_at_top.top();
        
    }

    // Return whether the queue is empty.
    bool empty(void) {
      return S_front_at_top.empty() && S_back_at_top.empty();
        
    }
private:
    stack<int> S_front_at_top;
    stack<int> S_back_at_top;
    bool front_active;
};


int main() {
  Queue Q;

  Q.push(1);
  Q.push(2);
  std::cout << Q.peek() << "\n";
  Q.push(3);
  std::cout << Q.peek() << "\n";


  return 0;
}

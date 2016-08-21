/* Problem Description
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include"header.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
      tp = -1;
    }
    
    void push(int x) {
        if(-1 == tp) {
            S.push_back(pair<int, int>(x,x));
        } else {
            int min = x <= S[tp].second ? x : S[tp].second;
            S.push_back(pair<int, int>(x,min));
        }
        tp++;
    }
    
    void pop() {
        if(-1 == tp) {
            return;
        } 
        
        S.pop_back();
        tp--;
        
    }
    
    int top() {
        if(-1 == tp) {
            cerr << "Error\n";
            return -1;
        } 
        return S[tp].first;
    }
    
    int getMin() {
          if(-1 == tp) {
            cerr << "Error\n";
            return -1;
        } 
        return S[tp].second;
    }
private:
    vector<pair<int, int>> S;
    int tp;
};

int main() {

 MinStack *obj = new MinStack();
 obj->push(-2);
 obj->push(0);
 obj->push(-3);
 cout << obj->getMin() << "\n";
 obj->pop();
 cout << obj->top() << "\n";
 cout << obj->getMin() << "\n";

  return 0;
}

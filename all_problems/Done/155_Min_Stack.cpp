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

Solution:
Mantain a second stack to hold the min correnpoding to each entry of main stack

Tags:
Satck
*/

#include"header.h"
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int x) {
        main.push(x);
        if(aux.empty()) {
            aux.push(x);
        } else {
            
            int prev_min = aux.top();
            if(x <= prev_min) {
                aux.push(x);
            } else {
                aux.push(prev_min);
            }
        }
    }
    
    void pop() {
        if(main.empty()) {
            return;
        } 
        
        main.pop();
        aux.pop();
        
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
         return aux.top();
    }
private:
    stack<int> main, aux;
    
};

class MinStack1 {
public:
    /** initialize your data structure here. */
    MinStack1() {
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

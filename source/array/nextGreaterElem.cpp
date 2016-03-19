/*
http://www.geeksforgeeks.org/next-greater-element/
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.
 */

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class stack {
  private:
    int currsize;
    int _top;
    vector<int> store;

  public:
    stack() {
      currsize = 0;
      _top = -1;
    }
    void push(int a) {
      if(_top == -1 || _top == currsize - 1) {
        currsize += 100;
        store.resize(currsize);
      }
      store[++_top] = a;
    }

    int top() {
      return store[_top];
    }

    int pop() {
      return store[_top--];
    }

    bool empty() {
      return (_top  == -1);
    }
};


void nge(vector<int> v) 
{
  stack s;
  s.push(v[0]);
  int next;
  for (int i = 1 ; i < v.size(); i++ ) {
    next = v[i];
    while(s.empty() != true) {
      if(s.top() < next) {
        int top = s.pop();
        cout << "nge of " << top << " : " << next << endl; 
      } else {
        break;
      }
    }
    s.push(next);
  }
  next  = -1;
  while(s.empty() != true) {
    int top = s.pop();
    cout << "nge of " << top << " : " << next << endl; 
  }
}

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}


int main() {
  int arr2[]  = {4, 5, 2, 25};
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
  cout << v2;
  nge(v2);

  int arr3[]  = {11, 13, 21, 3};
  vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
  cout << v3;
  nge(v3);

  int arr4[]  = {13, 7, 6, 12};
  vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));
  cout << v4;
  nge(v4);



  return 0;
}

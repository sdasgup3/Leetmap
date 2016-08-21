#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<climits>
#include <algorithm>
#include <sstream> // isstringstream
#include <iterator> //istream_iterator


using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

template <typename T>
ostream& operator << (ostream& OS, vector<T> V) {
  for(int i = 0 ; i < V.size(); i ++) {
    OS << V[i] << " " ;
  }
  OS << "\n" ;
}
 
const char C = ' ';

template <typename T>
class Stack {
  private:
    vector<T> V;
    int sp;

  public:
    Stack() {
         sp = -1;
    }

    void push(T val) {
      V.push_back(val);
      sp++;
    }

    void pop() {
      if(-1 == sp) {
        cerr << "Cannot pop\n";
        return;
      }
      V.pop_back();
      sp--;
    }

     T top() {
      if(-1 == sp) {
        cerr << "Cannot top\n";
        return T();
      }
      return V[sp];
    }

    bool isempty() {
      return sp == -1;
    }
};

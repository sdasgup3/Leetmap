#include<iostream>

class datanode {
  public: 
    int i;
    datanode() : i(0) {}
    datanode(int arg) : i(arg) {}
    datanode(const datanode &d) {
      i = d.i;
    }
    bool operator<(const datanode &d) {
      return i < d.i;
    }
    bool operator<=(const datanode &d) {
      return i <= d.i;
    }
    datanode& operator=(const datanode &d) {
      i = d.i;
    }
};


std::ostream & operator<<(std::ostream &stream,
    const datanode &d) {
  stream << " " << d.i << " "; 
}



template<class T>
class stacknode {
  public:
    T data;
    T min;
    stacknode* next;
};

template <class T>
class stack {
  protected:
    int size;
    stacknode<T>* head;

  public:
    stack():size(0), head(NULL) {}

    void push(T data) {

      stacknode<T>* n = new stacknode<T>;
      n->data = data;
      n->next = head;
      head = n;
      size++;
    }

    T pop() {
      if(head == NULL) {
        std::cerr<< "pop from empty";
        return 0;
      }

      stacknode<T>* tbd = head;
      head = head->next;
      size --;
      T ret = tbd->data;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return head == NULL;
    }

    void sort(void) {
      if(isEmpty()) return;

      stack<T> aux;

      bool check = true;
      while(check) {
        check = false;
        while(false == isEmpty()) {
          T mem1 = pop();
          T mem2;
          if(false == isEmpty()) {
            mem2 = pop();
          } else {
            push(mem1);
            break;
          }
          if(mem1 <= mem2) {
            aux.push(mem1);
            push(mem2);
          } else {
            check = true;
            aux.push(mem2);
            push(mem1);
          }
       }
     }

     while(false == aux.isEmpty()) {
       T d = aux.pop();
       push(d);
     }
    }

    void print() {
      std::cout << "Stack :  ";
      stacknode<T>* tmp = head;
      while(tmp) {
        std::cout << tmp->data << " "; 
        tmp = tmp->next;
      }
      std::cout << "\n";
    }
};


int main() {
  stack<datanode> *s = new stack<datanode>;

  s->push(datanode(1));
  s->push(datanode(2));
  s->push(datanode(3));
  s->push(datanode(4));
  s->push(datanode(5));
  s->push(datanode(3));
  s->push(datanode(12));
  s->print();
  s->sort();
  s->print();

  return 0;
}

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
class node {
  public:
    T data;
    node* next;
};

template <class T>
class stack {
  protected:
    int size;
    node<T>* head;

  public:
    stack():size(0), head(NULL) {}

    void push(T data) {

      node<T>* n = new node<T>;
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

      node<T>* tbd = head;
      head = head->next;
      size --;
      T ret = tbd->data;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return head == NULL;
    }

    void print() {
      std::cout << "Stack :  ";
      node<T>* tmp = head;
      while(tmp) {
        std::cout << tmp->data << " "; 
        tmp = tmp->next;
      }
      std::cout << "\n";
    }
};

template <class T>
class queue {
  private:
    int size;
    stack<T> one;
    stack<T> two;
    bool popMode;

  public:
    queue():size(0), one(), two(), popMode(false) {}

    void enq(T data) {
      if(popMode) {
        while(false == two.isEmpty()) {
          T d = two.pop();
          one.push(d);
        }
      }
      one.push(data);
      popMode = false;;
      size++;
    }

    T deq() {
      if(popMode) {
        return two.pop();
      }
      while(false == one.isEmpty()) {
        T d = one.pop();
        two.push(d);
      }
      popMode = true;
      size--;
      return two.pop();
    }

    bool isEmpty() {
      return size == 0;
    }

    void print() {
      if(popMode) {
        two.print();
      } else {
        one.print();
      }
    }
};


int main() {
  queue<datanode> *Q = new queue<datanode>;

  Q->enq(datanode(1));
  Q->print();

  Q->enq(datanode(2));
  Q->print();

  Q->deq();
  Q->print();

  Q->deq();
  Q->print();

  Q->enq(datanode(3));
  Q->print();
  Q->deq();
  Q->print();

  return 0;
}

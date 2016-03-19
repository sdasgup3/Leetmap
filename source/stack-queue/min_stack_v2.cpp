#include<iostream>
#define K 5

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
    bool operator==(const datanode &d) {
      return i == d.i;
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

    T peek() {
      return head->data;
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

template <class T>
class stack_min: public stack<T> {
  private:
    stack<T> aux;

  public:
    stack_min(): stack<T>() {}

    void push(T data) {

      stacknode<T>* n = new stacknode<T>;
      n->data = data;

      if(aux.isEmpty()) {
        aux.push(data);
      } else {
        if(data <= aux.peek()) {
          aux.push(data);
        }
      }

      n->next = stack<T>::head;
      stack<T>::head = n;
      stack<T>::size++;
    }

    T pop() {
      if(stack<T>::head == NULL) {
        std::cerr<< "pop from empty";
        return 0;
      }

      stacknode<T>* tbd = stack<T>::head;
      stack<T>::head = stack<T>::head->next;
      stack<T>::size --;
      T ret = tbd->data;

      if(ret == aux.peek()) {
        aux.pop();
      }

      delete tbd;
      return ret;
    }

    T findMin() {
      if(aux.isEmpty()) {
        std::cerr << "Stack empty";
        return -1;
      }
      return aux.peek();
    }

};

int main() {
  stack_min<datanode> *s = new stack_min<datanode>;

  std::cout << "Min : " << s->findMin().i << std::endl;
  s->push(datanode(53));
  s->print();
  std::cout << "Min : " << s->findMin().i << std::endl;

  s->push(datanode(53));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(54));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(54));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(52));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(51));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(50));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->push(datanode(50));
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;
  s->pop();
  s->print();
  std::cout << "Min : " << s->findMin() << std::endl;

  return 0;
}

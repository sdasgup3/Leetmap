#include<iostream>
#define K 5

typedef struct _Node {
    int data;
    struct _Node* next;
} node;

class stack {
  private:
    int size;
    node* head;

  public:
    stack():size(0), head(NULL) {}

    void push(int data) {
      node* n = new node;
      n->data = data;

      n->next = head;
      head = n;
      size++;
    }

    int pop() {
      if(head == NULL) {
        std::cerr<< "pop from empty";
        return 0;
      }

      node* tbd = head;
      head = head->next;
      size --;
      int ret = tbd->data;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return head == NULL;
    }
    void print() {
      node* tmp = head;
      while(tmp) {
        std::cout << tmp->data; 
        tmp = tmp->next;
      }
    }
};

class queue {
  private:
    int size;
    node* head;
    node* last;

  public:
    queue():size(0), head(NULL), last(NULL) {}

    void enq(int data) {
      node* n = new node;
      n->data = data;
      n->next = NULL;

      if(NULL == head) {
        head = last = n;
      } else {
        last->next = n;
        last = n;
      }
      size++;
    }

    int deq() {
      if(head == NULL) {
        std::cerr<< "deq from empty";
        return 0;
      }

      size --;
      if(head == last) {
        last =  NULL;
      }
      node* tbd = head;
      head = head->next;
      int ret = tbd->data;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return head == NULL;
    }

    void print() {
      node* tmp = head;
      while(tmp) {
        std::cout << tmp->data << " "; 
        tmp = tmp->next;
      }
      std::cout << "\n";
    }
};

class queue_array {
  private:
    int *arr;
    int head;
    int last;

  public:
    queue_array():head(-1), last(-1)  {
      arr = new int[K];
    }

    void enq(int data) {
      if((last + 1)%K == head) {
        std::cerr<<"Full\n";
        return;
      }

      if(-1 == head) {
        head = last = 0;
      } else {
        last = (last  +1 )%K;
      }
      arr[last] = data;
    }

    int deq() {
      if(head ==  -1) {
        std::cerr << "Nothing to delete";
        return 0;
      }
      int ret = arr[head];

      if(head == last) {
        head = last = -1;
      } else {
        head = (head  +1 )%K;
      }
      return ret;
    }

    bool isEmpty() {
      return head == -1;
    }

    void print() {
      int i = 0;
          std::cout << "<"<< head << " " << last << ">\n"; 
        while(i < K) {
          std::cout << arr[i] << " "; 
          i = i +1 ;
        }
      std::cout << "\n";
    }
};


int main() {
  stack *s = new stack;
  std::cout << "Is empty : " << s->isEmpty() << std::endl;
  s->push(1);
  s->push(2);
  s->push(3);
  std::cout << "Is empty : " << s->isEmpty() << std::endl;
  s->pop();
  s->pop();
  s->pop();
  std::cout << "Is empty : " << s->isEmpty() << std::endl;

  queue *q = new queue;
  q->enq(1);
  q->print();
  q->enq(2);
  q->print();
  q->enq(3);
  q->print();
  q->deq();
  q->print();
  q->deq();
  q->print();
  q->deq();
  q->print();
  q->enq(1);
  q->print();

  queue_array *Q = new queue_array;
  Q->enq(1);
  Q->print();
  Q->enq(2);
  Q->print();
  Q->enq(3);
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();
  Q->enq(4);
  Q->print();
  Q->enq(5);
  Q->print();
  Q->enq(6);
  Q->print();
  Q->enq(7);
  Q->print();
  Q->enq(8);
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();
  Q->deq();
  Q->print();




  return 0;
}

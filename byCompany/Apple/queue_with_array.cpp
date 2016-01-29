#include<iostream>
using namespace std;

template <class T>
class queue {
  private:
    int *arr;
    int start, end;
    int size;
  public:
    queue() {
      start = end = 0;
      size = 5;
      arr = new int[size];
    }
    void enq(T data) {

      int index  = (end+1)%size;
      if(index == start) {
        cout << "Cannot enq\n";
        return;
      }
      end  = index;
      arr[end] = data;
      cout << "Enqued at " << end << "\n" ;
    }

    T deq() {
      if(start == end) {
        cout << "\nNoting to deq";
        return T();
      }

      int index = (start+1)%size;
      T ret =  arr[index];
      arr[index] = -1;
      cout << "Dequed from " << index << "\n" ;

      if(index == end) {
        start = end = 0;
      } else {
        start = index;
      }
      return ret;
    }

    void print() {
      int i = start; 
      int j = end;
      if(i == j) {
        return;
      }
      for(int i = 0; i < size; i++) {
        cout << arr[i] << " " ;
      }
      cout << "\n" ;
    }

};

int main()
{
  queue<int> Q;
  Q.enq(1);
  Q.print();
  Q.enq(2);
  Q.print();
  Q.enq(3);
  Q.print();
  Q.enq(4);
  Q.print();
  Q.enq(5);
  Q.print();
  Q.deq();
  Q.print();
  Q.deq();
  Q.print();
  Q.deq();
  Q.print();
  Q.deq();
  Q.print();
  Q.deq();
  Q.print();
  Q.enq(6);
  Q.print();
  Q.deq();
  Q.print();

}

/*
      }

      while(1) {
        i = (i+1)%size;
        if(i > j) {
          break;
        }

        cout << arr[i] << " ";
      }

       cout << "\n";
    }
    */

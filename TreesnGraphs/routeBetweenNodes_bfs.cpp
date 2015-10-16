#include<iostream>
#define V 6

template<class T>
class  queuenode {
  public:
    T data;
    queuenode<T>* next;
};

template<class T>
class queue {
  private:
    int size;
    queuenode<T>* head;
    queuenode<T>* last;

  public:
    queue():size(0), head(NULL), last(NULL) {}

    void enq(T data) {
      queuenode<T>* n = new queuenode<T>;
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

    T deq() {
      if(head == NULL) {
        std::cerr<< "deq from empty";
        return 0;
      }

      size --;
      if(head == last) {
        last =  NULL;
      }
      queuenode<T>* tbd = head;
      head = head->next;
      T ret = tbd->data;
      delete tbd;
      return ret;
    }

    bool isEmpty() {
      return head == NULL;
    }

    void print() {
      queuenode<T>* tmp = head;
      while(tmp) {
        std::cout << tmp->data << " "; 
        tmp = tmp->next;
      }
      std::cout << "\n";
    }
};

struct _AJLnode ;
typedef struct _Node {
  int v;
  bool visited;
  struct _AJLnode* list;
} node;

typedef struct _AJLnode {
  node* link;
  struct _AJLnode * next;
} AJLnode;

void print(node** g)
{
  for(int i = 0 ; i <  V; i++){
    std::cout << g[i]->v << " : " ;
    AJLnode* list = g[i]->list;
    while(list) {
      std::cout << list->link->v << " " ;
      list = list->next;
    }
    std::cout << "\n";
  }
}

void 
insert(node** g, int src, int dest) {

  AJLnode* n = new AJLnode;
  n->next = NULL;
  n->link = g[dest];

  if(NULL == g[src]->list) {
    g[src]->list = n;
  } else {
    n->next = g[src]->list;
    g[src]->list = n;
  }
}

bool isPath(node** g, int src, int dest)
{
  queue<node*> worklist;
  worklist.enq(g[src]);

  while(false == worklist.isEmpty()) {
    node* p = worklist.deq();
    
    if(p->v == dest) return true;


    if(p->visited == true) {
      continue;
    }
    
    p->visited = true;
    AJLnode* list = p->list;
    while(list) {
      worklist.enq(list->link);
      list = list->next;
    }
  }
   return false;
}



int main() {
    /* Let us create the following weighted graph
       (0)------->(1)<-------(2)
        | \         |\        /|\
        |  \        | \        |
        |   \       |  \       |
       \|/   \      V   \----> |
       (5)    ---> (4)<------(3)
     */
    node* graph[V];

    for(int i = 0; i< V; i++) {
      graph[i] = new node;
      graph[i]->v = i;
      graph[i]->list = NULL;
      graph[i]->visited = false;
    }
      
    insert(graph, 0,1);
    insert(graph, 0,5);
    insert(graph, 0,4);

    insert(graph, 1,3);
    insert(graph, 1,4);

    insert(graph, 2,1);

    insert(graph, 3,2);
    insert(graph, 3,4);
      
    print(graph);
    for(int i = 0 ; i < V; i++) {
      for(int j = 0 ; j < V; j++) {
        std::cout << " " << i << " " << j << " : "<<  isPath(graph, i,j) << "\n";
        for(int k = 0; k< V; k++) {
          graph[k]->visited = false;
        }
      }
    }
    return 0;
}

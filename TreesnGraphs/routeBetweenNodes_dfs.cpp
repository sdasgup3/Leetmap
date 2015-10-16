#include<iostream>
#define V 6

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

bool isPath(node* g, int dest)
{
  if(g->v == dest) return true;

  g->visited = true;
  AJLnode* list = g->list;
  for(;list;list = list->next) {
    if(true == list->link->visited) {
      continue;
    }
    if(true == isPath(list->link, dest)) {
      return true;
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
        std::cout << " " << i << " " << j << " : "<<  isPath(graph[i],j) << "\n";
        for(int k = 0; k< V; k++) {
          graph[k]->visited = false;
        }
      }
    }
    return 0;
}

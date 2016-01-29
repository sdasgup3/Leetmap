#include<iostream> 
#include<vector> 
#include<climits> 
#include<cassert> 
#include<queue> 
#define V 9

class node {
  public:
    node(int a, int b): id(a), dist(b) {}
    int id;
    int dist;
};

bool
operator<(const node& a,const  node& b) {
  return a.dist > b.dist;
}

std::vector<int>
dijkstra(int graph[V][V], int start) 
{
  std::vector<int> dist(V, INT_MAX);
  std::vector<int> parent(V, -1);
  std::priority_queue<node> Q;
  std::vector<bool> visited(V, false);


  Q.push(node(0,0));
  dist[0] = 0;
  parent[0] = 0;

  while(false == Q.empty()) {

    node minNode = Q.top();
    Q.pop();
    int minI = minNode.id;


    visited[minI] = true;

    for(int i = 0; i < V; i++) {
      if(i == minI || 0 == graph[minI][i] || true == visited[i]) {
        continue;
      }

      if(dist[minI] + graph[minI][i] < dist[i]) {
        dist[i] = dist[minI] + graph[minI][i];
        Q.push(node(i, dist[i]));
        parent[i] = minI;

      }
    }
  }

  //print
  for(int v = 0 ; v < V; v++) {
    std::cout << v << " : " << dist[v] << " " << v << "--" << parent[v] << " \n";
  }

  return parent;
}

void
getPath(std::vector<int> T, int start, int end)
{
  if(end == start) {
    std::cout << start << " ";
    return;
  }
  getPath(T, start, T[end]);
  std::cout << end << " ";
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {
            //         0    1   2   3   4   5   6   7   8    
                      {0,   4,  0,  0,  0,  0,  0,  8, 0},
                      {4,   0,  8,  0,  0,  0,  0, 11, 0},
                      {0,   8,  0,  7,  0,  4,  0,  0, 2},
                      {0,   0,  7,  0,  9,  14, 0,  0, 0},
                      {0,   0,  0,  9,  0,  10, 0,  0, 0},
                      {0,   0,  4,  14, 10,  0,  2,  0, 0},
                      {0,   0,  0,  0, 0,   2,  0,  1, 6},
                      {8,   11, 0, 0,   0,  0,  1,  0, 7},
                      {0,   0,  2, 0,   0,  0,  6,  7, 0}
                     };
 
   std::vector<int > T = dijkstra(graph, 0);
   getPath(T, 0, 4);
   return 0;
}

#include<iostream>
#define V 4

void print(int reach[][V])
{
    printf ("\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf ("%d ", reach[i][j]);
        printf("\n");
    }
}

void transitiveClosure(int graph[V][V])
{
  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
}

int main() {
    /* Let us create the following weighted graph
       (0)------->(3)
        |         /|\
        |          |
        |          | 
       \|/         |
       (1)------->(2)
     */
    int graph[V][V] = { 
                        {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
 
    // Print the solution
    print(graph);
    transitiveClosure(graph);
    print(graph);
    return 0;
}

#include<iostream>
#include<vector>
#define N 9
int offset_x[] = {1,   0};
int offset_y[] = {0,   1};

void printSolution(std::vector<std::pair<int, int>> &S)
{
    int sol[N][N] = { 
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    std::vector<std::pair<int, int>>::iterator iterB = S.begin();
    std::vector<std::pair<int, int>>::iterator iterE = S.end();
    for (;iterB !=  iterE; iterB++) {
       sol[(*iterB).first][(*iterB).second] = 1;
    }

    for (int i = 0 ; i < N; i++ ) {
      for (int j = 0 ; j < N; j++ ) {
            printf(" %d ", sol[i][j]);
      }
      printf("\n");
    }
      printf("\n");
      printf("\n");
}

bool
isSafe(int maze[N][N], int x, int y) {
  if(x >= 0 && x <= N-1 && y >= 0 && y <= N-1 && 1 == maze[x][y]) return true;

  return false;
}

bool
solve(int maze[N][N],   std::vector<std::pair<int, int>> &S, std::pair<int, int> p) 
{
  
  int last_move_x = p.first;;
  int last_move_y = p.second;

  if(true == isSafe(maze, last_move_x, last_move_y)) {
    S.push_back(p);
    if(last_move_x == N-1 && last_move_y == N-1) {
      printSolution(S);
      return true;
    }

    for(int i = 0 ; i < sizeof(offset_x)/sizeof(offset_x[0]); i++) {
      int next_move_x = last_move_x + offset_x[i];
      int next_move_y = last_move_y + offset_y[i];
      //if(true == solve(maze, S, std::pair<int, int>(next_move_x, next_move_y)))
      solve(maze, S, std::pair<int, int>(next_move_x, next_move_y));
    } 
    S.pop_back();
  }

  return false;
}


bool solveMaze(int maze[N][N])
{
    std::vector<std::pair<int, int>> S;
 
    if(solve(maze, S, std::pair<int , int>(0,0)) == false)
    {
        printf("Solution doesn't exist");
        return false;
    } else {
      for (int i = 0 ; i < N; i++ ) {
        for (int j = 0 ; j < N; j++ ) {
            printf(" %d ", maze[i][j]);
        }
        printf("\n");
      }
        printf("\n");
        printf("\n");

      printSolution(S);
      return true;
    }
}



// driver program to test above function
int main()
{
    int maze[N][N]  =  { 
        {1, 0, 0, 0, 1, 0, 0, 0,  0},
        {1, 1, 0, 1, 1, 1, 1, 1,  0},
        {0, 1, 0, 0, 1, 0, 1, 1,  0},
        {1, 1, 1, 1, 1, 1, 1, 1,  0},
        {1, 0, 0, 0, 1, 0, 1, 1,  0},
        {1, 1, 0, 1, 1, 1, 0, 1,  0},
        {0, 1, 0, 0, 1, 0, 0, 1,  0},
        {1, 1, 1, 1, 1, 0, 0, 1,  0},
        {1, 1, 1, 1, 1, 0, 0, 1,  1}
    };
 
    solveMaze(maze);
    return 0;
}

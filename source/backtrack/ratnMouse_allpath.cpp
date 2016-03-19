#include<iostream>
#include<vector>
#define N 9
int offset_x[] = {1,   0, -1, 0};
int offset_y[] = {0,   1, 0, -1};

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
    printf("\n\n\n");
}

bool
isSafe(int maze[N][N], int x, int y) {
  if(x >= 0 && x <= N-1 && y >= 0 && y <= N-1 && 1 == maze[x][y]) return true;

  return false;
}

bool
solve(int maze[N][N],   std::vector<std::pair<int, int>> &S) 
{
  int next_move_x;
  int next_move_y;
  
  std::pair<int , int> last_sol = S.back();
  int last_move_x = last_sol.first;;
  int last_move_y = last_sol.second;

  for(int i = 0 ; i < sizeof(offset_x)/sizeof(offset_x[0]); i++) {
    next_move_x = last_move_x + offset_x[i];
    next_move_y = last_move_y + offset_y[i];

    if(true == isSafe(maze, next_move_x, next_move_y)) {
      //std::cout << next_move_x << " " << next_move_y << std::endl;
      S.push_back(std::pair<int , int>(next_move_x,next_move_y));
      maze[next_move_x][next_move_y] = 0; 

      if(next_move_x == N-1 && next_move_y == N-1) {
        printSolution(S);
      } else {
        solve(maze, S);
      }

      std::pair<int , int> temp = S.back();
      //std::cout << "pop " << temp.first << " " << temp.second << std::endl;
      maze[temp.first][temp.second] = 1;
      S.pop_back();
    } 
  }
}


bool solveMaze(int maze[N][N])
{
    std::vector<std::pair<int, int>> S;
    S.push_back(std::pair<int , int>(0,0));
 
    solve(maze, S);
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
    /*
  int maze[N][N]  =  { 
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    */
 
    solveMaze(maze);
    return 0;
}

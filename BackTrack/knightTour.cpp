#include<iostream>
#include<vector>
#define N 8

int offset_x[] = {2, 1,  -1,  -2,  2,   -2,       1,    -1};
int offset_y[] = {1, 2,   2,  1,  -1,   -1,       -2,   -2};

void printSolution(std::vector<std::pair<int, int>> &S)
{
    int sol[N][N] ;
    for(int i =0; i<8; i++) {
      for(int j =0; j <8; j++) {
        sol[i][j] = -1;
      }
    }

    for(int i = 0 ; i < N*N; i++) {
      std::pair<int , int> p = S[i];
      sol[p.first][p.second] = i;
    }

    for (int i = 0 ; i < N; i++ ) {
      for (int j = 0 ; j < N; j++ ) {
            printf(" %d ", sol[i][j]);
      }
      printf("\n");
    }
}

bool
isSafe(int playg[N][N], int x, int y) {
  if(x >= 0 && x <= N-1 && y >= 0 && y <= N-1 && -1 == playg[x][y]) return true;

  return false;
}

bool
solve(int playg[8][8], std::vector<std::pair<int, int>> &S) 
{
  int next_move_x;
  int next_move_y;
  
  std::pair<int , int> last_sol = S.back();
  int last_move_x = last_sol.first;;
  int last_move_y = last_sol.second;

  for(int i = 0 ; i < sizeof(offset_x)/sizeof(offset_x[0]); i++) {
    next_move_x = last_move_x + offset_x[i];
    next_move_y = last_move_y + offset_y[i];

      //std::cout << "Trying : " << next_move_x << " " << next_move_y << std::endl;
    if(true == isSafe(playg, next_move_x, next_move_y)) {
      //std::cout << next_move_x << " " << next_move_y << std::endl;
      S.push_back(std::pair<int , int>(next_move_x,next_move_y));
      playg[next_move_x][next_move_y] = 0;

      if(S.size() == N*N) {
        return true;
      } 

      if(solve(playg, S)) return true;
      
      playg[next_move_x][next_move_y] = -1;
      S.pop_back();
    } 
  }
  return false;
}


bool solveKT()
{

    int playg[8][8];
    for(int i =0; i<8; i++) {
      for(int j =0; j <8; j++) {
        playg[i][j] = -1;
      }
    }
 
    std::vector<std::pair<int, int>> S;
    S.push_back(std::pair<int , int>(0,0));
    playg[0][0]  = 0;

    if(solve(playg, S) == false)
    {
        printf("Solution doesn't exist");
        return false;
    } else {
      printSolution(S);
      return true;
    }
}



// driver program to test above function
int main()
{
    solveKT();
    return 0;
}

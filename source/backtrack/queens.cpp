#include<iostream>
#include<vector>
#define N 8

int offset_x[] = {2, 1,  -1,  -2,  2,   -2,       1,    -1};
int offset_y[] = {1, 2,   2,  1,  -1,   -1,       -2,   -2};

void printplayg(int playg[N][N]) {
    for (int i = 0 ; i < N; i++ ) {
      for (int j = 0 ; j < N; j++ ) {
            printf(" %d ", playg[i][j]);
      }
      printf("\n");
    }
}
void printSolution(std::vector<std::pair<int, int>> &S)
{
    int sol[N][N] ;
    for(int i =0; i<8; i++) {
      for(int j =0; j <8; j++) {
        sol[i][j] = 0;
      }
    }

    for(int i = 0 ; i < S.size(); i++) {
      std::pair<int , int> p = S[i];
      sol[p.first][p.second] = 1;
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
isSafe(int x, int y,std::vector<std::pair<int, int>> &S) {
    for(int i = 0 ; i < S.size(); i++) {
      std::pair<int , int> p = S[i];
      if(y == p.second) {
        return false;
      }

      for(int i = p.first, j = p.second; i <= 7 && j <= 7; i++, j++) {
        if(x == i && y == j) {
          return false;
        }
      }
      for(int i = p.first, j = p.second; i <= 7 && j >= 0 ; i++, j--) {
        if(x == i && y == j) {
          return false;
        }
      }
    }

    return true;
}


bool
solve(int playg[8][8], std::vector<std::pair<int, int>> &S, int last_move_x) 
{
  int next_move_x;
  int next_move_y;
  
  next_move_x = last_move_x + 1;
  for(int i = 0 ; i < 8; i++) {
    next_move_y =  i;

      //std::cout << "Trying : " << next_move_x << " " << next_move_y << std::endl;
    if(true == isSafe(next_move_x, next_move_y, S)) {
      //std::cout << next_move_x << " " << next_move_y << std::endl;
      S.push_back(std::pair<int , int>(next_move_x,next_move_y));

      if(next_move_x == 7) {
        printSolution(S);
      } else { 
        solve(playg, S, next_move_x);
      }
      
      //std::cout <<"pop " <<  next_move_x << " " << next_move_y << std::endl;
      S.pop_back();
      //printplayg(playg);
    } 
  }
  return false;
}

bool solveKT()
{

    int playg[8][8];
    for(int i =0; i<8; i++) {
      for(int j =0; j <8; j++) {
        playg[i][j] = 1;
      }
    }
 
    std::vector<std::pair<int, int>> S;

    solve(playg, S, -1);
}



// driver program to test above function
int main()
{
    solveKT();
    return 0;
}

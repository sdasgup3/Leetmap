/* Problem Description
*/

#include"header.h"

typedef pair<int, int>P;

class mycompare {
  public:
    bool operator() (const P a, const P b) const{
      return a.first > b.first;
    }

};

typedef bool (*fty) (P a, P b);
bool X(P a, P b) {
      return a.first > b.first;
}

class Solution {

public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    //priority_queue<P, vector<P>, X > Q;
    mycompare cmp;
    //priority_queue<P, vector<P>, decltype(cmp) > Q(cmp);
    priority_queue<P, vector<P>, fty > Q(X);
    int r = matrix.size();
    int c = matrix[0].size();

    for(int i = 0 ; i < r ; i ++) {
      Q.push(pair<int, int>(matrix[i][0], i));
    }

    vector<int> posn(r,1);

    int count = 0;
    while(false == Q.empty()) {
      P p = Q.top();
      Q.pop();
      int row_to_pick = p.second;
      int curr_index = posn[p.second];
      if(curr_index < c)  {
        Q.push(pair<int, int> (matrix[row_to_pick][curr_index], row_to_pick) );
        posn[row_to_pick]++;
      }
      count++;
      if(count == k) {
        return p.first;
      }
    }

    return -1;
  }
private:

};

int main() {
  Solution S;

  vector<vector<int>> D;
  D.push_back({1,5,9});
  D.push_back({10,11,13});
  D.push_back({12,13,15});

  for(int i = 1; i <= 9 ; i++) {
    cout << S.kthSmallest(D, i) << "\n";
  }

  return 0;
}

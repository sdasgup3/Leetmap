/* Problem Description
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Solution:
Tags:
Priority Queue
*/

#include"header.h"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<int, pair<int, int>> P;
        
        auto cmp = [&] (P p1, P p2) {
          return p1.first > p2.first;  
        };
        priority_queue<P, vector<P>, decltype(cmp)> Q(cmp);
        
        //initialize the PQ
        for(int i = 0 ; i < matrix.size(); i++) {
            Q.push(P(matrix[i][0], pair<int, int>(i, 0)));
        }
        
        int count = 0;
        while(!Q.empty()) {
            P p = Q.top();
            count ++;
            if(k == count) {
                return p.first;
            }
            Q.pop();
            int r = p.second.first;
            int c = p.second.second;
            
            if(c +1 < matrix[r].size()) {
                Q.push(P(matrix[r][c+1],pair<int, int>(r,c+1)));
            }
        }
        
        return -1;
    }
};

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

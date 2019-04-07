#include"header.h"
class Solution1 {
    private:
        vector<vector<int>> V;
        int count;
public:
    typedef pair<int, int> P;
    //P findrep(vector<vector<P>> &REP, int r, int c) {
    //    while(1) {
    //        P p = REP[r][c];
    //        if(p.first == r && p.second == c) {
    //            return p;
    //        }
    //        r = p.first;
    //        c = p.second;
    //    }
    //}
     P findrep(const vector<vector<P>> &REP, int r, int c) {
           // P p = REP[r][c];
            
        while(!(REP[r][c].first == r && REP[r][c].second == c)) {
            r = REP[r][c].first;
            c = REP[r][c].second;
         // p = REP[r][c];
            
        }
        
        return REP[r][c];
    }

    void unionrep(vector<vector<P>> &REP, P p1, P p2) {
        REP[p1.first][p1.second] = {p2.first, p2.second};
    }
    
    void helper(vector<vector<P>> &REP, int x, int y, int r, int c, int m, int n, bool &first) {
        if(x >= 0 && x < m && y >= 0 && y < n &&  V[x][y] == 1) {
            P P1 = findrep(REP, x,y);
            P P2 = findrep(REP, r,c);
            if(P1 != P2) {
                if(!first)
                    count--;
                else 
                    first = false;
                unionrep(REP, P1, P2);
            }
        }
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<P>> REP(m, vector<P>(n));
        V.resize(m);
        for(int i = 0 ; i < m; i++) {
            V[i].resize(n, 0);
        }
        
        vector<int> res;
        count = 0;
        
        for(auto p : positions) {
            int r = p.first;
            int c = p.second;
            V[r][c] = 1;
            REP[r][c] = pair<int, int>(r,c);
            bool first = true;
            
           
            helper(REP, r+1, c, r, c, m,n,first);
            helper(REP, r-1, c, r, c, m,n,first);
            helper(REP, r, c+1, r, c, m,n,first);
            helper(REP, r, c-1, r, c, m,n,first);
            
            if(!first)
                res.push_back(count);
            else 
                res.push_back(++count);
        }
        
        return res;
        
    }
};

class Solution {
  typedef pair<int, int> P;
      
    public:
    bool checkValid(int x, int y, int m, int n, const vector<vector<int>> &V) {
        if(x < 0 || x >= m || y < 0 || y >= n || V[x][y] == 0) {
            return false;
        }
        return true;
    }
    
    P findRep(const vector<vector<P>> &R, int x, int y) {
        while(R[x][y].first != x || R[x][y].second != y) {
            x = R[x][y].first; /// flow dependence
            y = R[x][y].second;
        }
        
        return P(x, y);
    }
    
    void myunion(vector<vector<P>> &R, P x, P y) {
        R[x.first][x.second] = y;
    }
    
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        
        vector<vector<P>> R(m, vector<P>(n));
        vector<vector<int>> V(m, vector<int>(n, 0));
        
        for(int i = 0 ; i < m;  i ++) {
            for(int j = 0 ; j < n;  j ++) {
                R[i][j] = P(i, j);
            }
        }
        
        
        vector<int> retval;
        int count = 0;
        int D[4][2] = {{1, 0}, {-1,0}, {0,1}, {0,-1}}; 
        for(auto posn: positions) {
            count ++;
            int x = posn.first;
            int y = posn.second;
            V[x][y] = 1;
            
            for(int i = 0 ; i < 4; i++) {
                int nx = x + D[i][0];
                int ny = y + D[i][1];
                
                if(!checkValid(nx, ny, m, n, V)) {
                    continue;
                }
                
                // got a ngh
                P p = findRep(R, x, y);
                P q = findRep(R, nx, ny);
                if(p != q) {
                  myunion(R, p, q);
                  count --;
                }
            }
            
            retval.push_back(count);
            
        }
        
        return retval;
    }
};



int main() {
  Solution S;
  Solution1 S1;

  //vector<pair<int, int>> D({{0,0},{0,1},{1,2},{2,2}, {2,0}, {1,1} });
  vector<pair<int, int>>D1({{0,1},{1,2},{2,1},{1,0},{0,2},{0,0},{1,1}});

  //cout << S.numIslands2(3, 3, D1);
  cout << S1.numIslands2(3, 3, D1);

  return 0;
}

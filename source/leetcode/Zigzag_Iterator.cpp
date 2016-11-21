/* Problem Description
*/

#include"header.h"

class ZigzagIterator {
    private:
        int which_vec;
        vector<int>posn;
        vector<vector<int> > V;
public:
    ZigzagIterator(vector<vector<int> > & v) {
        which_vec = 0;
        posn.reserve(v.size());
        for(auto &c : posn) {
          c = 0;
        }
        V=v;
    }

    int next() {
        int t ;
        int s = V.size();

        int start = which_vec;
        int end = (which_vec-1)%s;
        int i = start;
        do {
          if(posn[i] < V[i].size()) {
               t = V[i][posn[i]++]; 
               which_vec = (which_vec+1)%s;
               break;
          } else {
            i = (i+1)%s;
          }
        } while(i != start);
        return t;
    }

    bool hasNext() {
      int s = V.size();
      for(int i = 0 ; i < s ; i++) {
        if(posn[i] < V[i].size()) {
          return true;
        }
      }
      return false;
    }
};



int main() {

  vector<vector<int> > V;

  V.push_back({1,2,3});
  V.push_back({4,5,6, 7});
  V.push_back({8,9});

  auto it = ZigzagIterator(V);
  while(it.hasNext()) {
    cout << it.next() << "\n";
  }
  return 0;
}

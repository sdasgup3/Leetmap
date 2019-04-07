/* 
 * Problem Description
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].

 * Solution
 Here the key is check all the vectors for yielding a next.
 this checjing invloves checking all the indexes in a circular array

  Ex. Let index = i 
  0  ..i-1  i .. n-1 
We need to check i, i+1,... , 0, ..., i-1
for that we need a do while

runner =  i;
do {
//check with runner
//
/runneri  = (runner+1)%n

} while(runner != i);




 * Tags
 Design, Iterator
*/

#include"header.h"

class ZigzagIterator1 {
    private:
    int turn; 
    vector<int> posn;
    vector<int> limits;
    vector<vector<int>> V;
    int K;
public:
    ZigzagIterator1(int k, vector<vector<int>>& V) {
        posn.resize(k,0);
        limits.resize(k,0);
        for(int i = 0 ; i < k ;  i++) {
          limits[i] = V[i].size();
        }
        this->V = V;
        turn  = -1;
        K = k;
    }

    int next() {
      posn[turn] ++;
      return V[turn][posn[turn]-1];
    }

    bool hasNext() {

      turn = (1 +turn)%K;

      int runner = turn;
      do {
        if(posn[runner] < limits[runner])  {
          turn   = runner;
          return true;
        } 

        runner = (runner +1 )%K;
      } while(runner != turn);

      return false;
    }
};

class ZigzagIterator {
    private:
    int turn;
    int k;
    vector<int> posn;
    vector<int> end;
    vector<vector<int>> V;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        k = 2;
        V.push_back(v1);
        V.push_back(v2);
        
        turn  = k-1;
        posn.resize(k,0);
        end.resize(k);
        
        for(int i = 0 ; i < k ;i ++) {
            end[i] = V[i].size();
        }
        
    }

    int next() {
        int val = V[turn][posn[turn]];
        posn[turn] ++;
        return val;
    }

    bool hasNext() {
        turn = (turn +1)%k;
        
        int runner = turn;
        do {
            if(posn[runner] < end[runner]) {
                turn  = runner;
                return true;
            }
            
            runner = (runner + 1)%k;
            
        } while (runner != turn);
        
        return false;
    }
};


int main() {

  vector<vector<int>> V;
  V.push_back({1,2});
  V.push_back({3,4,5});
  V.push_back({6,7,8,9});

  ZigzagIterator Z(V[0], V[1]);
  while (Z.hasNext()) 
    cout << Z.next() << "\n";

  return 0;
}

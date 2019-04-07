/* 
 * Problem Description
 Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]

 * Solution
Same idea as Meeting rooms 2
1   5
  2   6
record the changes for each time 
1 1 -1 -1

sort the changes based on time

now have a runner
  1   5
    2   6
  1 1 -1 -1

R 1 2 1  0
0 indicate that we got a merged interval


Second:
sort the intervals
for adjacent intervlas

i1 and i2
start = i1.start
if i1.second >= i2.second
end = max(i1.second, i1.second)



 * Tags
 Sort
*/

#include"header.h"

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

ostream &operator<<(ostream &OS, Interval &I) {
  OS << I.start << " " << I.end << "\n";
    return OS;
}




class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        vector<pair<int, int>> V;
        for(auto i : intervals) {
            V.push_back({i.start,1});
            V.push_back({i.end,-1});
        }
        
        //sort(V.begin(), V.end());
        sort(V.begin(), V.end() ,
            [&](pair<int, int> a, pair<int, int>b ) {
                if(a.first < b.first) {
                    return true;
                }
                if(a.first == b.first) {
                    return a.second > b.second;
                }
                
                return false;
            }    
        
        );
        cout << V;
        int start = -1, end, runner = 0;
        for(auto p : V) {
            if(-1 == start) {
                start = p.first;
            }
            runner += p.second;
            if(0 == runner) {
                end = p.first;
                res.push_back(Interval(start, end));
                start  = -1;
            }
        }
        
        return res;
    }
};


int main() {
  Solution S;

  vector<Interval> D;
  //D.push_back(Interval(1,3));
  //D.push_back(Interval(2,6));
  //D.push_back(Interval(8,10));
  //D.push_back(Interval(15,18));

  D.push_back(Interval(1,4));
  D.push_back(Interval(5,6));
  cout << S.merge(D);

  return 0;
}

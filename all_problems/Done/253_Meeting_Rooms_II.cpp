/*
   *Problem
   Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

*Solution
Case 1:
a1 a2  b1  b2 c2  c2

increment number of rooms on each start
decrement on each end

a1 a2  b1  b2 c2  c2
1  0   1   0  1   0

a1  a2
b1       b2
             c1  c2
2   1    0   1   0

a1  a2
b1           b2
          c1     c2
2   1     2   1   0


a1    a2
      b1   b2
   c1      c2
1  2  2    0

a1            a2
b1  b2 c1     c2
2   1   2     0


How to get this
a1    a2
      b1   b2
   c1      c2
1  2  2    0


First record the changes at each time

a1    a2 b1   b2 c1      c2
M[a1] = 1
M[a2] = 0 = M[b1]
M[c1] = 1
M[b2] = M[c2] = -2

Sort the changes according to time
a1  c1   a2,b1   b2,c2
1   1     0      -2

runner =  0
and add the changes
and find max val of runner

  a1  c1   a2,b1   b2,c2
  1   1     0      -2
R 1   2     2      0
max=  2

The changes can be stored on a map which will automatically do the sort 
also for
a1 a2
   b1  b2
There will be one entry in the map
M[b1 or a2] = 0

If we use vector of pairs
First we have to sort by times (pair.first)
also for
a1 a2
   b1  b2
There will be 2 entry in the vector
(a2,-1)
(b1,1)
  and their order matters

  because we we consider the following order

(a1, 1) (b1,1)  (a2 -1) (b2 -1) 
  we erroniiously calculate maxroom  = 2

  So while dorting we have to maintain the correct order
(a1, 1) (a2 -1) (b1 1) (b2 -1) 


*Tags:
Sort
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool compare(Interval a, Interval b) {
     if(a.start == b.start) {
         return a.end > b.end;
     }
  return a.start < b.start ;
}
class Solution {
public:


    int minMeetingRooms(vector<Interval>& intervals) {
        
        int res = 0;
        vector<pair<int, int>> V;
        
        
        for(auto i: intervals) {
            V.push_back({i.start, +1});
            V.push_back({i.end, -1});
        }
        
        sort(V.begin(), V.end(), 
            [&](pair<int, int> a, pair<int, int> b) {
                if(a.first < b.first) {
                    return true;
                } 
                if(a.first == b.first) {
                    return a.second < b.second;
                }
                
                return false;
            }
        );
        int runner=0;
        for(auto p: V) {
            runner += p.second;
            res = max(res, runner);
        }
        return res;
    }
};


int main ()
{
  Solution S;
  return 0;

}

/*
252	Meeting Rooms

Given an array of meeting time intervals consisting of first and second times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attsecond all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false. 
Given [[0, 5],[5, 10]
return true. 

 *Solution
 Here is all the intervals are disjoint(D) then only he can attend all the classs

 The only case to check is
 a1 b2...b1 b2...c1 c2

 Why sorting required:
 if D(I1, I2) == true and D(I2, I3) == true !=> D(I1, I3) = true

 (1 10) (11 20) (2 5)

 If the intervals are sorted, for intervals I1, I2, I3

 if I2.start >= I1.end ==> I3.start > I1.end

 The above is not ensured if the intervals are not sorted by start times

*Tags:
Sort
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef pair<int, int> Interval;

bool compare(Interval a, Interval b) {
  return a.first < b.first;
}

class Solution {
  public:
    bool canAttsecondMeetings(vector<Interval>& intervals) {
      sort(intervals.begin(), intervals.end(), compare);
      for(int i = 0 ; i < intervals.size() - 1; i++) {
        //if(intervals[i].first == intervals[i+1].first || intervals[i].second > intervals[i+1].first) {
        if(intervals[i].second > intervals[i+1].first) {
          return false;
        } 
      }

      return true;
    }
};

int main ()
{
  Solution S;

  vector<Interval> intervals;
  intervals.push_back(Interval(0,30));
  intervals.push_back(Interval(5,10));
  intervals.push_back(Interval(15,20));

  cout << S.canAttsecondMeetings(intervals);
  intervals.pop_back(); intervals.pop_back(); intervals.pop_back();

  intervals.push_back(Interval(0,5));
  intervals.push_back(Interval(0,10));
  cout << S.canAttsecondMeetings(intervals);

}

/* 
 * Problem Description
 Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

 * Solution

 Sort  the array based on max height
 also if the height is the same then sort on min k

sortarray: 70 71 61 50 52 44

for each n : sortarray
insert at posn n.k in result array

70 

70 71

70 61 71

50 70 61 71

50 70 52 61  71 

50 70 52 61 44  71 



 * Tags
 Sort
*/

#include"header.h"
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

      sort(people.begin(), people.end(), 
          [](pair<int, int> a, pair<int, int>b) {

            if(a.first > b.first) {
              return true;
            }
            if(a.first == b.first) {
              return a.second < b.second;
            }

            return false;
          }
          );

      vector<pair<int, int>> result;

      for(auto p : people) {
        result.insert(result.begin() + p.second, p);
      }

      return result;
        
    }
};


int main() {
  Solution S;

  vector<pair<int, int>> D;
  D.push_back({5,0});
  D.push_back({7,0});
  D.push_back({5,2});
  D.push_back({6,1});
  D.push_back({4,4});
  D.push_back({7,1});


  cout << S.reconstructQueue(D);

  return 0;
}

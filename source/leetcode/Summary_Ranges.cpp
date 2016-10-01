/* Problem Description
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

* 
*/

#include"header.h"
class Solution {

public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> R;
    size_t s = nums.size();
    if(s == 0) {
      return R;
    }
    int start = nums[0];
    int end;
    for(int i = 0; i < s-1 ; i++) {
      if(nums[i+1] != nums[i] +1) {
        end = nums[i];
        if(start == end) {
          R.push_back(to_string(start));
        } else {
          R.push_back(to_string(start) + "->" + to_string(end));
        }

        start = nums[i+1];
      }
    }

    end = nums[s-1];
    if(start == end) {
      R.push_back(to_string(start));
    } else {
      R.push_back(to_string(start) + "->" + to_string(end));
    }

    return R;
  }
private:

};


int main() {
  Solution S;

  //vector<int> D({0, 1,2,4,5,7});
  //vector<int> D({0});
  //vector<int> D({0,1});
  //vector<int> D({0,2});
  vector<int> D({0,2,3,4, 6});

  cout << S.summaryRanges(D);

  return 0;
}

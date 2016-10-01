/* Problem Description
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

#include"header.h"
class Solution {
public:
    int insert(vector<int>& nums, int n) {
      nums.push_back(n);
      int i;

      for(i = nums.size()-2; i >= 0 ; i--) {
        if(nums[i] > n) {
          nums[i+1] = nums[i];
        } else {
          break;
        }
      }
      nums[i+1] = n;
      return i+1;
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

      vector<string> R;
      if(lower > upper) {
        return R;
      }
  
      int lower_pos = insert(nums, lower);
      if(lower_pos > 0 && nums[lower_pos-1] == nums[lower_pos]) {
        lower_pos --;
      }
      //cout << nums;
      int upper_pos = insert(nums, upper);
      //cout << nums;

      int prev  = lower_pos;
      for(int i = lower_pos + 1 ; i <= upper_pos; i++) {
        int d = nums[i] - nums[prev];
        if(d > 1) {
          int start = nums[prev] +  1;
          if(prev == lower_pos) 
            start --; // to include nums[lower_pos] == lower

          int end = nums[i] -1;
          if(i == upper_pos) 
            end ++; // to include nums[upper_pos] == upper

          if(start == end) {
            R.push_back(std::to_string(start));
          } else {
            R.push_back(std::to_string(start) + "->" + std::to_string(end));
          }
        }
        prev = i;
      }

      return R;
    }
};


int main() {
  Solution S;

  vector<int> D({0, 1, 3, 50, 75});
  vector<int> D1({2, 5});
  vector<int> E;

  //cout << S.findMissingRanges(D, 0, 99);
  //cout << S.findMissingRanges(D, 4, 55);
  //cout << S.findMissingRanges(D1, 2, 5);
  cout << S.findMissingRanges(E, 1, 1);

  return 0;
}

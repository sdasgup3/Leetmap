#include "header.h"

class Solution {
public:
  bool checkPossibility(vector<int> &nums) {

    int count = 0;
    int first_violation = -1;

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] <= nums[i + 1]) {
        continue;
      }
      count++;
      if (count == 1) {
        first_violation = i;
      } else {
        return false;
      }
    }

    if (0 == count)
      return true;

    // count == 1
    int i = first_violation;
    if (i + 2 >= nums.size() || nums[i] <= nums[i + 2])
      return true;
    if (i - 1 < 0 || nums[i - 1] <= nums[i + 1])
      return true;
    return false;
  }
};

class RunTest {
public:
  void execute() {
    Testing<int> t;
    Solution s;

    t.v = vector<int>{4, 2, 3};
    cout << t.v;
    cout << s.checkPossibility(t.v) << "\n";

    t.v = vector<int>{4, 2, 1};
    cout << t.v;
    cout << s.checkPossibility(t.v) << "\n";

    t.v = vector<int>{3, 4, 2, 3};
    cout << t.v;
    cout << s.checkPossibility(t.v) << "\n";
  }
};

/* Problem Description
 * Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

#include"header.h"
class Solution {

public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        cout << nums;
        vector<int> R;
        int size = nums.size();
        for (int k = 0; k < size; k++) {
            nums[k] = (a * nums[k] + b) * nums[k] + c;
        }
        int i = 0, j = size - 1;
        while (i <= j) {
            if (nums[i] >= nums[j]) {
                R.push_back(nums[i++]);
            } else {
                R.push_back(nums[j--]);
            }
        }

        if(R[0] > R[R.size()]) {
          reverse(R.begin(), R.end());
        }

        cout << R;
        return R;
  }
private:

};


int main() {
  Solution S;

  vector<int> D({-2,-1,4,5});

  S.sortTransformedArray(D, 100000,-200,3);

  return 0;
}

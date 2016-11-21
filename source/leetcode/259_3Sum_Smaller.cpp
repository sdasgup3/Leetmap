/* Problem Description
 * Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?


Note:
1st algo:
i     j j' j''   k
* * * * *  *   * * * *
if(num[i] + nums[j] + nums[k] > k) and nums is sorted the u cannot choose any futher k
BUT can choose further i or j (like j' j'')


second:
      0   1 2 3 4 5
nums: -2 -1 0 1 2 3
target = 2
let k = 4
new_target =  target - nums[k] = 0

start = 0 
end = k-1 = 3
if: nums[start] + nums[end]  = -2 + 1 = -1 < 0
so all the following as the reuklts
-2 1 2
-2 0 2
-2 -1 2
i.e end - start = 3 results

then start++ => start = 1
if: nums[start] + nums[end]  = -1 + 1 = 0 !< 0
end--=> end = 2

if: nums[start] + nums[end]  = -1 + 0 = -1 < 0
-1 0 2
i.e 1 results


*/

#include"header.h"
class Solution {

public:
int threeSumSmaller(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int s = nums.size();
  int sum = 0 ;
  cout << nums;

  for(int k = 2 ; k < s ; k ++) {
    int new_target = target - nums[k];
    int start = 0;
    int end = k-1;
    cout << "k = " << k << "T= " << new_target << "\n";
    while(start < end) {
      cout << "\t" << start  << " " << end << " " << nums[start] + nums[end] <<  "\n";
      if(nums[start] + nums[end] >= new_target) {
        end--;
      } else {
        sum += (end - start);
        start++;
        cout << "\t" << start << " " << end << " " << sum <<  "\n";
      }
    }
  }

  return sum;        
}
private:

};


int main() {
  Solution S;

  vector<int> D({1,-1,2,0,3,-2});
  //vector<int> D({-2,0,1,3});

  cout << S.threeSumSmaller(D, 2);

  return 0;
}

/* Problem Description
 * Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

#include"header.h"

class Solution {
    private:
    vector<int> local_copy;
    vector<int> arrangement;
    int sz;
public:
    Solution(vector<int> nums) {
        sz = nums.size();
        local_copy.reserve(sz);
        arrangement.resize(sz);

        for(int i = 0 ; i < sz; i ++) {
          arrangement[i] = i;
        }

        local_copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        vector<int> local_copy2(sz);
        for(int i = 0 ; i < sz ; i++) {
            local_copy2[arrangement[i]] = local_copy[i];
        }
        
        local_copy = local_copy2;
        for(int i = 0 ; i < sz; i ++) {
          arrangement[i] = i;
        }
        return local_copy2;
    }

    void swap(int* p, int*q) {
      if(p == q) return;

      *p = *p ^ *q;
      *q = *p ^ *q;
      *p = *p ^ *q;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for(int i = 0 ; i < sz ; i++  ) {
            //arrange each position i taking a random number from i to sz-1
            int r = (rand() % (sz - i));
            int random_idx = i +  r;
            
            swap(&local_copy[i], &local_copy[random_idx]);
            swap(&arrangement[i], &arrangement[random_idx]);
        }
        
        return local_copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


int main() {

  vector<int> D({1,2,3});

  Solution S(D);
  cout << S.shuffle();
  cout << S.reset();
  cout << S.shuffle();
  cout << S.reset();


  return 0;
}

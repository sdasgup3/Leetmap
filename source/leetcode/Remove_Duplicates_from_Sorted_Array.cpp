/* Problem Description
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include"header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      if(size <= 1) {
        return size;
      }

      int runner = 1;
      int visited = nums[0];

      int counter = 1;
      while(1) {
        while(counter < size && visited == nums[counter]) {
          counter++;
        }

        if(counter == size) {
          return runner; 
        }

        nums[runner++] = visited = nums[counter];
        counter++;
      }
    }
};


int main() {
  Solution S;

  vector<int> D = {1,3,3,3,4,4,5};

  cout << S.removeDuplicates(D);

  return 0;
}

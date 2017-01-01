/* Problem Description
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

* 
*/

#include"header.h"

class Solution {
public:
    int trap(vector<int>& height) {
            
        size_t s = height.size();
        if(s == 0) {
            return 0;
        }
        
        //for each posn find max seen so far from left
        vector<int> max_left(s, 0);
        max_left[0] = height[0];
        for(int i = 1 ; i < s; i++) {
            max_left[i] = std::max(max_left[i-1], height[i]);
        }
        
        //for each posn find max seen so far from right
        vector<int> max_right(s, 0);
        max_right[s-1] = height[s-1];
        for(int i = s-2 ; i >= 0; i--) {
            max_right[i] = std::max(max_right[i+1], height[i]);
        }
        
        int sum = 0;
        for(int i = 0 ; i < s; i++) {
            int t = std::min(max_left[i], max_right[i]);
            if(height[i] < t) {
                sum += t - height[i];
            }
        }
        
        return sum;
        
    }
};

int main() {
  Solution S;

  //vector<int> D({0,1,0,2,1,0,1,3,2,1,2,1});
  vector<int> D;

  cout << S.trap(D);

  return 0;
}

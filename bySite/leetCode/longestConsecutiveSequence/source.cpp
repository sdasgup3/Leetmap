/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

      unordered_map<int, bool> M;
      for(int i = 0 ; i  < nums.size(); i++) {
        M[nums[i]] = true;
      }

      int ans = 0;
      int count = 0;


      for(unordered_map<int, bool>::iterator itb = M.begin(), ite = M.end() ; itb  != ite; itb++) {
        int curr  = (*itb).first;
        if(ite == M.find(curr-1)) {
          count = 1;
          curr ++;
          while(ite != M.find(curr)) {
            count++;
            curr++;
          }
          ans = max(ans, count);
        }
      }

      return ans;
        
    }
};
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int, bool> M;
      for(int i = 0 ; i  < nums.size(); i++) {
        M[nums[i]] = true;
      }

      int ans = 0;
      int count = 0;


      //for(unordered_map<int, bool>::iterator itb = M.begin(), ite = M.end() ; itb  != ite; itb++) {
      while(0 != M.size()) {        
        int curr  = (*(M.begin())).first;
        M.erase(curr);
        
        count = 1;
        int temp = curr -1;
        while(M.end() != M.find(temp)) {
            M.erase(temp);
            temp --;
            count++;
            
        }
        
        temp = curr + 1;
        while(M.end() != M.find(temp)) {
            M.erase(temp);
            temp ++;
            count++;
        }
        
        ans = max(ans, count);
      }

      return ans;
  
    }
};

int main() {
	Solution S;

        int arr1[] = {100, 4, 200, 1, 3, 2};
        vector<int> A = vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
	std::cout << S.longestConsecutive(A) << "\n";

        int arr2[] = {1, 9, 3, 10, 4, 20, 2};
        A = vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
	std::cout << S.longestConsecutive(A) << "\n";

        int arr3[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
        A = vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
	std::cout << S.longestConsecutive(A) << "\n";
}

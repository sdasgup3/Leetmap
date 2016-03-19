/*
 * ##Sort Colors
 * Given an array with n objects colored red, white or blue, sort them so that 
 * objects of the same color are adjacent, with the colors in the order red, 
 * white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
 * and blue respectively.
 */

#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    void partition(vector<int>& nums, int pivot) {
        int size = nums.size();
        int first = 0;
        int last = size-1;
        
        while(first < last) {
            while(first < size && nums[first] <= pivot) {
                first++;
            }
            
            while(last >= 0 && nums[last] > pivot) {
                last --;
            }
            
            if(first < last) {
                int temp = nums[first];
                nums[first] = nums[last];
                nums[last] = temp;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        partition(nums, 0);
        partition(nums,1);
    }
};

int main() {
	Solution S;
	int arr[] = {2,1,0};
	std::vector<int> V(arr, (arr + sizeof(arr)/sizeof(arr[0])) );
	S.sortColors(V);

}

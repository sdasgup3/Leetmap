/*
Find the contiguous subarray within an array (containing at least one number)
which has the largest product.

For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the
largest product = 6.
*/

#include<iostream>
#include<vector>



class Solution { 
	
	public: 
		
int maxProduct(std::vector<int>& nums) {
        
	int len = nums.size();
        
	if(0 == len) return 1;
        
	int max, min, ret; 
	max = min = ret = nums[0];
        
	for(int i = 1; i < len; i ++) { 
		int temp = max;
		max = std::max(std::max(nums[i], max*nums[i]),  min*nums[i]); min =
		std::min(std::min(nums[i], temp*nums[i]),  min*nums[i]);
	    	ret = std::max(ret, max); 
	}
        
	return ret; 
} 

};


int main() {
	Solution S;
	int arr[] = {2,3,-2,4};
	std::vector<int> V(arr, (arr + sizeof(arr)/sizeof(arr[0])) );
	std::cout << S.maxProduct(V) << "\n";

}

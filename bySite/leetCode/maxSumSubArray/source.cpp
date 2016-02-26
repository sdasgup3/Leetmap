#include<iostream>
#include<vector>
using namespace std;



class Solution { 
	
  public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0 ) return 0;
        
        int runningMax, ret;
        
        runningMax =  ret = nums[0];
        
        for(int i =1; i < len; i++) {
            runningMax = std::max(runningMax+nums[i], nums[i] );
            ret = std::max(runningMax, ret );
        }
        
        return ret;
    }
};
		
int main() {
	Solution S;
	int arr[] = {2,3,-2,4};
	std::vector<int> V(arr, (arr + sizeof(arr)/sizeof(arr[0])) );
	std::cout << S.maxSubArray(V) << "\n";

}

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int trappedwater = 0;
        int len = height.size();
        
        if(0 == len) return trappedwater;
        
       
        int leftMax[len];
        int rightMax[len];
        
        leftMax[0] = 0;
        rightMax[len-1] = 0;
        
        //for(int i= 1; i < len; i++) {
        //    leftMax[i] = std::max(leftMax[i-1], height[i-1]);    
        //}
        
        for(int i= len-2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i+1], height[i+1]);    
        }
        
        for(int i= 1; i < len; i++) {
            leftMax[i] = std::max(leftMax[i-1], height[i-1]);
            int currenttrap = std::min(rightMax[i], leftMax[i]) - height[i];
            trappedwater += currenttrap <= 0 ? 0 : currenttrap;    
        }
        
        return trappedwater;
        
    }
};

int main() {
	Solution S;
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> V(arr, (arr + sizeof(arr)/sizeof(arr[0])) );
	cout << S.trap(V) << "\n";

}

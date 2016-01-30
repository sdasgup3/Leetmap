#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> result(len,0);
        
        if(0 == len) return result;
        
        int leftProd[len];
        int rightProd[len];
        
        
        leftProd[0] = 1;
        rightProd[len-1] = 1;
        
        
        for(int i = 1 ; i < len; i ++) {
            leftProd[i] = leftProd[i-1]*nums[i-1];    
        }
        
        for(int i = len-2 ; i >= 0; i --) {
            rightProd[i] = rightProd[i+1]*nums[i+1];    
        }
        
        for(int i = 0 ; i < len; i ++) {
            result[i] = leftProd[i]*rightProd[i];    
        }
        
        return result;
    }

vector<int> productExceptSelf_improved(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> result(len,0);
        
        if(0 == len) return result;
        
        int leftProd[len];
        int rightProd[len];
        
        
        leftProd[0] = 1;
        rightProd[len-1] = 1;
        
        
        
        for(int i = len-2 ; i >= 0; i --) {
            rightProd[i] = rightProd[i+1]*nums[i+1];    
        }
        
        result[0] = leftProd[0]*rightProd[0];    
        for(int i = 1 ; i < len; i ++) {
            leftProd[i] = leftProd[i-1]*nums[i-1];    
            result[i] = leftProd[i]*rightProd[i];    
        }
        
        return result;
    }

int main()
{
	int arr[] = {1,2,3,4};
	vector<int> a(arr, arr+ (sizeof(arr)/sizeof(arr[0])));
	productExceptSelf(a);	

}

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int len = prices.size();
        if(len <=1) return 0;
        
        //int diff[len];
        
        //diff[0] = 0;
        //for(int i = 1 ; i < len; i ++) {
        //    diff[i] = prices[i] - prices[i-1];
        //}
        
        int max , runningsum;
        max = runningsum = 0;
        
        for(int i = 1 ; i < len; i ++) {
            int temp = (prices[i] - prices[i-1]);
            runningsum = std::max(runningsum + temp , temp);
            max = std::max(max, runningsum);
        }
        
        return max;
    }
};

int main() {
	Solution S;
	int arr[] = {2,3,-2,4};
	std::vector<int> V(arr, (arr + sizeof(arr)/sizeof(arr[0])) );
	std::cout << S.maxProfit(V) << "\n";

}

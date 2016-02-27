#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int size = nums.size();
        int max = 1 << size;
        vector<vector<int>> res(max);
        vector<int> elem;
        
        for(int i = 0; i < max; i++) {
            elem.clear();
            int n = i;
            
            int q,r;
            for(int  j =  0;  j < size; j++) {
                if(0 == n) {
                    break;
                }
                q = n/2;
                r = n%2;
                
                if(1 == r) {
                    elem.push_back(nums[j]);
                }
                n = q;
                
            }
            sort(elem.begin(), elem.end());
            res[i] = elem;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> res;
    void rec(vector<int>& nums, vector<int> elem, int pos) {
        if(pos == nums.size()) {
            sort(elem.begin(),elem.end());
            res.push_back(elem);
            return;
        }
        //Exclude nums[pos]
        rec(nums, elem, pos+1);
        //Include nums[pos]
        elem.push_back(nums[pos]);
        rec(nums, elem, pos+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> elem;
        
        rec(nums, elem, 0);
        
        return res;
       
    }
};

int main() {
	Solution2 S;
        int arr[] = {4,1,0};
        vector<int> v(arr, arr + (sizeof(arr)/sizeof(arr[0])));
	S.subsets(v) ;

}


#include"header.h"

class Solution {
    private:
    vector<vector<int>> retval;
public:
    vector<vector<int>> combinationSum(vector<int>& C, int target) {
        if(target == 0 || C.size() == 0) return retval;
        
        sort(C.begin(), C.end());
        vector<int> tmp;
        helper(C, 0, target, 0, tmp);
        
        return retval;
        
    }
    
    
    void helper(vector<int>& C, int idx, int target, int sum, vector<int>soln) {
        
        if(sum == target) {
            vector<int> T;
            for(int k = 0 ; k < soln.size(); k++) {
                if(soln[k] != 0) {
                    T.insert(T.end(), soln[k], C[k]);
                }
            } 
            retval.push_back(T);
            return;
        }

        if(idx == C.size()) {
          return;
        }
        
        int low = 0;
        int high = target / C[idx];
        if(high == 0) {
            return;
        }
        
        for(int i = low;  i <= high; i++) {
            soln.push_back(i);
            helper(C, idx+1, target, sum + C[idx]*i, soln);
            soln.pop_back();
        }
    }
};

int main() {
  Solution S;
  //vector<int> V= {48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
  vector<int> V= {2,3,6,7};
  cout << S.combinationSum(V, 7);


}

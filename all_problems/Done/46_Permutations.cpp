/* Problem Description
*/

#include"header.h"
class Solution {
    private:
    vector<vector<int>> R;
    
public:
    void swap(int *a, int *b) {
        if(a == b) return;
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    void helper(vector<int> v, int posn) {
        int s = v.size();
        if(posn == s) {
            R.push_back(v);
        }
        for(int i = posn; i < s; i++) {
            swap(&v[posn], &v[i]);
            helper(v, posn+1);
            swap(&v[posn], &v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return R;
    }
};

int main() {
  Solution S;

  vector<int> D({1,2,3});

  cout << S.permute(D);

  return 0;
}

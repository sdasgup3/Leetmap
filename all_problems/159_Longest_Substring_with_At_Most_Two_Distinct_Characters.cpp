/* 
 * Problem Description
 Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

 * Solution
 1. Get all the substrings and find their distinct chars using a map and kep track of max

 2. 
ecabaaa

ecab at this point we have 4 dis chars and we are stuck
remove one from left ; register in max; and keep proceeding


 * Tags
 Map
*/

#include"header.h"
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int sz = s.length();
        if(0 == sz) return 0;
        unordered_map<int, int> M;
        int res = INT_MIN;
        
        for(int i = 0, j = 0 ; i < sz ; i++) {
            M[s[i]]++;
            while(M.size() > 2) {
                M[s[j]]--;
                if(M[s[j]] == 0) {
                    M.erase(s[j]);
                }
                j++;
            }
            
            res = max(res, i-j+1);
        }
        
        return res;
    }
};


int main() {
  Solution S;

  cout << S.lengthOfLongestSubstringKDistinct("eceba", 2);
  cout << S.lengthOfLongestSubstringKDistinct("ecabaa", 2);

  return 0;
}

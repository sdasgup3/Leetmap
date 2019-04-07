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
class Solution {
public:
    int lengthOfLongestSubstringKDistinct2(string s, int k) {
        
        
        unordered_map<int, int>M;
        int sz = s.length();
        if(0 == sz) return 0;
        int m = INT_MIN;
        int i, j;
        
        for( i = 0 ; i < sz; i++) {
            M.clear();
            for( j = i ; j < sz; j++) {
                M[s[j]]++;
                if(M.size() > k) {
                    break;
                }
            }
            m = max(m, j-1 - i +1);
        }
        
        return m;
    }

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        
        unordered_map<int, int>M;
        int sz = s.length();
        if(0 == sz) return 0;
        int m = INT_MIN;
        int i, j=0;
        
        for( i = 0 ; i < sz; i++) {
            M[s[i]]++;
              while(M.size() > k) {
                M[s[j]]--;
                if(M[s[j]] == 0) {
                  M.erase(s[j]);
                }
                j++;
              }
            m = max(m, i -j+1 );
        }
        
        return m;
    }
};


int main() {
  Solution S;

  cout << S.lengthOfLongestSubstringKDistinct("eceba", 2);
  cout << S.lengthOfLongestSubstringKDistinct("ecabaa", 3);

  return 0;
}

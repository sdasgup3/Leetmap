#include "header.h"
class Solution {
    map<int, int> M;
    string retval;
    int minL;
public:
    bool checkIfCovered(string str) {
        map<int, int> P = M;
        
        for(auto s: str) {
            if(P.count(s) == 0) {
                continue;
            }
            P[s]--;
            if(P[s] == 0) {
                P.erase(s);
            }
        }
        
        return P.size() == 0;
    }
    
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        minL = INT_MAX;
        retval = "";
        
        if(lens < lent) return "";
        
        for(auto p: t) {
            M[p]++;
        }
        
        // Take 2 pointers L R
        // 2. Incr R as long as all chars are covered. Record it. and break;
        // 3. conctract L as long we are still valid. Record it.
        // 4. At this point we are not valid, repeat 2
        
        int L = 0, R = 0;
        
        while(L <= R) {
            // expand R
            while(R < lens) {
                string str = s.substr(L, R-L+1);
                if(checkIfCovered(str)) {
                    if(minL > str.size()) {
                        minL = str.size();
                        retval = str;
                    }
                    break;
                }
                R++;
            }
            
        
            // Contract
            while(L <= R) {
                string str = s.substr(L, R-L+1);
                if(checkIfCovered(str)) {
                    if(minL > str.size()) {
                        minL = str.size();
                        retval = str;
                    }
                    
                } else {
                    break;
                }
                L++;
            }
            
            if(R == lens) {
                break;
            }
        }
        
        return retval;
    }
};

int main() {
  Solution S;
  cout << S.minWindow("a", "a");
} 

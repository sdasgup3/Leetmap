/* Problem Description
*/

#include"header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        
        if(0 == n) {
            return 0;
        }
        
        //How to diffrentiate "a" and "___"
        // in first case start == end  == 0 and in the later start == end == -1
        int start = -1;
        int end = -1;
        for(int i = 0 ; i < n; i++) {
            //skip the spaces;
            if(s[i] == ' ') {
                continue;
            }
            
            //Got the non start char; init start
            start = i;
            //Try getting the end
            int k;
            for(k = i+1; k  < n; k++) {
                if(s[k] == ' ') {
                    end = k-1;
                    break;
                }
            }
            if(k == n) {
                end = n-1;
                break;
            }
            i = k;
        }
        
    
        if(end == start && start == -1) return 0;
        
        return end - start +1;
    }
};


int main() {
  Solution S;

  cout << S.lengthOfLastWord("") << "\n";
  cout << S.lengthOfLastWord("a") << "\n";
  cout << S.lengthOfLastWord("a ") << "\n";
  cout << S.lengthOfLastWord(" a") << "\n";
  cout << S.lengthOfLastWord("a sad") << "\n";
  cout << S.lengthOfLastWord("  ") << "\n";

  return 0;
}

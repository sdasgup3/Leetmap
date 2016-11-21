/* Problem Description
*/

#include"header.h"

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        //find max row/coln
        int r = words.size();
        int c = INT_MIN;
        for(auto s : words)  {
            //c = std::max(c, s.length());
            c = c < s.length() ? s.length() : c;
        }
        
        int max_rc = std::max(r,c);
        for(int k = 0 ; k < max_rc; k++) {
            string a = words[k];
            string b;
            for(auto s : words) {
                if(k >= s.length()) {
                    
                    break;
                    
                } else {
                b.push_back(s[k]);
                }
            }
            if(0 != a.compare(b)) return false;
        }
        
        return true;
    }
};

int main() {
  Solution S;

  S.validWordSquare(D);

  return 0;
}

#include "header.h"
class Solution {
public:
     vector<string> generatePossibleNextMoves(string s) {
        int ln = s.length();
        vector<string> ans;
        
        if(ln <=1) {
            return ans; 
        }

         for(int i = 0; i < ln-1; i++) {
              if(s[i] == '+' && s[i+1] == '+') {
                  s[i] = '-'; s[i+1]= '-';
                  ans.push_back(s);
                  s[i] = '+'; s[i+1]= '+';
              }
            }
        
   //     cout << ans << "\n";    
        return ans;
        
    }

    bool helper(string s, int move) {
        
        auto V = generatePossibleNextMoves(s);
        cout << s << " " << move <<" " << V.size() << "\n";
        if(V.size() == 0) { 
            if(0 != move%2 ) {
                return true;
            } else{
                false;
            }
        }
        
        bool ans = false;
        for(auto v: V) {
            ans = ans || helper(v, move + 1);
        }
        cout << "\n";
        
        return ans;
    }
    
    bool canWin(string s) {
        
        return helper(s, 0);
    }

    bool canWin2(string s) {
        auto V = generatePossibleNextMoves(s);

        cout << s << " " << V.size() << "\n";

    for(auto str : V){
        if(!canWin2(str))
            return true;
    }
    return false;      
  }

};

int main() {
  Solution S;
  //cout << S.canWin("+");
  //cout << "\n\n";
  //cout << S.canWin("++");
  //cout << "\n\n";
  //cout << S.canWin("+++");
  //cout << "\n\n";
  //cout << S.canWin("++++");
  //cout << "\n\n";
  //cout << S.canWin("+++++");
  //cout << "\n\n";
  //cout << S.canWin("+++++++");
  //cout << "\n\n";
  cout << S.canWin("+++++++++");
  cout << "\n\n";
  cout << S.canWin2("+++++++++");
  cout << "\n\n";

  return 0;
}

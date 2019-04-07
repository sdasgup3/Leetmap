/* Problem Description
*/

#include"header.h"
class Solution {
    private:
    vector<char> C;
    vector<char> M;
    
public:
    string complete(string r, int index, int n) {
        string s(n, '.');
        cout << r << " " << index << "\n" ;
        int i;
        for(i = 0;  i < index; i++) {
            s[i] = r[i];
        }
        int j = index-1; 
        if((index-1) %2 != 0) {
            j--;
        }
        for(; i < n ; i++, j--) {
            if(r[j] == 9) {
                s[i] = '6';
            } else if(r[j] == '6') {
                s[i] = '9';    
            } else {
                s[i] = r[j];
            }
        }
        cout << r << " " << s << "\n" ;
        return s;
    }
    string helper(string r, int index, int n) {
        if(index == (n-1)/2) {
            for(int i = 0 ; i < 3; i++) {
                r.push_back(M[i]);
                return helper(r, index+1, n);
            }
        } 
        
        if( index < (n-1)/2) {
            for(int i = 0 ; i < 5; i++) {
                r.push_back(C[i]);
                return helper(r, index+1, n);
            }
        }
        
        return complete(r, index, n);

    }
    vector<string> findStrobogrammatic(int n) {
        C = {'0','1','8','6','9'};
        M = {'0','1','8'};;
        vector<string> R;
        if(1 == n) {
            for(int i = 0 ; i < 5; i++) {
                R.push_back(to_string(C[i]));   
            }
        }
     
        for(int i = 0 ; i < 5; i++) {
            string r;
            if(0 == i) {
                continue;
            }
            r.push_back(C[i]);
            R.push_back(helper(r, 1, n));
        }
        
        return R;
    }
};


int main() {
  Solution S;

  vector<string> D;

  D.push_back("dear");
  D.push_back("cart");
  D.push_back("cane");
  D.push_back("make");

  S.ValidWordAbbr(D);

  return 0;
}

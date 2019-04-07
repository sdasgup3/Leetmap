#include "header.h"
#include<set>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        auto it = s.find("[", 0);
        if(it == string::npos) {
            return s;
        }
        
        int count = 0;
        int i;
        for(i = it; i < s.length(); i++) {
            if(s[i] == '[') {
                count ++;
            }
            if(s[i] == ']') {
                count --;

                if(count == 0) {
                    break;
                }
            }
        }
        
        string str("");
        int j;
        
        int rep = 0; int p = 1;
        for(j = it-1 ; j >=0; j--, p *=10) {
            if(s[j] >= '0' && s[j] <= '9') {
                rep += (s[j] - '0')*p;
                continue;
            }
            break;
        }
        //cout << j << "\n";
        cout << it << " " << i << " "<<  rep <<  "\n";
        
        // pre
        if(j >= 0) {
            str += s.substr(0, j+1);
        }
        ///cout << str << "\n";
        
        //rep
        for(int k = 0; k < rep; k++) {
            str += s.substr(it+1, i -1 - it );
        }
        
        //post
        if(i+1 != s.length()) {
            str += s.substr(i+1, s.length() - i);
        }
        return decodeString(str);
        
    }
};

int main() {
  Solution S;
  cout << S.decodeString("3[cd]ef");

}

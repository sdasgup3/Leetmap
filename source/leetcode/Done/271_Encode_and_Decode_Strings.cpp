/* Problem Description
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.

Solution:
1. str1@str2@ : what if str contains @
2. <n>@str
if start  = 0; find with give posn of @; which these u can find n and the next value of start

@<n>str
here to get the value of n u need to parse the chars beyond @

Tags:
Array
*/

#include"header.h"
class Codec1 {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string R;
        for (auto str: strs) {
            R.append(to_string(str.length()) + "@" + str);
        }
        return R;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> R;
        int pos, start = 0;
        pos = s.find("@", start);
        
        while(pos != string::npos) {
            string len = s.substr(start, (pos- 1)  - start  + 1 );
            int l = atoi(len.c_str());
            R.push_back(s.substr(pos+1, l));
            start = pos+l +1;
            pos = s.find("@", start);
        
        }
        
        return R;
    }
};

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string R("");
        if(strs.size() ==0) return R;
        
        
        for (auto str: strs) {
            R += str; 
            R += "@";
        }
        return R;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> R;
        if(s.length() == 0 ) return R;
        
        
        int posn, start = 0;
        while(1) {
            posn = s.find("@", start);
            if(posn == string::npos) break;
            R.push_back(s.substr(start, posn-1 - start  +1));
            start = posn+1;
        }
        
        return R;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
  Codec S;

  vector<string> D({"", "defs", "cane", "dsdefafefacfewfFRV", "EFWefwFAWE32R32FFCF2f2@"});
  //vector<string> D({""});

  string str = S.encode(D);
  vector<string> d = S.decode(str);
  cout << "#"<< D << " " << D.size() << "\nencode>" << str << "\ndecode>" <<  d <<" " << d.size() << "\n";

  return 0;
}

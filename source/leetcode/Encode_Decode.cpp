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
*/

#include"header.h"
/*
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string R;

        for (auto str: strs) {
            cout << str.length() << "E@" << str <<"\n";
            R.append(to_string(str.length()) + "@" + str);
        }
        return R;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> R;
        int start = 0;
        int pos = s.find("@", start);
        
        while(pos != string::npos) {
            string len = s.substr(start, (pos- 1)  - start  + 1 );
            int l = std::atoi(len.c_str());
            R.push_back(s.substr(pos+1, l));
            cout << l << "D@" << s.substr(pos+1, l)  <<"\n";
            start = pos+l +1;
            pos = s.find("@", start);
        }
        
        return R;
    }
};
*/
class Codec {
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

int main() {
  Codec S;

  //vector<string> D({"", "defs", "cane", "dsdefafefacfewfFRV", "EFWefwFAWE32R32FFCF2f2@"});
  vector<string> D({""});

  string str = S.encode(D);
  cout << "#"<< D << "encode>" << str << "decode>" <<  S.decode(str);

  return 0;
}

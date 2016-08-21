/* Problem Description
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

* 
*/

#include"header.h"
class Solution {
public:
    string addBinary(string a, string b) {
      
      char carry = '0';
      int len_a = a.length();
      int len_b = b.length();

      string res;

      if(len_a == 0) {
        return b;
      } else if(len_b == 0) {
        return  a;
      } 

      int i,j;
      for(i = len_a-1, j = len_b-1; i>=0 && j >= 0; i--, j--) {

       // cout << a[i] << " " << b[j] << " " << carry << " " << res << "\n";
        if('0' == carry) {
          if(a[i] == '1' && b[j] == '1') {
            carry = '1';
            res.push_back('0');
          } else if(a[i] == '0' && b[j] == '0') {
            carry = '0';
            res.push_back('0');
          } else {
            carry = '0';
            res.push_back('1');
          }
        } else {
          if(a[i] == '1' && b[j] == '1') {
            carry = '1';
            res.push_back('1');
          } else if(a[i] == '0' && b[j] == '0') {
            carry = '0';
            res.push_back('1');
          } else {
            carry = '1';
            res.push_back('0');
          }
        }
      }

      //Handling left overs of b
      if(j != -1) {
        for(;  j >= 0;  j--) {
         // cout << b[j] << " " << carry << " " << res << "\n";
          if('0' == carry) {
            if(b[j] == '1') {
              carry = '0';
              res.push_back('1');
            } else { 
              carry = '0';
              res.push_back('0');
            }
          } else {
            if(b[j] == '1') {
              carry = '1';
              res.push_back('0');
            } else { 
              carry = '0';
              res.push_back('1');
            }
          } 
        }
      }
      //Handling left overs of a
      if(i != -1) {
        for(;  i >= 0;  i--) {
          //cout << a[i] << " " << carry << " " << res << "\n";
          if('0' == carry) {
            if(a[i] == '1') {
              carry = '0';
              res.push_back('1');
            } else { 
              carry = '0';
              res.push_back('0');
            }
          } else {
            if(a[i] == '1') {
              carry = '1';
              res.push_back('0');
            } else { 
              carry = '0';
              res.push_back('1');
            }
          } 
        }
      }

      // adjeust the carry if any
      if('1' == carry) {
        res.push_back('1');
      }

      // reverse res
      int l = res.length();
      for(int i = 0 ; i < l/2; i++) {
        char c = res[i];
        res[i] = res[l-1-i];
        res[l-1-i] = c;
      }

      return res;
    }
};

int main() {
  Solution S;

  //string a = "1101011";
  //string b = "1011";
  string a = "1";
  string b = "1";
  cout << a << "\n" << b << "\n" << S.addBinary(a,b) << "\n";

  return 0;
}

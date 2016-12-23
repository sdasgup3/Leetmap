/* Problem Description
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*Solution

  for 2 bits x and y
  carry = x&y
  sum = x^y

  for 3 bits x and y
  carry = x&y | z(x^y);
  sum = x^y^z


*Tags
Bits
*/

#include"header.h"
class Solution {
public:
    string addBinary(string a, string b) {
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

       
        int c = carry-'0';
        int x = a[i] - '0';
        int y = b[j] - '0';
    
        carry = ((x&y) | (c&(x^y))) + '0';
        res.push_back((x^y^c)+'0');
      }

      //Handling left overs of b
      if(j != -1) {
        for(;  j >= 0;  j--) {
            int c = carry-'0';
            int y = b[j] - '0';
    
            carry = (c&y) + '0';
            res.push_back((y^c)+'0');
        }
      }
      
      //Handling left overs of a
      if(i != -1) {
        for(;  i >= 0;  i--) {
            int c = carry-'0';
            int y = a[i] - '0';
    
            carry = (c&y) + '0';
            res.push_back((y^c)+'0');
        }
      }

      // adjeust the carry if any
      if('1' == carry) {
        res.push_back('1');
      }

        reverse(res.begin(), res.end());
      

      return res;
    }
};
      
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

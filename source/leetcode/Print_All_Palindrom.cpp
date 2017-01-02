/*
   Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  private:
    //vector<int> v(256,0);
    int v[256] = {0};
    char oddchar;
    bool hasOddChar;

  public:
    Solution() {
      hasOddChar = false;
      
    }
    bool checkIfPalindromPermutation(string &s) {
      for(char c:s) {
        v[c] ++;
      }

      bool tolerance = false;
      for(auto c: s) {
        if(v[c] %2 != 0) {
          if(tolerance == false) {
            tolerance = true;
            hasOddChar = true;
            oddchar  = c ;
          } else {
            return false;
          }
        }
      }

      return true;
    }

    void printAll(string s) {
      if(false == checkIfPalindromPermutation(s)) {
        return;
      }

      string w;
      for(int i = 0  ; i < 256 ;  i++) {
        if(v[i] != 0) {
          for(int j = 0; j < v[i]/2; j++) {
            w.push_back(i);
          }
        }
      }

      permute(w, 0);
    }

    void permute (string w, int posn) {
      if(w.length() == posn) {
        if(hasOddChar) {
          cout << w + oddchar + reverse(w) << endl;
        } else {
          cout << w + reverse(w) << endl;
        }
        return;
      }

      for(int i = posn; i < w.length(); i++) {
        swap(&w[posn], &w[i] );
        permute(w, posn+1);
        swap(&w[posn], &w[i] );
      }
    }

    void swap(char* a, char*b) {
      if(a == b) return;

      *a = *a ^ *b;
      *b = *a ^ *b;
      *a = *a ^ *b;
    }

    string reverse(string w) {
      int len = w.length();
      for(int i  = 0 ; i < len/2; i ++) {
        swap(&w[i], &w[len-1-i]);
      }
      return w;
    }
};

int main() {
  Solution X;
  X.printAll("aabcb");
  Solution Y;
  Y.printAll("aabbcadad");
}


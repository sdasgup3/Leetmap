/*
Given a string, determine if a permutation of the string could form a palindrome.

For example, "code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice? Count the frequency of each character. If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

Solution:
Count the frequency in a map
Once the count reaches even, delete the member
At the end look for map size 0 or 1
for size ==1 , no need to look at the count beecause the count can never be >1

Tags:
Map

*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    bool canPermutePalindrome(string s) {
      unordered_map<int, bool> M;

      for(int i  = 0 ; i < s.length(); i++) {
        if(M.count(s[i]) == 0) {
          M[s[i]] = true;
        } else {
          M.erase(s[i]);
        }
      }

      return M.size() <= 1 ;
   }
};


int main ()
{
  Solution S;
  cout << S.canPermutePalindrome("code");
  cout << S.canPermutePalindrome("aab");
  cout << S.canPermutePalindrome("carerac");
  cout << S.canPermutePalindrome("");

}


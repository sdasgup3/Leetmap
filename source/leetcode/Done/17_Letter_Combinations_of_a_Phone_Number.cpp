/* Problem Description
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Tags:
Recursion
*/

#include"header.h"
class Solution {
    private:
    unordered_map<char, string> M;
    vector<string> R;
public:
    Solution() {
        M['2'] = string("abc");
        M['3'] = string("def");
        M['4'] = string("ghi");
        M['5'] = string("jkl");
        M['6'] = string("mno");
        M['7'] = string("pqrs");
        M['8'] = string("tuv");
        M['9'] = string("wxyz");
        
    }
    void helper(string digits, int idx, string str) {
        if(idx == digits.length()) {
            return R.push_back(str);
        }
        
        string alter = M[digits[idx]];
        for(auto c: alter) {
            str.push_back(c);
            helper(digits, idx+1, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int ln = digits.length();
        if(0 == ln) {
            return R;
        }
        string str("");
        helper(digits, 0, str);
        return R;
    }
};

int main() {
  Solution S;

  cout << S.letterCombinations("23");

  return 0;
}

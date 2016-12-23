/* 
 * Problem Description
 * Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * Solution
 
1. find the first [ and its matching ]
2. repeat the contents within n times
3. releat the 1. and 2. till it workds

 
 * Tags
  Array
*/

#include"header.h"
class Solution {

public:
public:
    string decodeString(string s) {

      while(1) {
        //find first '['
        size_t index = s.find('[', 0);
        for()
        string num = stoi(s.substr(index-1,  ));


      }
    }
};


int main() {
  Solution S;

  S.decodeString(3[a]2[bc]);

  return 0;
}

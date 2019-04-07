/* Problem Description
   Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


Bijection means dog is mpped to a and a is mapped to dog
We need two maps for this
Map1: word to letter
Map2: letter to word

Solution:
scan through the words
  if the Map1[word] does not exist; 
    check if Map2[letter] also does not exist; else error
    Map1[word] = letter; Map2[leter] = word
  if already exits; check letter == Map1[word]

Tag:
Map
*/

#include"header.h"
class Solution {

public:
  
  bool wordPattern(string pattern, string str) {
    unordered_map<string, char> M1;
    unordered_map<char, string> M2;

    istringstream buffer(str);
    istream_iterator<string> begin(buffer);
    istream_iterator<string> end;
    vector<string> V(begin, end);

    if(V.size() != pattern.length()) return false;
    cout << V;

    for(int i = 0 ; i < V.size(); i ++) {
      string word = V[i];
      char letter = pattern[i];

      //Not found
      if(M1.count(word) == 0) {
        if(M2.count(letter) != 0) {
          return false;
        }
        M1[word] = letter; M2[letter] = word;
      } else {
        //QFound
        if(letter != M1[word]) {
          return false;
        }
      }
    }

    return true;
  }
private:

};


int main() {
  Solution S;

  cout << S.wordPattern("abba", "dog  cat     cat  dog") << "\n";

  return 0;
}

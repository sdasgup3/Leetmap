/*
 243	Shortest Word Distance 

 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Tags:
Array

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {

  public:
    int shortestDistance(vector<string> words, string word1, string word2) {
      int pivot = -1;
      int size = words.size();

      int result = words.size();


      for(int i = 0; i< size; i++) {
        if(0 == words[i].compare(word1) || 0 == words[i].compare(word2)) {
          pivot = i;
          break;
        } 
      }

      if(-1 == pivot) {
        return -1;
      }


      for(int i = pivot + 1; i < size; i ++) {
        if(0 == words[i].compare(word1) || 0 == words[i].compare(word2)) {
          if(0 != words[i].compare( words[pivot])) {
            result = min(result, i - pivot);
            pivot = i;
          } else {
            pivot = i;
          } 
        }
      }

      return result;
    }

};

int main() {
  Solution S;

  vector<string> words  = {"practice", "makes", "perfect", "coding", "makes"};
  cout << S.shortestDistance(words,  "coding","practice") << endl;
  cout << S.shortestDistance(words,  "makes","coding") << endl;

}

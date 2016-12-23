/*
   *Problem
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Tags:
Array
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int pos1 = -1, pos2 = -1;
        int ans = INT_MAX;
        
        for(int i = 0 ; i < words.size(); i++) {
            if(word1 == words[i]) {
                pos1 = i;
            }
            if(word2 == words[i]) {
                pos2 = i;
            }
            
            if(pos1 != -1 && pos2 != -1) {
                ans =  min(ans, abs(pos1-pos2));
            }
        }
        
        return ans;
        
    }
};

int main() {
  Solution S;

  vector<string> words  = {"practice", "makes", "perfect", "coding", "makes"};
  cout << S.shortestDistance(words,  "coding","practice") << endl;
  cout << S.shortestDistance(words,  "makes","coding") << endl;

}

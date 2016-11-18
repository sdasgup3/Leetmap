/* Problem Description
 * 208. Implement Trie (Prefix Tree)  
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

After  inserting abc and abcde
we must search(abc) as true, even though we havnt reached a leaf
search(abcd) as false

*/

#include"header.h"

class TrieNode {
    private:
        vector<TrieNode*> M;
        bool word_ends ;
public:
    // Initialize your data structure here.
    TrieNode() {
        M.reserve(26);
        for(int i = 0 ; i < 26 ; i ++) {
            M[i] = NULL;
        }
        word_ends = false;
    }
    
    bool hasEnd() {
        return word_ends == true;
    }
    
    TrieNode *insert(char c) {
        int index = c - 'a';
        if(M[index] != NULL) {
            return M[index];
        }
        M[index] = new TrieNode();
        //cout << "Root:" << this << " " << M[index] << " " <<  c <<  count  <<   "\n";
        return M[index];
    }

    TrieNode *search(char c) {
      int index = c - 'a';
      //cout << "Root:" << this << " " << M[index] << " " <<  c << count << "\n";
      return M[index]; 
    }
    
    void ends() {
        // the parent of this node has completed a wprd
        word_ends  = true;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *Troot = root;
        for(char c : word) {
            Troot = Troot->insert(c);    
        }
        Troot->ends();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int l = word.length();
        TrieNode *Troot = root;
        for(int i = 0 ; i < l; i++) {
            Troot = Troot->search(word[i]);
            if(NULL == Troot) {
                return false;
            }
        }    
        
        return Troot->hasEnd() == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int l = prefix.length();
        TrieNode *Troot = root;
        for(int i = 0 ; i < l; i++) {
            Troot = Troot->search(prefix[i]);
            if(NULL == Troot) {
                return false;
            }
        }    
        
        return true;
       
    }

private:
    TrieNode* root;
};


int main() {
  Trie trie;
  trie.insert("somestring");
  cout << trie.search("somestring");
  cout << trie.search("otherstring");
  cout << trie.startsWith("some");

  return 0;
}

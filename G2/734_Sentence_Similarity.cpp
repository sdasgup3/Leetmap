#include "header.h"

class Solution {
private:
  unordered_map<string, unordered_set<string>> M;
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) {
            return false;
        }

        for(auto p: pairs) {
          M[p.first].insert(p.second);
        }
        
        for (int i = 0 ; i < words1.size(); i++) {
          auto s1 = words1[i];
          auto s2 = words2[i];

          if(s1 == s2) {
            continue;
          } 

          if(
                 (M.count(s1) && M[s1].count(s2))
              || (M.count(s2) && M[s2].count(s1))
              ) {
            continue;
          } else {
            return false;
          }
            
        }

        return true;
        
    }
};

int main() {
  Solution S;
  vector<string> V1 = {"this","summer","thomas","get","actually","actually","rich","and","possess","the","actually","great","and","fine","vehicle","every","morning","he","drives","one","nice","car","around","one","great","city","to","have","single","super","excellent","super","as","his","brunch","but","he","only","eat","single","few","fine","food","as","some","fruits","he","wants","to","eat","an","unique","and","actually","healthy","life"};

  vector<string> V2 = {"this","summer","thomas","get","very","very","rich","and","possess","the","very","fine","and","well","car","every","morning","he","drives","a","fine","car","around","unique","great","city","to","take","any","really","wonderful","fruits","as","his","breakfast","but","he","only","drink","an","few","excellent","breakfast","as","a","super","he","wants","to","drink","the","some","and","extremely","healthy","life"};

  vector<pair<string, string>> V3 = {
pair<string, string>("good","nice"),pair<string, string>("good","excellent"),pair<string, string>("good","well"),pair<string, string>("good","great"),pair<string, string>("fine","nice"),pair<string, string>("fine","excellent"),pair<string, string>("fine","well"),pair<string, string>("fine","great"),pair<string, string>("wonderful","nice"),pair<string, string>("wonderful","excellent"),pair<string, string>("wonderful","well"),pair<string, string>("wonderful","great"),pair<string, string>("extraordinary","nice"),pair<string, string>("extraordinary","excellent"),pair<string, string>("extraordinary","well"),pair<string, string>("extraordinary","great"),pair<string, string>("one","a"),pair<string, string>("one","an"),pair<string, string>("one","unique"),pair<string, string>("one","any"),pair<string, string>("single","a"),pair<string, string>("single","an"),pair<string, string>("single","unique"),pair<string, string>("single","any"),pair<string, string>("the","a"),pair<string, string>("the","an"),pair<string, string>("the","unique"),pair<string, string>("the","any"),pair<string, string>("some","a"),pair<string, string>("some","an"),pair<string, string>("some","unique"),pair<string, string>("some","any"),pair<string, string>("car","vehicle"),pair<string, string>("car","automobile"),pair<string, string>("car","truck"),pair<string, string>("auto","vehicle"),pair<string, string>("auto","automobile"),pair<string, string>("auto","truck"),pair<string, string>("wagon","vehicle"),pair<string, string>("wagon","automobile"),pair<string, string>("wagon","truck"),pair<string, string>("have","take"),pair<string, string>("have","drink"),pair<string, string>("eat","take"),pair<string, string>("eat","drink"),pair<string, string>("entertain","take"),pair<string, string>("entertain","drink"),pair<string, string>("meal","lunch"),pair<string, string>("meal","dinner"),pair<string, string>("meal","breakfast"),pair<string, string>("meal","fruits"),pair<string, string>("super","lunch"),pair<string, string>("super","dinner"),pair<string, string>("super","breakfast"),pair<string, string>("super","fruits"),pair<string, string>("food","lunch"),pair<string, string>("food","dinner"),pair<string, string>("food","breakfast"),pair<string, string>("food","fruits"),pair<string, string>("brunch","lunch"),pair<string, string>("brunch","dinner"),pair<string, string>("brunch","breakfast"),pair<string, string>("brunch","fruits"),pair<string, string>("own","have"),pair<string, string>("own","possess"),pair<string, string>("keep","have"),pair<string, string>("keep","possess"),pair<string, string>("very","super"),pair<string, string>("very","actually"),pair<string, string>("really","super"),pair<string, string>("really","actually"),pair<string, string>("extremely","super"),pair<string, string>("extremely","actually")
  };

  cout << S.areSentencesSimilar(V1, V2, V3) << "\n";
  return 0;
}


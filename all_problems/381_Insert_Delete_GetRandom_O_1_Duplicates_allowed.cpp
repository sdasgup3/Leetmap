/* 
 * Problem Description
 Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();

 * Solution
 Use a map to store the indices of vector

 M[val]-----> i 
     
      i
 --------------
   | val |
 --------------

 Once an element is deleted swap it with the leftmost element of array



 * Tags
 Map Array
*/

#include"header.h"
class RandomizedCollection {
    private:
    unordered_map<int, vector<int>> M;
    vector<int> V;
    int first ;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
       // first = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        V.push_back(val);//add val in arr
        M[val].push_back(V.size() - 1);//add its index in dic[val]
        return M[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(M.count(val) == 0) {
            return false;
        }
        
        //FInd the index in the vector
        int sz = M[val].size();
        int vindex = M[val][sz-1];
        //Remove the index from map and remove the entry itself if all the corresponding indices are removed
        M[val].pop_back();
        
        if(M[val].size() == 0) {
          M.erase(val);
        }
        
        if((V.size()-1) != vindex) {
            //Swap the index with last in the vector
            int last = V[V.size()-1];
            V[vindex] = last;
            
            for(int i = 0; i < M[last].size(); i++) {
                if(M[last][i] == (V.size()-1)) {
                    M[last][i] = vindex;
                }
            }
            //Remove one index from  M[V[first]] as one is invalidated
            
            //M[last].pop_back();
            //Update the index of M[V[first]] to be pointing to index
            //M[last].push_back(vindex);    
        }
        
        //incr the deleted pool counter
        V.pop_back();
       // cout << V[0] << " " << V[1] << " " <<  V.size()<< "\n";
        
        return true;
    }
    
    
    /** Get a random element from the collection. */
    int getRandom() {
        return V[rand()%V.size()];
        
    }
};

int main() {
   RandomizedCollection obj;
  bool param_1 = obj.insert(0);
  bool param_2 = obj.remove(0);
  bool param_3 = obj.insert(-1);
  bool param_4 = obj.remove(0);
  obj.getRandom();


  return 0;
}

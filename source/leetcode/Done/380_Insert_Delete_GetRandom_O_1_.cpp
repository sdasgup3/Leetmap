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
 Map
 Array
*/

#include"header.h"
class RandomizedSet1 {
    private:
    unordered_map<int, int> M;
    vector<int> V;
    int first;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        first = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M.count(val)) {
            int index = M[val];
            //check if the index does not belongs to deleted pool
            if(index >= first) {
                return false;
            }
        }
        
        
        
        V.push_back(val);
        M[val] = V.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(M.count(val) == 0) {
            return false;
        }
        
        int index = M[val];
        
        //check if the index belongs to deleted pool
        if(index < first) {
            return false;
        }
        
        //swap first and index
        int tmp  = V[first];
        V[first] = V[index];
        M[val] = first;
        V[index] = tmp;
        M[tmp] = index;
        
        
        
        first++;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int randval = rand()%(V.size()-1 - first + 1);
        return V[first + randval];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

class RandomizedSet {
    private:
    unordered_map<int, int> M;
    vector<int> V;
    int first;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        first = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M.count(val)) {
            return false;
        }
        
        
        V.push_back(val);
        M[val] = V.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(M.count(val) == 0) {
            return false;
        }
        
        int index = M[val];
        
        //revise the index of the element to be swaped with deleted element
        M[V[first]] = index;
        V[index] = V[first];
        
        
        M.erase(val);
        
        first++;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int randval = rand()%(V.size()-1 - first + 1);
        return V[first + randval];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


int main() {
  Solution S;


  return 0;
}

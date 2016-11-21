/* Problem Description
*/

#include"header.h"

class Iterator {
    private:
      int posn ;
        vector<int>V;
public:
    Iterator(const vector<int > & v) {
        V=v;
        posn =0;
    }

    int next() {
        return V[posn++];
    }

    bool hasNext() {
      if(posn < V.size()) {
        return true;
      }
      return false;
    }
};

class PeekingIterator : public Iterator {
    private:
    Iterator *it;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    it = new Iterator(nums);
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    int t = it->next();
	    vector<int> V;
	    V.push_back(t);
	    while(it->hasNext()) {
            V.push_back(it->next());
        }
        delete it;
        it = new Iterator(V);
        return t;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return it->next();
	    
	}

	bool hasNext() const {
	    return it->hasNext();
	}
};



int main() {

  vector<int> V({1,2,3,4});;

  auto it = PeekingIterator(V);
  cout << it.peek() << "\n";
  cout << it.next() << "\n";
  cout << it.next() << "\n";
  cout << it.hasNext() << "\n";
  cout << it.hasNext() << "\n";
  cout << it.next() << "\n";
  cout << it.next() << "\n";
  cout << it.hasNext() << "\n";
  return 0;
}

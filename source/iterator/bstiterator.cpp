#include<iostream>
#include<vector>

template <class T>
class bstnode {
  public:
    T data;
    bstnode<T> *left, *right;
  public:
    bstnode(T d, bstnode<T>* l, bstnode<T>* r): data(d) {
      left  =  l;
      right = r;
    }
    T   &getdata() {return data;}
    bstnode<T>*  &getleft() {return left;}
    bstnode<T>*  &getright() {return right;}
};


template <class T> 
class bstiterator;

template <class T> 
class bst {
  private:
    bstnode<T> *root;
    int size;
  public:
    bst(): root(NULL), size(0) {}
    friend class bstiterator<T>; // does not matter if the friend decl is in private or public
                                 // This is for bstiterator class to use the private members of bst 
    typedef bstiterator<T> iterator;
    iterator begin() {
      return bstiterator<T> (root, 0);
    }
    iterator end() {
      return bstiterator<T> (root, size);
    }

    void addrecursive(bstnode<T> **R, T val) {
      if(*R == NULL) {
        *R = new bstnode<T>(val, NULL, NULL);
        return;
      }
      if(val <= (*R)->getdata()) {
        addrecursive(&((*R)->getleft()), val);
      } else {
        addrecursive(&((*R)->getright()), val);
      }
    }
    void insert(T val) {
      size++;
      addrecursive(&root, val);
    }
};


template <class T> 
class bstiterator {
  private:
    bstnode<T>* &root;  // If we dont use ref here, then on assigning bst::root = NULL, will not change this value;
                        // where the expectation is that this iterator is tied to any changes of the iterator'ee
    std::vector<T> C;
    int index;
  public:
    bstiterator(bstnode<T>* &r, int idx): 
        root(r), index(idx) { // Here we need the reference of the root, not its copy
    }


    //void iterateNfill(const bstnode<T>* &root) {
    void iterateNfill( bstnode<T>* root, std::vector<T> &C) {
      if(NULL != root) {
        iterateNfill(root->getleft(), C);
        C.push_back(root->getdata());      
        iterateNfill(root->getright(), C);
      }       
    }


    bstiterator<T> &operator++() {  //prefix
      index++;
      return *this;
    }

    bstiterator<T> operator++(int notused) {  //postfix;  the return type is NOT ref because we dont want to return ref to a temp
      bstiterator<T> clone(*this);
      index++;
      return clone;
    }

    bool operator==(bstiterator<T> rhs) {
      return (root == rhs.root) && (index == rhs.index) ;
    }

    bool operator!=(bstiterator<T> rhs) {
      return !(*this == rhs);
    }

    const T& operator*() {
      iterateNfill(root, C);
      if(0 == C.size()) {
        std::cout << "Enmpty!!\n";
      }
      return C[index];
    }

};

int main() {
  bst<int> bInt;
  bInt.insert(5);
  bInt.insert(4);
  bInt.insert(6);
  bInt.insert(2);

  for(bst<int>::iterator i = bInt.begin(); i != bInt.end(); i++) {
    std::cout << *i << " " ; 
  }
  std::cout << "\n" ; 

  return 0;
}

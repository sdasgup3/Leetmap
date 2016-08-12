#include<iostream>

class Base {
  public:
    Base() {
      std::cout << "cTor\n";
    }

    ~Base() {
      std::cout << "dTor\n";
    }
};

int main() {
  //Base *b = new Base(); is equivalent to allocating raw bytes and creating an object
  //on it (calling cTor).
  
  void *temp = operator new(sizeof(Base));
  Base *b = new(temp) Base;

  

  //delete b; is equivalent to calling  dTor and then deallocation
  b->~Base();
  operator delete(static_cast<void *>(b));

  return 0;
}

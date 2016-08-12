/*  How to make a C++ class whose objects can only be dynamically allocated?
 *
 */

#include<iostream>

class Base {
  public:
    Base() {
      std::cout << "cTor\n";
    }

    static void operator delete(void *ptr) {
      std::cout << "In operator delete\n"; 

      // segmentation fault because of inf recursive calls
      //delete (Base *)ptr;   
      
      ::operator delete (ptr);
    }

    ~Base() {
      std::cout << "dTor\n";
    }
};

int main() {
  // Compile time error
  //Base b1;
  Base *b2 = new Base();
  delete b2; // This will call ~Base() first and the overloaded delete

  return 0;
}

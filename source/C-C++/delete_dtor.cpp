/*  1. delete invokes the dTor and then the memory is deallocated
 *  2. An object's destructor always invokes the destructors of its member objects (not for member variables that are pointers to objects) regardless of whether or not such calls are made explicitly in the destructor.
 */

#include<iostream>
class A
{
    char *someHeapMemory;
public:
    A() : someHeapMemory(new char[1000]) {}
    ~A() { 
      std::cout << "dTor A\n";
      delete[] someHeapMemory; }
};

class B
{
    A* APtr;
    A Amember;
public:
    B() : APtr(new A()) {}
    ~B() { 
      std::cout << "dTor B\n";
      delete APtr; 
    }
};

class C
{
    A Amember;
public:
    C() : Amember() {}
    ~C() { // A is freed / destructed automatically.
      std::cout << "dTor C\n";
    }
};

int main()
{
    B* BPtr = new B();
    delete BPtr; // Calls ~B() which calls ~A() 

    std::cout << "\n\n";

    C *CPtr = new C();
    delete CPtr; 

    std::cout << "\n\n";
    {
      B b;
    }
    std::cout << "\n\n";
    {
      C c;
    }
} 

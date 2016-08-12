/* Function overloading and const keyword
 * C++ allows member methods to be overloaded on the basis of const type.
 *
 */

#include <iostream>

class Base {
  public:
  void func() const {
    std::cout << "Const function\n";
  }

  void func() {
    std::cout << "Non Const function\n";
  }

  void bar() const {
    std::cout << "Const bar\n";
  }
  void foo()  {
    std::cout << "NonConst foo\n";
  }
};


// PROGRAM 1 (Fails in compilation)
/*
void fun(const int i)
{
    cout << "fun(const int) called ";
}
void fun(int i)
{
    cout << "fun(int ) called " ;
}
*/

// PROGRAM 2 (Compiles and runs fine)
void fun(char *a)
{
  std::cout << "non-const fun() " << a;
}
 
void fun(const char *a)
{
  std::cout << "const fun() " << a;
}

int main() { 
  Base b1;
  b1.func();
  b1.bar();

  const Base b2 = Base();
  b2.func();
  //b2.foo(); error

  /* C++ allows functions to be overloaded on the basis of const-ness of
   * parameters only if the const parameter is a reference or a pointer. That
   * is why the program 1 failed in compilation, but the program 2 worked fine.
   * This rule actually makes sense. In program 1, the parameter ‘i’ is passed
   * by value, so ‘i’ in fun() is a copy of ‘i’ in main(). Hence fun() cannot
   * modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ is received
   * as a const parameter or normal parameter. When we pass by reference or
   * pointer, we can modify the value referred or pointed, so we can have two
   * versions of a function, one which can modify the referred or pointed
   * value, other which can not.
   */
    //const int i = 10; 
    //fun(i);

  const char* a = "";
  fun(a);

  return 0;
}

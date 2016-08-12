#include<iostream>
using namespace std;
 
class Base {
public:
    virtual void fun(int i) { 
    cout << "Bse::fun(int x) called";
    }
};
 
class Derived: public Base {
private:
    void fun(int x)   {  
      cout << "Derived::fun(int x) called";
    }
};
 
int main()
{ 
  /* error: 'fun' is a private member of 'Derived'
  Derived d;
  d.fun(1);
  */


  /*In the above program, private function “Derived::fun(int )” is being called
   * through a base class pointer, the program works fine because fun() is
   * public in base class. Access specifiers are checked at compile time and
   * fun() is public in base class. At run time, only the function
   * corresponding to the pointed object is called and access specifier is not
   * checked. So a private function of derived class is being called through a
   * pointer of base class.
   *
   *
   */

  Base *b = new Derived();
  b->fun(1);

  return 0;
}

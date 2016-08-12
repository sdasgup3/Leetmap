/* How to print “Hello” with empty main() in C++?
 */

#include <iostream>

//Method 1
class Base {
  public:
    Base () {
      std::cout << "In Base constructor: Hello\n";
    }
};

Base b; // This is one way to create "Hello" from a cTor of a class for which we create a global object.

//Method 2

/* Apply the constructor attribute to myStartupFun() so that it
    is executed before main() */
void myStartupFun (void) __attribute__ ((constructor));
 
 
/* Apply the destructor attribute to myCleanupFun() so that it
   is executed after main() */
void myCleanupFun (void) __attribute__ ((destructor));
 
 
/* implementation of myStartupFun */
void myStartupFun (void)
{
    printf ("startup code before main()\n");
}
 
/* implementation of myCleanupFun */
void myCleanupFun (void)
{
    printf ("cleanup code after main()\n");
}

int main() { 
  std::cout << "In main\n";
  return 0;
}

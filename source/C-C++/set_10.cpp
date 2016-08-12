/*The first line of output is printed by statement “String s1(“Geeks”);” and
 * the second line is printed by statement “s1 = name;”. The reason for the
 * second call is, a single parameter constructor also works as a conversion
 * operator 
 *
 * In s1 = name; first a new String is created using the cTor to created a temp copy which is 
 * then copied to s1. In case assignment op is provided the copy will happen using that.
 */


#include<iostream>
#include<string.h>
#include<ostream>

using namespace std;
 
class String
{
    char *p;
    int len;
public:
    String(const char *a);
    String& operator=(String  src) {
      delete p;
      int length = strlen(src.p);
      p = new char[length +1];
      strcpy(p, src.p);
      std::cout << "Assignment op\n " << endl;
      return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s);


};

std::ostream& operator<<(std::ostream& os, const String& s) {
  std::cout << s.p << " ";
  return os;
}
 
String::String(const char *a)
{
    int length = strlen(a);
    p = new char[length +1];
    strcpy(p, a);
    std::cout << "Constructor Called for  " << this << endl;
}
 
int main()
{
    String s1("Geeks");
    std::cout << s1; 
    const char *name = "forGeeks";
    s1 = name; 
    std::cout << s1; 
    return 0;
}

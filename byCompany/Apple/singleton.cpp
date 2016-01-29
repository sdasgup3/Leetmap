#include<iostream>
using namespace std;


class myclass {
  private:
    myclass() {}
    static myclass* myobj;
    

  public:
    static myclass* getObj() {
      if(myobj == NULL) {
        myobj = new myclass();
      }
      return myobj;
    }
};

myclass* myclass::myobj = NULL;


int 
main(){
  myclass* m1 = myclass::getObj() ;
  cout << m1 << " ";

  myclass* m2 = myclass::getObj() ;
  cout << m2 << " ";



  return 0;
}

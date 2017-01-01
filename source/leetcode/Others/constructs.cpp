
#include"header.h"

bool myfunc(int a, int b) {
  return a > b;
}
typedef pair<int, int> PI; 

int main() {

  vector<int> V({5,2,1,4,3,3});
  int sz = V.size();


  cout << "\n\nth_element examples\n=================\n";
  /* ***************** nth_element ****************************************
   * Rearranges the elements in the range [first,last), in such a way that the
   * element at the nth position is the element that would be in that position
   * in a sorted sequence.  The other elements are left without any specific
   * order, except that none of the elements preceding nth are greater than it,
   * and none of the elements following it are less.
   *
   */
  cout << V;
  auto first = V.begin(); auto last = V.end(); 
  nth_element(first, first + sz/2, last); 
  cout << V;

  first = V.begin(); last = V.end(); 
  nth_element(first, first + sz/2, last, myfunc); 
  cout << V;


  cout << "\n\nsort examples\n=================\n";
  /************* sort *****************************/
  vector<PI> V1;
  V1.push_back(PI(10,5));
  V1.push_back(PI(30,6));
  V1.push_back(PI(20,5));
  V1.push_back(PI(40,4));
  auto f1 = V1.begin();  auto l1 = V1.end(); 
  cout << V1;
  sort(f1, l1, [=](PI a, PI b)-> bool{
       return a.second < b.second;
      }
      );
  cout << V1;



  return 0;
}

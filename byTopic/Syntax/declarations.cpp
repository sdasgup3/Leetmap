#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class listNode {
  public:
    int value;
    listNode* next;
    listNode() {
      cout << " In listNode Cons "<< 0 <<  "\n";
    }
    listNode(int val) {
      cout << " In listNode Cons "<< val <<  "\n";
      value = val;
      next = NULL;
    }
};


int main() {
  vector<int> V(10,171);

  for(int I: V) cout << I << " ";
  cout << endl;

  int init_val1[] = {1,3,5,7,9};
  
  vector<int> v1(init_val1, init_val1 + (sizeof(init_val1)/sizeof(init_val1[0])));
  for(int I = 0; I < v1.size(); I++) cout << v1[I] << " ";
  cout << endl;



  int* V2 = new int[10];
  memset(V2, 1, 10*sizeof(int));
  /*
   *  each of the 4 bytes of each of the 10 integers 
   *  are set to 1
   * 16843009 =  2^24 + 2^16 + 2^8 + 1
   */
  for(int I = 0; I < 10; I++) cout << V2[I] << " ";
  cout << endl;

  fill(V2, V2+10, 181);
  for(int I = 0; I < 10; I++) cout << V2[I] << " ";
  cout << endl;


  int a[10];
  memset(a, 0, 10*sizeof(int));
  for(int I = 0; I < 10; I++) cout << a[I] << " ";
  cout << endl;
  fill(a, a+10, 191);
  for(int I = 0; I < 10; I++) cout << a[I] << " ";
  cout << endl;

  listNode* L = new listNode[10];
  vector<listNode> L2(10, listNode(21));
  for(listNode I: L2) cout << I.value << " ";
  cout << endl;


  return 0;
}

/*To implement if a string has all unisue characters.
 * What if cannot use additional data structures?
 */

/* Assumption is characters are extended ASCII encoded i.e 
 * 8 bits are required to rep any one of 0-255 characters. 
 * Non extended version has 0-127 characters.
 * Where as UNICODE characters takes much more bits to represent.
 */

#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<stdlib.h>

using namespace std;


void setBit(int &I, int bit) {
  int mask = 1 << bit;
  //cout << "mask " <<  mask << endl;
  I = I | mask;
}

int getBit(int I, int bit) {
  int mask = 1 << bit;
  return  (I & mask) == 0 ? 0: 1 ;
}

bool isUnique_v1(string str) 
{
  if(str.length() > 256) return false;
  if(str.length() == 0) return true;

  vector<bool> v(256,false);
  for(string::iterator I = str.begin(), E = str.end(); I != E; I++) 
  {
    int C = *I;
    if(v[C]) {
      return false;
      break;
    }
    v[*I] = true;
  }
  return true;
}

bool isUnique_v2(string str) {
  /* Assuming that sizeof(int) == 32 bits.
   * we need 8 ints so that we have 256  bits in total
   * each rep one character.
   */ 

  if(str.length() > 256) return false;
  if(str.length() == 0) return true;

  int Int[8] = {0,0,0,0,0,0,0,0};

  for(string::iterator I = str.begin(), E = str.end(); I != E; I++) 
  {
    int C = *I;
    int index = C/32;
    int bit = C%32;

    //cout << C << " " << index << " " <<  bit << endl << endl;

    if(1 == getBit(Int[index], bit)) {
      return false;
    }
    setBit(Int[index], bit);
  }
  return true;
}



int main(int argc, char** argv) 
{

  string input[] ={"aa", "*_@#|12345|\"\"", "|#$%\\"};
  //string input[] ={"aa"};
  for(string s:input) {
    cout << "The string to test: " << s << endl;
    cout << "isUnique v1: " << ((false == isUnique_v1(s))? "false":"true") << endl; 
    cout << "isUnique v2: " << ((false == isUnique_v1(s))? "false":"true") << endl; 
  }

  return 0;
}

/*To check  if two string are permutation to each other.
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
#include<algorithm>


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

bool isPermute_v1(string str1, string str2) 
{
  if(str1.length() !=  str2.length()) return false;

  vector<int> v(256,0);
  for(string::iterator I = str1.begin(), E = str1.end(); I != E; I++) {
    int C = *I;
    v[*I]++;
  }
  for(string::iterator I = str2.begin(), E = str2.end(); I != E; I++) {
    int C = *I;
    if(v[C] == 0) {
      return false;
    }
    v[*I]--;
  }
  for(string::iterator I = str1.begin(), E = str1.end(); I != E; I++) {
    int C = *I;
    if(0 < v[C]) {
      return false;
    }
  }
  return true;
}

bool isPermute_v2(string str1, string str2) {
  /* Assuming that sizeof(int) == 32 bits.
   * we need 8 ints so that we have 256  bits in total
   * each rep one character.
   */ 
  if(str1.length() !=  str2.length()) return false;


  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  for(int i = 0; i < str1.length(); i++) {
    if(str1[i] != str2[i]) {
      return false;
    }
  }
  return true;
}



int main(int argc, char** argv) 
{

  string input[][2] ={
                      {"*_@#|12345|\"\"", "54321\"\"||#@_*"},
                      {"abbb", "ab"},
                      {"ab", "abc"},
                      {"ab", "abb"}
                    };
  for(int i = 0; i< 4; i ++ ) {
  cout << "The strings to test: " << input[i][0] << " and "<<  input[i][1]<< endl;
  cout << "isPermute v1: " << ((false == isPermute_v1(input[i][0], input[i][1]))? "false":"true") << endl; 
  cout << "isPermute v2: " << ((false == isPermute_v2(input[i][0], input[i][1]))? "false":"true") << endl; 
  }

  return 0;
}

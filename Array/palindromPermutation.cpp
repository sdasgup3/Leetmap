#include<iostream>
#include<cstring>

bool pp_v1(std::string str) {
  int ds[256];
  memset(ds, 0, 256*sizeof(int));

  for(int i = 0 ; i < str.length(); i++) {
    ds[str[i]] ++;
  }

  bool foundPivot = false;
  for(int i = 0 ; i < str.length(); i++) {
    int out = ds[str[i]] % 2;
    if(1 == out) {
      if(false == foundPivot) {
        foundPivot = true;
      } else {
        return false;
      }
    }
  }
  return true;
}

void resetBit(int &I, int bit) {
  int mask = 1 << bit;
  I = I & (~mask);
}

void setBit(int &I, int bit) {
  int mask = 1 << bit;
  I = I | mask;
}

int getBit(int I, int bit) {
  int mask = 1 << bit;
  return  (I & mask) >> bit;
}

void toggle(int &I, int bit) {
  if(1 == getBit(I, bit)) {
    resetBit(I, bit);
  } else {
    setBit(I, bit);
  }
}

bool pp_v2(std::string str) {
  int INT[8];
  memset(INT, 0, 8*sizeof(int));


  for(int i = 0 ; i < str.length(); i++) {
    int C = str[i];
    int index = C / (8*sizeof(int));
    int bit   = C % (8*sizeof(int));
    //std::cout << C << " "<< index << " " << bit << " ";
    //std::cout << getBit(INT[index], bit) << " " ;
    toggle(INT[index], bit);
    //std::cout << getBit(INT[index], bit) << std::endl ;
  }

  bool foundPivot = false;
  for(int i = 0 ; i < str.length(); i++) {
    int C = str[i];
    int index = C / (8*sizeof(int));
    int bit   = C % (8*sizeof(int));

    if(1 == getBit(INT[index], bit)) {
      if(false == foundPivot) {
        foundPivot = true;
      } else {
        return false;
      }
    } 
  }
  return true;
}



int main()
{
  std::string str[] = {"aabbcd", "aab", "abCa", "tactcoa"};
  int size = sizeof(str)/sizeof(str[0]);
  std::cout << sizeof(str) << " " << sizeof(str[0]) << std::endl;

  for(int i = 0 ; i < size; i++) {
    std::cout << "String is :" << str[i] << std::endl;

    bool res_v1 = pp_v1(str[i]);
    bool res_v2 = pp_v2(str[i]);
    std::cout << "Is permutation of palindrom " << (res_v1 ? "True ": "False ") << std::endl;
    std::cout << "Is permutation of palindrom " << (res_v2 ? "True ": "False ") << std::endl;
  }
}

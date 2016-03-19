#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cassert>
//./a.out 2147483648
//./a.out 2147483647

void toBinary(double F) {
  int size = 8*sizeof(int);

  std::vector<char> V(2*size + 1,0);

  int I = (int) F;
  double d = F -I;

  //Integer part
  if(I < 0) {
    V[0] = 1;
    I = pow(2,size -1) + I;
  }

  int index = size -1 ;

  for(; I ;index --) {
    int q = I /2;
    int r = I %2;
    V[index] = r + 48;
    I = q;
  }

  //Decimal part
  index = size;
  V[index++] = '.';
  while(0 != d && index < 2*size +1) {
    d = d*2;
    if(d >= 1) {
      V[index++] = '1';
      d = d -1;
    } else {
      V[index++] = '0';
    }
  }

  //Print
  for(int  i = 0; i < 2*size + 1  ;i++) {
    std::cout << V[i] ;
  }
  std::cout << std::endl;
}


double my_atof(char* str) {

  assert(str != NULL && "Empty argument to atoi");

  std::string S(str);
  std::size_t found = S.find('.');

  std::string pre_dec(""), post_dec("");

  if(found != std::string::npos) {
    post_dec = std::string(str+ (found+1), S.length() - found - 1);
  }
  if(0 != found) {
    pre_dec = std::string(str, found );
  }

  //std::cout << " pre " << pre_dec << "(" << pre_dec.length() << ")" << std::endl;
  //std::cout << " post " << post_dec << "(" << post_dec.length() << ")" << std::endl;

  //char* number = strdup(str);
  //char* pre_dec   = strtok(number, ".");
  //char* post_dec  = strtok(NULL, ".");

  //Pre decimal
  double I = 0;
  int sign = 1;

  if(0 != pre_dec.length()) {
    int start = 0;

    int len = pre_dec.length();

    if('-' == pre_dec[0]) {
      sign = -1;
      start =1;
    }

    for(int i = len -1 ,  p =1; i >= start; i--, p = p*10) {
      assert('0' <= pre_dec[i] && '9' >= pre_dec[i] && "Invalid number string");
      I = I + p*(pre_dec[i] - '0');
    }
  } 

  //Post decimal
  if(0 != post_dec.length()) {
    int start = 0;

    int len = post_dec.length();
    double p  = 1.0/10;
    for(int i = start ; i < len; i++, p = p/10) {
      I = I + p*(post_dec[i] - '0');
    }
  }
  return sign*I;
}

int main(int argc, char** argv) {
  double I = my_atof(argv[1]);

  std::cout << "The binary format of " << I <<  std::endl;
  toBinary(I);

  return 0;
}

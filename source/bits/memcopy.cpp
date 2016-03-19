#include<iostream>
#include<cstring>
#include<stddef.h>

void my_memcpy(void*  dst, void* src,size_t n ) {

  char* d =  (char *)dst;
  char* s =  (char *)src;

  bool not_overlap = ((d + n) <= src) || ((s + n) <=d);

  if(! not_overlap) {
    std::cerr << "Overlapped dst and src\n";
    return;
  }

  for(int  i = 0 ; i < n ; i ++) {
    *d = *s;
    d++;
    s++;
  }

}



int main(int argc, char** argv) {
  int n_bytes = 6;

  char src[13] = "ABCDEFabcdef";
  std::cout << "Src :" << src << "\n" ;

  my_memcpy(&src[6],&src[0],n_bytes);
  std::cout << "Src :" << src << "\n" ;

  my_memcpy(&src[0],&src[10],2);
  std::cout << "Src :" << src << "\n" ;

  my_memcpy(&src[0],&src[1],2);
  std::cout << "Src :" << src << "\n" ;
  return 0;
}

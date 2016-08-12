#include<stdio.h>

int var = 20;

void func() {
 printf("In func: %d", var);
}

int main() {
  extern int var ;
  func();
  printf("%d", var);
}



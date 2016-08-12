/*  What happens if loop till Maximum of Signed and Unsigned in C/C++ In C,
 *  signed overflow is undefined behavior, hence the above solution may not
 *  work on all machines for signed numbers. Also, the output shown above for
 *  signed may not be same on all machines. The behavior is well defined for
 *  unsigned numbers.
 */

#include<stdio.h>

int main()
{
  {
    unsigned char c =  0;
    printf("%d ", c);
    c++;

    for(; c > 0; c ++) {
      printf("%d ", c);
    }
  }

  printf("\n\n");
  
  {
    char c =  0;
    printf("%d ", c);
    c++;

    for(; c > 0; c ++) {
      printf("%d ", c);
    }
  }

  printf("\n\n");
  
  {
    char c =  0;
    do {
      printf("%d ", c++);
    } while(c > 0);
  }

  printf("\n\n");
  return 0;

}

#include <stdio.h>
 
int 
getAbs(int n)
{
  int const mask = n >> (sizeof(int) * 8 - 1); // all 1's for neg /  all zeros for pos
  //First toggle
  n = n ^ mask; //For pos n = n and for neg n = ~n;
  //then add one, now for neg mask  = -1 so n -mask  = n + 1; for pos n +mask =  
  //n
  return n -mask;
}
 
/* Driver program to test above function */
int main()
{
  int n = -6;
  printf("Absoute value of %d is %u", n, getAbs(n));
 
  getchar();
  return 0;
}

#include<iostream>


void 
sortedMerge(int A[], int n, int B[], int m) 
{
  int indexA = n-1;
  int indexB = m-1;

  int ptr = n+m-1;

  while(indexA >= 0 && indexB >=0) {
    if(A[indexA] >= B[indexB]) {
      A[ptr--] = A[indexA];
      indexA--;
    } else {
      A[ptr--] = B[indexB];
      indexB--;
    }
  }

  if(indexA == 0) {
    while(indexB >=0) {
      A[ptr--] = B[indexB];
      indexB--;
    }
  }
}


int main()
{
  int A[12] = {1,3,5,7,9,12};
  int B[6] = {2,4,6,8,10,11};

  sortedMerge(A, 6, B, 6);

  for(int i = 0 ; i < 12; i++ ) {
    std::cout << A[i] << " ";  
  }
}

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


  /*
   *  |---------------|---------------|---------------|
   *  Let | denotes the alignment boundary. The goal is to 
   *  return the address (memptr) which is a multiple of alignment and to store the 
   *  actual malloc'd address size_t bytes before memptr. 
   *
   *  i.e.
   *  |---------------|---------------|---------------|
   *  ^
   *  |
   *  data = This is the actual pointer returned by malloc.
   *  x = data + sizeof(size_t)
   *  case 1: (x - data) < alignment
   *  |-----x---------|---------------|---------------|
   *                   ^
   *                   |
   *  Find the nearest alignment and store address of Data   sizeof(size_t) before it
   *  wastage: alignment bytes
   *
   *  case 2: (x - data) == alignment
   *  |----------------x---------------|---------------|
   *                   ^
   *                   |
   *  x is the alligned position, so return x after  storing the address of data sizeof(size_t) before it
   *  wastage: 0 bytes
   *
   *  case 3: (x - data) > alignment
   *  |----------------|--x------------|---------------|
   *                                   ^
   *                                   |
   *  Find the                        nearest alignment and store address of Data   sizeof(size_t) before it
   *  wastage: 2*alignment bytes
   */

void malloc_alligned(void **memptr, size_t alignment, size_t size) {

  if(0 == alignment) {
    *memptr = NULL;
    return ;
  }

  size_t total_size = 2*alignment + size + sizeof(size_t);

  char* data = (char* ) malloc(sizeof(char)*total_size);

  char* start_data = data;

  data += sizeof(size_t);

  if(0 == ((size_t)data % alignment)) { // Case 2
    *memptr = data;
  } else {
    char *tmp =  data + alignment;
    *memptr = tmp - ((size_t) tmp % alignment);
  }
  *((int *)(*memptr - sizeof(int))) = (size_t)start_data;

  assert(0 == (((size_t)*memptr) % alignment) &&  "Alignment problem ");
  assert(((char *)*memptr) >= start_data && ((char *)*memptr) < start_data + total_size);
}


void free_alligned(void *memptr) 
{
  if(NULL == memptr) return;
  void* book = ((char *) memptr) - sizeof(size_t);
  void* ptr_to_free = ( *((int *)(book)) );
  free(ptr_to_free);
}

int main()
{
  void *ptr = NULL;

  int iter = 0;
  srand (time(NULL));
  size_t size ;
  size_t alignment ;

  for( iter = 0 ; iter < 100; iter++) {
    size = rand() % 10;
    alignment = rand() % 10;

    printf("Trying aligned %zd, size %zd\n", alignment, size);
    malloc_alligned(&ptr, alignment, size);   


    free_alligned(ptr);
  }


    size = 1;
    alignment = 1;
  printf("Trying aligned %zd, size %zd\n", alignment, size);
  malloc_alligned(&ptr, alignment, size);   
  return 0;
}
















#include<stdlib.h>
#include<assert.h>
#include<iostream>


void malloc_alligned_v2(void **memptr, size_t alignment, size_t size) {
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

  size_t total_size = 2*alignment + size;

  char* data = (char* ) malloc(sizeof(char)*total_size);

  char* start_data = data;

  data += sizeof(size_t);

  if(0 == ((size_t)data % alignment)) { // Case 2
    *memptr = ( void *) data;
    *((size_t *)start_data) = (size_t) start_data; 
  } else {
    //ofset = distance from x to the next alignment boundary
    size_t offset = alignment - (((size_t) data) % alignment);
    data += offset;
    *memptr = ( void *) data;

    assert(0 == (((size_t) (data)) % alignment) &&  "Alignment problem ");

    *((size_t *)((char *)data  - sizeof(size_t))) = (size_t) start_data; 
  }

  assert(*memptr >= start_data && *memptr < start_data + total_size);
}


void free_alligned_v2(void *memptr) 
{
  void* book = ((char *) memptr) - sizeof(size_t);
  void* ptr_to_free = (void *) ( *((size_t *)(book)) );
  free(ptr_to_free);
}

void*
malloc_alligned(size_t allignment, size_t size) {
  size_t total_size = sizeof(size_t) + allignment + size;
  void *data = malloc(total_size);

  char* ptr = (char *)data;
  ptr = ptr + sizeof(size_t);

  char *next_alligned_ptr ;
  if(((size_t)ptr % allignment) == 0 ) {
    next_alligned_ptr = ptr ;
  } else {
    next_alligned_ptr = (ptr - ((size_t)ptr % allignment)) + allignment;
  }

  size_t* ptrActualData = (size_t*)(next_alligned_ptr - sizeof(size_t));
  (*ptrActualData) = (size_t)data; 
  return next_alligned_ptr;
}

void
free_alligned(void* ptr) {
  
  size_t* ptrActualData = (size_t *) ( (char *)ptr - sizeof(size_t));
  void* data = (void*)(*ptrActualData);
  free(data);
}

int main()
{
  void *ptr = NULL;

  int iter = 0;
  srand (time(NULL));

  for( iter = 0 ; iter < 100; iter++) {
    size_t size = rand() % 10000;
    size_t allignment = rand() % 10000;
    ptr = malloc_alligned(allignment, size);   

    assert((((size_t) ptr) % allignment) == 0 && "Assertio failed");
    //printf("Is byte aligned = %s: aligned %ld, size %ld\n", ((((size_t) ptr) % alignment ) ? "no" : "yes"), alignment, size);

    free_alligned(ptr);
  }

  size_t size = 1;
  size_t allignment = 2;
  ptr = malloc_alligned(allignment, size);   
  assert((((size_t) ptr) % allignment) == 0 && "Assertio failed");

  return 0;
}

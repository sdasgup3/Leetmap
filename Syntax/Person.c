#include"Person.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void delete_Person(Person* const pPersonObj) {
  printf("From Base: Deleting Person\n");
  free(pPersonObj);
}

void Person_DisplayInfo(Person* const pPersonObj) {
  printf("\nFrom Base: %s %s\n", pPersonObj->pFName , pPersonObj->pLName);
}

void Person_Special(void) {
  printf("Exclusive to Base\n");
}

Person* 
new_Person(const char* const pFirstName, const char* const pLastName)
{
  Person *p = (Person *)malloc(sizeof(Person));
  p->pFName = strdup(pFirstName);
  p->pLName = strdup(pLastName);

  p->Display = Person_DisplayInfo;
  p->Delete = delete_Person;
  p->Special = Person_Special;

  return p;
}

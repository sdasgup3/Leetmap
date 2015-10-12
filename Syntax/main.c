#include"Employee.h"
#include<stdio.h>

int main()
{
  Person* p = new_Person("Sandeep", "Dasgupta");
  p->Display(p);
  p->Delete(p);
  p = NULL;

  Employee* e = new_Employee("Sandeep", "Dasgupta", "UIUC", 200);
  e->Display(e);
  e->Delete(e);
  e  =NULL;

  printf("\n\nPolymorphic Function: Display Virtual Functions: Delete");
  e = new_Employee("Sandeep", "Dasgupta", "UIUC", 200);
  e->baseObj.Display(&(e->baseObj));
  e->baseObj.Display((Person *)e);
  e->Special();
  e->Delete(e);
  e  =NULL;

  printf("\n\nPolymorphic Function: Display Virtual Functions: Delete");
  p = new_Employee("Sandeep", "Dasgupta", "IIT", 200);
  p->Display(p); 
  p->Delete(p);
  p = NULL;

  return 0;

}


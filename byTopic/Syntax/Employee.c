#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"Employee.h"

//We have to change the proto in order to
//match that of the base class Delete proto
//Because the Person::Delete can point to it.
void delete_Employee(Person* const pPersonObj) {
  Employee* pEmployeeObj = (Employee *)pPersonObj;	 	
  printf("From Derived: Deleting Person\n");
  printf("From Derived: Deleting Employee\n");
	
  free(pEmployeeObj);
}

void Employee_DisplayInfo(Employee* const pEmployeeObj) {
  //Person_DisplayInfo(pEmployeeObj->baseObj);
  printf("%s %s\n", pEmployeeObj->baseObj.pFName , pEmployeeObj->baseObj.pLName);
  printf("From Derived: Company: %s Salary: %d\n", pEmployeeObj->company , pEmployeeObj->salary);
}

Employee* 
new_Employee(const char* const pFirstName, 
    const char* const pLastName, 
    const char* const company, 
    const int  salary)
{
  Employee *e = (Employee* ) malloc(sizeof(Employee));
  //Initialize the base object
  e->baseObj.pFName = strdup(pFirstName);
  e->baseObj.pLName = strdup(pLastName);
  e->baseObj.Display = Person_DisplayInfo;
  e->baseObj.Special = Person_Special;

  //Initial the virtual functions in
  //Base class which are overridden by Derived.
  e->baseObj.Delete = delete_Employee;

  //Initialize the base object
  e->company = strdup(company);
  e->salary = salary;
  e->Display = Employee_DisplayInfo;
  e->Delete = delete_Employee;
  /* The following is some function which is 
   * overridedn by derived class. So let it point to base definition.
   * Else point it to overridden one.
  */
  e->Special = e->baseObj.Special;



  return e;
}

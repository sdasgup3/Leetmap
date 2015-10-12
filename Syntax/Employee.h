//Derived Class
#include"Person.h"

typedef struct _Employee Employee;

typedef void    (*fptrDisplayInfoE)(Employee*);
typedef void    (*fptrDelete)( Person *) ;
typedef void    (*fptrSpecialE)(void) ;

typedef struct _Employee 
{
    Person baseObj;
    char* company;
    int salary;

    fptrDisplayInfoE   Display;
    fptrDelete      Delete;
    fptrSpecialE      Special;
}Employee;

Employee* 
new_Employee(const char* const pFirstName, 
    const char* const pLastName, 
    const char* const company, 
    const int  salary);

void delete_Employee(Person* const );
void Employee_DisplayInfo(Employee* const pEmployeeObj);

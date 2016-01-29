//Base Class

typedef struct _Person Person;

typedef void    (*fptrDisplayInfo)(Person*);
typedef void    (*fptrDelete)( Person *) ;
typedef void    (*fptrSpecial)( void) ;

typedef struct _Person 
{
    char* pFName;
    char* pLName;


    fptrDisplayInfo   Display;
    fptrDelete      Delete;
    fptrSpecial		Special;	
}Person;

Person* new_Person(const char* const ,const char* const );  
void delete_Person(Person* const pPersonObj);
void Person_DisplayInfo(Person* const pPersonObj);
void Person_Special(void);

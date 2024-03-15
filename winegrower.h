#ifndef __WINEGROWER_H__
#define __WINEGROWER_H__
#include "csv.h"

//define constants
#define MAX_PEOPLE 100
#define MAX_DOCUMENT_LENGTH 30
#define MAX_NAME_LENGTH 20
#define MAX_SURNAME_LENGTH 25
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_CP_LENGTH 5

#define MAX_WINEGROWER_ID_LENGTH 14
#define MAX_DO_LENGTH 2
#define MAX_VINEYARDPLOTID_LENGTH 13

#define MAX_WINEGROWERS 200

//define data types

typedef struct {    
    int day; 
    int month;
    int year;
} tDate;

// Parse a tDate from string information
void date_parse(tDate* date, const char* text);

// Compare two tDate structures and return true if they contain the same value or false otherwise.
bool date_equals(tDate date1, tDate date2);

// Ex 1: Define data types here...

typedef struct{
    char document[MAX_DOCUMENT_LENGTH];
    char name[MAX_NAME_LENGTH];
    char surname[MAX_SURNAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char cp[MAX_CP_LENGTH];
    tDate birthday;
} tPerson;

typedef struct{
    tPerson elems[MAX_PEOPLE];  
    int count;
} tPeople;

typedef struct{
    char email[MAX_EMAIL_LENGTH];
    tDate when;
    char who [MAX_WINEGROWER_ID_LENGTH];
    char what [MAX_DO_LENGTH];
} tMessage;

///////////////////////////

// Length of the date
#define DATE_LENGTH 10

typedef struct {
    tDate registrationDate;
    char document [MAX_DOCUMENT_LENGTH];
    char winegrowerId [MAX_WINEGROWER_ID_LENGTH];
    char DO [MAX_DO_LENGTH];
    char vineyardplotId [MAX_VINEYARDPLOTID_LENGTH];
    float weight;
} tWinegrower;

typedef struct {
    tWinegrower elems[MAX_WINEGROWERS];
    int count;
} tWinegrowerData;

//////////////////////////////////

// Ex 2: Define your methods here ....

// Initialize the list of winegrowers
void winegrowerData_init(tWinegrowerData* data);


// Get the number of registered winegrowers
int winegrowerData_len(tWinegrowerData data);


// Get a winegrower by the position in the list
void winegrowerData_get(tWinegrowerData data, int index, char* buffer);

// Parse input from CSVEntry
void winegrower_parse(tWinegrower* wg, tCSVEntry entry);

// ...

// Add a new winegrower to the list
void winegrowerData_add(tWinegrowerData* data, tWinegrower wg);

// Remove a winegrower from the list
void winegrowerData_del(tWinegrowerData* data, char *id);

////////////////////////////////////////////

#endif

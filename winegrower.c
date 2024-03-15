#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "winegrower.h"

// Parse a tDate from string information
void date_parse(tDate* date, const char* text)
{
    // Check output data
    assert(date != NULL);
    
    // Check input date
    assert(text != NULL);
    assert(strlen(text) == DATE_LENGTH);
 
    // Parse the input date
    sscanf(text, "%d/%d/%d", &(date->day), &(date->month), &(date->year));
}

// Compare two tDate structures and return true if they contain the same value or false otherwise.
bool date_equals(tDate date1, tDate date2)
{
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year); 
}

// EX2: Implement your methods here...

// Initialize the winegrowers data
void winegrowerData_init(tWinegrowerData* data)
{
     data->count = 0;
}

// Get the number of registered winegrowers
int winegrowerData_len(tWinegrowerData data)
{
    return data.count;
}

// Get a winegrower data by the position in the list and output formated data
void winegrowerData_get(tWinegrowerData data, int index, char* buffer)
{
    
   // Check if the index is valid
    if (index < 0 || index >= data.count) {
        strcpy(buffer, "Invalid position");
        return;
    }
    
    // Format the winegrower data into the buffer
    sprintf(buffer, "%02d/%02d/%04d;%s;%s;%s;%s;%.2f",
            data.elems[index].registrationDate.day,
            data.elems[index].registrationDate.month,
            data.elems[index].registrationDate.year,
            data.elems[index].document,
            data.elems[index].winegrowerId,
            data.elems[index].DO,
            data.elems[index].vineyardplotId,
            data.elems[index].weight);
    
}

// Parse input data from CSVEntry
void winegrower_parse(tWinegrower* wg, tCSVEntry entry)
{
    
    const char* registrationDateStr = entry.fields[0];
    date_parse(&(wg->registrationDate), registrationDateStr);
    
    // Copy other fields
    strcpy(wg->document, entry.fields[1]);
    printf("%s\n", wg->document);
    strcpy(wg->winegrowerId, entry.fields[2]);
    printf("%s\n", wg->winegrowerId);
    strcpy(wg->DO, entry.fields[3]);
    printf("%s\n", wg->DO);
    strcpy(wg->vineyardplotId, entry.fields[4]);
    printf("%s\n", wg->vineyardplotId);
    wg->weight = atof(entry.fields[5]);
    printf("%f\n", wg->weight);
}

// Add a new winegrower
void winegrowerData_add(tWinegrowerData* data, tWinegrower wg)
{
        // Check if the winegrower already exists
    for (int i = 0; i < data->count; ++i) {
        if (strcmp(data->elems[i].document, wg.document) == 0) {
            // If the winegrower code already exists
            if (strcmp(data->elems[i].vineyardplotId, wg.vineyardplotId) == 0 &&
                strcmp(data->elems[i].DO, wg.DO) == 0) {
                // Update registration date and accumulate weight
                data->elems[i].registrationDate = wg.registrationDate;
                data->elems[i].weight += wg.weight;
                return; // Registration done
            } else {
                // If the winegrower code exists with different vineyard or DO, skip registration
                return; // No need to proceed further
            }
        }
    }
    
    // If the winegrower does not exist, add it to the list
    // Check if there's space in the array
    if (data->count < MAX_WINEGROWERS) {
        // Add the winegrower to the list
        data->elems[data->count] = wg;
        data->count++;
    } else {
        // Handle the case where the array is full
        printf("Maximum number of winegrowers reached. Cannot add new winegrower.\n");
    }
}

// Remove a winegrower
void winegrowerData_del(tWinegrowerData* data, char* id) 
{


    int index = -1;
    for (int i = 0; i < data->count; i++) {
        printf("%s, %s\n", id, data->elems[i].winegrowerId);
        if (strcmp(data->elems[i].winegrowerId, id) == 0) {
            index = i;
        }
    }
    
    printf("Index found: %d\n", index);

    // If the winegrower with the given ID is found
    if (index != -1) {
        printf("Winegrower ID before removal: %s\n", data->elems[index].winegrowerId);
        // Shift elements to overwrite the deleted entry
        for (int i = index; i < data->count - 1; i++) {
            data->elems[i] = data->elems[i + 1];
        }
        // Decrement the count to reflect the removal
        data->count--;

        // You don't need to resize the array, just decrement the count
        printf("Winegrower ID after removal: %s\n", data->elems[index].winegrowerId);
    }
    
}


// EX2: Implement any auxiliary method here...




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "date.h"

/*
* Date structure to hold date info
*/
struct date { int day; int month; int year; };

/*
 * date_create creates a Date structure from `datestr`
 * `datestr' is expected to be of the form "dd/mm/yyyy"
 * returns pointer to Date structure if successful,
 *         NULL if not (syntax error)
 */
Date *date_create(char* datestr) {
  if(strlen(datestr)==0){
    return NULL;
  }
  char buffer[5] = ""; // Buffer to hold date numbers
  int numbers[] = {0,0,0}; // Array to store date numbers

  int buffer_counter = 0;
  int char_counter = 0;
  int numbers_counter = 0;

  while (char_counter <= strlen(datestr)){
    char letter = datestr[char_counter];
    // If character is a delimiter or end of string
    // add the number store in buffer to numbers array.
    // Empty out the buffer
    if(letter == '/' || letter == '\0'){
      numbers[numbers_counter] = atoi(buffer);
      numbers_counter = numbers_counter + 1;
      buffer_counter = 0;
      memset(buffer, 0, 4);
    } else {
      buffer[buffer_counter] = letter;
      buffer_counter = buffer_counter + 1;
    }
    char_counter = char_counter + 1;
  }

  // Check for 0 date numbers
  if(numbers[0] == 0 || numbers[1] == 0 || numbers[2]==0){
    return NULL;
  }

  // Allocate memory for Date
  Date* x = malloc(sizeof(Date));
  if(x){
    x->day = numbers[0];
    x->month = numbers[1];
    x->year = numbers[2];
    return x;
  } else {
    return NULL;
  }

}

/*
 * date_duplicate creates a duplicate of `d'
 * returns pointer to new Date structure if successful,
 *         NULL if not (memory allocation failure)
 */
Date *date_duplicate(Date *d){
  Date* x = malloc(sizeof(Date));
  if(x){
  x->day = d->day;
  x->month = d->month;
  x->year = d->year;
  return x;
  } else {
    return NULL;
  }
}

/*
 * date_compare compares two dates, returning -1, 0, 1
 * date1<date2, date1==date2, date1>date2, respectively
 */
int date_compare(Date *date1, Date *date2){
  // Compare if equal
  if(date1->day==date2->day && date1->month==date2->month && date1->year==date2->year){
    return 0;
  } else {
    // Compare years
    if(date1->year > date2->year){
      return 1;
    } else {
      if(date1->year < date2->year){
        return -1;
      } else {
        // Compare months
        if(date1->month > date2->month){
          return 1;
        } else {
          if(date1->month < date2->month){
             return -1;
          } else {
            // Compare dates
            if(date1->day > date2->day){
              return 1;
            } else {
              return -1;
            }
          }
        }
      }
    }
  }
}

/*
 * date_destroy returns any storage associated with `d' to the system
 */
void date_destroy(Date *d){
  free(d);
}

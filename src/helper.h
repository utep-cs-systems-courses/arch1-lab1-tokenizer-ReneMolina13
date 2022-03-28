#ifndef _HELPER_
#define _HELPER_

#include "history.h"

enum histChoices {no_op, print_hist, get_hist};

/* Prints out the desired number of dashes for the border */
void printDashes(int dashes);

/* Prints out enough dashes to fit the largest string in the history list */
void historyDashes(List *list);

/* Checks string for a reference to the history list and returns the desired entry 
   Also updates history list */
int historyCheck(char *str, int length);

/* Retrieves the id for get_history from the inputted string */
int getId(char *str, int length);

#endif

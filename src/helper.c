#include <stdio.h>
#include "history.h"
#include "helper.h"

/* Prints out the desired number of dashes for the border */

void printDashes(int dashes)
{
  for (int i = 0; i < dashes; i++) // set border dashes
    printf("-");
}

/* Prints out enough dashes to fit the largest string in the history list */

void historyDashes(List *list)
{
  int maxDashes = 0;
  int dashes = 0;
  Item *current = list->root;
  while (current != 0) {
    for (int i = 0; *((current->str)+i) != '\0'; i++)
      dashes++;
    if (dashes > maxDashes)
      maxDashes = dashes;
    dashes = 0;
    current = current->next;
  }
  printDashes(maxDashes);
}

/* Checks string for a reference to the history list and returns the desired entry 
   Also updates history list */

int historyCheck(char *str, int length)
{ 
  if (*str != '!')
    return no_op;

  else if (*(str+1) == '*' && *(str+2) == '\0')
    return print_hist;

  // for loop does not look at first ('!') or last ('\0') index of str
  for (int i = 1; i < length; i++) {
    // if string not in format for referencing history, exit function
    if (*(str+length-i) < '0' || *(str+length-i) > '9')
      return no_op;
  }
  return get_hist;
}

/* Retrieves the id for get_history from the inputted string */

int getId(char *str, int length)
{
  int digit; // holds the digit of the history id
  int num = 0; // holds the number converted from the string
  
  // for loop does not look at first ('!') or last ('\0') index of str
  for (int i = 1; i < length; i++) {
    // convert inputted string into number 
    if (i == 1)
      digit = 1;
    else
      digit *= 10;
    num += (digit * ((int)(*(str+length-i))-48));
  }
  return num;
}

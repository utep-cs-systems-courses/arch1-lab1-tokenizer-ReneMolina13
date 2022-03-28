#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "helper.h"

int main (void) {
  /* Initialization */
  
  int length; // holds the length of the inputted string (assumes not '\n')
  char *buffer = (char *) malloc ((sizeof(char)*100)); // Buffer for the fgets function
  char *str; // holds the string inputted
  List *history = init_history();
  enum histChoices histFlag; // indicates history operation to perform
  int id; // holds the index for getting a string from history list
  
  printf("Type in a string to see it split into words\n");
  printf("Type ! followed by a number to access previous entries, !* for all entries\n");
  printDashes(74);

  /* Take Input, test for end of program and start processing the string */
  
  while (1) {
    length = 1;
    printf("\n$ "); // signals that program is ready for input
    char *str = fgets(buffer, 100, stdin);
    
    if (*str == '\n') {
      printDashes(2);
      goto done;
    }
    // find the length of the string
    while ((*(str+length)) != '\n')
      length++;
    str = copy_str(str, length); // create new string without the \n character
    
    /* Check string for history references and execute correct operation */
    
    histFlag = historyCheck(str, length);
    switch(histFlag) {
    case no_op:
      add_history(history, str);
      break;
    case print_hist:
      print_history(history); // print the entire history linked list
      historyDashes(history); // print out dashes for history list
      continue;
    case get_hist:
      id = getId(str, length); // convert inputted list index to an integer
      str = get_history(history, id); // retrieve string referenced by user from history list
      if (str == 0) {
	printf("index out of bounds\n");
	printDashes(19);
	continue;
      }
    }
    
    /* Tokenize and print the string */
    
    char **tokens = tokenize(str);
    print_tokens(tokens);
    free_tokens(tokens);
    printDashes(length+2); // print 2 more dashes than characters in the string
  }
done:
  free_history(history);
  printf("\n");
}

# Project 1: Tokenizer
# ====================

### Objective A: Simple UI

- The simple UI consists of an infinite loop that takes the user's input and
  repeats it until the return button is pressed without input
- The symbol used is the '$' and there is a border between user entries with
  the '-' character which adjusts for the length of user input

### Objective B: Working with strings & memory allocation for strings

The first 6 functions in `tokenizer.h` have been implemented:
1.  `int space_char(char c)`
2.  `int non_space_char(char c)`
3.  `char *word_start(char *s)`
4.  `char *word_terminator(char *word)`
    1.  This function does not return a pointer to the null character, but
    rather a pointer to whatever whitespace existed directly after the final
    letter of that word
5.  `int count_words(char *s)`
    1.  This function accounts for the possibility of whitespace at the
    beginning of the string and more than 1 whitespace character between words
6.  `char *copy_str(char *inStr, short len)`

### Objective C: Adding Tokens

The final 3 functions have been implemented:
1.  `char **tokenize(char *s)`
2.  `void print_tokens(char**)`
3.  `void free_tokens(char**)`

### Objective D: Maintaining History

The functions in `history.h` have been implemented:
1.  `List* init_history()`
2.  `void add_history(List *list, char *str)`
3.  `char *get_history(List *list, int id)`
4.  `void print_history(List *list)`
5.  `void free_history(List *list)`

### Objective E: Putting it all together

The main function for this program is somewhat complicated, thus a helper
header file called `helper.h` with its associated implementation `helper.c`
were created. They contain:
1.  `enum histChoices {no_op, print_hist, get_hist}`
    1.  This enumerated data type helps with readability when the program
    looks for an indication from the user that they want to access the history linked list
2.  `void printDashes(int dashes)`
    1.  This function simply prints out a line of as many dashes to serve as a
    border between each input/output combination
3.  `void historyDashes(List *list)`
    1.  This function is only called when the user requests to print out the
    entire history linked list. It goes through the linked list and determines
    the longest string, then prints out enough dashes to form a good border
4.  `int historyCheck(char *str, int length)`
    1.  This function checks the input to determine if the user would like to
    access the history linked list. The histChoices enumerated data type is
    used to determine if no history access is desired (no_op), if the user
    would like to print the entire linked list (print_hist), or if the user
    would like to access a particualar entry in the linked list (get_hist)
5.  `int getId(char *str, int length)`
    1.  This function is only used if it was determined that a particular
    entry in the linked list would like to be accessed. This function simply
    converts the string entered by the user into an integer that is used to
    access the particular element in the linked list

The format of the main function is as follows:
1.  Initialization
    1.  All variables used in main are created and initialized if needed
    2.  Instructions are given the the user for how to run the program
    3.  Dashes are printed out as a border followed by an infinite while loop
2.  Take in and process input
    1.  `fgets` is used to take in a line of input (keeps the newline)
    2.  If the input is just a newline (\n), exit the program
    3.  Determine the length of the string
    4.  Use the `copy_str()` function from `tokenizer.h` to make a new copy of
    the input without the newline character
3.  Check for history references
    1.  Calls `historyCheck()` function to determine if a history operation is
    desired and if so, what
    2.  Based on the result from `historyCheck()`, a switch statement is used
    to perform the correct operation
        1.  If `no_op` is selected: the input is added to the history linked
	list
	2.  If `print_hist` is selected, the history linked list is printed
	out and the `historyDashes()` function is called to print out the
	appropriate number of dashes, then the rest of that loop iteration is skipped
	3.  If `get_hist` is selected, the `getId()` and `get_history()`
	functions are called to retrieve the desired entry from the linked list
4.  Tokenize and print the string
    1.  A pointer to a character array is created and filled with the words
    inputted by the user
    2.  The character array pointer is stepped through to print out the
    individual tokens
    3.  The memory allocated to each token array and the pointer to these
    arrays are freed
    4.  A bottom row of dashes is printed out to form a border between the
    next input/output set
5.  End of program
    1.  Once the user decides to end the program, the history linked list is
    first freed from memory allocation

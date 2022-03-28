#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == '\t' || c == ' ')
    return 1;
  else
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if (c != '\t' && c != ' ' && c != '\0')
    return 1;
  else
    return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  while (space_char(*str))
      str++;
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (non_space_char(*word))
    word++;
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int words = 0;
  str = word_start(str);
  while (*str != '\0') {
    words++;
    str = word_terminator(str);
    str = word_start(str);
  }
  return words;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copy = (char *) malloc(sizeof(char) * (len+1));
  for (int i = 0; i < len; i++)
    *(copy+i) = *(inStr+i);
  *(copy+len) = '\0';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  // count how many words are in str and create pointer array
  int words = count_words(str);
  char **tokens;
  tokens = (char **) malloc(sizeof(char *) * (words+1));
  
  // copy each word into the correct index of the pointer array (adds null at last index)
  for (int i = 0; i <= words; i++) {
    str = word_start(str);
    short length = word_terminator(str) - str;
    *(tokens+i) = copy_str(str, length);
    str = word_terminator(str);
  }
  
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i = 0;
  while (**(tokens+i) != '\0') {
    printf("%s\n", *(tokens+i));
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  int i = 0;
  while (**(tokens+i) != '\0') {
    free(*(tokens+i));
    i++;
  }
  free(tokens);
}

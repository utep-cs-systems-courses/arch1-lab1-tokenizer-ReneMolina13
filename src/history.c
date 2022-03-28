#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *historyList = (List *) malloc(sizeof(List));
  historyList->root = 0;
  return historyList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  // setup id index and temp pointer
  int id = 0;
  Item *current;

  // if empty list, insert to root
  if (list->root == 0) {
    list->root = (Item *) malloc(sizeof(Item));
    list->root->id = id;
    list->root->str = str;
    return;
  }

  // traverse to the end of the list
  id++;
  current = list->root;
  while (current->next != 0) {
    current = current->next;
    id++;
  }
  
  // insert history item
  current->next = (Item *) malloc(sizeof(Item));
  current = current->next;
  current->id = id;
  current->str = str;
  current->next = 0;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  // setup temp pointer and traverse to correct id
  Item *current = list->root;
  for (int i = 0; i < id; i++) {
    if (current == 0)
      return 0;
    current = current->next;
  }
  // return the string at that id
  if (current == 0)
    return 0;
  return current->str;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  // traverse through the list and print each item one by one
  Item *current = list->root;
  while (current != 0) {
    printf("%s\n", current->str);
    current = current->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  // traverse through the list and free the memory of each item one by one
  Item *temp;
  Item *current = list->root;
  while (current != 0) {
    temp = current;
    current = current->next;
    free (temp);
  }
}

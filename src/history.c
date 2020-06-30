#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next; 
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/*Initialize the linked list to keep the history*/
List* init_history() 
{
  List *head;
  head = (List*)malloc(sizeof(List)); //allocating memory
  head -> root = NULL; //initializing null list 
  return head;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *newItem, *helper;
  newItem = (Item*)malloc(sizeof(Item));
  newItem->str = str; //newItem asigna a str whatever str has
  newItem->next = NULL; //newItem now has to point to another new structure
  if(list == NULL)
    {
      list = newItem; //If empty it assigns it as the first value
    }
  else
    {
      /*To avoid losing values when rewriting/adding more items*/
      helper = list; //we store list items in a temp/aux variable
      while(helper->next != NULL)
	{
	  helper = helper->next;
	}
      helper->next = newItem;
    }
  return list;
}


void print_history(List *list)
{
  
  while(list != NULL)
    {
      printf("%s\n", list->str);
      list = list->next; //to iterate
    }
}



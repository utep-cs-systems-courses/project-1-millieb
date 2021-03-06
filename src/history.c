#include <stdio.h>
#include <stdlib.h>
#include "history.h"

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
   char* str - the string to store*/
void add_history(List *list, char *str)
{
  Item *newItem =  newItem = list->root; 
  if(list == NULL)
    {
      list->root = newItem; //If empty it assigns it as the first value
      newItem->id = 1;
    }
  
  else
    {
      newItem = (Item*)malloc(sizeof(Item));
      while(newItem->next != NULL)
	{
	  newItem = newItem->next;
	}
      newItem->str = str; //newItem assigns to str whatever str has
      newItem->id = newItem->id+1;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */ //obtained help from geeksforgeeks.org review/study
char *get_history(List *list, int id)
{
  Item *helper;
  helper = list->root;
  while(helper !=NULL)
    {
      if(helper->id == id)
	{
	  return (helper->str);
	}
      helper = helper->next;
    }
  return 0;
}

/*Print the entire contents of the list*/
void print_history(List *list)
{
  Item *tempItem = list->root;
  while(tempItem != NULL)
    {
      printf("%s\n", list->root);
      tempItem = tempItem->next;
    }
}

/*Free the history list and the strings it references*/
void free_history(List *list)
{
  Item *helper = list->root;
  while(helper != NULL)
    {
      helper = helper->next; //helper points to next node
      free(helper);      
    }
  free(list);
}

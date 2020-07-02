#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"
#include "history.c"

void main()
{
  char input[100];
  List *list = init_history();

  while(1)
    {
      printf("<h> to see history\n<c> to clear history\nEnter <e> to close program\nStart writing to enter test\n>");
      fgets(input, sizeof(input), stdin);

      if(input[0] == 'c')
	{
	  printf("Entered clear history\n\n");
	  free_history(list);
	}
      else if(input[0] == 'h')
	{
	  printf("Entered view history\n\n");
	  print_history(list);
	  printf("\n");
	  free_history(list);
	}
      else if(input[0] == 'e')
	{
	  exit(0);
	}
      else
	{
	  printf(input); 
	  add_history(list, input);
	  char **tokens = tokenize(input);
	  print_tokens(tokens);
	  
	}
    }
}

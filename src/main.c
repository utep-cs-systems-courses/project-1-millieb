#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main()
{
  char input[100];

  while(1)
    {
      printf("<h> to see history\n<c> to clear history\nEnter <e> to close program\nStart writing to enter test\n>");
      fgets(input, sizeof(input), stdin);

      if(input[0] == 'c')
	{
	  printf("Entered clear history\n\n");
	}
      else if(input[0] == 'h')
	{
	  printf("Entered view history\n\n");
	}
      else if(input[0] == 'e')
	{
	  exit(0);
	}
      else
	{
	  printf("Text entered is: %s\n\n", input);
	}
    }
}

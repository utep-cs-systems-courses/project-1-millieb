#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*Return true (1) if whitespace*/
int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;
  
  else if (c == '\n') /*zero terminators return false*/
    return 0;
  
  else
  return 0;
}

/*Return true (1) if non-whitespace*/
int non_space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\n')
    return 0;

  else
    return 1;
}

/*Returns a pointer to the first character of the next space separated string*/
char word_start(char *str)
{
  char *apt = str;
  while (non_space_char(*apt)) /*while true*/
    {
      apt++;
    }
  return *apt;
}

/*Return a pointer terminator char following *word */
char *word_terminator(char *word)
{
  
}

int main()
{
  return 0;
}

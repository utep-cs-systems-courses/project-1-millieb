#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;
  
  else if (c == '\n')
    return 0;
  
  else
  return 0;
}

int main()
{
  int result = space_char('m');
  printf("%i\n", result);
  int result2 = space_char(' ');
  printf("%i\n", result2);
}

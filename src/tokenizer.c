#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;

  return 0;
}

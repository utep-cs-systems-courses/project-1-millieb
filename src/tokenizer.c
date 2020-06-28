#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define OUT 0
#define IN 1

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
  char *apt = word;
  while (!non_space_char(*apt)) /*while false*/
    {
      apt++;
    }
  return 0;
}

/*Count the number of words in the string*/
int count_words(char *str)
{
  char *apt = str;
  int state = OUT; //The state out detects a separator
  int wordcount = 0;
  

  while(*str)
    {
      if (!non_space_char(*str)) /*if char is a space_char then state=out*/
	{
	  state = OUT;
	}

      else if(state == OUT) /*if char is !space_char then state = in and increment counter */
	{
          state = IN;
	  wordcount++;
	}
      str++; /*move on to next word*/	
    }
      return wordcount;
}

/*Returns a fresly allocated new zero-terminated string containing <len> chars from <inStr>*/
char *copy_str(char *inStr, short len)
{
  char *copystr = malloc(len + 1); /*memory allocation*/

  int tracker;
  for (tracker = 0; tracker < len; tracker++)
    {
      copystr[tracker] = inStr[tracker]; /*Copies inStr to copystr*/
    }
  copystr[len] = '\0';
  return copystr;
}


int main ()
{
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define OUT 0
#define IN 1

/*Return true (1) ifit is whitespace*/
int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;
  
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
  while (space_char(*str)) /*while true*/
    {
      str++;
    }
  return *str;
}

/*Return a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (non_space_char(*word)) /*while false*/
    {
      word++;
    }
  return 0;
}

/*Count the number of words in the string*/
int count_words(char *str)
{
  int state = OUT; //The state out detects a separator
  int wordcount = 0;
  

  while(*str)
    {
      if (non_space_char(*str) && state == 0) /*if char is a space_char then state=out*/
	{
	  state = IN;
	  wordcount++;
	}

      else if(state == IN && space_char(*str)) /*if char is !space_char then state = in and increment counter */
	{
          state = OUT;
	  *str++;
	}
      return wordcount;
    }
}

/*Returns a fresly allocated new zero-terminated string containing <len> chars from <inStr>*/
char *copy_str(char *inStr, short len)
{
  char *copystr = (char*)malloc((sizeof(char*))*(len+1)); /*memory allocation*/
  int tracker;
  for (tracker = 0; tracker < len; tracker++)
    {
      copystr[tracker] = inStr[tracker]; /*Copies inStr to copystr*/
      copystr[len] = '\0';
      return copystr;
    }
}

/*Prints all tokens.*/
void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != "\0"; i++)
    {
      printf("Token[%d] = ", i); /*Prints token position*/
      printf("%s", tokens[i]);
      printf("\n");
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  for(int i=0; tokens[i] != 0; i++)
    {
      free(tokens[i]);
      free(tokens);
    }
}

/* Returns a freshly allocated vector of freshly allocated tokens from str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/

int length(char *str)
{
  char *apt = str;
  char *start;
  char *end;
  int length;

  *start = word_start(apt);
  end = word_terminator(apt);

  length = end - start;
  
  return length;
}

char **tokenize(char *str)
{
  int wordCounter = count_words(str);
  int len, i;
  char *temp = str;

  /*Allocate memory for all tokens*/
  char **tokens = (char**)malloc((sizeof(char*))*(wordCounter+1));
  
  for(i = 0; i<wordCounter; i++)
    {
      len = length(temp);
      tokens[i] = copy_str(temp, len);

      temp = word_terminator(temp); //return to start of a word
    } 
  tokens[i] = "\0";
  return tokens;
}


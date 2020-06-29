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
  while (non_space_char(*str)) /*while true*/
    {
      str++;
    }
  return *str;
}

/*Return a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (!non_space_char(*word)) /*while false*/
    {
      word++;
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

  for (int tracker = 0; tracker < len; tracker++)
    {
      copystr[tracker] = inStr[tracker]; /*Copies inStr to copystr*/
    }
  copystr[len] = '\0';
  return copystr;
}

/*Prints all tokens.*/
void print_tokens(char **tokens)
{
  int tracker = 0;
  while(*tokens)
    {
      printf("Token[%d] = %s\n", tracker, tokens[tracker]); /*Prints token position and token*/
      tokens++; /*Next token*/
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  while(*tokens)
    {
      free(*tokens);
      tokens++;
    }
  free(tokens);
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
  *apt = word_start(apt);

  int currentChar = 0;
  int counter = 0;

  while(non_space_char(apt[currentChar]) && (count_words(apt) > 0))
    {
      counter++;
      currentChar++;
    }
  return counter;
}

char **tokenizer(char *str)
{
  char *apt = str;
  int wordTracker = 0;
  int wordCounter = count_words(str);

  /*Allocate memory for all tokens*/
  char **tokens = (char**)malloc(sizeof(char*)*(wordCounter+1));

  while(wordTracker < wordCounter)
    {
      char *apt = str;
      char *start = str;
      *start = word_start(apt);
      char *end = word_terminator(start);
      char *newWord = copy_str(apt, length(apt));
      apt = word_terminator(apt);

      tokens[wordTracker] = newWord;
      wordTracker++;
    }
  tokens[wordTracker] = "\0";
  return tokens;
}


int main () {
  char input[100];
  
  printf(">");
  scanf("%[^\n]", input);

  printf("%s\n",input);
  printf("%i\n", length(input));
  return 0;

}

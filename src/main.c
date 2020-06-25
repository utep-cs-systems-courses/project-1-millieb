#include <stdio.h>

int main () {

  char input[100];
  printf(">");

  /*Used fgets instead of scanf in order to be able to print input string with spaces*/
  fgets(input,sizeof(input), stdin);
  printf("%s",input);

  return 0;

}

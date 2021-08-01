// Sample with strtok function
#include <stdio.h>
#include <string.h>

int main(void) {
  char name[] = " Hello there! My name is Kevin Carvalho de Jesus";
  char delim[] = " ";

  char *token = strtok(name, delim);

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, delim);
  }
 
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char letter;
  FILE *file;

  //openning file
  file = fopen("test-file.txt", "r");

  // if occuring some error to open file
  if (file == NULL)
  {
    printf("you can't open this file!!");
    exit(1);
  }

  // reading each letter from file until ending
  printf("Inside file 'test-file.txt', there are these contents:\n");
  while ((letter = getc(file)) != EOF)
    printf("%c", letter);

  //closing file
  fclose(file);

  return 0;
}
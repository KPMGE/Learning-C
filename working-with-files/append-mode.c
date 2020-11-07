#include <stdio.h>
#include <stdlib.h>

void displayFileContent(FILE *file);

int main(void)
{
  int qtdNames;
  char name[40];
  FILE *file;


  // before to append data
  printf("Before to append data:\n");
  displayFileContent(file);
  printf("\n\n");

  printf("How many names do you want to add? ");
  scanf("%d", &qtdNames);

  // openning file in append mode
  file = fopen("test-file.txt", "a");

  // writing name to file
  for (int i = 1; i <= qtdNames; i++)
  {
    printf("Enter %do name: ", i);
    scanf("%s", name);
    fprintf(file, "%s\n", name);
  }

  // closing file
  fclose(file);

  // after to modify file
  printf("\n\nAfter to append that data to file, now there are these contents:\n");
  displayFileContent(file);

  // closing file
  fclose(file);

  return 0;
}

void displayFileContent(FILE *file)
{
  char character;
  file = fopen("test-file.txt", "r");

  while ((character = getc(file)) != EOF)
    printf("%c", character);
}


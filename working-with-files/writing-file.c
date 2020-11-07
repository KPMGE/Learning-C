#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int qtdNames;
  FILE *file;
  char name[40];

  printf("How many names do you want to add? ");
  scanf("%d", &qtdNames);

  // opening file in write mode
  file = fopen("test-file.txt", "w");

  // reading names and appending it into the file
  for (int i = 1; i <= qtdNames; i++)
  {
    printf("Enter %do name: ", i);
    scanf("%s", name);
    fprintf(file, "%s\n", name);
  }

  // closing file
  fclose(file);

  // openning file in read mode
  file = fopen("test-file.txt", "r");
  
  // displaying context of the file
  printf("\nThere are these names in the file:\n");
  for (int i = 1; i <= qtdNames; i++)
  {
    // reding name from file
    fscanf(file, "%s", name);
    // displaying name on screen
    printf("%s\n", name);
  }

  // closing file
  fclose(file);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


int main(void) {
  char nameFile[50];
  char character;
  int count = TRUE;

  printf("Enter the file name: ");
  scanf("%s", nameFile);

  FILE *fileUser = fopen(nameFile, "r");
  FILE *finalFile = fopen("removeWhiteLines.txt", "w");

  if (fileUser == NULL) {
    printf("you can't open that file");
    exit(1);
  }

  while ((character = fgetc(fileUser)) != EOF) {
    if (character == '\n') {
      if (count) {
        fprintf(finalFile, "%c", '\n');
        count = FALSE;
      }
      continue;
    }
    fprintf(finalFile, "%c", character);
    count = TRUE;
  }

  fclose(finalFile);
  fclose(fileUser);

  return 0;
}

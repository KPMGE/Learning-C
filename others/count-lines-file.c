// Program that count amount of lines from a file

#include <stdio.h>
#include <stdlib.h>

int countLines(FILE *someFile);

int main(void) {
  char nameFile[50];

  printf("Enter your file's name: ");
  scanf("%[^\n]", nameFile);

  FILE *file = fopen(nameFile, "r");

  if (file == NULL) {
    printf("Your can't open that file");
    exit(1);
  }

  printf("Your file have %d lines", countLines(file));

  return 0;
}

int countLines(FILE *someFile) {
  int amountLines = 0;
  char character;

  while ((character = fgetc(someFile)) != EOF) {
    if (character == '\n') {
      amountLines++;
    }
  }

  return amountLines;
}

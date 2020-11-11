// some operations on files using C

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int readChoice();
void checkFile(FILE *file);
void createFile();
void convertFile(int mode);
char toUpper(char character);
char toLower(char character);

int main(void)
{
  int choiceUser;

  choiceUser = readChoice();

  switch (choiceUser)
  {
    case 1:
      createFile();
    break;

    case 2:
      convertFile(1);
    break;

    case 3:
      convertFile(2);
    break;
  }

  return 0;
}

int readChoice() 
{
  int choice;
  printf("What do you want to do?\n");
  printf("1 - create a file and fill it\n");
  printf("2 - convert a file to uppercase\n");
  printf("3 - convert a file to lowercase\n");
  printf("\n> ");
  scanf("%d", &choice);
  return choice;
}

void checkFile(FILE *file) 
{
  if (file == NULL)
  {
    printf("you can't open the files!!");
    exit(1);
  }
}

void createFile()
{
  FILE *file;
  char nameFile[30], character;

  printf("Enter the name to your file: ");
  scanf("%s", nameFile);

  file = fopen(nameFile, "w");
  checkFile(file);

  while ((character  = getchar()) != '.')
    putc(character, file);

  fclose(file);
  printf("all right, you file '%s' was created", nameFile);
}

char toUpper(char character)
{
  if (character >= 'a' && character <= 'z')
    character = character - 'a' + 'A';
  return character;
}

char toLower(char character)
{
  if (character >= 'A' && character <= 'Z')
    character = character - 'A' + 'a';
  return character;
}

void convertFile(int mode)
{
  char wayFile[50], ch;
  FILE *file, *convertedFile;

  printf("enter way to file: ");
  scanf("%s", wayFile);

  switch (mode)
  {
    case 1:
      file = fopen(wayFile, "r");
      checkFile(file);
      convertedFile = fopen("uppercase_file.txt", "w");
      checkFile(convertedFile);

      while ((ch = fgetc(file)) != EOF)
        putc(toUpper(ch), convertedFile);

      fclose(file);
      fclose(convertedFile);
    break;
    
    case 2:
      file = fopen(wayFile, "r");
      convertedFile = fopen("lowercase_file.txt", "w");

      while ((ch = fgetc(file)) != EOF)
        putc(toLower(ch), convertedFile);

      fclose(file);
      fclose(convertedFile);
    break;
  }

  printf("all right your files was created");
}

// fourth replit
// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

void encodePassword(char string1[], char string2[], int key);
int isValidPassword(char password1[], char password2[]);
int haveAnUpperCaseLetter(char password[]);
int haveALowerCaseLetter(char password[]);
int haveAdigit(char password[]);
int haveASpecialCharacter(char password[]);

int main(void)
{
  char string1[40], string2[40];
  int key;

  scanf("%[^,]%*c %[^,]%*c %d", string1, string2, &key);

  if (isValidPassword(string1, string2))
  {
    encodePassword(string1, string2, key);
    printf("%s", string1);
  }

  return 0;
}

int isValidPassword(char password1[], char password2[])
{
  if (strlen(password1) >= 8 && strlen(password1) <= 20)
  {
    if (haveAnUpperCaseLetter(password1))
    {
      if (haveALowerCaseLetter(password1))
      {
        if (haveAdigit(password1))
        {
          if (haveASpecialCharacter(password1))
          {
            if (strcmp(password1, password2) == 0)
            {
              return True;
            }
            else
            {
              printf("ITEM F INVALIDO");
              return False;
            }
          }
          else 
          {
            printf("ITEM E INVALIDO");
            return False;
          }
        }
        else
        {
          printf("ITEM D INVALIDO");
          return False;
        }
      }
      else 
      {
        printf("ITEM C INVALIDO");
        return False;
      }
    }
    else
    {
      printf("ITEM B INVALIDO");
      return False;
    }
  }
  else
  {
    printf("ITEM A INVALIDO");
    return False;
  }
}

void encodePassword(char string1[], char string2[], int key)
{
  int i;

  for (i = 0; i < strlen(string1); i++)
  {
    string1[i] = string2[i] ^ key;
  }
}

int haveAnUpperCaseLetter(char password[])
{
  int i;
  for (i = 0; i < strlen(password); i++)
  {
    if (password[i] >= 'A' && password[i] <= 'Z')
      return True;
  }
  return False;
}

int haveALowerCaseLetter(char password[])
{
  int i;
  for (i = 0; i < strlen(password); i++)
  {
    if (password[i] >= 'a' && password[i] <= 'z')
      return True;
  }
  return False;
}

int haveAdigit(char password[])
{
  int i;
  for (i = 0; i < strlen(password); i++)
  {
    if (password[i] >= '0' && password[i] <= '9')
      return True;
  }
  return False;
}

int haveASpecialCharacter(char password[])
{
  int i;
  for (i = 0; i < strlen(password); i++)
  {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '%' || password[i] == '&' || password[i] == '[' || password[i] == ']')
      return True;
  }
  return False;
}

//import librarires
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
  //declaring variables
  char reserch[4], word[4];
  int i, j, k, cont = 0;

  //reading word
  printf("Type a word with 3 letters: ");
  scanf(" %3[^\n]", reserch);

  for (i = 'a'; i <= 'z'; i++)
  {
    for (j = 'a'; j <= 'z'; j++)
    {
      for (k = 'a'; k <= 'z'; k++)
      {
        //showing anagram made with the words
        printf("%c%c%c", i, j, k);
        printf("\n");

        //creating anagram
        word[0] = i;
        word[1] = j;
        word[2] = k;
        word[3] = '\0';

        //incrementing cont
        cont++;

        //if word is found
        if (!strcmp(word, reserch))
        {
          //ending program
          printf("Word found!!\n%d Combinations!!", cont);
          exit(1);
        }
      }
    }
  }

  return 0;
}

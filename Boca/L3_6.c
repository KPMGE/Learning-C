// exercise: L3_6 - BOCA  
// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

int isPalindrome(int num);

int main(void)
{
  int num;

  while (scanf("%d", &num) == 1)
  {
    if (isPalindrome(num))
      printf("S\n");
    else
      printf("N\n");
  }

  return 0;
}

int isPalindrome(int num)
{
  int originalNum, palindrome, resto;

  originalNum = num;
  palindrome = 0;

  while (num != 0)
  {
    resto = num % 10;
    palindrome = palindrome + resto;
    num = num / 10;

    if (num != 0)
      palindrome = palindrome * 10;
  }

  if (palindrome == originalNum)
    return True; 
  else
    return False;
}

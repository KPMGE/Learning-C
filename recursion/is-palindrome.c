// program to check if a string is a palindrome

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromeHelper(char *string, int startPoint, int finishPoint);
bool isPalindrome(char *string);

int main(void) {
  char *str1 = "Kevin";
  char *str2 = "racecar";

  printf("\'%s\' %s", str1, isPalindrome(str1) ? "Is palindrome\n" : "Is not a palindrome\n");
  printf("\'%s\' %s", str2, isPalindrome(str2) ? "Is palindrome\n" : "Is not a palindrome\n");

  return 0;
}

bool isPalindromeHelper(char *string, int startPoint, int finishPoint) {
  if (string[startPoint] != string[finishPoint]) {
    return false;
  }

  if (startPoint < finishPoint + 1) {
    return isPalindromeHelper(string, startPoint + 1, finishPoint - 1);
  }

  return true;
}

bool isPalindrome(char *string) {
  int stringLength = strlen(string);

  if (stringLength == 0 || stringLength == 1) {
    return true;
  }

  return isPalindromeHelper(string, 0, stringLength - 1);
}

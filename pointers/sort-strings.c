#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int (fptrOperation)(const char*, const char*);

char* stringToLower(const char* string);
int compare(const char* str1, const char* str2);
int compareIgnoreCase(const char* str1, const char* str2);
void sort(char *array[], int size, fptrOperation operation);
void displayNames(char* names[], int size);


int main(int argc, char **argv) {
  char *names[] = {"Kevin", "karina", "ana", "Alice"};

  // with simple compare
  sort(names, 4, compare);
  displayNames(names, 4);

  // without case sensitive
  sort(names, 4, compareIgnoreCase);
  displayNames(names, 4);

  return 0;
}

char* stringToLower(const char* string) {
  char *tmp = (char*) malloc(strlen(string) + 1);
  char *start = tmp;

  while (*string != 0) {
    *tmp++ = tolower(*string++);
  }

  *tmp = 0;
  return start;
}

int compare(const char* str1, const char* str2) {
  return strcmp(str1, str2);
}

int compareIgnoreCase(const char* str1, const char* str2) {
  char *s1 = stringToLower(str1);
  char *s2 = stringToLower(str2);
  int result = strcmp(s1, s2);
  free(s1);
  free(s2);
  return result;
}

void sort(char *array[], int size, fptrOperation operation) {
  int swap = 1;

  while(swap) {
    swap = 0;
    for(int i=0; i<size-1; i++) {
      if(operation(array[i],array[i+1]) > 0){
        swap = 1;
        char *tmp = array[i];
        array[i] = array[i+1];
        array[i+1] = tmp;
      }
    }
  }
}

void displayNames(char* names[], int size) {
  for(int i=0; i<size; i++) {
    printf("%s ",names[i]);
  }
  printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createSequenceToBet();
int createNumberToBet();
void displaySequence(int sequence[]);

int main(void)
{
  displaySequence(createSequenceToBet());

  return 0;
}

int createNumberToBet()
{
  srand(time(NULL));
  return rand() % 60;
}

int* createSequenceToBet()
{
  int *sequence;
  sequence = (int* ) malloc(sizeof(int) * 6); 

  for(int i = 0; i < 6; i++)
  {
    sequence[i] = createNumberToBet();
    
    for (int j = 0; j < (i - 1); j++)
      if (sequence[i] == sequence[j])
        sequence[i] = createNumberToBet();
  } 

  return sequence;
}

void displaySequence(int sequence[])
{
  printf("you can bet in the following sequence: ");
  printf("%d", sequence[0]);

  for (int i = 1; i < 6; i++)
  {
    printf(", ");
    printf("%d", sequence[i]);
  }

  free(sequence);
}
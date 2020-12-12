#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *top, *p1, stack[SIZE];

int main(void)
{
  int value;

  top = stack; 
  p1 = stack; 

  do
  {
    printf("Enter a value: ");
    scanf("%d", &value);

    if (value != 0)
      push(value);
    else
      printf("The top value is %d\n", pop());
  } while (value != -1);
}

void push(int i)
{
  p1++;
  if (p1 == (top + SIZE))
  {
    printf("Estouro da pilha");
    exit(1);
  }
  *p1 = i;
}

int pop(void)
{
  if (p1 == top)
  {
    printf("Stack overloaded");
    exit(1);
  }
  p1--;
  return *(p1 + 1);
}

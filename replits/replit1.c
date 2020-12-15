#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  int number, id, number2, size;
  int algarismUnit, algarismHundred, algarismDozen, algarismThousand;
  int smallest = 0, greatest = 0, half = 0;

  scanf("%d %d", &number, &id);

  number2 = number;

  //encontrando os algarismos
  algarismThousand = number2 / 1000;
  algarismUnit = number2 % 10;
  number2 -= algarismUnit;
  algarismDozen = (number2 % 100) / 10;
  number2 -= algarismDozen * 10;
  algarismHundred = (number2 % 1000) / 100;


  if(number == 0)
    printf("0, 0, 0");

  else if(size == 1)
  {
    if(id == 0)
      printf("VOID");
    else
      printf("%d", number);
  }
  
  switch(size)
  {
    case 2:
      if(id == 0)
        printf("%d", algarismUnit);
      
      else if(id == 1)
        printf("%d", algarismDozen);

      else
      {
        if(algarismDozen >= algarismUnit)
          printf("%d, %d", algarismUnit, algarismDozen);
        else
          printf("%d, %d", algarismDozen, algarismUnit);
      }
    break;

    case 3:
      switch(id)
      {
        case 0:
          if(algarismDozen >= algarismUnit)
          {
            smallest = algarismUnit;
            greatest = algarismDozen;
          }
          else
          {
            smallest = algarismDozen;
            greatest = algarismUnit;
          }
          printf("%d, %d", smallest, greatest);
        break;

        case 1:
          if(algarismHundred >= algarismUnit)
          {
            smallest = algarismUnit;
            greatest = algarismHundred;
          }
          else
          {
            smallest = algarismHundred;
            greatest = algarismUnit;
          }
          printf("%d, %d", smallest, greatest);
        break;

        case 2:
          if(algarismHundred >= algarismDozen)
          {
            smallest = algarismDozen;
            greatest = algarismHundred;
          }
          else
          {
            smallest = algarismHundred;
            greatest = algarismDozen;
          }
          printf("%d, %d", smallest, greatest);
        break;

        case 3:
          if((algarismHundred >= algarismDozen))
          {
            if(algarismDozen >= algarismUnit)
            {
              smallest = algarismUnit;
              half = algarismDozen;
              greatest = algarismHundred;
            }
            else if(algarismHundred >= algarismUnit)
            {
              smallest = algarismDozen;
              half = algarismUnit;
              greatest = algarismHundred;
            }
            else
            {
              smallest = algarismDozen;
              half = algarismHundred;
              greatest = algarismUnit;
            }
          }
          else 
          {
            if(algarismDozen > algarismUnit)
            {
              if(algarismHundred >= algarismUnit)
              {
                smallest = algarismUnit;
                half = algarismHundred;
                greatest = algarismDozen;
              }
              else
              {
                smallest = algarismHundred;
                half = algarismUnit;
                greatest = algarismDozen;
              }
            }
            else
            {
              smallest = algarismUnit;
              half = algarismDozen;
              greatest = algarismHundred;
            }
          }

          printf("%d, %d, %d", smallest, half, greatest);
        break;
      }
      break;

    case 4:
      //analisando id
      switch(id)
      {
        case 0:
          if((algarismHundred >= algarismDozen))
          {
            if(algarismDozen >= algarismUnit)
            {
              smallest = algarismUnit;
              half = algarismDozen;
              greatest = algarismHundred;
            }
            else if(algarismHundred >= algarismUnit)
            {
              smallest = algarismDozen;
              half = algarismUnit;
              greatest = algarismHundred;
            }
            else
            {
              smallest = algarismDozen;
              half = algarismHundred;
              greatest = algarismUnit;
            }
          }
          else 
          {
            if(algarismDozen > algarismUnit)
            {
              if(algarismHundred >= algarismUnit)
              {
                smallest = algarismUnit;
                half = algarismHundred;
                greatest = algarismDozen;
              }
              else
              {
                smallest = algarismHundred;
                half = algarismUnit;
                greatest = algarismDozen;
              }
            }
            else
            {
              smallest = algarismUnit;
              half = algarismDozen;
              greatest = algarismHundred;
            }
          }

          printf("%d, %d, %d", smallest, half, greatest);
          break;
        
        case 1:
          if((algarismThousand >= algarismDozen))
          {
            if(algarismDozen >= algarismUnit)
            {
              smallest = algarismUnit;
              greatest = algarismThousand;
              half = algarismDozen;
            }
            else if(algarismThousand >= algarismUnit)
            {
              smallest = algarismDozen;
              greatest = algarismThousand;
              half = algarismUnit;
            }
            else
            {
              smallest = algarismDozen;
              greatest = algarismUnit;
              half = algarismThousand;
            }
          }
          else 
          {
            if(algarismDozen > algarismUnit)
            {
              if(algarismThousand >= algarismUnit)
              {
                smallest = algarismUnit;
                greatest = algarismDozen;
                half = algarismThousand;
              }
              else
              {
                smallest = algarismThousand;
                greatest = algarismDozen;
                half = algarismUnit;
              }
            }
            else
            {
              smallest = algarismUnit;
              half = algarismDozen;
              greatest = algarismThousand;
            }
          }

          printf("%d, %d, %d", smallest, half, greatest);
          break;

        case 2:
          if((algarismThousand >= algarismHundred))
          {
            if(algarismHundred >= algarismUnit)
            {
              smallest = algarismThousand;
              half = algarismHundred;
              greatest = algarismUnit;
            }
            else if(algarismThousand >= algarismUnit)
            {
              smallest = algarismThousand;
              half = algarismUnit;
              greatest = algarismHundred;
            }
            else
            {
              smallest = algarismUnit;
              half = algarismThousand;
              greatest = algarismHundred;
            }
          }
          else 
          {
            if(algarismHundred > algarismUnit)
            {
              if(algarismThousand >= algarismUnit)
              {
                smallest = algarismHundred;
                half = algarismThousand;
                greatest = algarismUnit;
              }
              else
              {
                smallest = algarismHundred;
                half = algarismUnit;
                greatest = algarismThousand;
              }
            }
            else
            {
              smallest = algarismUnit;
              half = algarismHundred;
              greatest = algarismThousand;
            }
          }

          printf("%d, %d, %d", greatest, half, smallest);
          break;

        case 3:
          if((algarismHundred >= algarismDozen))
          {
            if(algarismDozen >= algarismThousand)
            {
              smallest = algarismThousand;
              half = algarismDozen;
              greatest = algarismHundred;
            }
            else if(algarismHundred >= algarismThousand)
            {
              smallest = algarismDozen;
              half = algarismThousand;
              greatest = algarismHundred;
            }
            else
            {
              smallest = algarismDozen;
              half = algarismHundred;
              greatest = algarismThousand;
            }
          }
          else 
          {
            if(algarismDozen > algarismThousand)
            {
              if(algarismHundred >= algarismThousand)
              {
                smallest = algarismThousand;
                half = algarismHundred;
                greatest = algarismDozen;
              }
              else
              {
                smallest = algarismHundred;
                half = algarismThousand;
                greatest = algarismDozen;
              }
            }
            else
            {
              smallest = algarismThousand;
              half = algarismDozen;
              greatest = algarismHundred;
            }
          }

          printf("%d, %d, %d", smallest, half, greatest);
          break;
      }

    break;
  }

  return 0;
}
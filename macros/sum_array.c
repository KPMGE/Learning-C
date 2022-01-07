#include <math.h>
#include <stdio.h>

// macro that sums all the numbers passed as parameters
#define sum(...) sum_array((double[]){__VA_ARGS__, NAN})

double sum_array(double *array);

int main(int argc, char *argv[]) {

  printf("%lf", sum(2, 2, 3));

  return 0;
}

double sum_array(double *array) {
  int sum = 0;

  for (int i = 0; !isnan(array[i]); i++) {
    sum += array[i];
  }

  return sum;
}

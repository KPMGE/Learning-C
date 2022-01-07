#include <stdio.h>
#include <stdlib.h>

#define Function_apply(type, function, ...)                                    \
  {                                                                            \
    void *stopper_for_apply = (int[]){0};                                      \
    type **list_for_apply = (type *[]){__VA_ARGS__, stopper_for_apply};        \
                                                                               \
    for (int i = 0; stopper_for_apply != list_for_apply[i]; i++) {             \
      function(list_for_apply[i]);                                             \
    }                                                                          \
  }

#define Free_all(...) Function_apply(void, free, __VA_ARGS__)

int main(int argc, char *argv[]) {
  int *value = malloc(10000);
  int *value1 = malloc(10000);
  int *value2 = malloc(10000);
  int *value3 = malloc(10000);

  Free_all(value, value1, value2, value3);

  return 0;
}

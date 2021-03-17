#undef MATRIX_H_INCLUDED
#undef TYPE 
#undef TYPED
#undef FORMAT

#define TYPE int
#define TYPED(SOMETHING) INT_##SOMETHING
#define FORMAT "%d "
#include "matrix.h"
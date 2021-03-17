#undef MATRIX_H_INCLUDED
#undef TYPE 
#undef TYPED
#undef FORMAT

#define TYPE double
#define TYPED(SOMETHING) FLOAT_ ## SOMETHING
#define FORMAT "%.3f "
#include "matrix.h"
// exported type
typedef struct complex D_Complex_t;

//  functions that creates a complex number
D_Complex_t* createComplex(double real, double imag);
// function that sums two complex numbers
D_Complex_t* sumComplex(D_Complex_t *number1, D_Complex_t *number2);
// function that subtracts two complex numbers
D_Complex_t* subtractComplex(D_Complex_t *number1, D_Complex_t *number2);
// function that subtracts number1 and number2 and assign outcome to number3
D_Complex_t* subractComplexInto(D_Complex_t *number1, D_Complex_t *number2, D_Complex_t *number3);
// function that multiplicates two complex numbers
D_Complex_t* multiplicateComplex(D_Complex_t *number1, D_Complex_t *number2);
// function that do a division for two complex numbers
D_Complex_t* divisionComplex(D_Complex_t *number1, D_Complex_t *number2);
// function that returns real field of a complex number
double getRealField(D_Complex_t *number);
// function that returns imaginary field of a complex number
double getImaginaryField(D_Complex_t *number);
// function that accumulates the sum of number1 and number2 in number1
void accumulateComplex(D_Complex_t **number1, D_Complex_t *number2);
// function that displays the complex number
void displayComplex(D_Complex_t *number);
// function that releases an allocated complex number
void freeComplex(D_Complex_t *number);


//TAD for a matrix m to n

//type exported as Matrix
typedef struct matrix Matrix;

//function that creates the matrix, allocated dynamically
Matrix* create_matrix(int row, int column);

//function that releases the matrix allocated
void free_matrix(Matrix* matrix);

//function that accesses a value in the row and column
float acess_matrix(Matrix* matrix, int row, int column);

//function that assigns a value for a element of the matrix
void assign_matrix(Matrix* matrix, int row, int column, float value);

//function that returns the number of rows 
int matrix_rows(Matrix* matrix);

//function that returns the number of columns
int matrix_columns(Matrix* matrix);

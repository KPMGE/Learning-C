typedef struct matrix Matrix;

Matrix* createMatrix(int rows, int columns);
Matrix* sumMatrices(Matrix *mat1, Matrix *mat2);
Matrix* subtractMatrices(Matrix *mat1, Matrix *mat2);
int amountRows(Matrix *mat);
int amountColumns(Matrix *mat);
float getValueMatrix(Matrix *mat, int i, int j);
void setValueMatrix(Matrix *mat, int i, int j, float value);
void displayMatrix(Matrix *mat);
void fillMatrix(Matrix *mat, float value);
void freeMatrix(Matrix *mat);



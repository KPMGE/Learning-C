// header for type move

// exported type
typedef struct move Move_t;
// function that set new values to a move
void setMove(Move_t *move, int x, int y, char value);
// function that returns the values from a move
void getMove(Move_t *move, int *x, int *y, char *value);
// function that releases memory
void freeMove(Move_t *move);
// function that reads a move
int readMove(Move_t *move);
// function  that creates an instance of a move type
Move_t* createMove();

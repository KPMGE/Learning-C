typedef struct usuario Usuario_t;

Usuario_t* criaUsuario(char *nome, int cpf);
char* nomeUsuario(Usuario_t *usuario);
int cpfUsuario(Usuario_t *usuario);
void destroiUsuario(Usuario_t *usuario);
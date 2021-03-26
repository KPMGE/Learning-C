typedef struct conta Conta_t;

Conta_t* criaConta(char *nome, int cpf, int conta, float saldo);
int agencia(Conta_t *conta);
int contaUsuario(Conta_t *conta);
float saldo(Conta_t *conta);
int sacar(Conta_t* conta, float valor);
void depositar(Conta_t *conta, float valor);
void exibeDados(Conta_t **listaContas, int qtd);
int transferir(Conta_t* conta1, Conta_t* conta2, float valor);
Conta_t* pesquisaConta(Conta_t** listaContas, int qtd, int Nconta);
void destroiListaContas(Conta_t **listaContas);
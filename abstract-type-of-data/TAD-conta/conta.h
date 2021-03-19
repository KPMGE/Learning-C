typedef struct conta Conta_t;

Conta_t* criaConta(char *nome, int cpf, int agencia, int conta, float saldo);
int agencia(Conta_t *conta);
int contaUsuario(Conta_t *conta);
float saldo(Conta_t *conta);
void sacar(Conta_t *conta, float valor);
void depositar(Conta_t *conta, float valor);
void exibeDados(Conta_t *conta);
void destroiConta(Conta_t *conta);
#define MAX 50
#define MAX_P 5

// dados individuais do passageiro
struct pessoa{
    char nome[30];
    int idade;
    char planeta[20];
    int id;
    int doente; // atribui 1 caso esteja e 0 para indicar saudavel
};

// armazena os passageiros de cada nave
struct nave{
    int prioridade;
	struct pessoa passageiros[MAX_P];
	//struct recurso;
};

// compartimentos de recursos de cada nave
struct recurso{
    char r1[20];
    char r2[20];
    char r3[20];
};

struct fila{
	int qtd;
	struct nave naves[MAX];
};

int inserir(struct nave, int x);
void subir(int i, int x);
void descer(int i, int x);
void remover();
int geraPrioridade(struct nave);
int validaDados();
int verificaRecursos();

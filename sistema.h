// dados individuais do passageiro (implementar função que cria passageiros e adiciona-los a uma lista ou adicionalos imediatamente a nave??)
struct passageiro{
    char nome[30];
    int idade;
    char planeta[20];
    int id;
    int doente; // atribui 1 caso esteja e 0 para indicar saudavel
};

// lista de passageiros?

// armazena os passageiros de cada nave (implementar uma função para definir uma lista de passageiros para cada nave para assim identificar clandestinos???)
struct passageiros{
    //
};

// compartimentos de recursos de cada nave (armazena três recursos aleatorios)
struct recursosNave{
    char r1[20];
    char r2[20];
    char r3[20];
};

// lista dos 100 recursos disponiveis na galaxia (utilizar uma funçao para adiciona-los aleatoriamente aos compartimentos)
char recursosDoUniverso[];

typedef struct nave *Heap;

Heap *criar();

void geraPrioridade(struct passageiro p, struct recursosNave r);
int inserirNaFila(struct passageiro p, struct recursosNave r);
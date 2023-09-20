// dados individuais do passageiro (implementar função que cria passageiros e adiciona-los a uma lista ou adicionalos imediatamente a nave??)
struct passageiro{
    char nome[30];
    int idade;
    char planeta[20];
    int id;
    int doente; // atribui 1 caso esteja e 0 para indicar saudavel
};

// armazena os passageiros de cada nave (implementar uma função para definir uma lista de passageiros para cada nave para assim identificar clandestinos???)
struct tripulacao{
    struct passageiro capitao;
    struct passageiro navegador;
    struct passageiro tripulante1;
    struct passageiro tripulante2;
    struct passageiro tripulante3;
};

// compartimentos de recursos de cada nave (armazena três recursos aleatorios)
struct recursosNave{
    char r1[20];
    char r2[20];
    char r3[20];
};

// lista dos 100 recursos disponiveis na galaxia (utilizar uma funçao para adiciona-los aleatoriamente aos compartimentos)
char recursosDoUniverso[];

void constroiHeap(struct nave n, int t);
void geraPrioridade();
int inserirNaFila();
void subir(struct nave n, int i);
void descer(struct nave n, int i, int t);
// void heapSort(struct nave n, int t);
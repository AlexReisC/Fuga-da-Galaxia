#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

struct nave{
    int prioridade;
    struct tripulacao;
    struct compartimentosDeRecursos;
    struct nave *filhoEsquerdo; // filho 2i
    struct nave *filhoDireito; // filho 2i+1
};

typedef struct nave Nave;

// função de definição de prioridade das naves 


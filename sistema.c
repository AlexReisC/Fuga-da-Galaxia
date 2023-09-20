#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

struct nave{
    int prioridade;
    struct passageiros;
    struct compartimentosDerecursos;
    struct nave *filhoEsquerdo; // filho 2i
    struct nave *filhoDireito; // filho 2i+1
}

// função de definição de prioridade das naves 

typedef struct nave 

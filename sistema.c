#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

struct nave{
    int prioridade;
    struct passageiros;
    struct recursos;
    struct nave *proximo;
}

typedef struct nave 

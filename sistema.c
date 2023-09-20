#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

struct nave{
    int prioridade;
    struct passageiros;
    struct recursos;
    struct nave *filho_i;
    struct nave *filho_2i;
}

typedef struct nave 

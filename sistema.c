#include <stdlib.h>
#include "sistema.h"

struct fila{
	int qtd;
	struct nave naves[MAX];
};

Fila* criar(){
	Fila *fi = (Fila*)malloc(sizeof(Fila));
	if(fi != NULL){
		fi->qtd = 0;
	}
	return fi;
}

// Função que aumenta a prioridade de uma espaconave
void subir(int i, int x){
	fila.naves[i].prioridade = x;
	int j = i/2;
	if(x > fila.naves[j].prioridade && j >= 0){ // troca de posicoes na fila
		struct nave aux = fila.naves[j]; 
		fila.naves[j] = fila.naves[i]; 
		fila.naves[i] = aux;
		subir(int j, int x);
	}
}

// Função que insere uma nave na fila
void inserir(struct nave nova, int x){
	fila.naves[qtd] = nova;
	fila.qtd = fila.qtd + 1;
	subir(i, x);
}

// Função que diminui a prioridade de uma nave
void descer(int i, int x){
	fila.naves[i].prioridade = x;
	int j = 2*i+1;
	if(j <= fila.qtd){
		if(x < fila.naves[j].prioridade){
			if(j < n){
				if(fila.naves[j].prioridade < fila.naves[j+1].prioridade){
					j = j+1;
				}
			}
			struct nave aux = fila.naves[i];
			fila.naves[i] = fila.naves[j];
			fila.naves[j] = aux;
			descer(j, x);
		}
	}
}

void remover(){
	fila.naves[0] = fila.naves[qtd-1];
	fila.qtd = fila.qtd - 1;
	descer(0,fila.naves[0].prioridade);
}

int geraPrioridade(){
	
}

int verificaRecursos(){
	
}

int validaDados(){
	
}


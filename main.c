#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sistema.h"
#include "funcoesMain.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char str[12];
	FILE *arquivo = fopen("informacoes.txt", "r");
	if (arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
		return -1;
	}
	char *result = fgets(str, 10, arquivo);
	if(result == NULL){
		printf("Erro na leitura do arquivo.");
	} else{
		printf("Texto: %s\n", str);
	}
	
	fclose(arquivo);
    return 0;
}

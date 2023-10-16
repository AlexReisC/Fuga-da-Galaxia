#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "sistema.h"

// Atribui nome aos passageiros
void atribuiNomes(FILE *arquivo, struct nave *nova){
	int i = 0;
	int j = 0;
	char linha[9];
	//char string[] = "Nomes: ";
	
	fseek(arquivo, 8, SEEK_SET);
	
	while(i < MAX_P){
		char *nome = fgets(linha, 9, arquivo);
		if(nome == NULL){
			printf("Erro na leitura do arquivo.");
		} else{
//			if(strcmp(texto, palavra) != 0){
				strcpy(nova->passageiros[i].nome, linha);
				j++;
//			}
			fseek(arquivo, 1, SEEK_CUR);
			i++;			
		}
	}
}

// Atribui o planeta do passageiro
void atribuiPlanetas(FILE *arquivo, struct nave *nova){	
	int i = 0;
	int j = 0;
	char texto[9];
	char palavra[] = "Planetas: ";
	char palavra2[] = "Idades: ";
	
	fseek(arquivo, 469, SEEK_SET);
	char *string = fgets(texto, 9, arquivo);
	if(string == NULL){
		printf("Erro na leitura do arquivo.");
	}
	
	while(i < MAX_P){
		if(strcmp(texto, palavra) != 0){
			strcpy(nova->passageiros[j].planeta, texto);
			j++;
		}
		if(strstr(texto, palavra2)){
			break;
		}
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
}

void atribuiIdade(FILE *arquivo, struct nave *nova){
	int i = 0;
	int j = 0;
	char texto[9];
	char palavra[] = "Idades: ";
	char palavra2[] = "Id: ";
	
	fseek(arquivo, 8, SEEK_SET);
	
	while(i < MAX_P){
		char *string = fgets(texto, 9, arquivo);
		if(string == NULL){
			printf("Erro na leitura do arquivo.");
		}
		if(strcmp(texto, palavra) != 0){
			int num = atoi(texto);
			nova->passageiros[j].idade = num;
			j++;
		}
		if(strstr(texto, palavra2)){
			break;
		}
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
}

void atribuiId(FILE *arquivo, struct nave *nova){
	int i = 0;
	int j = 0;
	char texto[9];
	char palavra[] = "Id: ";
	char palavra2[] = "Doentes: ";
	
	//strstr()
	
	fseek(arquivo, 8, SEEK_SET);
	char *string = fgets(texto, 9, arquivo);
	if(string == NULL){
		printf("Erro na leitura do arquivo.");
	}
	
	while(i < MAX_P){
		if(strcmp(texto, palavra) != 0){
			int num = atoi(texto);
			nova->passageiros[j].id = num;
			j++;
		}
		if(strstr(texto, palavra2)){
			break;
		}
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	struct nave nave1;
//	struct fila filaDeNaves;
	
	
	// Abre o arquivo com as informações dos passageiros
	FILE *arquivo = fopen("informacoes.txt", "r");
	if (arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
		return -1;
	}
	
	FILE *fila = fopen("fila.txt", "w");
	if(fila == NULL){
		printf("Erro na criação do arquivo da fila");
	}
	
	atribuiNomes(arquivo, fila, &nave1);
	//atribuiPlanetas(arquivo, &nave1);
	
	int i;
	for(i = 0; i < 5; i++){
		printf("%s \n", nave1.passageiros[i].nome);
	}
	
	fclose(arquivo);
	fclose(fila);
	
    return 0;
}

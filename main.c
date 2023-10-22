#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "sistema.h"

// Atribui nome aos passageiros
void atribuiNomes(FILE *arquivo, FILE *arquivo2, struct nave *nova){
	int i = 0;
	char nomes[] = "Nomes: ";
	char linha[1000];
	int posicao;
	char dados[9];
	
	arquivo = fopen("informacoes.txt", "r");
	if(arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
	}
	
	// Selecionar os dados para inserir na struct
	char *result;
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		result = strstr(linha, nomes);
		if(result != NULL){
			posicao = result - linha;
		}
	}
	
	fseek(arquivo, posicao+7, SEEK_SET);
	while(i < MAX_P){
		char *string = fgets(dados, 9, arquivo);
		if(string == NULL){
			printf("Erro na leitura.\n");
		}
		strcpy(nova->passageiros[i].nome, dados);
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
	// Inseri-los no arquivo fila.txt
	
	// Remove-los no arquivo informacoes.txt
	fclose(arquivo);
}

// Atribui o planeta de origem dos passageiros
void atribuiPlanetas(FILE *arquivo, FILE *arquivo2, struct nave *nova){
	int i = 0;
	char planetas[] = "Planetas: ";
	char linha[1000];
	int posicao;
	char dados[9];
	
	arquivo = fopen("informacoes.txt", "r");
	if(arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
	}
	
	// Selecionar os dados para inserir na struct
	char *result;
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		result = strstr(linha, planetas);
		if(result != NULL){
			posicao = result - linha;
		}
	}
	
	fseek(arquivo, posicao+10, SEEK_SET);
	while(i < MAX_P){
		char *string = fgets(dados, 9, arquivo);
		if(string == NULL){
			printf("Erro na leitura.\n");
		}
		strcpy(nova->passageiros[i].planeta, dados);
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
	// Inseri-los no arquivo fila.txt
	
	// Remove-los no arquivo informacoes.txt
	fclose(arquivo);
}

void atribuiIdades(FILE *arquivo, FILE *arquivo2, struct nave *nova){
	int i = 0;
	char idades[] = "Idades: ";
	char linha[1000];
	int posicao;
	char dados[1];
	
	arquivo = fopen("informacoes.txt", "r");
	if(arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
	}
	
	// Selecionar os dados para inserir na struct
	char *result;
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		result = strstr(linha, idades);
		if(result != NULL){
			posicao = result - linha;
		}
	}
	
	fseek(arquivo, posicao+8, SEEK_SET);
	while(i < MAX_P){
		char *string = fgets(dados, 3, arquivo);
		if(string == NULL){
			printf("Erro na leitura.\n");
		}
		int num = atoi(dados);
		nova->passageiros[i].idade = num;
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
	// Inseri-los no arquivo fila.txt
	
	// Remove-los no arquivo informacoes.txt
	fclose(arquivo);
}

void atribuiIds(FILE *arquivo, FILE *arquivo2, struct nave *nova){
	int i = 0;
	char ids[] = "Ids: ";
	char linha[1000];
	int posicao;
	char dados[1];
	
	arquivo = fopen("informacoes.txt", "r");
	if(arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
	}
	
	// Selecionar os dados para inserir na struct
	char *result;
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		result = strstr(linha, ids);
		if(result != NULL){
			posicao = result - linha;
		}
	}
	
	fseek(arquivo, posicao+5, SEEK_SET);
	while(i < MAX_P){
		char *string = fgets(dados, 6, arquivo);
		if(string == NULL){
			printf("Erro na leitura.\n");
		}
		int num = atoi(dados);
		nova->passageiros[i].id = num;
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
	// Inseri-los no arquivo fila.txt
	
	// Remove-los no arquivo informacoes.txt
	fclose(arquivo);
}

void atribuiDoentes(FILE *arquivo, FILE *arquivo2, struct nave *nova){
	int i = 0;
	char doentes[] = "Doentes: ";
	char linha[1000];
	int posicao;
	char dados[1];
	
	arquivo = fopen("informacoes.txt", "r");
	if(arquivo == NULL) {
		printf("Ocorreu erro na abertura do arquivo.");
	}
	
	// Selecionar os dados para inserir na struct
	char *result;
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		result = strstr(linha, doentes);
		if(result != NULL){
			posicao = result - linha;
		}
	}
	
	fseek(arquivo, posicao+9, SEEK_SET);
	while(i < MAX_P){
		char *string = fgets(dados, 3, arquivo);
		if(string == NULL){
			printf("Erro na leitura.\n");
		}
		int num = atoi(dados);
		nova->passageiros[i].doente = num;
		fseek(arquivo, 1, SEEK_CUR);
		i++;
	}
	// Inseri-los no arquivo fila.txt
	
	// Remove-los no arquivo informacoes.txt
	fclose(arquivo);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	struct nave nave1;
	struct fila filaDeNaves;
	
	// Abre o arquivo com as informações dos passageiros
	FILE *arquivo;
	FILE *arquivo2;
	
	atribuiNomes(arquivo, arquivo2, &nave1);
	atribuiPlanetas(arquivo, arquivo2, &nave1);
	atribuiIdades(arquivo, arquivo2, &nave1);
	atribuiIds(arquivo, arquivo2, &nave1);
	atribuiDoentes(arquivo, arquivo2, &nave1);
	
	int i;
	for(i = 0; i < 5; i++){
		printf("Nome %s Planeta %s Idade %d Id %d Donete %d\n", nave1.passageiros[i].nome, nave1.passageiros[i].planeta, nave1.passageiros[i].idade, 
		nave1.passageiros[i].id, nave1.passageiros[i].doente);
	}
	
    return 0;
}

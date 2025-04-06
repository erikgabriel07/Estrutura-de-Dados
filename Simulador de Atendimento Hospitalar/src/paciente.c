#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "paciente.h"
#include "utils.h"

Paciente *novo_paciente(char *nome, int idade, Gravidade gravidade) {
	srand(time(NULL));
	
	int id = gerar_id();
	char hora_data[30] = {};
	
	hora_data_atual(hora_data);
	
	Paciente *novo = (Paciente *) malloc(sizeof(Paciente));
	novo->id = id;
	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->gravidade = gravidade;
	strcpy(novo->tempo_chegada, hora_data);
	novo->timestamp = time(NULL);
	novo->next = NULL;
	
	return novo;
}

void exibir_dados_paciente(Paciente **paciente) {
	printf("ID           : %d\n", (*paciente)->id);
	printf("NOME         : %s\n", (*paciente)->nome);
	printf("IDADE        : %d anos\n", (*paciente)->idade);
	printf("GRAVIDADE    : %d\n", (*paciente)->gravidade);
	printf("TEMPO CHEGADA: %s\n", (*paciente)->tempo_chegada);
	printf("=================================\n");
}
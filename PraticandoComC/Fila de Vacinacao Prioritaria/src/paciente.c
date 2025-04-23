#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "paciente.h"

void exibir_dados_paciente(PacienteVacina *paciente) {
	printf("ID   : %d\n", paciente->id);
	printf("NOME : %s\n", paciente->nome);
	printf("IDADE: %d\n", paciente->idade);
	
	switch (paciente->risco) {
		case 0:
			printf("RISCO: SEM COMORBIDADE\n");
			break;
		case 1:
			printf("RISCO: GESTANTE\n");
			break;
		case 2:
			printf("RISCO: CARDIOPATA\n");
			break;
		case 3:
			printf("RISCO: IMUNOSSUPRIMIDO\n");
			break;
	}
	printf("================================\n");
}

PacienteVacina *criar_paciente(const char *nome, int idade, GrupoRisco risco) {
	srand(time(NULL));
	
	PacienteVacina *novo = (PacienteVacina *) malloc(sizeof(PacienteVacina));
	
	novo->id = 1 + (rand() % 1000);
	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->risco = risco;
	novo->next = NULL;
	
	return novo;
}
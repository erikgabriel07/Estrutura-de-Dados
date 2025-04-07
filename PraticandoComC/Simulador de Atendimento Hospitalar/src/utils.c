#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "paciente.h"
#include "fila.h"
#include "utils.h"

int gerar_id() {
	srand(time(NULL));
	
	int id = 10000 + (rand() % 99999 - 10000 + 1);
	
	return id;
}

void hora_data_atual(char *pBuffer) {
	time_t atual;
	struct tm *tempo_info;
	char buffer[30];
	
	time(&atual);
	tempo_info = localtime(&atual);
	
	strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", tempo_info);
	
	strcpy(pBuffer, buffer);
}

int selecionar_gravidade() {
	int gravidade = 0;
	
	printf("1 - LEVE, 2 - MODERADA, 3 - MEDIA, 4 - GRAVE, 5 - URGENTE\n");
	
	while (gravidade > 5 || gravidade < 1) {
		printf("DIGITE UMA GRAVIDADE VALIDA: ");
		scanf("%d", &gravidade);
	}
	
	return gravidade;
}

void carregar_arquivo(char *filename, FilaPaciente **head) {
	FILE *fptr;
	
	fptr = fopen(filename, "r");
	
	if (!fptr) {
		printf("Arquivo não encontrado!\n");
		return;
	}
	
	while (1) {
		
		Paciente *paciente = (Paciente *) malloc(sizeof(Paciente));
		
		if (fscanf(fptr, "%d\n", &paciente->id) != 1) break;
		
		if (!fgets(paciente->nome, sizeof(paciente->nome), fptr)) break;
		paciente->nome[strcspn(paciente->nome, "\n")] = '\0';
		
		if (fscanf(fptr, "%d\n", &paciente->idade) != 1) break;
		
		if (fscanf(fptr, "%d\n", (int *) &paciente->gravidade) != 1) break;
		
		if (!fgets(paciente->tempo_chegada, sizeof(paciente->tempo_chegada), fptr)) break;
		paciente->tempo_chegada[strcspn(paciente->tempo_chegada, "\n")] = '\0';
		
		if (fscanf(fptr, "%lld\n", &paciente->timestamp) != 1) break;
		
		paciente->next = NULL;
		
		inserir_paciente(&paciente, head);
	}
	
	fclose(fptr);
}

void salvar_arquivo(char *filename, FilaPaciente **head) {
	FILE *fptr;
	
	fptr = fopen(filename, "w");
	
	if (*head == NULL || (*head)->begin == NULL) {
		fclose(fptr);
		return;
	}
	
	Paciente *paciente = (*head)->begin;
	
	while (paciente != NULL) {
		fprintf(fptr, "%d\n", paciente->id);
		fprintf(fptr, "%s\n", paciente->nome);
		fprintf(fptr, "%d\n", paciente->idade);
		fprintf(fptr, "%d\n", paciente->gravidade);
		fprintf(fptr, "%s\n", paciente->tempo_chegada);
		fprintf(fptr, "%lld\n", paciente->timestamp);
		paciente = paciente->next;
	}
	
	fclose(fptr);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "fila.h"

void liberar(FilaVacina **fila) {
	if (!(*fila)) return;
	
	PacienteVacina *temp, *delete = (*fila)->begin;
	
	while (delete) {
		temp = delete->next;
		free(delete);
		delete = temp;
	}
	
	delete = temp = NULL;
	
	free(*fila);
	*fila = NULL;
}

void listar_fila(FilaVacina *fila) {
	if (!fila) return;
	
	PacienteVacina *p = fila->begin;
	
	printf("\n=========== LISTAGEM ===========\n");
	while (p) {
		exibir_dados_paciente(p);
		p = p->next;
	}
}

void inserir_paciente_vacina(PacienteVacina *novo, FilaVacina **fila) {
	if (!novo) return;
	
	if (!(*fila)) {
		*fila = (FilaVacina *)malloc(sizeof(FilaVacina));	
		(*fila)->begin = NULL;
	}

	PacienteVacina *p = (*fila)->begin, *q = NULL;
	
	while (p) {
		if ((novo->risco > p->risco) || 
			(novo->risco == p->risco && novo->idade > p->idade)) break;
			
		q = p;
		p = p->next;
	}
	
	if (!q) {
		novo->next = p;
		(*fila)->begin = novo;
	} else {
		novo->next = q->next;
		q->next = novo;
	}
}

void chamar_paciente(FilaVacina *fila) {
	if (!fila || !fila->begin) return;
	
	PacienteVacina *delete = fila->begin;
	
	printf("\n====== Deletando paciente ======\n");
	exibir_dados_paciente(delete);
	
	fila->begin = delete->next;
	
	free(delete);
	delete = NULL;
}

void carregar_pacientes_arquivo(const char *filename, FilaVacina **fila) {
	FILE *fptr;
	
	fptr = fopen(filename, "r");
	
	if (!fptr) {
		printf("Nao foi possivel carregar arquivo!\n");
		return;
	}
	
	while (1) {
		PacienteVacina *paciente = (PacienteVacina *) malloc(sizeof(PacienteVacina));
		
		if (fscanf(fptr, "%d\n", &paciente->id) != 1) break;
		
		if (!fgets(paciente->nome, sizeof(paciente->nome), fptr)) break;
		paciente->nome[strcspn(paciente->nome, "\n")] = '\0';
		
		if (fscanf(fptr, "%d\n", &paciente->idade) != 1) break;
		
		if (fscanf(fptr, "%d\n", (int *)&paciente->risco) != 1) break;
		
		paciente->next = NULL;
		
		inserir_paciente_vacina(paciente, fila);
	}
	
	fclose(fptr);
}

void salvar_pacientes_arquivo(const char *filename, FilaVacina **fila) {
	if (!(*fila)) return;
	
	FILE *fptr;
	
	fptr = fopen(filename, "w");
	
	PacienteVacina *p = (*fila)->begin;
	
	while (p != NULL) {
		fprintf(fptr, "%d\n", p->id);
		fprintf(fptr, "%s\n", p->nome);
		fprintf(fptr, "%d\n", p->idade);
		fprintf(fptr, "%d\n", (int)p->risco);
		p = p->next;
	}
	
	fclose(fptr);
}

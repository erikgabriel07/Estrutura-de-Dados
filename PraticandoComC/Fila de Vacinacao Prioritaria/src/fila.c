#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "fila.h"

void listar_fila(FilaVacina **fila) {
	PacienteVacina *p = (*fila)->begin;
	
	printf("====== EXIBINDO PACIENTES ======\n");
	while (p != NULL) {
		exibir_dados_paciente(&p);
		p = p->next;
	}
}

void chamar_paciente(FilaVacina **fila) {
	PacienteVacina *remover = (*fila)->begin;
	
	printf("Chamando paciente: %s\n", remover->nome);
	
	(*fila)->begin = remover->next;
	
	free(remover);
	remover = NULL;
}

PacienteVacina *buscar_paciente_anterior(PacienteVacina **atual, FilaVacina **fila) {
	PacienteVacina *anterior, *p;
	p = (*fila)->begin;
	
	while (p != NULL) {
		if (p == *atual) {
			return anterior;
		}
		anterior = p;
		p = p->next;
	}
}

void inserir_paciente_vacina(PacienteVacina **novo, FilaVacina **fila) {
	/*
	if (*fila == NULL) {
		*fila = (FilaVacina *) malloc(sizeof(FilaVacina));
		(*fila)->begin = *novo;
		return;
	}
	
	PacienteVacina *atual = (*fila)->begin;
	
	if ((*novo)->idade > atual->idade || ((*novo)->idade <= atual->idade && (*novo)->risco > atual->risco)) {
		(*fila)->begin = *novo;
		(*novo)->next = atual;
		return;
	}
	
	while (atual != NULL) {
		if ((*novo)->idade > atual->idade || ((*novo)->idade <= atual->idade && (*novo)->risco > atual->risco)) {
			(*novo)->next = atual;
			buscar_paciente_anterior(&atual, fila)->next = *novo;
			return;
			break;
		} else if ((*novo)->risco == atual->risco && atual->next == NULL) {
			(*novo)->next = atual->next;
			atual->next = *novo;
			return;
			break;
		} else if ((
		*novo)->risco < atual->risco) {
			(*novo)->next = atual->next;
			atual->next = *novo;
			return;
			break;
		} else {
			printf("ALGO ESTA ERRADO...");
		}
		atual = atual->next;
	}
	*/
	
	return;
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
		
		inserir_paciente_vacina(&paciente, fila);
	}
	
	fclose(fptr);
}

void salvar_pacientes_arquivo(const char *filename, FilaVacina **fila) {
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

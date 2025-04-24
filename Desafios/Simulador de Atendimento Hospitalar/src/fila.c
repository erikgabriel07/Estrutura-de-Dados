#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "paciente.h"
#include "fila.h"

void inicializar_fila(FilaPaciente **head) {
	*head = NULL;
}

void listagem_fila(FilaPaciente **head) {
	if (*head == NULL || (*head)->begin == NULL) return;
	
	Paciente *p = (*head)->begin;
	
	printf("\n===== LISTAGEM DE PACIENTES =====\n");
	while (p != NULL) {
		exibir_dados_paciente(&p);
		p = p->next;
	}
}

Paciente *buscar_paciente(int id, FilaPaciente **head) {
	Paciente *p = (*head)->begin;
	
	while (p != NULL) {
		if (p->id == id) {
			printf("\n===== PACIENTE ENCONTRADO =====\n");
			exibir_dados_paciente(&p);
			return p;
			break;
		}
		p = p->next;
	}
	printf("\nNao foi possivel localizar paciente ID %d!\n", id);
	
	return NULL;
}

void inserir_paciente(Paciente **paciente, FilaPaciente **head) {
	if (*head == NULL) {
		*head = (FilaPaciente *) malloc(sizeof(FilaPaciente));
		
		(*head)->begin = *paciente;
		(*head)->end = *paciente;
		
	} else {
		if ((*head)->begin == NULL) {
			(*head)->begin = *paciente;
			(*head)->end = *paciente;
		} else {
			(*head)->end->next = *paciente;
			(*head)->end = *paciente;
		}
	}
	
	printf("Cliente adicionado a lista com sucesso!\n");
}

void atender_paciente(FilaPaciente **head) {
	if (*head == NULL || (*head)->begin == NULL) {
        printf("\nNenhum paciente na fila para atendimento.\n");
        return;
    }
	
	Paciente *remover = (*head)->begin;
	(*head)->begin = remover->next;
	
	printf("\n===== CHAMANDO PACIENTE =====\n");
	printf("ID   : %d\n", remover->id);
	printf("NOME : %s\n", remover->nome);
	printf("TEMPO DE ESPERA: %lld segundos\n", time(NULL) - remover->timestamp);
	printf("===============================\n");
	
	free(remover);
	remover = NULL;
}

int cancelar_atendimento(int id, FilaPaciente **head) {
	Paciente *remover = buscar_paciente(id, head);
	Paciente *anterior;
	
	if (remover == NULL) {
		printf("\nNao foi possivel cancelar atendimento de ID %d!\n", id);
		return 0;
	}
	
	if (remover == (*head)->begin) {
		(*head)->begin = remover->next;
		
		free(remover);
		remover = NULL;
		
		printf("Cancelamento do ID %d sucedido!\n", id);
		
		return 1;
	} else {
		while (remover != NULL) {
			if (remover->id == id) {
				anterior->next = remover->next;
				
				free(remover);
				remover = NULL;
				
				printf("Cancelamento do ID %d sucedido!\n", id);
				
				return 1;
				break;
			}
			anterior = remover;
			remover = remover->next;
		}
	}
	
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tarefa.h"

void inicializar(Tarefa **inicio, Tarefa **fim) {
	*inicio = NULL;
	*fim = NULL;
}

void listar_tarefas(Tarefa **inicio) {
	Tarefa *p = *inicio;
	p = p->next;
	
	printf("========= Listagem =========\n");
	while (p != NULL) {
		printf("ID: %d\n", p->id);
		printf("Desc: %s\n", p->desc);
		printf("Prioridade: %d\n", p->prioridade);
		printf("==============================\n");
		p = p->next;
	}
}

Tarefa *buscar_tarefa(int id, Tarefa **inicio) {
	if (*inicio == NULL) return NULL;
	if ((*inicio)->id == id) {
		printf("===== Tarefa encontrada! =====\n");
		printf("ID: %d\n", (*inicio)->id);
		printf("Descricao: %s\n", (*inicio)->desc);
		printf("Prioridade: %d\n", (*inicio)->prioridade);
		printf("==============================\n");
		return *inicio;
	}
	buscar_tarefa(id, &(*inicio)->next);
}

Tarefa *buscar_tarefa_anterior(Tarefa **tarefa, Tarefa **inicio, Tarefa **anterior) {
	if (inicio == NULL) return NULL;
	if (*inicio == *tarefa) return *anterior;
	buscar_tarefa_anterior(tarefa, &(*inicio)->next, inicio);
}

void copiarDadosEOrdenar(Tarefa **targetInicio, Tarefa **targetFim, Tarefa **source) {
	Tarefa *copiaElemento = (Tarefa *)malloc(sizeof(Tarefa));
	copiaElemento->id = (*source)->id;
	strcpy(copiaElemento->desc, (*source)->desc);
	copiaElemento->prioridade = (*source)->prioridade;
	copiaElemento->next = NULL;
	
	if (*targetFim == NULL) {
		*targetInicio = (Tarefa *)malloc(sizeof(Tarefa));
		*targetFim = (Tarefa *)malloc(sizeof(Tarefa));
		
		(*targetInicio)->next = copiaElemento;
		(*targetFim)->next = copiaElemento;
	} else {
		if (copiaElemento->prioridade >= (*targetInicio)->next->prioridade) {
			copiaElemento->next = (*targetInicio)->next;
			(*targetInicio)->next = copiaElemento;
		} else {
			if (copiaElemento->prioridade > (*targetFim)->next->prioridade) {
				Tarefa *anterior = buscar_tarefa_anterior(&(*targetFim)->next, targetInicio, NULL);
				
				while (anterior->prioridade <= copiaElemento->prioridade) {
					anterior = buscar_tarefa_anterior(&anterior, targetInicio, NULL);
				}
				
				copiaElemento->next = anterior->next;
				anterior->next = copiaElemento;
			} else {
				(*targetFim)->next->next = copiaElemento;
				(*targetFim)->next = copiaElemento;
			}
		}
	}
}

void inserir_tarefa(char *desc, int prioridade, Tarefa **inicio, Tarefa **fim) {
	int id = 100 + (rand() % 9901);
	
	Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
	nova->id = id;
	strcpy(nova->desc, desc);
	nova->prioridade = prioridade;
	nova->next = NULL; 
	
	if (*fim == NULL) {
		*inicio = (Tarefa *)malloc(sizeof(Tarefa));
		*fim = (Tarefa *)malloc(sizeof(Tarefa));
		
		(*inicio)->next = nova;
		(*fim)->next = nova;
	} else {
		(*fim)->next->next = nova;
		(*fim)->next = nova;
	}
	
	printf("Tarefa com inserida com sucesso!\n");
}

void remover_tarefa(int id, Tarefa **inicio, Tarefa **fim) {
	Tarefa *delete = buscar_tarefa(id, inicio);
	Tarefa *atual, *anterior;
	atual = (*inicio)->next;
	
	if (delete == NULL) {
		printf("\nNenhuma tarefa encontrada com ID = %d\n", id);
		return;
	}
	if (delete == (*inicio)->next) (*inicio)->next = (*inicio)->next->next;
	
	while (atual != NULL) {
		if (atual == delete) {
			printf("Deletando tarefa com ID = %d\n", atual->id);
			printf("Descricao tarefa: %s\n", atual->desc);
			
			anterior->next = delete->next;
			
			if (delete == (*fim)->next) (*fim)->next = anterior;
			
			free(delete);
			delete = NULL;
			break;
		}
		anterior = atual;
		atual = atual->next;
	}
}
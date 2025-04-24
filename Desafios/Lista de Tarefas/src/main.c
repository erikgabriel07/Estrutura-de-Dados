#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tarefa.h"

/*
	Informação a respeito da prioridade

	1 - Prioridade baixa
	2 - Prioridade média
	3 - Prioridade alta
*/

int main() {

	srand(time(NULL));
	
	Tarefa *inicio;
	Tarefa *fim;
	
	inicializar(&inicio, &fim);
	
	inserir_tarefa("Jogar no PS5", 1, &inicio, &fim);
	inserir_tarefa("Lavar a louca", 2, &inicio, &fim);
	inserir_tarefa("Revisao para prova", 3, &inicio, &fim);
	inserir_tarefa("Varrer a casa", 2, &inicio, &fim);
	inserir_tarefa("Levar criancas na escola", 3, &inicio, &fim);
	inserir_tarefa("Fazer compras", 1, &inicio, &fim);
	
	char opcao = {};
	
	printf("BEM-VINDO AO GERENCIADOR DE TAREFAS");
	while (opcao != '6') {
		printf("\n===== ESCOLHA UMA OPCAO =====\n");
		printf("[1] Listar tarefas por prioridade\n");
		printf("[2] Inserir nova tarefa\n");
		printf("[3] Listar tarefas\n");
		printf("[4] Deletar tarefa\n");
		printf("[5] Buscar tarefas\n");
		printf("[6] Sair\n");
		printf("opcao: ");
		opcao = getchar();
		
		while (getchar() != '\n');
		
		printf("\n"); // Quebrando algumas linhas
		
		switch (opcao) {
			case '1':
				Tarefa *p = inicio, *copiaInicio, *copiaFim;
				p = p->next;
				
				inicializar(&copiaInicio, &copiaFim);
				
				while (p != NULL) {
					copiarDadosEOrdenar(&copiaInicio, &copiaFim, &p);
					p = p->next;
				}
				
				listar_tarefas(&copiaInicio);
				
				free(copiaInicio);
				free(copiaFim);
				copiaInicio = NULL;
				copiaFim = NULL;
				
				break;
			case '2':
				char desc[100];
				int prioridade = 0;
				
				printf("Descricao: ");
				fgets(desc, sizeof(desc), stdin);
				desc[strcspn(desc, "\n")] = '\0';
				
				printf("Prioridade (1 - Baixa, 2 - Media, 3 - Alta): ");
				scanf("%d", &prioridade);
				
				while (getchar() != '\n');
				
				if (prioridade < 1 || prioridade > 3) {
					printf("Prioridade invalida! Escolha 1, 2 ou 3.\n");
					break;
				}
				
				inserir_tarefa(desc, prioridade, &inicio, &fim);
				break;
			case '3':
				listar_tarefas(&inicio);
				break;
			case '4':
				int id_tarefa;
				
				printf("ID da tarefa que deseja deletar: ");
				scanf("%d", &id_tarefa);
				
				while (getchar() != '\n');
				
				remover_tarefa(id_tarefa, &inicio, &fim);
				
				break;
			case '5':
				int id_tarefa_buscar;
				
				printf("ID da tarefa que deseja buscar: ");
				scanf("%d", &id_tarefa_buscar);
				
				while (getchar() != '\n');
				
				buscar_tarefa(id_tarefa_buscar, &inicio);
				
				break;
			case '6':
				printf("Encerrando programa...");
				break;
			default:
				printf("Essa opcao nao existe!\n");
				break;
		}
	}
	
	return EXIT_SUCCESS;
}

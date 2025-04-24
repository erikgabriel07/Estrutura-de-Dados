#ifndef TAREFA_H
#define TAREFA_H

typedef struct tipo_tarefa {
	int id;
	char desc[100];
	int prioridade;
	struct tipo_tarefa *next;
} Tarefa;

void inicializar(Tarefa **inicio, Tarefa **fim);
void listar_tarefas(Tarefa **inicio);
Tarefa *buscar_tarefa(int id, Tarefa **inicio);
Tarefa *buscar_tarefa_anterior(Tarefa **tarefa, Tarefa **inicio, Tarefa **anterior);
void copiarDadosEOrdenar(Tarefa **targetInicio, Tarefa **targetFim, Tarefa **source);
void inserir_tarefa(char *desc, int prioridade, Tarefa **inicio, Tarefa **fim);
void remover_tarefa(int id, Tarefa **inicio, Tarefa **fim);

#endif
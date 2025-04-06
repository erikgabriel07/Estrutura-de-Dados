#ifndef PACIENTE_H
#define PACIENTE_H

typedef enum {
	SEM_COMORBIDADE,
	GESTANTE,
	CARDIOPATA,
	IMUNOSSUPRIMIDO
} GrupoRisco;

typedef struct paciente_vacina {
	int id;
	char nome[100];
	int idade;
	GrupoRisco risco;
	struct paciente_vacina *next;
} PacienteVacina;

void exibir_dados_paciente(PacienteVacina **paciente);
PacienteVacina *criar_paciente(const char *nome, int idade, GrupoRisco risco);

#endif
#ifndef PACIENTE_H
#define PACIENTE_H

/* Definindo a estrutura do grupo de risco */
typedef enum {
	SEM_COMORBIDADE,
	GESTANTE,
	CARDIOPATA,
	IMUNOSSUPRIMIDO
} GrupoRisco;

/* Definindo a estrutura de pacientes */
typedef struct paciente_vacina {
	int id;
	char nome[100];
	int idade;
	GrupoRisco risco;
	struct paciente_vacina *next;
} PacienteVacina;

/**
 * Essa função exibe os dados dos pacientes.
 *
 * @param paciente		Ponteiro para um paciente.
 */
void exibir_dados_paciente(PacienteVacina *paciente);

/**
 * Essa função cria um novo paciente.
 *
 * @param nome			Nome do paciente.
 * @param idade			Idade do paciente.
 * @param risco			Grupo de risco do paciente.
 * @return				Um ponteiro para o novo paciente.
 */
PacienteVacina *criar_paciente(const char *nome, int idade, GrupoRisco risco);

#endif
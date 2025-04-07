#ifndef PACIENTE_H
#define PACIENTE_H

// Gravidade de 1 a 5, sendo 5 o mais grave.
typedef enum {
	UM = 1,
	DOIS,
	TRES,
	QUATRO,
	CINCO
} Gravidade;

typedef struct tipo_paciente {
	int id;
	char nome[150];
	int idade;
	Gravidade gravidade;
	char tempo_chegada[30];
	time_t timestamp;
	struct tipo_paciente *next;
} Paciente;

Paciente *novo_paciente(char *nome, int idade, Gravidade gravidade);
void exibir_dados_paciente(Paciente **paciente);

#endif
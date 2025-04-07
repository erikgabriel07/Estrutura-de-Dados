#ifndef FILA_H
#define FILA_H

typedef struct tipo_paciente Paciente;

typedef struct fila_paciente {
	Paciente *begin;
	Paciente *end;
} FilaPaciente;

void inicializar_fila(FilaPaciente **head);
void listagem_fila(FilaPaciente **head);
Paciente *buscar_paciente(int id, FilaPaciente **head);
void inserir_paciente(Paciente **paciente, FilaPaciente **head);
void atender_paciente(FilaPaciente **head);
int cancelar_atendimento(int id, FilaPaciente **head);

#endif
#ifndef UTILS_H
#define UTILS_H

typedef struct fila_paciente FilaPaciente;

int gerar_id();
void hora_data_atual();
int selecionar_gravidade();
void carregar_arquivo(char *filename, FilaPaciente **head);
void salvar_arquivo(char *filename, FilaPaciente **head);

#endif
#ifndef FILA_H
#define FILA_H

typedef struct paciente_vacina PacienteVacina;

typedef struct fila_vacina {
	PacienteVacina *begin;
} FilaVacina;

void listar_fila(FilaVacina **fila);
void chamar_paciente(FilaVacina **fila);
PacienteVacina *buscar_paciente_anterior(PacienteVacina **atual, FilaVacina **fila);
void inserir_paciente_vacina(PacienteVacina **novo, FilaVacina **fila);
void carregar_pacientes_arquivo(const char *filename, FilaVacina **fila);
void salvar_pacientes_arquivo(const char *filename, FilaVacina **fila);

#endif
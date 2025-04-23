#ifndef FILA_H
#define FILA_H

/* Declarando a estrutura PacienteVacina */
typedef struct paciente_vacina PacienteVacina;

/* Definindo estrutura da fila */
typedef struct fila_vacina {
	PacienteVacina *begin;
} FilaVacina;

/**
 * Libera toda a memória alocada para a fila de pacientes.
 *
 * @param fila			Ponteiro para o ponteiro da fila.
 */
void liberar(FilaVacina **fila);

/**
 * Exibe os dados de todos os pacientes na fila.
 *
 * @param fila			Ponteiro para a fila.
 */
void listar_fila(FilaVacina *fila);

/**
 * Insere um novo paciente na fila, mantendo a ordenação por prioridade.
 * A prioridade é determinada pelo risco (maior primeiro) e, em caso de empate, pela idade (mais velho primeiro).
 *
 * @param novo			Ponteiro para o novo paciente.
 * @param fila			Ponteiro para o ponteiro da fila.
 */
void inserir_paciente_vacina(PacienteVacina *novo, FilaVacina **fila);

/**
 * Remove o paciente com maior prioridade da fila e exibe seus dados.
 *
 * @param fila			Ponteiro para a fila.
 */
void chamar_paciente(FilaVacina *fila);

/**
 * Carrega pacientes de um arquivo e os insere na fila de forma ordenada.
 *
 * @param filename		Nome do arquivo a ser lido.
 * @param fila			Ponteiro para o ponteiro da fila.
 */
void carregar_pacientes_arquivo(const char *filename, FilaVacina **fila);

/**
 * Salva os dados dos pacientes da fila em um arquivo.
 *
 * @param filename		Nome do arquivo a ser escrito.
 * @param fila			Ponteiro para o ponteiro da fila.
 */
void salvar_pacientes_arquivo(const char *filename, FilaVacina **fila);

#endif
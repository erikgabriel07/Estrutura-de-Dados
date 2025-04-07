#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#ifdef __cplusplus
extern "C" {
#endif

/* struct para os dados dos documetnos */
typedef struct _Documento Documento;

/* struct para manipulação da fila de documentos */
typedef struct _DocFila DocFila;

struct _DocFila {
	Documento *inicio;
	Documento *fim;
};

struct _Documento {
	char nome[50];
	unsigned int paginas;
	struct _Documento *next;
};

/* Um valor armazenado no documento */
typedef void *DocValor;

/**
 * Função de callback para mostrar os valores contidos em um documento
 *
 * @param v1			Primeiro valor passado da lista.
 * @param v2			Segundo valor passado da lista.
 */
typedef void (*DocPrintFunc)(DocValor v1, DocValor v2);

/**
 * Função para criar um novo documento.
 *
 * @param nome			Nome do documento.
 * @param paginas		Quantidade de páginas do documento.
 * @return				Retorna um ponteiro de documento.
 */
Documento *criar_documento(const char *nome, unsigned int paginas);

/**
 * Libera a memória da lista.
 *
 * @param lista			Lista a ser liberada.
 */
void liberar_fila(DocFila **fila);

/**
 * Função para inicializar uma lista vazia.
 *
 * @param fila			Ponteiro para um ponteira de uma fila de documentos.
 */
void initialize(DocFila **fila);

/**
 * Função para mostrar todos os documentos na fila atual.
 *
 * @param fila			Ponteiro para um ponteira de uma fila de documentos.
 */
void listar_fila(DocFila **fila, DocPrintFunc print_func);

/**
 * Função para adicionar um novo documento ao final da fila.
 *
 * @param documento		Dados do novo documento.
 * @param fila			Ponteiro para a fila de documento.
 */
void adicionar_novo_documento(Documento *doc, DocFila **fila);

/**
 * Função que imprime o primeiro documento da fila (remove-o da fila).
 *
 * @param fila			Ponteiro para um ponteira de uma fila de documentos.
 */
void imprimir_documento(DocFila **fila, DocPrintFunc print_func);

/**
 * Função que retorna o próximo documento que deve ser imprimido.
 *
 * @param fila			Ponteiro para um ponteira de uma fila de documentos.
 */
void proximo_documento(DocFila **fila, DocPrintFunc print_func);

#ifdef __cplusplus
}
#endif

#endif
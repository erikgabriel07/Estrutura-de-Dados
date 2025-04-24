#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "documento.h"

Documento *criar_documento(const char *nome, unsigned int paginas) {
	Documento *novo = (Documento *)malloc(sizeof(Documento));
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->next = NULL;
	
	return novo;
}

void liberar_fila(DocFila **fila) {
	if (!(*fila) || !(*fila)->inicio) return;
	
	Documento *current = (*fila)->inicio;
	while (current) {
		Documento *tmp = current;
		current = current->next;
		free(tmp);
	}
	(*fila)->inicio = (*fila)->fim = NULL;
	free(*fila);
}

void initialize(DocFila **fila) {
	*fila = (DocFila *) malloc(sizeof(DocFila));
	(*fila)->inicio = (*fila)->fim = NULL;
}

void listar_fila(DocFila **fila, DocPrintFunc print_func) {
	if (!(*fila) || !(*fila)->inicio) return;
	
	Documento *current = (*fila)->inicio;
	
	while (current) {
		print_func((DocValor)current->nome, (DocValor)(uintptr_t)current->paginas);
		current = current->next;
	}
}

void adicionar_novo_documento(Documento *doc, DocFila **fila) {
	if (!(*fila)->fim) {
		(*fila)->inicio = doc;
		(*fila)->fim = doc;
	} else {
		doc->next = (*fila)->inicio;
		(*fila)->inicio = doc;
	}
}

void imprimir_documento(DocFila **fila, DocPrintFunc print_func) {
	if (!(*fila) || !(*fila)->inicio) return;
	
	Documento *delete = (*fila)->inicio;
	
	printf("Imprimindo documento...\n");
	print_func((DocValor)delete->nome, (DocValor)(uintptr_t)delete->paginas);
	
	(*fila)->inicio = delete->next;
	free(delete);
}

void proximo_documento(DocFila **fila, DocPrintFunc print_func) {
	if (!(*fila) || !(*fila)->inicio) return;
	
	print_func((DocValor)(*fila)->inicio->nome, (DocValor)(uintptr_t)(*fila)->inicio->paginas);
}
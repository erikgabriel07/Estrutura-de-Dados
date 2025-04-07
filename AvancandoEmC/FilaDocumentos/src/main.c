#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "documento.h"

void print_func(DocValor v1, DocValor v2) {
	char *nome = (char *)v1;
	unsigned int valor = (unsigned int)(uintptr_t)v2;
	
	printf("\n============ DOCUMENTO ============\n");
	printf("Nome: %s\nQtd. Paginas: %d\n", nome, valor);
	printf("===================================\n");
}

int main() {
	
	DocFila *fila;
	
	initialize(&fila);
	
	printf("IMPRESSORA DE DOCUMENTOS\n");
	
	char option = {};
	
	while (option != '5') {
		printf("\n=========== MENU ===========\n");
		printf("[1] Adicionar novo documento\n");
		printf("[2] Imprimir documento\n");
		printf("[3] Ver proximo\n");
		printf("[4] Listar fila\n");
		printf("[5] Sair\n");
		printf("sua opcao: ");
		option = getchar();
		
		while (getchar() != '\n');
		
		switch (option) {
			case '1':
				char nome[50];
				unsigned int paginas;
				
				printf("Nome do documento: ");
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = '\0';
				
				printf("Quantidade de paginas: ");
				scanf("%u", &paginas);
				
				while (getchar() != '\n');
				
				adicionar_novo_documento(criar_documento(nome, paginas), &fila);
				
				break;
			case '2':
				imprimir_documento(&fila, print_func);
				break;
			case '3':
				proximo_documento(&fila, print_func);
				break;
			case '4':
				listar_fila(&fila, print_func);
				break;
			case '5':
				printf("Saindo do programa...\n\n");
				break;
			default:
				printf("Opcao invalida!\n");
				break;
		}
	}
	
	liberar_fila(&fila);
	
	return 0;
}
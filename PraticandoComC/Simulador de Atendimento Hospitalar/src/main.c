#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "paciente.h"
#include "utils.h"

int main() {
	
	FilaPaciente *head;
	inicializar_fila(&head);
	
	carregar_arquivo("pacientes_db.txt", &head);
	
	Paciente *novo = (Paciente *) malloc(sizeof(Paciente));
	
	char opcao = {};
	
	printf("\nBEM-VIND AO GERENCIAMENTO DE FILAS DO SISTEMA\n\n");
	while (opcao != 's') {
		printf("\n====== ESCOLHA UMA OPCAO ======\n");
		printf("[i] Inserir novo paciente\n");
		printf("[a] Atender novo paciente\n");
		printf("[l] Listagem de pacientes\n");
		printf("[c] Cancelar atendimento\n");
		printf("[b] Buscar paciente\n");
		printf("[s] Sair do sistema\n\n");
		printf("sua opcao: ");
		opcao = getchar();
		
		while (getchar() != '\n');
		
		switch (opcao) {
			case 'i':
				int idade;
				char nome[150];
				Gravidade gravidade;
				
				printf("\nIDADE    : ");
				scanf("%d", &idade);
				
				while (getchar() != '\n');
				
				printf("NOME     : ");
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = '\0';;
				
				gravidade = selecionar_gravidade();
				
				while (getchar() != '\n');
				
				novo = novo_paciente(nome, idade, gravidade);
				inserir_paciente(&novo, &head);
				
				break;
			case 'a':
				atender_paciente(&head);
				break;
			case 'l':
				listagem_fila(&head);
				break;
			case 'c':
				int id;
				
				printf("\nID DO PACIENTE: ");
				scanf("%d", &id);
				
				while (getchar() != '\n');
				
				cancelar_atendimento(id, &head);
				
				break;
			case 'b':
				int id_busca;
				
				printf("\nID DO PACIENTE PARA BUSCAR: ");
				scanf("%d", &id_busca);
				
				while (getchar() != '\n');
				
				buscar_paciente(id_busca, &head);
				
				break;
			case 's':
				printf("Saindo do sistema...\n");
				break;
		}
	}

	salvar_arquivo("pacientes_db.txt", &head);
	
	return EXIT_SUCCESS;
}
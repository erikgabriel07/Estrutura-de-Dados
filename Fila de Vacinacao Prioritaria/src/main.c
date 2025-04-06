#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "paciente.h"

int main() {
	
	FilaVacina *inicio = NULL;
	
	carregar_pacientes_arquivo("pacientes.txt", &inicio);
	
	char opcao = {};
	
	printf("\nBEM-VINDO AO SIMULADOR DE VACINACAO\n\n");
	while (opcao != 's') {
		printf("\n\n====== ESCOLHA UMA OPCAO ======\n");
		printf("[n] Novo paciente\n");
		printf("[c] Chamar paciente\n");
		printf("[l] Listar pacientes\n");
		printf("[s] Sair\n");
		printf("Sua opcao: ");
		opcao = getchar();
		
		while (getchar() != '\n');
		
		switch (opcao) {
			case 'n':
				char nome[100];
				int idade = 0;
				GrupoRisco risco = 0;
				
				printf("\nNOME : ");
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = '\0';
				
				printf("IDADE: ");
				scanf("%d", &idade);
				
				while (getchar() != '\n');
				
				printf("RISCO: ");
				scanf("%d", (int *)&risco);
				
				while (getchar() != '\n');
				
				PacienteVacina *novo = criar_paciente(nome, idade, risco);
				
				inserir_paciente_vacina(&novo, &inicio);
				
				break;
			case 'c':
				chamar_paciente(&inicio);
				break;
			case 'l':
				listar_fila(&inicio);
				break;
			case 's':
				printf("Saindo do programa...");
				break;
		}
		
	}

	salvar_pacientes_arquivo("pacientes.txt", &inicio);
	
	return EXIT_SUCCESS;
}
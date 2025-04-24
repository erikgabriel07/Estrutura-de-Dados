#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {
	
	Node *root = create_node(0);
	
	insert_new_node(10, root);
	insert_new_node(20, root);
	insert_new_node(30, root);
	insert_new_node(40, root);
	insert_new_node(50, root);
	insert_new_node(60, root); // Não vai adicionar um novo item pois o máximo de nós já foi atingido
	
	for (int i = 0; i < 5; i++) {
		insert_new_node(i, root->nodes[0]);
		insert_new_node(i, root->nodes[1]);
		insert_new_node(i, root->nodes[2]);
		insert_new_node(i, root->nodes[3]);
		insert_new_node(i, root->nodes[4]);
	}
	
	print_node(0, root);
	
	if (find_node(1, root))
		printf("ENCONTRADO!\n");
	else
		printf("NAO ENCONTRADO!\n");
	
	remove_node(1, root);
	
	remove_node(0, root);
	
	remove_node(0, root);
	print_node(0, root);
	
	free_tree(&root);
	
	return 0;
}
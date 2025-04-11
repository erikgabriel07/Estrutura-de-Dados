#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {
	
	Node *root = create();
	
	insert_new_node(90, &root);
	insert_new_node(80, &root);
	insert_new_node(95, &root);
	insert_new_node(120, &root);
	insert_new_node(110, &root);
	insert_new_node(125, &root);
	insert_new_node(79, &root);
	insert_new_node(56, &root);
	insert_new_node(76, &root);
	insert_new_node(87, &root);
	insert_new_node(134, &root);
	insert_new_node(142, &root);
	insert_new_node(124, &root);
	insert_new_node(135, &root);
	
	printf("EM  ORDEM: ");
	in_order_listing(root);
	printf("\nPRE ORDEM: ");
	pre_order_listing(root);
	printf("\nPOS ORDER: ");
	post_order_listing(root);
	printf("\n");
	
	int finded = find_node_by_value(80, root);
	printf("ENCONTROU: %s\n", finded == 1 ? "SIM" : "NAO");
	finded = find_node_by_value(160, root);
	printf("ENCONTROU: %s\n", finded == 1 ? "SIM" : "NAO");
	
	Node *temp = get_left_child(root);
	
	printf("%u\n", temp->node_value);
	printf("%u\n", get_parent(temp)->node_value);
	
	temp = get_right_child(temp);
	printf("%u\n", temp->node_value);
	
	temp = get_left_child(get_parent(temp));
	printf("%u\n", temp->node_value);
	
	printf("ARVORE BINARIA:\n");
	beautify_print(root, 0);
	
	printf("Removendo 134...\n");
	remove_node(134, root);
	printf("ARVORE BINARIA:\n");
	beautify_print(root, 0);
	
	free_node(&root);
	
	return 0;
}
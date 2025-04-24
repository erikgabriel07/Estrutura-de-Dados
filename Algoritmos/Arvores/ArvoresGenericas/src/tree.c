#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void free_tree(Node **root) {
	if (!(*root)) return;
	
	for (int i = 0; i < MAX_NODES; i++) {
		if ((*root)->nodes[i]) {
			free_tree(&(*root)->nodes[i]);
		}
	}
	
	free(*root);
	*root = NULL_NODE;
}

Node *create_node(unsigned int data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	
	for (int i = 0; i < MAX_NODES; i++) {
		new_node->nodes[i] = NULL_NODE;
	}
	return new_node;
}

void print_node(unsigned int level, Node *root) {
	if (!root) return;
	
	for (unsigned int i = 0; i < level; i++) {
		printf("	");
	}
	
	printf("%u\n", root->data);
	
	for (int i = 0; i < MAX_NODES; i++) {
		print_node(level + 1, root->nodes[i]);
	}
}

int find_node(unsigned int position, Node *root) {
	if (!root || position >= MAX_NODES) return 0;
	
	if (root->nodes[position]) return 1;
	
	return 0;
}

int insert_new_node(unsigned int data, Node *root) {
	if (!root) return 0;
	
	for (int i = 0; i < MAX_NODES; i++) {
		if (!root->nodes[i]) {
			root->nodes[i] = create_node(data);
			return 1;
		}
	}
	return 0;
}

int remove_node(unsigned int position, Node *root) {
	if (!root || position >= MAX_NODES) return 0;
	
	free_tree(&root->nodes[position]);
	
	for (int i = position; i < MAX_NODES - 1; i++) {
		root->nodes[i] = root->nodes[i + 1];
	}
	
	root->nodes[MAX_NODES - 1] = NULL;
	
	return 1;
}
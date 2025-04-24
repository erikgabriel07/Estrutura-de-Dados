#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void free_node(Node **node) {
	if (!(*node)) return;
	free_node(&(*node)->left_node);
	free_node(&(*node)->right_node);
	free(*node);
	*node = NULL;
	return;
}

Node *create(void) {
	Node *new_node = NULL_NODE;
	
	return new_node;
}

void in_order_listing(Node *node) {
	if (!node) return;
	in_order_listing(node->left_node);
	printf("%d ", node->node_value);
	in_order_listing(node->right_node);
	return;
}

void pre_order_listing(Node *node) {
	if (!node) return;
	printf("%d ", node->node_value);
	pre_order_listing(node->left_node);
	pre_order_listing(node->right_node);
	return;
}

void post_order_listing(Node *node) {
	if (!node) return;
	post_order_listing(node->left_node);
	post_order_listing(node->right_node);
	printf("%d ", node->node_value);
}

void beautify_print(Node *node, int whitespace) {
	if (!node) return;
	
	whitespace += 5;
	
	beautify_print(node->right_node, whitespace);
	
	for (int i = 5; i < whitespace; i++)
		printf(" ");
	printf("%d\n", node->node_value);
	
	beautify_print(node->left_node, whitespace);
}

Node *get_left_child(Node *node) {
	if (!node) return NULL_NODE;
	
	if (node->left_node) return node->left_node;
	
	return NULL_NODE;
}

Node *get_right_child(Node *node) {
	if (!node) return NULL_NODE;
	
	if (node->right_node) return node->right_node;
	
	return NULL_NODE;
}

Node *get_parent(Node *node) {
	if (!node) return NULL_NODE;
	
	if (node->parent) return node->parent;
	
	return NULL_NODE;
}

int find_node_by_value(unsigned int node_value, Node *node) {
	if (!node) return 0;
	
	while (node) {
		if (node_value > node->node_value) {
			node = node->right_node;
		} else if (node_value < node->node_value) {
			node = node->left_node;
		} else {
			return 1;
		}
	}
	return 0;
}

int insert_new_node(unsigned int node_value, Node **node) {
	if (!(*node)) {
		*node = (Node *)malloc(sizeof(Node));
		(*node)->node_value = 100;
		(*node)->parent = NULL_NODE;
		(*node)->left_node = NULL_NODE;
		(*node)->right_node = NULL_NODE;
	}
	
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->node_value = node_value;
	
	Node *temp = *node, *previous;
	while (temp) {
		previous = temp;
		if (node_value > temp->node_value) {
			temp = temp->right_node;
		} else if (node_value < temp->node_value) {
			temp = temp->left_node;
		} else {
			printf("Node com valor %u ja existe!\n", node_value);
			return 0;
		}
	}
	
	if (node_value > previous->node_value)
		previous->right_node = new_node;
	else
		previous->left_node = new_node;
	
	if ((new_node->parent = previous)) return 1;
	
	return 0;
}

int remove_node(unsigned int node_value, Node *node) {
	if (!node) return 0;
	
	if (node_value > node->node_value) {
		remove_node(node_value, node->right_node);
	} else if (node_value < node->node_value) {
		remove_node(node_value, node->left_node);
	} else {
		if (!node->left_node && !node->right_node) {
			if (node->parent && node->parent->left_node == node) {
				node->parent->left_node = NULL_NODE;
			} else if (node->parent && node->parent->right_node == node) {
				node->parent->right_node = NULL_NODE;
			}
			
			free(node);
			node = NULL_NODE;
		}
		
		else if (!node->left_node || !node->right_node) {
			Node *temp = node->left_node ? node->left_node : node->right_node;
			
			if (node->parent) {
				if (node->parent->left_node == node) {
					node->parent->left_node = temp;
				} else if (node->parent->right_node == node) {
					node->parent->right_node = temp;
				}
			}
			
			temp->parent = node->parent;
			free(node);
			node = NULL_NODE;
		}
		
		else {
			Node *max_left = node->left_node;
			
			while (max_left->right_node) max_left = max_left->right_node;
			
			node->node_value = max_left->node_value;
			
			return remove_node(max_left->node_value, node->left_node);
		}
	}
	
	return 1;
}

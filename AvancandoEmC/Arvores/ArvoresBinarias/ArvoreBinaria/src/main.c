#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {
	
	printf("Hello, Tree!\n");
	printf("\n");
	
	TreeNode *node = create_root(100);
	
	printf("ROOT: %d\n", node->data);
	
	insert_new_node(150, &node);
	insert_new_node(50, &node);
	
	TreeNode *lchild = get_left_child(&node);
	TreeNode *rchild = get_right_child(&node);
	
	printf("L: %d\n", lchild->data);
	printf("R: %d\n", rchild->data);
	printf("\n");
	
	printf("SIBLING OF %d: %d\n", lchild->data, get_sibling(&lchild)->data);
	printf("SIBLING OF %d: %d\n", rchild->data, get_sibling(&rchild)->data);
	printf("\n");
	
	printf("PARENT OF %d: %d\n", lchild->data, get_parent(&lchild)->data);
	printf("PARENT OF %d: %d\n", rchild->data, get_parent(&rchild)->data);
	printf("\n");
	
	printf("INSERTING 20 in 50...\n");
	create_left_child(20, &lchild);
	printf("INSERTING 60 in 50...\n");
	create_right_child(60, &lchild);
	printf("\n");
	
	printf("INSERTING 130 in 150...\n");
	create_left_child(130, &rchild);
	printf("INSERTING 180 in 150...\n");
	create_right_child(180, &rchild);
	printf("\n");
	
	printf("L of %d: %d\n", lchild->data, lchild->left_child->data);
	printf("R of %d: %d\n", lchild->data, lchild->right_child->data);
	printf("\n");
	
	printf("L of %d: %d\n", rchild->data, rchild->left_child->data);
	printf("R of %d: %d\n", rchild->data, rchild->right_child->data);
	printf("\n");
	
	printf("SEARCHIN' NODE 50: %s\n", search_node(50, &node) ? "ENCONTRADO": "NAO ENCONTRADO");
	printf("SEARCHIN' NODE 80: %s\n", search_node(80, &node) ? "ENCONTRADO": "NAO ENCONTRADO");
	printf("\n");
	
	printf("EM ORDEM: ");
	in_order(&node);
	printf("\n");
	
	printf("PRE ORDEM: ");
	pre_order(&node);
	printf("\n");
	
	printf("POS ORDEM: ");
	post_order(&node);
	printf("\n");
	
	printf("\nREMOVING 50...\n\n");
	remove_node(50, &node);
	printf("EM ORDEM: ");
	in_order(&node);
	printf("\n");
	
	printf("PRE ORDEM: ");
	pre_order(&node);
	printf("\n");
	
	printf("POS ORDEM: ");
	post_order(&node);
	printf("\n");
	
	return 0;
}
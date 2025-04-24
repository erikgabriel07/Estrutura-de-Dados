#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void in_order(TreeNode **node) {
	if (*node == NULL)  return;
	in_order(&(*node)->left_child);
	printf("%d ", (*node)->data);
	in_order(&(*node)->right_child);
}

void pre_order(TreeNode **node) {
	if (*node == NULL) return;
	printf("%d ", (*node)->data);
	pre_order(&(*node)->left_child);
	pre_order(&(*node)->right_child);
}

void post_order(TreeNode **node) {
	if (*node == NULL) return;
	post_order(&(*node)->left_child);
	post_order(&(*node)->right_child);
	printf("%d ", (*node)->data);
}

TreeNode *get_parent(TreeNode **node) {
	TreeNode *temp = *node;
	
	if(temp->parent) temp = temp->parent;
	else return NULL;
	return temp;
}

TreeNode *get_left_child(TreeNode **node) {
	TreeNode *temp = *node;
	
	if (temp->left_child) temp = temp->left_child;
	else return NULL;
	return temp;
}

TreeNode *get_right_child(TreeNode **node) {
	TreeNode *temp = *node;
	
	if (temp->right_child) temp = temp->right_child;
	else return NULL;
	return temp;
}

TreeNode *get_sibling(TreeNode **node) {
	TreeNode *temp = *node;
	
	if (temp->parent && temp->data > temp->parent->data) {
		temp = temp->parent->left_child;
	} else temp = temp->parent->right_child;
	
	return temp;
}

TreeNode *create_root(int data) {
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = data;
	node->parent = NULL_VALUE;
	node->left_child = NULL_VALUE;
	node->right_child = NULL_VALUE;
	return node;
}

int create_left_child(int data, TreeNode **node) {
	if ((*node)->data == data) return 0;
	
	TreeNode *left_child = (TreeNode *)malloc(sizeof(TreeNode));
	
	TreeNode *temp = *node;
	
	for (temp; temp->left_child; temp = temp->left_child);
	
	left_child->data = data;
	left_child->parent = temp;
	left_child->left_child = NULL_VALUE;
	left_child->right_child = NULL_VALUE;
	
	temp->left_child = left_child;
	
	return 1;
}

int create_right_child(int data, TreeNode **node) {
	if ((*node)->data == data) return 0;
	
	TreeNode *right_child = (TreeNode *)malloc(sizeof(TreeNode));
	
	TreeNode *temp = *node;
	
	for (temp; temp->right_child; temp = temp->right_child);
	
	right_child->data = data;
	right_child->parent = temp;
	right_child->left_child = NULL_VALUE;
	right_child->right_child = NULL_VALUE;
	
	temp->right_child = right_child;
	
	return 1;
}

int search_node(int data, TreeNode **node) {
	TreeNode *temp = *node;
	
	if ((*node)->data == data) return 1;
	
	else {
		if (data > temp->data) {
			temp = temp->right_child;
		} else {
			temp = temp->left_child;
		}
		
		if (temp == NULL) return 0;
		search_node(data, &temp);
	}
}

int insert_new_node(int data, TreeNode **node) {
	if ((*node)->data == data) return 0;
	
	TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
	
	TreeNode *temp, *current = *node;
	
	while (current) {
		temp = current;
		if (current->data < data) {
			current = current->right_child;
		} else {
			current = current->left_child;
		}
	}
	
	if (temp->data < data) temp->right_child = new_node;
	else temp->left_child = new_node;
	
	new_node->data = data;
	new_node->parent = temp;
	new_node->left_child = NULL_VALUE;
	new_node->right_child = NULL_VALUE;
	
	return 1;
}

int remove_node(int data_to_match, TreeNode **node) {
	if (!node || !(*node)) return 0;
	
	TreeNode *current = *node;
	
	if (current->data > data_to_match) {
		return remove_node(data_to_match, &current->left_child);
	} else if (current->data < data_to_match) {
		return remove_node(data_to_match, &current->right_child);
	} else {
		if (!current->left_child && !current->right_child) {
			if (current->parent && current->parent->left_child == current) {
				current->parent->left_child = NULL;
			} else if (current->parent && current->parent->right_child == current) {
				current->parent->right_child = NULL;
			}
			
			free(current);
			*node = NULL;
		}
		
		else if (!current->left_child || !current->right_child) {
			TreeNode *child = current->left_child ? current->left_child : current->right_child;
			
			if (current->parent) {
				if (current->parent->left_child == current) {
					current->parent->left_child = child;
				} else {
					current->parent->right_child = child;
				}
			}
			
			child->parent = current->parent;
			free(current);
			*node = NULL;
		}
		
		else {
			TreeNode *max_left = current->left_child;
			
			while (max_left->right_child) max_left = max_left->right_child;
			
			current->data = max_left->data;
			
			return remove_node(max_left->data, &current->left_child);
		}
		
		return 1;
	}
}
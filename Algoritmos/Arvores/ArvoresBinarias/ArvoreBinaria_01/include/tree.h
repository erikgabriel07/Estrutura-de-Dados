#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Definindo nome da estrutura da árvore binária */
typedef struct _TreeNode TreeNode;

/* Definindo a árvore binária */
struct _TreeNode {
	int data;
	struct _TreeNode *parent;
	struct _TreeNode *left_child;
	struct _TreeNode *right_child;
};

#define NULL_VALUE ((void *) 0)

/**
 * Função que lista os nós da árvore em ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do nó raiz.
 */
void in_order(TreeNode **node);

/**
 * Função que lista os nós da árvore em pré ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do nó raiz.
 */
void pre_order(TreeNode **node);

/**
 * Função que lista os nós da árvore em pós ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do nó raiz.
 */
void post_order(TreeNode **node);

/**
 * Função que retorna o pai de um nó.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								elemento pai.
 */
TreeNode *get_parent(TreeNode **node);

/**
 * Função que retorna o nó à esquerda do nó pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								filho à esquerda.
 */
TreeNode *get_left_child(TreeNode **node);

/**
 * Função que retorna o nó à direita do nó pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								filho à direita.
 */
TreeNode *get_right_child(TreeNode **node);

/**
 * Função que retorna um ponteiro para um nó de um mesmo nó pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um nó.
 * @return						Retorna o ponteiro para o
 *								filho à esquerda.
 */
TreeNode *get_sibling(TreeNode **node);

/**
 * Função para criar um novo nó raiz ou nó pai.
 *
 * @param data					Dados do nó raiz.
 * @return						Retorna o ponteiro para o
 *								nó raiz.
 */
TreeNode *create_root(int data);

/**
 * Função para criar um novo nó à direita de um nó pai.
 *
 * @param data					Dados do nó filho.
 * @param node					Ponteiro para o nó pai.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int create_left_child(int data, TreeNode **node);

/**
 * Função para criar um novo nó à esquerda de um nó pai.
 *
 * @param data					Dados do nó filho.
 * @param node					Ponteiro para o nó pai.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int create_right_child(int data, TreeNode **node);

/**
 * Função para encontrar um nó na árvore.
 *
 * @param data					Dado do nó a ser encontrado.
 * @param node					Ponteiro para o nó raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int search_node(int data, TreeNode **node);

/**
 * Função para inserir um novo nó na árvore.
 *
 * @param data					Dados do novo nó.
 * @param node					Ponteiro para o nó raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int insert_new_node(int data, TreeNode **node);

/**
 * Função para remover um nó da árvore.
 *
 * @param data_to_match			Dado do nó a ser deletado.
 * @param node					Ponteiro para o nó raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int remove_node(int data_to_match, TreeNode **node);

#ifdef __cplusplus
}
#endif

#endif
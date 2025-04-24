#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Definindo nome da estrutura da �rvore bin�ria */
typedef struct _TreeNode TreeNode;

/* Definindo a �rvore bin�ria */
struct _TreeNode {
	int data;
	struct _TreeNode *parent;
	struct _TreeNode *left_child;
	struct _TreeNode *right_child;
};

#define NULL_VALUE ((void *) 0)

/**
 * Fun��o que lista os n�s da �rvore em ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do n� raiz.
 */
void in_order(TreeNode **node);

/**
 * Fun��o que lista os n�s da �rvore em pr� ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do n� raiz.
 */
void pre_order(TreeNode **node);

/**
 * Fun��o que lista os n�s da �rvore em p�s ordem.
 *
 * @param node					Ponteiro para um ponteiro
 *								do n� raiz.
 */
void post_order(TreeNode **node);

/**
 * Fun��o que retorna o pai de um n�.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								elemento pai.
 */
TreeNode *get_parent(TreeNode **node);

/**
 * Fun��o que retorna o n� � esquerda do n� pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								filho � esquerda.
 */
TreeNode *get_left_child(TreeNode **node);

/**
 * Fun��o que retorna o n� � direita do n� pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um elemento pai.
 * @return						Retorna o ponteiro para o
 *								filho � direita.
 */
TreeNode *get_right_child(TreeNode **node);

/**
 * Fun��o que retorna um ponteiro para um n� de um mesmo n� pai.
 *
 * @param node					Ponteiro para um ponteiro
 *								de um n�.
 * @return						Retorna o ponteiro para o
 *								filho � esquerda.
 */
TreeNode *get_sibling(TreeNode **node);

/**
 * Fun��o para criar um novo n� raiz ou n� pai.
 *
 * @param data					Dados do n� raiz.
 * @return						Retorna o ponteiro para o
 *								n� raiz.
 */
TreeNode *create_root(int data);

/**
 * Fun��o para criar um novo n� � direita de um n� pai.
 *
 * @param data					Dados do n� filho.
 * @param node					Ponteiro para o n� pai.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int create_left_child(int data, TreeNode **node);

/**
 * Fun��o para criar um novo n� � esquerda de um n� pai.
 *
 * @param data					Dados do n� filho.
 * @param node					Ponteiro para o n� pai.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int create_right_child(int data, TreeNode **node);

/**
 * Fun��o para encontrar um n� na �rvore.
 *
 * @param data					Dado do n� a ser encontrado.
 * @param node					Ponteiro para o n� raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int search_node(int data, TreeNode **node);

/**
 * Fun��o para inserir um novo n� na �rvore.
 *
 * @param data					Dados do novo n�.
 * @param node					Ponteiro para o n� raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int insert_new_node(int data, TreeNode **node);

/**
 * Fun��o para remover um n� da �rvore.
 *
 * @param data_to_match			Dado do n� a ser deletado.
 * @param node					Ponteiro para o n� raiz.
 * @return						Retorna 1 em caso de sucesso,
 *								ou 0 em caso de fracasso.
 */
int remove_node(int data_to_match, TreeNode **node);

#ifdef __cplusplus
}
#endif

#endif
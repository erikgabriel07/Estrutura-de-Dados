#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Definindo a árvore */
typedef struct _Node Node;

#define MAX_NODES 5

/* Definindo a estrutura da árvore */
struct _Node {
	unsigned int data;
	struct _Node *nodes[MAX_NODES];
};

#define NULL_NODE ((void *)0)

/**
 * Essa função libera a árvore da memória.
 *
 * @param root			Referência para o ponteiro da raíz da árvore
 */
void free_tree(Node **root);

/**
 * Essa função cria um novo nó.
 *
 * @param data			Os dados armazenados no ponteiro
 * @return				Um ponteiro para o novo nó
 */
Node *create_node(unsigned int data);

/**
 * Essa função mostra os nós existentes na árvore.
 *
 * @param level			Indicador da profundidade do nó da raiz (0 por padrão)
 * @param root			Ponteiro para a raíz da árvore
 */
void print_node(unsigned int level, Node *root);

/**
 * Essa função verifica a existência de um nó em determinada posição
 * da árvore.
 *
 * @param position		Posição na árvore.
 * @param root			Ponteiro para a raíz da árvore
 * @return				Retorna 1 se existir, se não 0
 */
int find_node(unsigned int position, Node *root);

/**
 * Essa função insere um novo nó na árvore.
 *
 * @param data			Os dados do novo nó que será inserido.
 * @param root			Ponteiro para a raíz da árvore
 * @return				Retorna 1 se sucesso, se não 0
 */
int insert_new_node(unsigned int data, Node *root);

/**
 * Essa função remove um nó existente na árvore.
 *
 *
 * @param position		Posição do nó a ser removido da árvore
 * @param root			Ponteiro para a raíz da árvore
 * return				Retorna 1 se sucesso, se não 0
 */
int remove_node(unsigned int positon, Node *root);

#ifdef __cplusplus
}
#endif

#endif // TREE_H
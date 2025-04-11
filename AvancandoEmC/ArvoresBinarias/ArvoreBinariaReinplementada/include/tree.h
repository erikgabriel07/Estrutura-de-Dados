#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Definindo árvore */
typedef struct _Node Node;

/* Definindo oa atributos da árvore cujo grau é dois */
struct _Node {
	unsigned int node_value;
	struct _Node *parent;
	struct _Node *left_node;
	struct _Node *right_node;
};

#define NULL_NODE ((void *)0)

/**
 * Essa função libera a árvore da memória.
 *
 * @param node			Um ponteiro que aponta para o ponteiro da árvore.
 */
void free_node(Node **node);

/**
 * Essa função cria uma nova raiz. 
 *
 * @return				Um ponteiro para o nó criado.
 */
Node *create(void);

/**
 * Essa função lista a árvore na forma LNR (Left - Node - Right).
 *
 * @param node			A raiz da árvore.
 */
void in_order_listing(Node *node);

/**
 * Essa função lista a árvore na forma NLR (Node - Left - Right).
 *
 * @param node			A raiz da árvore.
 */
void pre_order_listing(Node *node);

/**
 * Essa função lista a árvore na forma LRN (Left - Right - Node).
 *
 * @param node			A raiz da árvore.
 */
void post_order_listing(Node *node);

/**
 * Essa função lista a árvore de modo formatado, com um visual mais bonito.
 *
 * @param node			A raiz da árvore.
 */
void beautify_print(Node *node, int whitespace);

/**
 * Essa função retorna o nó à esquerda de um nó pai.
 *
 * @param node			Nó raiz ou qualquer outro nó.
 * @return				Um ponteiro para o nó encontrado.
 */
Node *get_left_child(Node *node);

/**
 * Essa função retorna o nó à direita de um nó pai.
 *
 * @param node			Nó raiz ou qualquer outro nó.
 * @return				Um ponteiro para o nó encontrado.
 */
Node *get_right_child(Node *node);

/**
 * Essa função retorna o nó pai de um nó na árvore.
 *
 * @param node			Um nó da árvore.
 * @return				Um ponteiro para o nó encontrado.
 */
Node *get_parent(Node *node);

/**
 * Essa função encontra um nó na árvore pelo seu valor.
 *
 * @param node_value	O valor a ser encontrado na árvore.
 * @param node			O nó raiz da árvore.
 * @return				Retorna 1 se o nó for encontrado, se não 0.
 */
int find_node_by_value(unsigned int node_value, Node *node);

/**
 * Essa função insere um novo nó na árvore.
 *
 * @param node_value	O novo valor que o novo nó irá armazenar.
 * @param node			O nó raiz da árvore.
 * @return				Retorna 1 se o nó for inserido, se não 0.
 */
int insert_new_node(unsigned int node_value, Node **node);

/**
 * Essa função remove um nó presente na árvore.
 *
 * @param node_value	O valor do nó que deve ser removido.
 * @param node			O nó raiz da árvore.
 * @return				Retorna 1 se o nó for removido, se não 0.
 */
int remove_node(unsigned int node_value, Node *node);

#ifdef __cplusplus
}
#endif

#endif
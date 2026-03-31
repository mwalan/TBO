#ifndef BST_H
#define BST_H

typedef struct bst_node BST;

BST* bst_create(void);
BST* bst_insert(BST* root, int key);
void bst_destroy(BST* root);
int bst_height(BST* root);

/* Nova funcao para o cliente ler a chave mantendo o no opaco */
int bst_get_key(BST* node);

/* Exercicio 3: Caminhamentos recursivos em profundidade */
void rec_preorder(BST *t, void (*visit)(BST*));
void rec_inorder(BST *t, void (*visit)(BST*));
void rec_postorder(BST *t, void (*visit)(BST*));

#endif
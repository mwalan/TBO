#ifndef BST_H
#define BST_H

/* Estrutura opaca: os detalhes do no estao no bst.c  */
typedef struct bst_node BST;

/* 1. Criacao de uma BST vazia [cite: 20] */
BST* bst_create(void);

/* 2. Insercao de uma chave na BST [cite: 21] */
BST* bst_insert(BST* root, int key);

/* 3. Destruicao (liberacao da memoria) de uma BST [cite: 22] */
void bst_destroy(BST* root);

/* Funcao para determinar a altura da arvore [cite: 33] */
int bst_height(BST* root);

#endif
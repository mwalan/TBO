#ifndef BST_H
#define BST_H

/* Estrutura opaca: os detalhes do nó estão escondidos no bst.c */
typedef struct bst_node BST;

/* 1. Criação de uma BST vazia */
BST* bst_create(void);

/* 2. Inserção de uma chave na BST */
BST* bst_insert(BST* root, int key);

/* 3. Destruição (liberação da memória) de uma BST */
void bst_destroy(BST* root);

#endif
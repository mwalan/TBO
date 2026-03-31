#include <stdlib.h>
#include "bst.h"

/* Definição da estrutura oculta do nó */
struct bst_node {
    int key;
    struct bst_node* left;
    struct bst_node* right;
};

/* 1. Criação de uma BST vazia */
BST* bst_create(void) {
    return NULL; // Uma árvore vazia é simplesmente um ponteiro nulo
}

/* 2. Inserção de uma chave na BST */
BST* bst_insert(BST* root, int key) {
    // Caso base: encontrou a posição onde a chave deve ser inserida
    if (root == NULL) {
        BST* new_node = (BST*)malloc(sizeof(BST));
        if (new_node != NULL) {
            new_node->key = key;
            new_node->left = NULL;
            new_node->right = NULL;
        }
        return new_node;
    }

    // Passos recursivos
    if (key < root->key) {
        root->left = bst_insert(root->left, key);
    } else if (key > root->key) {
        root->right = bst_insert(root->right, key);
    }
    // Se key == root->key, termina silenciosamente sem modificar a estrutura
    
    return root;
}

/* 3. Destruição (liberação da memória) de uma BST */
void bst_destroy(BST* root) {
    if (root != NULL) {
        // Usa caminhamento pós-ordem: libera os filhos antes do pai
        bst_destroy(root->left);
        bst_destroy(root->right);
        free(root);
    }
}
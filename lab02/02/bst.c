#include <stdlib.h>
#include "bst.h"

/* Definicao da estrutura interna do no  */
struct bst_node {
    int key;
    struct bst_node* left;
    struct bst_node* right;
};

/* 1. Criacao de uma BST vazia [cite: 20] */
BST* bst_create(void) {
    return NULL;
}

/* 2. Insercao de uma chave na BST [cite: 21] */
BST* bst_insert(BST* root, int key) {
    if (root == NULL) {
        BST* new_node = (BST*)malloc(sizeof(BST));
        if (new_node != NULL) {
            new_node->key = key;
            new_node->left = NULL;
            new_node->right = NULL;
        }
        return new_node;
    }

    if (key < root->key) {
        root->left = bst_insert(root->left, key);
    } else if (key > root->key) {
        root->right = bst_insert(root->right, key);
    }
    /* Se key == root->key, a insercao termina silenciosamente sem modificar a estrutura [cite: 24] */
    
    return root;
}

/* 3. Destruicao (liberacao da memoria) de uma BST [cite: 22] */
void bst_destroy(BST* root) {
    if (root != NULL) {
        bst_destroy(root->left);
        bst_destroy(root->right);
        free(root);
    }
}

/* Determina a altura da arvore */
int bst_height(BST* root) {
    /* A altura de uma arvore vazia e -1  */
    if (root == NULL) {
        return -1; 
    }
    
    int left_h = bst_height(root->left);
    int right_h = bst_height(root->right);
    
    /* A altura e o comprimento do caminho mais longo da raiz ate alguma folha [cite: 34] */
    if (left_h > right_h) {
        return left_h + 1;
    } else {
        return right_h + 1;
    }
}
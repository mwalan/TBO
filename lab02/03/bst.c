#include <stdlib.h>
#include "bst.h"

struct bst_node {
    int key;
    struct bst_node* left;
    struct bst_node* right;
};

BST* bst_create(void) { return NULL; }

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
    return root;
}

void bst_destroy(BST* root) {
    if (root != NULL) {
        bst_destroy(root->left);
        bst_destroy(root->right);
        free(root);
    }
}

int bst_height(BST* root) {
    if (root == NULL) return -1; 
    int left_h = bst_height(root->left);
    int right_h = bst_height(root->right);
    return (left_h > right_h) ? (left_h + 1) : (right_h + 1);
}

/* Retorna a chave do no para uso externo */
int bst_get_key(BST* node) {
    if (node != NULL) {
        return node->key;
    }
    return -1; // Retorno de seguranca caso passem um no nulo
}

/* --- EXERCICIO 3: Caminhamentos --- */

void rec_preorder(BST *t, void (*visit)(BST*)) {
    if (t != NULL) {
        visit(t);                     // 1. Visita t
        rec_preorder(t->left, visit); // 2. Esquerda
        rec_preorder(t->right, visit);// 3. Direita
    }
}

void rec_inorder(BST *t, void (*visit)(BST*)) {
    if (t != NULL) {
        rec_inorder(t->left, visit);  // 1. Esquerda
        visit(t);                     // 2. Visita t
        rec_inorder(t->right, visit); // 3. Direita
    }
}

void rec_postorder(BST *t, void (*visit)(BST*)) {
    if (t != NULL) {
        rec_postorder(t->left, visit); // 1. Esquerda
        rec_postorder(t->right, visit);// 2. Direita
        visit(t);                      // 3. Visita t
    }
}
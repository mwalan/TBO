#include <stdio.h>
#include "bst.h"

/* Funcao de visitacao que exibe o conteudo do no */
void print_node(BST* node) {
    printf("%d ", bst_get_key(node));
}

int main() {
    BST* tree = bst_create();
    int key;

    printf("Digite os valores inteiros (digite qualquer letra para encerrar):\n");
    while (scanf("%d", &key) == 1) {
        tree = bst_insert(tree, key);
    }

    printf("\n--- Resultados dos Caminhamentos ---\n");
    
    printf("Pre-ordem: ");
    rec_preorder(tree, print_node);
    printf("\n");

    printf("Em ordem (Deve sair ordenado): ");
    rec_inorder(tree, print_node);
    printf("\n");

    printf("Pos-ordem: ");
    rec_postorder(tree, print_node);
    printf("\n");

    bst_destroy(tree);
    return 0;
}
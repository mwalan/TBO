#include <stdio.h>
#include "bst.h"

int main() {
    // 1. Criação da árvore vazia
    BST* tree = bst_create();
    int key;

    printf("Iniciando processamento da BST...\n");
    printf("Digite os valores inteiros (digite qualquer letra para encerrar):\n");

    // 2. Leitura e Inserção
    // O scanf retornará 1 enquanto conseguir ler um número inteiro com sucesso.
    while (scanf("%d", &key) == 1) {
        printf("Lendo e inserindo chave: %d\n", key);
        tree = bst_insert(tree, key);
    }

    printf("Fim da leitura. Chaves processadas na BST (duplicatas ignoradas silenciosamente).\n");

    // 3. Destruição da árvore
    bst_destroy(tree);
    printf("Memoria da BST liberada com sucesso.\n");

    return 0;
}
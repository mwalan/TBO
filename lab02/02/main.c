#include <stdio.h>
#include "bst.h"

int main() {
    BST* tree = bst_create();
    int key;
    int count = 0;

    printf("Iniciando construcao da BST...\n");
    printf("Digite os valores inteiros (digite qualquer letra para encerrar):\n");

    /* Leitura de dados da entrada padrao */
    while (scanf("%d", &key) == 1) {
        printf("Inserindo chave: %d\n", key);
        tree = bst_insert(tree, key);
        count++;
    }

    printf("Fim da leitura. Total de tentativas de insercao: %d\n", count);

    /* Determina e exibe a altura da arvore gerada */
    int height = bst_height(tree);
    printf("Altura da BST: %d\n", height);

    /* Destruicao e liberacao de memoria */
    bst_destroy(tree);
    printf("Memoria da BST liberada com sucesso.\n");

    return 0;
}
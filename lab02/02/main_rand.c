#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* Necessario para geracao de numeros pseudo-aleatorios [cite: 36, 37] */
#include "bst.h"

int main(int argc, char *argv[]) {
    /* Recebe como argumento um numero N de chaves a serem geradas [cite: 31] */
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <N_CHAVES>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Erro: N deve ser um numero inteiro maior que zero.\n");
        return 1;
    }

    /* Cria uma BST vazia [cite: 31] */
    BST* tree = bst_create();

    /* Inicializa o gerador de numeros pseudo-aleatorios [cite: 38] */
    srand(time(NULL));

    /* Gera N chaves (ints) aleatorias e insere na BST [cite: 32] */
    for (int i = 0; i < n; i++) {
        /* Retorna um inteiro pseudo-aleatorio entre 0 e RAND_MAX [cite: 40] */
        int key = rand(); 
        tree = bst_insert(tree, key);
    }

    /* Determina a altura final da BST criada e exibe essa informacao em stdout [cite: 33] */
    int height = bst_height(tree);
    printf("Numero de chaves tentadas (N): %d\n", n);
    printf("Altura final da BST: %d\n", height);

    /* Destruicao da BST [cite: 22] */
    bst_destroy(tree);

    return 0;
}
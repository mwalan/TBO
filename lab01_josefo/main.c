#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <M> [1 para imprimir, 0 para silenciar]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int imprimir = (argc > 3) ? atoi(argv[3]) : 1;

    Josefo* roda = criar_josefo(n);

    // Elimina até sobrar apenas 1 (o líder)
    while (pessoas_restantes(roda) > 1) {
        int eliminado = eliminar_pessoa(roda, m);
        if (imprimir) {
            printf("%d ", eliminado);
        }
    }

    // A última pessoa a ser removida é o líder escolhido
    int lider = eliminar_pessoa(roda, 1);
    
    if (imprimir) {
        printf("\nLider escolhido: %d\n", lider);
    }

    destruir_josefo(roda);
    return 0;
}
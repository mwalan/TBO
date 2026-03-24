#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <N> [1 para imprimir primos, 0 para silenciar]\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[1]);
    int imprimir = (argc > 2) ? atoi(argv[2]) : 0;

    Crivo* meu_crivo = criar_crivo(n);

    // O algoritmo acontece aqui
    executar_crivo(meu_crivo);

    // Impressão opcional
    if (imprimir) {
        for (long long i = 2; i <= n; i++) {
            if (eh_primo(meu_crivo, i)) {
                printf("%lld\n", i);
            }
        }
    }

    destruir_crivo(meu_crivo);
    return 0;
}
#include <stdlib.h>
#include "crivo.h"

struct crivo {
    long long n;
    char* vetor; // Usando char para gastar apenas 1 byte por número
};

Crivo* criar_crivo(long long n) {
    Crivo* c = malloc(sizeof(Crivo));
    c->n = n;
    // calloc inicializa tudo com 0 (0 = primo, 1 = composto)
    c->vetor = calloc(n + 1, sizeof(char)); 
    return c;
}

void destruir_crivo(Crivo* c) {
    free(c->vetor);
    free(c);
}

void marcar_composto(Crivo* c, long long i) {
    c->vetor[i] = 1;
}

bool eh_primo(Crivo* c, long long i) {
    if (i < 2) return false;
    return c->vetor[i] == 0;
}

void executar_crivo(Crivo* c) {
    for (long long i = 2; i * i <= c->n; i++) {
        if (eh_primo(c, i)) {
            for (long long j = i * i; j <= c->n; j += i) {
                marcar_composto(c, j);
            }
        }
    }
}
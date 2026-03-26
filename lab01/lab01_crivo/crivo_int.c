#include <stdlib.h>
#include "crivo.h"

struct crivo {
    long long n;
    int* vetor; // 0 significa primo (não marcado), 1 significa composto
};

Crivo* criar_crivo(long long n) {
    Crivo* c = malloc(sizeof(Crivo));
    c->n = n;
    // calloc inicializa tudo com 0 (assumimos que todos são primos no início)
    c->vetor = calloc(n + 1, sizeof(int)); 
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
    // Otimização: só precisamos testar até a raiz quadrada de N (i * i <= n)
    for (long long i = 2; i * i <= c->n; i++) {
        if (eh_primo(c, i)) {
            // Otimização: os múltiplos começam a ser marcados a partir de i*i
            for (long long j = i * i; j <= c->n; j += i) {
                marcar_composto(c, j);
            }
        }
    }
}
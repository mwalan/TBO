#include <stdlib.h>
#include "crivo.h"

struct crivo {
    long long n;
    unsigned char* bitmap;
};

Crivo* criar_crivo(long long n) {
    Crivo* c = malloc(sizeof(Crivo));
    c->n = n;
    // Calcula quantos bytes precisamos para guardar N bits
    long long num_bytes = (n / 8) + 1; 
    c->bitmap = calloc(num_bytes, sizeof(unsigned char));
    return c;
}

void destruir_crivo(Crivo* c) {
    free(c->bitmap);
    free(c);
}

void marcar_composto(Crivo* c, long long i) {
    long long indice_byte = i / 8;
    int indice_bit = i % 8;
    c->bitmap[indice_byte] |= (1 << indice_bit); // Liga o bit (seta para 1)
}

bool eh_primo(Crivo* c, long long i) {
    if (i < 2) return false;
    long long indice_byte = i / 8;
    int indice_bit = i % 8;
    // Se o bit for 0, é primo. Invertemos o resultado com '!'
    return !(c->bitmap[indice_byte] & (1 << indice_bit)); 
}

void executar_crivo(Crivo* c) {
    // A lógica de execução é exatamente a mesma! O que muda é como marca/verifica.
    for (long long i = 2; i * i <= c->n; i++) {
        if (eh_primo(c, i)) {
            for (long long j = i * i; j <= c->n; j += i) {
                marcar_composto(c, j);
            }
        }
    }
}
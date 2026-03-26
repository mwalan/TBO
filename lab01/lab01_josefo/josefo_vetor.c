#include <stdlib.h>
#include "josefo.h"

struct josefo {
    int* prox; // Vetor que guarda o índice da próxima pessoa viva
    int atual;
    int tamanho;
};

Josefo* criar_josefo(int n) {
    Josefo* j = malloc(sizeof(Josefo));
    j->tamanho = n;
    
    // Aloca N+1 para usar os índices de 1 a N
    j->prox = malloc((n + 1) * sizeof(int)); 
    
    for (int i = 1; i < n; i++) {
        j->prox[i] = i + 1;
    }
    j->prox[n] = 1; // O último aponta para o primeiro
    j->atual = n;   // Começa "antes" do 1º
    
    return j;
}

int eliminar_pessoa(Josefo* j, int m) {
    if (j->tamanho == 0) return -1;

    // Pula M-1 vezes usando o valor do array como índice
    for (int i = 0; i < m - 1; i++) {
        j->atual = j->prox[j->atual];
    }

    int removido = j->prox[j->atual];
    
    // O atual agora aponta para quem estava DEPOIS do removido
    j->prox[j->atual] = j->prox[removido]; 
    j->tamanho--;

    return removido;
}

int pessoas_restantes(Josefo* j) {
    return j->tamanho;
}

void destruir_josefo(Josefo* j) {
    free(j->prox);
    free(j);
}